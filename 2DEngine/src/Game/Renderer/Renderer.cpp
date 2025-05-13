#include <2DEngine/Game/Renderer/Renderer.hpp>
#include <SDL_image.h>
Renderer::Renderer(const std::string& i_window_name) : m_window_name(i_window_name)
{
}

int Renderer::initialize(){
  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0)
  {
    printf("Unable to initialize SDL: %s\n", SDL_GetError());
    return -1;
  }

  m_window = SDL_CreateWindow(m_window_name.c_str(), 100, 100, 1280, 720, 0);
  if (!m_window)
  {
    printf("Failed to create window: %s\n", SDL_GetError());
    return -1;
  }
  m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

  if (IMG_Init(IMG_INIT_PNG) == 0)
	{
		printf("Unable to initialize SDL_image: %s\n", SDL_GetError());
		return -1;
	}
  return 0;
}

SDL_Texture *Renderer::createTexture(const std::string &i_file_path)
{
  SDL_Texture *texture = nullptr;
  // Is the texture already in the map?
  auto iter = m_loaded_textures.find(i_file_path);
  if (iter != m_loaded_textures.end())
  {
    texture = iter->second;
  }
  else
  {
    // Load from file
    SDL_Surface *surface = IMG_Load(i_file_path.c_str());
    if (!surface)
    {
      printf("Failed to load texture file %s\n", i_file_path.c_str());
      return nullptr;
    }

    // Create texture from surface
    texture = SDL_CreateTextureFromSurface(m_renderer, surface);
    SDL_FreeSurface(surface);
    if (!texture)
    {
      printf("Failed to convert surface to texture for %s\n", i_file_path.c_str());
      return nullptr;
    }

    m_loaded_textures.emplace(i_file_path.c_str(), texture);
  }
  return texture;
}

void Renderer::clearTextureMap(){
  for(auto texture : m_loaded_textures){
    SDL_DestroyTexture(texture.second);
  }
  m_loaded_textures.clear();
}
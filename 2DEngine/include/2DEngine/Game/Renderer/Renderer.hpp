#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <SDL2/SDL.h>
#include <string>
#include <unordered_map>

class Renderer {
    public :
        Renderer(const std::string& i_window_name);
        int initialize();
        SDL_Texture* createTexture(const std::string& i_file_path);
        void clearTextureMap();
    protected:
    private:
        std::string m_window_name;
        SDL_Window* m_window;
        SDL_Renderer* m_renderer;
        //Map of texture loaded
        std::unordered_map<std::string, SDL_Texture*> m_loaded_textures;
};
#endif //RENDERER_HPP 
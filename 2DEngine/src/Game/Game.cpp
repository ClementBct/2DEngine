#include <2DEngine/Game/Game.hpp>
#include <2DEngine/Game/Renderer/Renderer.hpp>
#include <2DEngine/Scene/Scene.hpp>
#include <2DEngine/Actor/Actor.hpp>

#include <SDL2/SDL.h>

Game::Game(const std::string& i_game_name) : m_game_name(i_game_name){

}

int Game::initialize(){
    m_renderer = std::make_shared<Renderer>(m_game_name);
    if(m_renderer->initialize() < 0){
        return -1;
    }
    m_ticks_count = SDL_GetTicks();
    return 0;
}

void Game::runLoop(){

}

void Game::updateGame(){
    // Compute delta time
	// Wait until 16ms has elapsed since last frame
	while (!SDL_TICKS_PASSED(SDL_GetTicks(), m_ticks_count + 16)); 
    float delta_time_s = (SDL_GetTicks() - m_ticks_count) / 1000.0f;
    if (delta_time_s > 0.05f)
	{
		delta_time_s = 0.05f;
	}
	m_ticks_count = SDL_GetTicks();
    if(m_active_scene){
        for(auto actor : m_active_scene->getActorList()){
            actor->update(delta_time_s);
        }
    }

}
#include <2DEngine/Game/Game.hpp>
#include <2DEngine/Game/Renderer/Renderer.hpp>

Game::Game(const std::string& i_game_name) : m_game_name(i_game_name){

}

int Game::initialize(){
    m_renderer = std::make_shared<Renderer>(m_game_name);
    if(m_renderer->initialize() < 0){
        return -1;
    }
    return 0;
}

void Game::runLoop(){

}
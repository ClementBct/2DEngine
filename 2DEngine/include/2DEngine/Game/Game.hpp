#ifndef GAME_HPP
#define GAME_HPP

#include <string>
#include <vector>
#include <memory>

class Game {
    public :
        Game(const std::string& i_game_name);
        int initialize();
        void runLoop();
    protected:
    private:
        std::shared_ptr<class Renderer> m_renderer;
        class Scene* m_active_scene;
        std::vector<class Scene*> m_scene_list;
        std::string m_game_name;
        void processInput();
};
#endif //GAME_HPP 
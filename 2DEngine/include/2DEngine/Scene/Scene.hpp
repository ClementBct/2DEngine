#ifndef SCENE_HPP
#define SCENE_HPP

#include <string>
#include <vector>

class Scene {
    public :
        Scene(const std::string& i_scene_name);
        virtual void update(float i_delta_time_s);
        void addActor(class Actor* i_actor);
        void removeActor(class Actor* i_actor);
        std::vector<class Actor*> getActorList();
    protected:
    private:
        std::string m_scene_name;
        std::vector<class Actor*> m_actor_list;
};
#endif //SCENE_HPP 
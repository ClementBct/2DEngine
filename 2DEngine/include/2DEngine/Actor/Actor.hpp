#ifndef ACTOR_HPP
#define ACTOR_HPP

#include <string>
#include <vector>
#include <2DEngine/Game/Math/Math.hpp>

class Actor {
    public :
        Actor(const std::string& i_actor_name, class Scene* i_scene_owner = nullptr);
        ~Actor();
        std::vector<class Component*> getComponentList();
        void addComponent(class Component* i_component);
        void removeComponent(class Component* i_component);
        std::string getActorName();
        virtual void update(float i_delta_time);
        virtual void onStart();
        Vector2 getPosition();
        float getScale();
        float getRotation();
    protected:
    private:
        class Scene* m_scene_owner = nullptr;
        std::string m_actor_name;
        std::vector<class Component*> m_component_list;
        Vector2 m_position;
        float m_scale = 1.0f;
        float m_rotation = 0.0f;
};
#endif //COMPONENT_HPP 
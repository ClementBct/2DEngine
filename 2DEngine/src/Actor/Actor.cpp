#include <2DEngine/Actor/Actor.hpp>
#include <2DEngine/Component/Component.hpp>
#include <2DEngine/Scene/Scene.hpp>

#include <algorithm>

Actor::Actor(const std::string& i_actor_name, Scene* i_scene_owner) : m_actor_name(i_actor_name), m_scene_owner(i_scene_owner){
    m_position = (Vector2::Zero);
}
Actor::~Actor(){
    m_scene_owner->removeActor(this);
    while (!m_component_list.empty())
	{
		delete m_component_list.back();
	}
}

std::vector<Component*> Actor::getComponentList(){
    return m_component_list;
}

void Actor::addComponent(Component* i_component){
	uint32_t component_order = i_component->getUpdateOrder();
	auto iter = m_component_list.begin();
	for (;
		iter != m_component_list.end();
		++iter)
	{
		if (component_order < (*iter)->getUpdateOrder())
		{
			break;
		}
	}
	m_component_list.insert(iter, i_component);
	i_component->setComponentOwner(this);
}
void Actor::removeComponent(Component* i_compoent){
    auto iter = std::find(m_component_list.begin(), m_component_list.end(), i_compoent);
	if (iter != m_component_list.end())
	{
		m_component_list.erase(iter);
	}
}

Vector2 Actor::getPosition(){
    return m_position;
}
float Actor::getRotation(){
    return m_rotation;
}

float Actor::getScale(){
    return m_scale;
}

std::string Actor::getActorName(){
	return m_actor_name;
}

void Actor::update(float i_delta_time_s){
    for(auto component : m_component_list){
        component->update(i_delta_time_s);
    }
}

void Actor::onStart(){
	for(auto component : m_component_list){
        component->onStart();
    }
}
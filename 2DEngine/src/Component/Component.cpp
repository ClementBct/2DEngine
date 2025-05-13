#include <2DEngine/Component/Component.hpp>
#include <2DEngine/Actor/Actor.hpp>
Component::Component(const std::string &i_component_name, Actor *i_owner_actor, uint32_t i_update_order) : m_component_name(i_component_name), m_owner_actor(i_owner_actor), m_update_order(i_update_order)
{
}

std::string Component::getComponentName()
{
    return m_component_name;
}
uint32_t Component::getUpdateOrder()
{
    return m_update_order;
}

void Component::update(float i_delta_time_s)
{
}
void Component::onStart(){

}

void Component::setComponentOwner(class Actor* i_owner_actor){
    m_owner_actor = i_owner_actor;
}

Actor* Component::getComponentOwner(){
    return m_owner_actor;
}
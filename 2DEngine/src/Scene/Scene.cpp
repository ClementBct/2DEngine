#include <2DEngine/Scene/Scene.hpp>
#include <2DEngine/Actor/Actor.hpp>

#include <algorithm>

Scene::Scene(const std::string &i_scene_name) : m_scene_name(i_scene_name)
{

}
void Scene::update(float i_delta_time_s)
{
    for(auto actor : m_actor_list){
        actor->update(i_delta_time_s);
    }
}

void Scene::addActor(Actor *i_actor)
{
    m_actor_list.push_back(i_actor);
}
void Scene::removeActor(Actor *i_actor)
{
    auto iter = std::find(m_actor_list.begin(), m_actor_list.end(), i_actor);
	if (iter != m_actor_list.end())
	{
		m_actor_list.erase(iter);
	}
}
std::vector<Actor*> Scene::getActorList(){
    return m_actor_list;
}


#include <2DEngine/Component/Sprite/SpriteComponent.hpp>
#include <2DEngine/Actor/Actor.hpp>

SpriteComponent::SpriteComponent(const std::string& i_sprite_name,Actor* i_owner_actor ,uint32_t i_update_order) : Component(i_sprite_name,i_owner_actor ,i_update_order) {

}

void SpriteComponent::update(float i_delta_time_s){
} 

void SpriteComponent::onStart(){
} 
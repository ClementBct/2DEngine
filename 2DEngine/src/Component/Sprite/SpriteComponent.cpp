#include <2DEngine/Component/Sprite/SpriteComponent.hpp>
#include <2DEngine/Actor/Actor.hpp>

SpriteComponent::SpriteComponent(const std::string& i_sprite_name,Actor* i_owner_actor ,uint32_t i_draw_order) : Component(i_sprite_name,i_owner_actor), m_draw_order(i_draw_order) {

}

void SpriteComponent::update(float i_delta_time_s){
} 

void SpriteComponent::onStart(){
} 

void SpriteComponent::draw(SDL_Renderer* i_renderer){
    if(m_texture && m_owner_actor){
        		SDL_Rect r;
		// Scale the width/height by owner's scale
		r.w = static_cast<int>(m_texture_width * m_owner_actor->getScale());
		r.h = static_cast<int>(m_texture_height * m_owner_actor->getScale());
		// Center the rectangle around the position of the owner
		r.x = static_cast<int>(m_owner_actor->getPosition().x - r.w / 2);
		r.y = static_cast<int>(m_owner_actor->getPosition().y - r.h / 2);

		// Draw (have to convert angle from radians to degrees, and clockwise to counter)
		SDL_RenderCopyEx(i_renderer,
			m_texture,
			nullptr,
			&r,
			-Math::ToDegrees(m_owner_actor->getRotation()),
			nullptr,
			SDL_FLIP_NONE);
    }
}

void SpriteComponent::setTexture(SDL_Texture* i_texture){
    m_texture = i_texture;
}
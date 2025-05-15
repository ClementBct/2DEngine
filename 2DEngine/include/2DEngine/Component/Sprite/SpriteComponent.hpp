#ifndef SPRITE_COMPONENT_HPP
#define SPRITE_COMPONENT_HPP

#include <2DEngine/Component/Component.hpp>
#include <SDL2/SDL.h>

class SpriteComponent : public Component {
    public :
        SpriteComponent(const std::string& i_sprite_name, class Actor* i_owner_actor,  uint32_t i_draw_order = DEFAULT_UPDATE_ORDER);
        void update(float i_delta_time_s) override;
        void onStart() override;
        virtual void draw(SDL_Renderer* i_renderer);
        virtual void setTexture(SDL_Texture* i_texture);
    protected:
    private:
        uint32_t m_draw_order;
        SDL_Texture* m_texture = nullptr;
        uint32_t m_texture_height;
        uint32_t m_texture_width;
};
#endif //SPRITE_COMPONENT_HPP 
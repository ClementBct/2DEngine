#ifndef SPRITE_COMPONENT_HPP
#define SPRITE_COMPONENT_HPP

#include <2DEngine/Component/Component.hpp>

class SpriteComponent : public Component {
    public :
        SpriteComponent(const std::string& i_sprite_name, class Actor* i_owner_actor,  uint32_t i_update_order = DEFAULT_UPDATE_ORDER);
        void update(float i_delta_time_s) override;
        void onStart() override;
    protected:
    private:
};
#endif //SPRITE_COMPONENT_HPP 
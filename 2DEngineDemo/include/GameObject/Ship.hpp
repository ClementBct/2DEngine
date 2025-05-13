#ifndef SHIP_HPP
#define SHIP_HPP

#include <2DEngine/Actor/Actor.hpp>

class Ship : public Actor {
    public:
        Ship(const std::string i_ship_name);
        void update(float i_delta_time_s);
        void onStart();
    protected:
    private:
};
#endif //SHIP_HPP

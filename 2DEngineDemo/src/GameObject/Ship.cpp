#include <GameObject/Ship.hpp>
Ship::Ship(const std::string i_ship_name) : Actor(i_ship_name){
}

void Ship::update(float i_delta_time_s){
    Actor::update(i_delta_time_s); //obligatoire
}

void Ship::onStart(){
    Actor::onStart(); //obligatoire
}
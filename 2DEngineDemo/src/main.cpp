#include <iostream>
#include <2DEngine/Game/Game.hpp>

#include <GameObject/Ship.hpp>
int main(int argv, char **args)
{
    Game myNewGame("Super game");
    myNewGame.initialize();
    Ship mySuperShip("MySuperShip");
    return 0;
}
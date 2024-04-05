#include "throwableItem.h"
#include <iostream>
#include "Zombie.h"


Throwable::Throwable(std::string _name, int _price) : Item(_name, _price) {}

void Throwable::use(Player& player,StrongZombie& zombie)
{
    std::cout << "Threw " << getName() << " at the enemy." << std::endl;
    zombie.setHealth(zombie.getHealth() - 10);
    // Assuming the throwable item causes 10 damage to the enemy
}

Molotov::Molotov(std::string _name, int _price) : Throwable(_name, _price) {}

Brick::Brick(std::string _name, int _price) : Throwable(_name, _price) {}

Grenade::Grenade(std::string _name, int _price) : Throwable(_name, _price) {}

#include "throwableItem.h"
#include <iostream>
#include <conio.h>
#include "Enemy.h"


Throwable::Throwable(std::string _name, int _price) : Item(_name, _price) {}

void Throwable::use(Player& player,Enemy* enemy)
{
    std::cout << "\t\t\t\t"  << "Threw " << getName() << " at the enemy." << std::endl;
    enemy->setHealth(enemy->getHealth() - 10);
    std::cout << "\t\t\t\t"  << "Press any key to continue... " << std::endl;
    char s = _getch();
    // Assuming the throwable item causes 10 damage to the enemy
}

Molotov::Molotov(std::string _name, int _price) : Throwable(_name, _price) {}

Brick::Brick(std::string _name, int _price) : Throwable(_name, _price) {}

Grenade::Grenade(std::string _name, int _price) : Throwable(_name, _price) {}

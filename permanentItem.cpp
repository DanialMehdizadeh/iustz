#include "permanentItem.h"

PermanentItem::PermanentItem(std::string _name, int _price) : Item(_name, _price) {}

void PermanentItem::use(Player& player, StrongZombie& zombie)
{
    // Placeholder for future use
}

Weapon::Weapon(std::string _name, int _price, int _damage) : PermanentItem(_name, _price), damage(_damage) {}

void Weapon::use(Player& player, StrongZombie& zombie)
{
    // Placeholder for future use
}

Melee::Melee(std::string _name, int _price, int _damage) : Weapon(_name, _price, _damage) {}

void Melee::use(Player& player, StrongZombie& zombie)
{
    // Placeholder for future use
}

HotWeapon::HotWeapon(std::string _name, int _price, int _damage) : Weapon(_name, _price, _damage) {}

void HotWeapon::use(Player& player, StrongZombie& zombie)
{
    // Placeholder for future use
}

Rifle::Rifle(std::string _name, int _price, int _damage) : HotWeapon(_name, _price, _damage) {}

void Rifle::use(Player& player, StrongZombie& zombie) 
{
    std::cout << "Fired " << getName() << " and dealt " << damage << " damage." << std::endl;
}

Pistol::Pistol(std::string _name, int _price, int _damage) : HotWeapon(_name, _price, _damage) {}

void Pistol::use(Player& player, StrongZombie& zombie) 
{
    std::cout << "Fired " << getName() << " and dealt " << damage << " damage." << std::endl;
}

Shotgun::Shotgun(std::string _name, int _price, int _damage) : HotWeapon(_name, _price, _damage) {}

void Shotgun::use(Player& player, StrongZombie& zombie) 
{
    std::cout << "Fired " << getName() << " and dealt " << damage << " damage." << std::endl;
}

Knife::Knife(std::string _name, int _price, int _damage) : Melee(_name, _price, _damage) {}

void Knife::use(Player& player, StrongZombie& zombie) 
{
    std::cout << "Stabbed with " << getName() << " and dealt " << damage << " damage." << std::endl;
}

Katana::Katana(std::string _name, int _price, int _damage) : Melee(_name, _price, _damage) {}

void Katana::use(Player& player, StrongZombie& zombie) 
{
    std::cout << "Slashed with " << getName() << " and dealt " << damage << " damage." << std::endl;
}

Axe::Axe(std::string _name, int _price, int _damage) : Melee(_name, _price, _damage) {}

void Axe::use(Player& player, StrongZombie& zombie) 
{
    std::cout << "Swung " << getName() << " and dealt " << damage << " damage." << std::endl;
}
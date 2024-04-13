#include "permanentItem.h"
#include "Player.h"

PermanentItem::PermanentItem(std::string _name, int _price) : Item(_name, _price) {}

void PermanentItem::use(Player& player, Enemy* enemy)
{
    // Placeholder
}

Weapon::Weapon(std::string _name, int _price, int _damage) : PermanentItem(_name, _price), damage(_damage) {}

void Weapon::use(Player& player, Enemy* enemy)
{
    player.setAttack(player.getAttackDamage()+ damage);
    std::cout << "\t\t\t\t"  <<  name << " equiped and added " << damage << "to your attack damage." << std::endl;
}

Melee::Melee(std::string _name, int _price, int _damage) : Weapon(_name, _price, _damage) {}

void Melee::use(Player& player, Enemy* enemy)
{
    player.setAttack(player.getAttackDamage()+ damage);
    std::cout << "\t\t\t\t"  <<  name << " equiped and added " << damage << "to your attack damage." << std::endl;
}

Firearm::Firearm(std::string _name, int _price, int _damage) : Weapon(_name, _price, _damage) {}

void Firearm::use(Player& player, Enemy* enemy)
{
    player.setAttack(player.getAttackDamage()+ damage);
    std::cout << "\t\t\t\t"  <<  name << " equiped and added " << damage << "to your attack damage." << std::endl;
}

Rifle::Rifle(std::string _name, int _price, int _damage) : Firearm(_name, _price, _damage) {}

void Rifle::use(Player& player, Enemy* enemy) 
{
    player.setAttack(player.getAttackDamage()+ damage);
    std::cout << "\t\t\t\t"  <<  name << " equiped and added " << damage << "to your attack damage." << std::endl;
}

Pistol::Pistol(std::string _name, int _price, int _damage) : Firearm(_name, _price, _damage) {}

void Pistol::use(Player& player, Enemy* enemy) 
{
    player.setAttack(player.getAttackDamage()+ damage);
    std::cout << "\t\t\t\t"  <<  name << " equiped and added " << damage << "to your attack damage." << std::endl;
}

Shotgun::Shotgun(std::string _name, int _price, int _damage) : Firearm(_name, _price, _damage) {}

void Shotgun::use(Player& player, Enemy* enemy) 
{
    player.setAttack(player.getAttackDamage()+ damage);
    std::cout << "\t\t\t\t"  <<  name << " equiped and added " << damage << "to your attack damage." << std::endl;
}

Knife::Knife(std::string _name, int _price, int _damage) : Melee(_name, _price, _damage) {}

void Knife::use(Player& player, Enemy* enemy) 
{
    player.setAttack(player.getAttackDamage()+ damage);
    std::cout << "\t\t\t\t"  <<  name << " equiped and added " << damage << "to your attack damage." << std::endl;
}

Katana::Katana(std::string _name, int _price, int _damage) : Melee(_name, _price, _damage) {}

void Katana::use(Player& player, Enemy* enemy) 
{
    player.setAttack(player.getAttackDamage()+ damage);
    std::cout << "\t\t\t\t"  <<  name << " equiped and added " << damage << "to your attack damage." << std::endl;
}

Axe::Axe(std::string _name, int _price, int _damage) : Melee(_name, _price, _damage) {}

void Axe::use(Player& player, Enemy* enemy) 
{
    player.setAttack(player.getAttackDamage()+ damage);
    std::cout << "\t\t\t\t"  <<  name << " equiped and added " << damage << "to your attack damage." << std::endl;
}
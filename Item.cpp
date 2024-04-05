#include "Item.h"
#include "Player.h"
#include "Zombie.h"

Item::Item(std::string _name, int _price) : name(_name), price(_price) {}

void Item::use(Player& player,StrongZombie& zombie) {

}
std::string Item::getName() const
{
    return name;
}
int Item::getPrice() const
{
    return price;
}

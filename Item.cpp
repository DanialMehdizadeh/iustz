#include "Item.h"
#include "Player.h"
#include "Enemy.h"

Item::Item(std::string _name, int _price) : name(_name), price(_price) {}

void Item::use(Player& player,Enemy* enemy) {

}
std::string Item::getName() const
{
    return name;
}
int Item::getPrice() const
{
    return price;
}

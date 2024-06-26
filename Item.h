#ifndef ITEM_H
#define ITEM_H


#include <iostream>
#include <string>
class Player;
class Enemy;

class Item {
protected:
    std::string name;
    int price;

public:
    virtual void use(Player& player,Enemy* enemy) = 0;
    Item(std::string _name, int _price);


    std::string getName() const;
    int getPrice() const;
};

#endif //ITEM_H
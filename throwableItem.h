#ifndef THROWABLEITEM_H
#define THROWABLEITEM_H

#include "Item.h"

class StrongZombie;

class Throwable : public Item {
public:
    Throwable(std::string _name, int _price);

    void use(Player& player,StrongZombie& zombie) override;
};

class Molotov : public Throwable {
public:
    Molotov(std::string _name, int _price);
};

class Brick : public Throwable {
public:
    Brick(std::string _name, int _price);
};

class Grenade : public Throwable {
public:
    Grenade(std::string _name, int _price);
};

#endif //THROWABLEITEM_H
#ifndef CONSUMABLEITEM_H
#define CONSUMABLEITEM_H

#include "Item.h"
class Player;

class Consumable : public Item {
public:
    Consumable(std::string _name, int _price);

    void use(Player& player,StrongZombie& zombie) override;
};

class HealthBooster : public Consumable {
    int effectValue;

public:
    HealthBooster(std::string _name, int _price, int _effectValue);

    void use(Player& player,StrongZombie& zombie) override;
};

class StaminaBooster : public Consumable {
    int effectValue;

public:
    StaminaBooster(std::string _name, int _price, int _effectValue);

    void use(Player& player,StrongZombie& zombie) override;
};

class HealthPotion : public HealthBooster {
public:
    HealthPotion(std::string _name, int _price, int _effectValue);
};

class CannedFood : public HealthBooster {
public:
    CannedFood(std::string _name, int _price, int _effectValue);
};

class EnergyDrink : public StaminaBooster {
public:
    EnergyDrink(std::string _name, int _price, int _effectValue);
};

class ChocolateBar : public StaminaBooster {
public:
    ChocolateBar(std::string _name, int _price, int _effectValue);
};


#endif //CONSUMABLEITEM_H
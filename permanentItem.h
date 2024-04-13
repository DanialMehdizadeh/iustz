#ifndef PERMANENTITEM_H
#define PERMANENTITEM_H

#include "item.h"


class PermanentItem : public Item {
public:
    PermanentItem(std::string _name, int _price);

    void use(Player& player, Enemy* enemy) override;
};

class Weapon : public PermanentItem {
protected:
    int damage;

public:
    Weapon(std::string _name, int _price, int _damage);

    void use(Player& player, Enemy* enemy) override;
};

class Melee : public Weapon {
public:
    Melee(std::string _name, int _price, int _damage);

    void use(Player& player, Enemy* enemy) override;
};

class Firearm : public Weapon {
public:
    Firearm(std::string _name, int _price, int _damage);

    void use(Player& player, Enemy* enemy) override;
};

class Rifle : public Firearm {
public:
    Rifle(std::string _name, int _price, int _damage);

    void use(Player& player, Enemy* enemy) override;
};

class Pistol : public Firearm {
public:
    Pistol(std::string _name, int _price, int _damage);

    void use(Player& player, Enemy* enemy) override;
};

class Shotgun : public Firearm {
public:
    Shotgun(std::string _name, int _price, int _damage);

    void use(Player& player, Enemy* enemy) override;
};

class Knife : public Melee {
public:
    Knife(std::string _name, int _price, int _damage);

    void use(Player& player, Enemy* enemy) override;
};

class Katana : public Melee {
public:
    Katana(std::string _name, int _price, int _damage);

    void use(Player& player, Enemy* enemy) override;
};

class Axe : public Melee {
public:
    Axe(std::string _name, int _price, int _damage);

    void use(Player& player, Enemy* enemy) override;
};
#endif //PERMANENTITEM_H
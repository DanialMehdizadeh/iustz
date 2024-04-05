#ifndef PERMANENTITEM_H
#define PERMANENTITEM_H

#include "item.h"


class PermanentItem : public Item {
public:
    PermanentItem(std::string _name, int _price);

    void use(Player& player, StrongZombie& zombie) override;
};

class Weapon : public PermanentItem {
protected:
    int damage;

public:
    Weapon(std::string _name, int _price, int _damage);

    void use(Player& player, StrongZombie& zombie) override;
};

class Melee : public Weapon {
public:
    Melee(std::string _name, int _price, int _damage);

    void use(Player& player, StrongZombie& zombie) override;
};

class HotWeapon : public Weapon {
public:
    HotWeapon(std::string _name, int _price, int _damage);

    void use(Player& player, StrongZombie& zombie) override;
};

class Rifle : public HotWeapon {
public:
    Rifle(std::string _name, int _price, int _damage);

    void use(Player& player, StrongZombie& zombie) override;
};

class Pistol : public HotWeapon {
public:
    Pistol(std::string _name, int _price, int _damage);

    void use(Player& player, StrongZombie& zombie) override;
};

class Shotgun : public HotWeapon {
public:
    Shotgun(std::string _name, int _price, int _damage);

    void use(Player& player, StrongZombie& zombie) override;
};

class Knife : public Melee {
public:
    Knife(std::string _name, int _price, int _damage);

    void use(Player& player, StrongZombie& zombie) override;
};

class Katana : public Melee {
public:
    Katana(std::string _name, int _price, int _damage);

    void use(Player& player, StrongZombie& zombie) override;
};

class Axe : public Melee {
public:
    Axe(std::string _name, int _price, int _damage);

    void use(Player& player, StrongZombie& zombie) override;
};
#endif //PERMANENTITEM_H
#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <string>
#include <iostream>
#include "Player.h"
#include "Bar.h"





class Zombie {
protected:
    std::string name;
    std::string description;
    std::string ability;
    int level;
    int maxHealth;
    int health;
    int maxStamina;
    int staminaCost;
    int stamina;
    int attackDamage;
    int infection;

public:
    Zombie(std::string _name);
    std::string getName() const;
    std::string getDescription() const;
    std::string getAbility() const;
    int getLevel() const;
    int getMaxHealth() const;
    int getHealth() const;
    int getMaxStamina() const;
    int getStamina() const;
    int getDamage() const;
    int getInfection() const;
    void setHealth(int newHealth);
    void setStamina(int newStamina);
    void printZombieInfo();
    void printZombieStatus();
    int getRandomAttackDamage();
    int getRandomStaminaCost();
    virtual void attack(Player &player);
};

class StrongZombie : public Zombie {
public:
    StrongZombie(std::string _name, int _level);
    void setAbility(int level);
    void attack(Player &player) override;
    void takeDamage(Player &player);
};

int chooseZombieLevel(Player player);


#endif // ZOMBIE_H
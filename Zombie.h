#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <string>
#include <iostream>
#include "Enemy.h"
#include "Player.h"
#include "Bar.h"



class Zombie:public Enemy {
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
    std::string getName() override;
    std::string getDescription() const;
    std::string getAbility() const;
    int getLevel() const;
    int getMaxHealth() override;
    int getHealth() override;
    int getMaxStamina() override;
    int getStamina() override;
    int getDamage() const;
    int getInfection() const;
    void setHealth(int newHealth) override;
    void setStamina(int newStamina) override;
    void setMaxHealth(int newMaxHealth) override;
    void setMaxStamina(int newMaxStamina) override;
    void printEnemyInfo() override;
    void printEnemyStatus() override;
    int getRandomAttackDamage();
    int getRandomStaminaCost();
    void attack(Player &player) override;
    void takeDamage(Player &player) override;
};

class StrongZombie : public Zombie {
public:
    StrongZombie(std::string _name, int _level);

    std::string getName() override;
    int getMaxHealth() override;
    int getHealth() override;
    int getMaxStamina() override;
    int getStamina() override;
    void setHealth(int newHealth) override;
    void setStamina(int newStamina) override;
    void setMaxHealth(int newMaxHealth) override;
    void setMaxStamina(int newMaxStamina) override;
    void printEnemyInfo() override;
    void printEnemyStatus() override;
    void setAbility(int level);
    void attack(Player &player) override;
    void takeDamage(Player &player) override;
};

int chooseZombieLevel(Player player);


#endif // ZOMBIE_H
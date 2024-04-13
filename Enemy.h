#ifndef ENEMY_H
#define ENEMY_H
#include <string>
#include <iostream>
#include "Player.h"
#include "Bar.h"


class Enemy {
protected:
    std::string name;
    int health;
    int stamina;
    int maxStamina;
    int maxHealth;
public:
    virtual void attack(Player &player) = 0;
    virtual void takeDamage(Player &player) = 0;
    virtual void printEnemyInfo() = 0;
    virtual void printEnemyStatus() = 0;
    virtual void setMaxHealth(int newMaxHealth) = 0;
    virtual void setMaxStamina(int newMaxStamina) = 0;
    virtual void setHealth(int newHealth) = 0;
    virtual void setStamina(int newStamina) = 0;
    virtual std::string getName() = 0;
    virtual int getMaxHealth() = 0;
    virtual int getMaxStamina() = 0;
    virtual int getHealth() = 0;
    virtual int getStamina() = 0; 
};

#endif // ENEMY_H
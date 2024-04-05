#ifndef PLAYER_H
#define PLAYER_H


#include <iostream>
#include <string>
#include "Item.h"
#include "Shop.h"
#include "BackPack.h"
#include "Bar.h"
class StrongZombie;
struct Stats {
    int levelNumber;
    int strength;
    int intelligence;
    int agility;
    int firearmSkill;
    int meleeSkill;
};

class Player {
protected:
    std::string name;
    std::string gender;
    int age;
    int maxHealth;
    int maxStamina;
    int health;
    int stamina;
    int staminaCost;
    int attackDamage;
    int defense;
    int money;
    int skillPoints;
    int killCount;
    bool infected;
    Stats playerStats;
    

public:
    Backpack backpack;
    Player(std::string newName, std::string newGender, int newAge);
    // Declare member functions here
    // Getters and setters
    void setMaxHealth(int newMaxHealth);
    void setMaxStamina(int newMaxStamina);
    void setHealth(int newHealth);
    void setStamina(int newStamina);
    void setStaminaCost(int newStaminaCost);
    void setAttack(int newAttackDamage);
    void setDefense(int newDefense);
    void setMoney(int newMoney);
    std::string getName();
    std::string getGender();
    int getAge();
    int getMaxHealth();
    int getMaxStamina();
    int getHealth();
    int getStamina();
    int getStaminaCost();
    int getAttackDamage();
    int getDefense();
    int getMoney();
    int getSkillPoints();
    int getKillCount();
    int getLevel();
    int getRandomAttackDamage();
    int getRandomStaminaCost();
    void setInfected(bool infectionStatus);
    void printPlayerInfo();
    void printPlayerStatus();
    void addLevel();
    void addKill();
    void addSkillPointsRandom();
    void addRandomMoney();
    bool addStats(int number);


    void visitStore(Shop& shop);
    void visitBackpackInventory(StrongZombie& zombie);
    void addPermanentItemToBackpack(Item* item);
    void addConsumableItemToBackpack(Item* item);
    void addThrowableItemToBackpack(Item* item);
};


#endif // PLAYER_H
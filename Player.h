#ifndef PLAYER_H
#define PLAYER_H


#include <iostream>
#include <string>
#include "Item.h"
#include <fstream>
#include "Shop.h"
#include "BackPack.h"
#include "Enemy.h"
#include "Bar.h"

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
    int dayCount;
    enum playertype {jobless,warrior,knight,athletic,farmer} ;
    playertype class1;
    
public:
    Backpack backpack;
    Player(std::string newName, std::string newGender, int newAge);
    // Declare member functions here
    // Getters and setters
    void setplayerclass(playertype _class);
    playertype getplayerclass();
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
    int getDay();
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
    void nextDay();
    
    void savePlayer(const std::string& filename);
    void loadPlayer(const std::string& filename);
    
    void visitStore(Shop& shop);
    void visitBackpackInventory(Enemy* enemy, bool &isEnemysTurn);
    void addPermanentItemToBackpack(Item* item);
    void addConsumableItemToBackpack(Item* item);
    void addThrowableItemToBackpack(Item* item);
};


#endif // PLAYER_H
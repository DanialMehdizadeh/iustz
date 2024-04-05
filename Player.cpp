#include "Player.h"

Player::Player(std::string newName, std::string newGender, int newAge) :
    name(newName), gender(newGender), age(newAge),
    maxHealth(100), maxStamina(40), health(100), stamina(40),
    staminaCost(5), attackDamage(10), defense(0), money(100),
    skillPoints(0), killCount(0), infected(false) {
        playerStats.levelNumber = 1;
        playerStats.strength = 0;
        playerStats.intelligence = 0;
        playerStats.agility = 0;
        playerStats.firearmSkill = 0;
        playerStats.meleeSkill = 0;
}
void Player::setMaxHealth(int newMaxHealth) {
    maxHealth = newMaxHealth; 
}

void Player::setMaxStamina(int newMaxStamina) {
    maxStamina = newMaxStamina; 
}

void Player::setHealth(int newHealth) {
    if (newHealth <= 0) {
        health = 0;
    }
    else if (newHealth >= maxHealth) {
        health = maxHealth;
    }
    else {
        health = newHealth; 
    }
}

void Player::setStamina(int newStamina) {
    if (newStamina <= 0) {
        stamina = 0;
    }
    else if (newStamina >= maxStamina) {
        stamina = maxStamina;
    }
    else {
        stamina = newStamina; 
    }
}

void Player::setStaminaCost(int newStaminaCost) {
    staminaCost = newStaminaCost; 
}

void Player::setAttack(int newAttackDamage) {
    attackDamage = newAttackDamage;
}

void Player::setDefense(int newDefense) {
    defense = newDefense;
}

void Player::setMoney(int newMoney) {
    money = newMoney;
}

std::string Player::getName() {
    return name;
}

std::string Player::getGender() {
    return gender;
}

int Player::getAge() {
    return age;
}

int Player::getMaxHealth() {
    return maxHealth;
}

int Player::getMaxStamina() {
    return maxStamina;
}

int Player::getHealth() {
    return health;
}

int Player::getStamina() {
    return stamina;
}

int Player::getStaminaCost() {
    return staminaCost;
}

int Player::getAttackDamage() {
    return attackDamage;
}

int Player::getDefense() {
    return defense;
}

int Player::getMoney() {
    return money;
}

int Player::getSkillPoints() {
    return skillPoints;
}

int Player::getKillCount() {
    return killCount;
}

int Player::getLevel() {
    return playerStats.levelNumber;
}

int Player::getRandomAttackDamage() {
    int maxDamage = attackDamage + playerStats.strength;
    int randomDamage = rand() % 6 + (maxDamage - 5);
    return randomDamage;
}

int Player::getRandomStaminaCost() {
    int randomStaminaCost = rand() % 6 + staminaCost;
    return randomStaminaCost;
}

void Player::setInfected(bool infectionStatus) {
    infected = infectionStatus;
}

void Player::printPlayerInfo() {
    SetConsoleColor(14);
    std::cout << std::endl << "Your character:" << std::endl << " -Name: " << name << std::endl
    << " -Gender: " << gender << std::endl
    << " -Age: " << age << std::endl << std::endl
    << " -Level: " << playerStats.levelNumber << std::endl
    << " -Strength: " << playerStats.strength << std::endl
    << " -Intelligence: " << playerStats.intelligence <<std::endl
    << " -Agility: " << playerStats.agility << std::endl
    << " -Firearm Skill: " << playerStats.firearmSkill << std::endl
    << " -Melee Skill: " << playerStats.meleeSkill << std::endl;
    SetConsoleColor(7);
}

void Player::printPlayerStatus() {
    std::cout << std::endl << name << ": Health";
    playerHealthBar(health, maxHealth, 10);
    std::cout << " Stamina";
    staminaBar(stamina, maxStamina, 10);
    std::cout << std::endl;
}

void Player::addLevel() {
    if (playerStats.levelNumber < 5) {
        playerStats.levelNumber += 1;
        std::cout << "Congratulations, since you hit a milestone of " << killCount << " kills you are now level " << playerStats.levelNumber << "." << std::endl;
    }
}

void Player::addKill() {
    killCount++;
}

void Player::addSkillPointsRandom() {
    int randomNumber = rand() % 2;
    if (randomNumber == 0) {
        skillPoints++;
        std::cout << "You gained 1 skill point" << std::endl;
    }
}

void Player::addRandomMoney() {
    int randomMoney = rand() % 100 + 1;
    money += randomMoney;
    std::cout << "You earned " << randomMoney << "$" << std::endl;
} 

bool Player::addStats(int number) {
    if (skillPoints >= 5) {
        if (number == 1) {
            playerStats.strength += 1;
        }
        else if (number == 2) {
            playerStats.intelligence += 1;
        }
        else if (number == 3) {
            playerStats.agility += 1;
        }
        else if (number == 4) {
            playerStats.firearmSkill += 1;
        }
        else if (number == 5) {
            playerStats.meleeSkill += 1;
        }
        skillPoints -= 5;
        return true;
    }
    else if (number != 6){
        std::cout << std::endl << "Sorry, you don't have enough skill points to upgrade" << std::endl;
        return false;
    }
    return false;
}

void Player::visitStore(Shop& shop) {
    shop.startShopping(*this);
}

void Player::visitBackpackInventory(StrongZombie& zombie) {
    backpack.showInventoryMenu(*this, zombie);
}

void Player::addPermanentItemToBackpack(Item* item) {
    backpack.addPermanentItem(item);
}

void Player::addConsumableItemToBackpack(Item* item) {
    backpack.addConsumableItem(item);
}

void Player::addThrowableItemToBackpack(Item* item) {
    backpack.addThrowableItem(item);
}

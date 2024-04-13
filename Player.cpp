#include "Player.h"

Player::Player(std::string newName, std::string newGender, int newAge) :
    name(newName), gender(newGender), age(newAge),
    maxHealth(100), maxStamina(40), health(100), stamina(40),
    staminaCost(5), attackDamage(10), defense(0), money(100),
    skillPoints(0), killCount(0), infected(false), dayCount(1) {
        playerStats.levelNumber = 1;
        playerStats.strength = 0;
        playerStats.intelligence = 0;
        playerStats.agility = 0;
        playerStats.firearmSkill = 0;
        playerStats.meleeSkill = 0;
        class1 = jobless;
}

Player::playertype Player::getplayerclass() {
    return class1 ;
}
void Player::setplayerclass(playertype _class) {
    class1 == _class ;
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

int Player::getDay() {
    return dayCount;
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
    std::cout << "\t\t\t\t" << "+-----------------------------------+" << std::endl;
    std::cout << "\t\t\t\t" << "|           " << name << "                  |" << std::endl;
    std::cout << "\t\t\t\t" << "+-----------------------------------+" << std::endl;
    std::cout << "\t\t\t\t" << "| Gender:       " << gender << std::endl;
    std::cout << "\t\t\t\t" << "| Age:          " << age << std::endl;
    std::cout << "\t\t\t\t" << "|-----------------------------------|" << std::endl;
    std::cout << "\t\t\t\t" << "|              Skills                " << std::endl;
    std::cout << "\t\t\t\t" << "| - Level:        " << playerStats.levelNumber << std::endl;
    std::cout << "\t\t\t\t" << "| - Strength:     " << playerStats.strength << std::endl;
    std::cout << "\t\t\t\t" << "| - Intelligence: " << playerStats.intelligence << std::endl;
    std::cout << "\t\t\t\t" << "| - Agility:      " << playerStats.agility << std::endl;
    std::cout << "\t\t\t\t" << "| - Firearm Skill:" << playerStats.firearmSkill << std::endl;
    std::cout << "\t\t\t\t" << "| - Melee Skill:  " << playerStats.meleeSkill << std::endl;
    std::cout << "\t\t\t\t" << "+-----------------------------------+" << std::endl;
    SetConsoleColor(7);
}

void Player::printPlayerStatus() {
    std::cout << std::endl << "\t\t\t\t"  << name << ": Health";
    playerHealthBar(health, maxHealth, 10);
    std::cout << " Stamina";
    staminaBar(stamina, maxStamina, 10);
    std::cout << std::endl;
}

void Player::addLevel() {
    if (playerStats.levelNumber < 5) {
        playerStats.levelNumber += 1;
        std::cout << "\t\t\t\t"  << "Congratulations, since you hit a milestone of " << killCount << " kills you are now level " << playerStats.levelNumber << "." << std::endl;
    }
}

void Player::addKill() {
    killCount++;
}

void Player::addSkillPointsRandom() {
    int randomNumber = rand() % 2;
    if (randomNumber == 0) {
        skillPoints++;
        std::cout << "\t\t\t\t"  << "You gained 1 skill point" << std::endl;
    }
}

void Player::addRandomMoney() {
    int randomMoney = rand() % 100 + 1;
    money += randomMoney;
    std::cout << "\t\t\t\t"  << "You earned " << randomMoney << "$" << std::endl;
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
        std::cout << std::endl << "\t\t\t\t"  << "Sorry, you don't have enough skill points to upgrade" << std::endl;
        return false;
    }
    return false;
}

void Player::nextDay() {
    dayCount++;
}

void Player::visitStore(Shop& shop) {
    shop.startShopping(*this);
}

void Player::visitBackpackInventory(Enemy* enemy, bool &isEnemysTurn) {
    backpack.showInventoryMenu(*this, enemy, isEnemysTurn);
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


void Player::savePlayer(const std::string& filename) {
        std::ofstream file(filename);
        if (file.is_open()) {
            file << name << "\n";
            file << gender << "\n";
            file << age << "\n";
            file << maxHealth << "\n";
            file << maxStamina << "\n";
            file << health << "\n";
            file << stamina << "\n";
            file << staminaCost << "\n";
            file << attackDamage << "\n";
            file << defense << "\n";
            file << money << "\n";
            file << skillPoints << "\n";
            file << killCount << "\n";
            file << infected << "\n";
            file << dayCount << "\n";
            file << playerStats.levelNumber << "\n";
            file << playerStats.strength << "\n";
            file << playerStats.intelligence << "\n";
            file << playerStats.agility << "\n";
            file << playerStats.firearmSkill << "\n";
            file << playerStats.meleeSkill << "\n";
            file << class1 << "\n";
            backpack.saveBackPack(file);
            file.close();
        }
}

void Player::loadPlayer(const std::string& filename) {
        std::ifstream file(filename);
        if (file.is_open()) {
            file >> name;
            file >> gender;
            file >> age;
            file >> maxHealth;
            file >> maxStamina;
            file >> health;
            file >> stamina;
            file >> staminaCost;
            file >> attackDamage;
            file >> defense;
            file >> money;
            file >> skillPoints;
            file >> killCount;
            file >> infected;
            file >> dayCount; 
            file >> playerStats.levelNumber;
            file >> playerStats.strength;
            file >> playerStats.intelligence;
            file >> playerStats.agility;
            file >> playerStats.firearmSkill;
            file >> playerStats.meleeSkill;
            int classVal;
            file >> classVal;
            class1 = static_cast<playertype>(classVal);
            backpack.loadBackPack(filename);
            file.close();
        }
}

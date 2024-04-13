#include "Zombie.h"



// Constructor for Zombie class
Zombie::Zombie(std::string _name) : name(_name), description(""), ability("None"), level(1), maxHealth(10), health(10), maxStamina(20), staminaCost(2), stamina(20), attackDamage(10), infection(1) {}

// Setter method for health ensuring it's within bounds
void Zombie::setHealth(int newHealth) {
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

void Zombie::setMaxHealth(int newMaxHealth) {
    maxHealth = newMaxHealth; 
}
void Zombie::setMaxStamina(int newMaxStamina) {
    maxStamina = newMaxStamina; 
}

// Setter method for stamina ensuring it's within bounds
void Zombie::setStamina(int newStamina) {
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

// Method to print zombie's information
void Zombie::printEnemyInfo() {
     // Set color for the card header
    SetConsoleColor(14);
    // Print card header
    std::cout << "\t\t\t\t" << "+-----------------------+" << std::endl;
    std::cout << "\t\t\t\t" << "|        Zombie         |" << std::endl;
    std::cout << "\t\t\t\t" << "+-----------------------+" << std::endl;
    // Print card content
    std::cout << "\t\t\t\t" << "|  -Name:    " << name << std::endl;
    // Print card footer
    std::cout << "\t\t\t\t" << "+-----------------------+" << std::endl;
    // Reset color for the card content
    SetConsoleColor(7);
}

// Method to print zombie's status
void Zombie::printEnemyStatus() {
    std::cout << "\t\t\t\t"  << name << ": Health";
    zombieHealthBar(health, maxHealth, 10);
    std::cout << " Stamina";
    staminaBar(stamina, maxStamina, 10);
    std::cout << std::endl;
}


    std::string Zombie::getName() { return name; }
    std::string StrongZombie::getName() { return name; }
    std::string Zombie::getDescription() const { return description; }
    std::string Zombie::getAbility() const { return ability; }
    int Zombie::getLevel() const { return level; }
    int Zombie::getMaxHealth()  { return maxHealth; } 
    int Zombie::getHealth()  { return health; }
    int Zombie::getMaxStamina()  { return maxStamina; }
    int Zombie::getStamina()  { return stamina; }
    int Zombie::getDamage() const { return attackDamage; }
    int Zombie::getInfection() const { return infection; }


// Method to generate random attack damage for the zombie
int Zombie::getRandomAttackDamage() {
    int maxDamage = attackDamage;
    int randomDamage = rand() % 6 + (maxDamage - 5);
    return randomDamage;
}

// Method to generate random stamina cost for the zombie
int Zombie::getRandomStaminaCost() {
    int randomStaminaCost = rand() % 3 + staminaCost;
    return randomStaminaCost;
}


// Method for the zombie to attack the player
void Zombie::attack(Player &player) {
    int actual = getRandomAttackDamage() - player.getDefense();
    if (actual > 0) {
        player.setHealth(player.getHealth() - actual);
    }
    int random = rand() % 100 + 1;
    if (random <= infection) {
        player.setInfected(true);
    }
}

// Constructor for StrongZombie class
StrongZombie::StrongZombie(std::string _name, int _level) : Zombie(_name) {
    level = _level;
    setAbility(level);
}

// Setter method for the ability of StrongZombie
void StrongZombie::setAbility(int level) {
    if (level == 1) {
        ability = "None";
    }
    else if (level == 2) {
        ability = "Exploder";
    }
    else if (level == 3) {
       ability = "Hunter";
    }
    else if (level == 4) {
       ability = "Spitter";
    }
    else if (level == 5) {
       ability = "Brute";
    }
}

// Method for StrongZombie to attack the player
void StrongZombie::attack(Player &player) {
    int actual = 0;
    int randomStaminaCost = getRandomStaminaCost();
    if (ability == "None") {
        actual = getRandomAttackDamage() - player.getDefense();
    }
    else if (ability == "Exploder") {
        actual = getRandomAttackDamage() - player.getDefense();
        setHealth(0);
    }
    else if (ability == "Hunter") {
        actual = getRandomAttackDamage() - player.getDefense();
        player.setStamina(player.getStamina()/2);
    }
    else if (ability == "Spitter") {
        actual = getRandomAttackDamage() - player.getDefense();
        player.setDefense(player.getDefense() / 2);
    }
    else if (ability == "Brute") {
        actual = getRandomAttackDamage() * 2 - player.getDefense();
    }

    if (actual > 0) {
        std::cout << std::endl << "\t\t\t\t"  << name << " tries to attack you." << " (Stamina Cost: " << randomStaminaCost << "(" << stamina << "), Damage: " << actual << ")" << std::endl;
        if (stamina >= randomStaminaCost) {
            player.setHealth(player.getHealth() - actual);
            stamina -= randomStaminaCost;
            std::cout << "\t\t\t\t"  << "Attack successful!" << std::endl;
        }
        else {
            std::cout << "\t\t\t\t"  << name << "didn't have enough energy to attack you." << std::endl;
        }
    }

    int random = rand() % 100 + 1;
    if (random <= infection) {
        player.setInfected(true);
    }
}

void StrongZombie::takeDamage(Player &player) {
    int randomStaminaCost = player.getRandomStaminaCost();
    int randomAttackDamage = player.getRandomAttackDamage();
    std::cout << std::endl << "\t\t\t\t"  << "You try to attack " << name << ". (Stamina Cost: " << randomStaminaCost << "(" << player.getStamina() << "), Damage: " << randomAttackDamage << ")" << std::endl;
    if (player.getStamina() >= randomStaminaCost) {
        setHealth(health - randomAttackDamage);
        player.setStamina(player.getStamina() - randomStaminaCost);
        std::cout << "\t\t\t\t"  << "Attack successful!" << std::endl;
    }
    else {
        std::cout << "\t\t\t\t"  << "Not enough stamina to attack!!" << std::endl;
    }
}

// Method for StrongZombie to take damage from the player
void Zombie::takeDamage(Player &player) {
    int randomStaminaCost = player.getRandomStaminaCost();
    int randomAttackDamage = player.getRandomAttackDamage();
    std::cout << std::endl << "\t\t\t\t"  << "You try to attack " << name << ". (Stamina Cost: " << randomStaminaCost << "(" << player.getStamina() << "), Damage: " << randomAttackDamage << ")" << std::endl;
    if (player.getStamina() >= randomStaminaCost) {
        setHealth(health - randomAttackDamage);
        player.setStamina(player.getStamina() - randomStaminaCost);
        std::cout << "\t\t\t\t"  << "Attack successful!" << std::endl;
    }
    else {
        std::cout << "\t\t\t\t"  << "Not enough stamina to attack!!" << std::endl;
    }
}

// Function to choose a random level for a zombie based on player's level
int chooseZombieLevel(Player player) {
    int n = player.getLevel();
    int randomNumber = rand() % n + 1;
    return randomNumber;
}


void StrongZombie::printEnemyInfo() {
    SetConsoleColor(14);
    std::cout << "\t\t\t\t" << "+-----------------------+" << std::endl;
    std::cout << "\t\t\t\t" << "|     Strong Zombie     |" << std::endl;
    std::cout << "\t\t\t\t" << "+-----------------------+" << std::endl;
    // Print card content
    std::cout << "\t\t\t\t" << "|  -Name:    " << name << std::endl;
    std::cout << "\t\t\t\t" << "|  -Ability: " << ability << std::endl;
    std::cout << "\t\t\t\t" << "|  -Level:   " << level << std::endl;
    // Print card footer
    std::cout << "\t\t\t\t" << "+-----------------------+" << std::endl;
    // Reset color for the card content
    SetConsoleColor(7);

}

// Method to print zombie's status
void StrongZombie::printEnemyStatus() {
    std::cout << "\t\t\t\t"  << name << ": Health";
    zombieHealthBar(health, maxHealth, 10);
    std::cout << " Stamina";
    staminaBar(stamina, maxStamina, 10);
    std::cout << std::endl;
}

// Setter method for health ensuring it's within bounds
void StrongZombie::setHealth(int newHealth) {
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

void StrongZombie::setMaxHealth(int newMaxHealth) {
    maxHealth = newMaxHealth; 
}
void StrongZombie::setMaxStamina(int newMaxStamina) {
    maxStamina = newMaxStamina; 
}

// Setter method for stamina ensuring it's within bounds
void StrongZombie::setStamina(int newStamina) {
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


int StrongZombie::getMaxHealth()  { return maxHealth; } 
int StrongZombie::getHealth()  { return health; }
int StrongZombie::getMaxStamina()  { return maxStamina; }
int StrongZombie::getStamina()  { return stamina; }


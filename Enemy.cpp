#include "Enemy.h"

void Enemy::attack(Player &player) {
    //empty for now
}
void Enemy::takeDamage(Player &player) {
    //empty for now
}

void Enemy::printEnemyInfo() {

}
void Enemy::printEnemyStatus() {

}

void Enemy::setMaxHealth(int newMaxHealth) {
    maxHealth = newMaxHealth; 
}
void Enemy::setMaxStamina(int newMaxStamina) {
        maxStamina = newMaxStamina; 
}

void Enemy::setHealth(int newHealth) {
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
void Enemy::setStamina(int newStamina) {
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
std::string Enemy::getName() {
    return name;
}
int Enemy::getMaxHealth() {
    return maxHealth;
}
int Enemy::getMaxStamina() {
    return maxStamina;
}
int Enemy::getHealth() {
    return health;
}
int Enemy::getStamina() {
    return stamina;
}
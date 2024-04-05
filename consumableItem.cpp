#include "consumableItem.h"
#include "Player.h"

// Implementation of Consumable class
Consumable::Consumable(std::string _name, int _price) : Item(_name, _price) {}

void Consumable::use(Player& player,StrongZombie& zombie)
{
    // Placeholder for future use
}

// Implementation of HealthBooster class
HealthBooster::HealthBooster(std::string _name, int _price, int _effectValue) : Consumable(_name, _price), effectValue(_effectValue) {}

void HealthBooster::use(Player& player,StrongZombie& zombie)
{
    std::cout << "Consumed " << getName() << " and gained " << effectValue << " health." << std::endl;
    player.setHealth(player.getHealth() + effectValue);
}

// Implementation of StaminaBooster class
StaminaBooster::StaminaBooster(std::string _name, int _price, int _effectValue) : Consumable(_name, _price), effectValue(_effectValue) {}

void StaminaBooster::use(Player& player,StrongZombie& zombie)
{
    std::cout << "Consumed " << getName() << " and gained " << effectValue << " stamina." << std::endl;
    player.setStamina(player.getStamina() + effectValue);
}

// Implementation of HealthPotion class
HealthPotion::HealthPotion(std::string _name, int _price, int _effectValue) : HealthBooster(_name, _price, _effectValue) {}

// Implementation of CannedFood class
CannedFood::CannedFood(std::string _name, int _price, int _effectValue) : HealthBooster(_name, _price, _effectValue) {}

// Implementation of EnergyDrink class
EnergyDrink::EnergyDrink(std::string _name, int _price, int _effectValue) : StaminaBooster(_name, _price, _effectValue) {}

// Implementation of ChocolateBar class
ChocolateBar::ChocolateBar(std::string _name, int _price, int _effectValue) : StaminaBooster(_name, _price, _effectValue) {}
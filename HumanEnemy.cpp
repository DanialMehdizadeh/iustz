#include "HumanEnemy.h"
#include "Player.h"

void HumanEnemy::setEnemyClass (enemyType _class) {
    class1 = _class;
}
HumanEnemy::enemyType HumanEnemy::getClass() {
    return class1;
}
void HumanEnemy::initialClass() {
    
    level = rand() % 3 ;
        if (level == 0) {
            class1 = tank;
        }
        else if (level == 1) {
            class1 = coward;
        }
        else {
            class1 = berserk;
        }
    
}


void HumanEnemy::setMaxHealth(int newMaxHealth) {
    maxHealth = newMaxHealth; 
}
void HumanEnemy::setMaxStamina(int newMaxStamina) {
        maxStamina = newMaxStamina; 
}

void HumanEnemy::setHealth(int newHealth) {
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
void HumanEnemy::setStamina(int newStamina) {
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
void HumanEnemy::setStaminaCost(int newStaminaCost) {
    staminaCost = newStaminaCost; 
}
void HumanEnemy::setAttack(int newAttackDamage) {
    attackDamage = newAttackDamage;
}
void HumanEnemy::setDefense(int newDefense) {
    defense = newDefense;
}
int HumanEnemy::getRandomAttackDamage() {
    int maxDamage = attackDamage;
    int randomDamage = rand() % 6 + (maxDamage - 5);
    return randomDamage;
}
std::string HumanEnemy::getName() {
    return name;
}
int HumanEnemy::getLevel () {
    return level;
}
int HumanEnemy::getAge() {
    return age;
}
int HumanEnemy::getMaxHealth() {
    return maxHealth;
}
int HumanEnemy::getMaxStamina() {
    return maxStamina;
}
int HumanEnemy::getHealth() {
    return health;
}
int HumanEnemy::getStamina() {
    return stamina;
}
int HumanEnemy::getStaminaCost() {
    return staminaCost;
}
int HumanEnemy::getAttackDamage() {
    return attackDamage;
}
int HumanEnemy::getDefense() {return defense;}


// Method to print zombie's information
void HumanEnemy::printEnemyInfo() {
    SetConsoleColor(14);
    std::cout << "\t\t\t\t"  << "Enemy's Information:" << std::endl << "\t\t\t\t"  << " -Name: " << name << std::endl <<  "\t\t\t\t"  << " -Age: " << age << std::endl
     << "\t\t\t\t" << " -Level: " << level << std::endl;
    SetConsoleColor(7);
}

// Method to print zombie's status
void HumanEnemy::printEnemyStatus() {
    std::cout << "\t\t\t\t"  << name << ": Health";
    playerHealthBar(health, maxHealth, 10);
    std::cout << " Stamina";
    staminaBar(stamina, maxStamina, 10);
    std::cout << std::endl;
}



HumanEnemy::HumanEnemy(std::string newName,int newAge) : name(newName) ,  age(newAge), currentState(HumanEnemy::State::BASE),maxHealth(100), maxStamina(40), health(100), stamina(40),
    staminaCost(5), attackDamage(10), defense(0) {
        initialClass() ;
        createItems();
    }
void HumanEnemy::setState(State newState) {currentState = newState;}
HumanEnemy::State HumanEnemy::getState(){ return currentState;}
        
//srand(static_cast<unsigned int>(time(nullptr))) ;
//  void cowardguy(HumanEnemy& model) {
//     if (model.class1 == 2 ) {
//         if (model.getState() == HumanEnemy::State::LOW_HP){
//             cout << "your enemy will escape kill him fast " << endl ;
//             model.setState(HumanEnemy::State::SCARED);
//         }
//     }
//  }

void HumanEnemy::takeDamage(Player &player) {    
    int randomStaminaCost = player.getRandomStaminaCost();
    int randomAttackDamage = player.getRandomAttackDamage();
    std::cout << std::endl << "You try to attack " << name << ". (Stamina Cost: " << randomStaminaCost << "(" << player.getStamina() << "), Damage: " << randomAttackDamage << ")" << std::endl;
    if (player.getStamina() >= randomStaminaCost) {
        setHealth(health - randomAttackDamage);
        player.setStamina(player.getStamina() - randomStaminaCost);
        std::cout << "Attack successful!" << std::endl;
    }
    else {
        std::cout << "Not enough stamina to attack!!" << std::endl;
    }
}

void HumanEnemy::attack(Player &player) {        
    if(getState() == HumanEnemy::State::ATTACK){
    int itemdamage ;
    if (permanentItems[0]->getName() == "Rifle" or permanentItems[0]->getName() == "Pistol" or permanentItems[0]->getName() == "Shotgun" )
    itemdamage = 25 ;
    else {
        itemdamage = 15 ;
    }
    if (class1 == 1) {
        if (getHealth() < maxHealth/2) { 
            int actual = (2*getRandomAttackDamage() + itemdamage - player.getDefense());
            if (actual > 0) {
                player.setHealth(player.getHealth() - actual);
            }
        }else {
             int actual = (getRandomAttackDamage() + itemdamage - player.getDefense());
            if (actual > 0) {
                player.setHealth(player.getHealth() - actual);
            }
        }
    }
   else { 
    int actual = getRandomAttackDamage() - player.getDefense();
    if (actual > 0) {
        player.setHealth(player.getHealth() - actual);
    }  
    }   
    }
    else if (getState() == HumanEnemy::State::THROW_ITEM){
        std::cout << "\t\t\t\t"  << "Threw " << throwableItems[0]->getName() << " at the enemy." << std::endl;
    player.setHealth(player.getHealth() - 15);
    }
}

void HumanEnemy::newState() {
    if (getHealth() < 20 && !healthboostItems.empty()) {
        setState(HumanEnemy::State::LOW_HP);
    } 
    else if (getStamina() < 20 && !staminaboostItems.empty()) {
        setState(HumanEnemy::State::LOW_STAMINA);
    }
    else {
        setState(HumanEnemy::State::BASE);
    }
    // model.cowardguy();
}




EnemyController::EnemyController(HumanEnemy &enemy) : model(enemy) {};
void EnemyController::useconsumablebyenemy(){
    if (model.getState() == HumanEnemy::State::LOW_HP){
        std::cout << "\t\t\t\t"  << "Consumed " << model.healthboostItems[0]->getName() << " and gained " << "10" << " Health." << std::endl ;
        model.setHealth(model.getHealth() + 10) ;
    }
    else if (model.getState() == HumanEnemy::State::LOW_STAMINA){
        std::cout << "\t\t\t\t"  << "Consumed " << model.staminaboostItems[0]->getName() << " and gained " << "10" << " stamina." << std::endl ;
        model.setHealth(model.getHealth() + 10) ;
    }
         }
void EnemyController::chooseHowToAttack() {
    int choice = rand()%2;
    if (choice == 0 && !model.throwableItems.empty()) {
        model.setState(HumanEnemy::State::THROW_ITEM);
    }
    else {
        model.setState(HumanEnemy::State::ATTACK);
    }
}

    
void EnemyController::performAction(Player &player) {
    if (model.getState() == HumanEnemy::State::LOW_HP) {
        if (model.getClass() == 2) {
            if (model.getState() == HumanEnemy::State::LOW_HP) {
                std::cout << "your enemy will escape kill him fast " << std::endl;
            }
            }
       useconsumablebyenemy() ;
        model.newState();
    }
    else if (model.getState() == HumanEnemy::State::LOW_STAMINA) {
      useconsumablebyenemy() ;
        model.newState();
    }
    else if (model.getState() == HumanEnemy::State::BASE) {
        chooseHowToAttack() ;
        model.attack(player);
        model.newState();
        // if (model.getState() == HumanEnemy::State::ATTACK) {
        //     model.attack(Player& player);
        // }
        // model.newState();
        // else if (model.getState() == HumanEnemy::State::THROW_ITEM) {   
        //     model.attack(Player &player);
        //     model.newState() ;
        // }
    }  
}

// Factory برای ایجاد کاراکترهای دشمن
// class EnemyFactory {
// public:
//     static HumanEnemy createEnemy(int initialHealth, int initialAttackPower) {
//         return HumanEnemy(initialHealth, initialAttackPower);
//     }
// };

void HumanEnemy::createItems()
{
    std::vector<std::string> permanent = {"Rifle", "Pistol", "Shotgun" , "Knife" , "Katana" ,"Axe"  };
    std::vector<std::string> healthboost = {"HealthPotion", "CannedFood", "Havij_Bastani"};
    std::vector<std::string> staminaboost = {"EnergyDrink", "ChocolateBar", "Teryak"};
    std::vector<std::string> shield = {"Mini_Shield", "Big_Shield"};
    std::vector<std::string> throwable = {"Molotov", "Brick", "Grenade"};
    int rndindx_permanent = rand() % permanent.size(); 
    std::string permanent_name = permanent[rndindx_permanent]; 

        
        if (permanent_name == "Rifle") {
                permanentItems.push_back(new Rifle("Rifle", 25, +10));
            } else if (permanent_name == "Pistol") {
                permanentItems.push_back(new Pistol("Pistol", 25, +10));
            } else if (permanent_name == "Shotgun") {
                permanentItems.push_back(new Shotgun("Shotgun", 25, +10));
            } else if (permanent_name == "Knife") {
                permanentItems.push_back(new Knife("Knife", 15, +10));
            } else if (permanent_name == "Katana") {
                permanentItems.push_back(new Katana("Katana", 15, +10));
            } else if (permanent_name == "Axe") {
                permanentItems.push_back(new Axe("Axe", 15, +10));
            }
    
    int rndindx_healthboost = rand() % healthboost.size(); 
    std::string healthboost_name = healthboost[rndindx_healthboost];

    if (healthboost_name == "HealthPotion") {
                healthboostItems.push_back(new HealthPotion("HealthPotion", 10, +10));
            } else if (healthboost_name == "CannedFood") {
                healthboostItems.push_back(new CannedFood("CannedFood", 10, +10));
            }


    int rndindx_staminaboost = rand() % staminaboost.size(); 
    std::string staminaboost_name = staminaboost[rndindx_staminaboost];

    if (staminaboost_name == "EnergyDrink") {
                staminaboostItems.push_back(new EnergyDrink("EnergyDrink", 10, +10));
            } else if (staminaboost_name == "ChocolateBar") {
                staminaboostItems.push_back(new ChocolateBar("ChocolateBar", 10, +10));
            }
    
    int rndindx_shield = rand() % shield.size(); 
    std::string shield_name = shield[rndindx_shield];

   int rndindx_throwable = rand() % throwable.size(); 
    std::string throwable_name = throwable[rndindx_throwable];
   
    if (throwable_name == "Molotov") {
                throwableItems.push_back(new Molotov("Molotov", 15));
            } else if (throwable_name == "Brick") {
                throwableItems.push_back(new Brick("Brick", 15));
            } else if (throwable_name == "Grenade") {
                throwableItems.push_back(new Grenade("Grenade", 15));
            }
}
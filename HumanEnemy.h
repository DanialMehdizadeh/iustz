#ifndef HUMANENEMY_H
#define HUMANENEMY_H

#include <iostream> 
#include <string>
#include "Player.h"
#include "Enemy.h"
#include "Bar.h"

class HumanEnemy:public Enemy {
protected : 
    int age;
    std::string name;
    int level;
    int health;
    int stamina;
    int attackDamage;  
    int defense;
    int staminaCost;
    int maxStamina;
    int maxHealth;
    enum enemyType {tank,berserk,coward} ;
    enemyType class1;

    
public:
    std::vector<Item*> permanentItems;
    std::vector<Item*> healthboostItems;
    std::vector<Item*> staminaboostItems;
    std::vector<Item*> shieldItems;
    std::vector<Item*> throwableItems;
    
    void setEnemyClass (enemyType _class);
    enemyType getClass();
    void initialClass();
    void setMaxHealth(int newMaxHealth) override;
    void setMaxStamina(int newMaxStamina) override;
    void setHealth(int newHealth) override;
    void setStamina(int newStamina) override;
    void setStaminaCost(int newStaminaCost);
    void setAttack(int newAttackDamage);
    void setDefense(int newDefense);
    int getRandomAttackDamage();
    std::string getName() override;
    int getLevel ();
    int getAge();
    int getMaxHealth() override;
    int getMaxStamina() override;
    int getHealth() override;
    int getStamina() override;
    int getStaminaCost();
    int getAttackDamage();
    int getDefense();

    void printEnemyInfo() override;
    void printEnemyStatus() override;

    void createItems();

    enum class State { LOW_HP,LOW_STAMINA,THROW_ITEM,ATTACK,BASE};
    State currentState;
    HumanEnemy (std::string newName, int newAge);
    void setState(State newState);
    State getState();
        
    //srand(static_cast<unsigned int>(time(nullptr))) ;
    //  void cowardguy(HumanEnemy &enemy) {
    //     if (model.class1 == 2 ) {
    //         if (enemy.getState() == HumanEnemy::State::LOW_HP){
    //             cout << "your enemy will escape kill him fast " << endl ;
    //             enemy.setState(HumanEnemy::State::SCARED);
    //         }
    //     }
    //  }


    void takeDamage(Player &player) override;
    void attack(Player &player) override;
    void newState ();
};


// Controller
class EnemyController {
private:

    HumanEnemy model;
public:
   void useconsumablebyenemy();
   EnemyController(HumanEnemy &enemy);
   void chooseHowToAttack();
   void performAction(Player &player);
};

// 
// class EnemyFactory {
// public:
//     static HumanEnemy createEnemy(int initialHealth, int initialAttackPower) {
//         return HumanEnemy(initialHealth, initialAttackPower);
//     }
// };





#endif // HUMANENEMY_H
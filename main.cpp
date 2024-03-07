#include <iostream>
#include <string>
#include <cstdlib> 
#include <vector>

using namespace std;

void Story(string name) {
    cout << "there's a survivor named " << name <<".\n"
    << "They're thrown into a chaotic world, where they fight to hold onto their humanity.\n"
    << "In this harsh reality, " << name << " encounters both kind and cruel individuals.\n"
    << "They learn to survive in unknown places and find peace in memories and friendships.\n"
    << "Despite the dangers, " << name << " perseveres. They're determined to find redemption in a world where survival is crucial.";
//zombies
#include <iostream>
#include <string>
#include <cstdlib> 
using namespace std;
class Zombie {
  private:
    //level of the zombie
    int level;
    //name of the zombie
    string name;
    //information of the zombie
   string description;
    //health of the zombie
    int health;
    //damage of the zombie
    int damage;
    //defense of the zombie
    int defense;
    // speed of the zombie
    int speed;
    //infection chance of the zombie
    int infection;
  public:
    //constructor for the normall zombie class
    Zombie(int level, string name, string description, int health, int damage, int defense, int speed, int infection) {
      this->level = level;
      this->name = name;
      this->description = description;
      this->health = health;
      this->damage = damage;
      this->defense = defense;
      this->speed = speed;
      this->infection = infection;
    }
    //getters for the attributes of the zombie
    int getLevel() {
      return this->level;
    }
    
    string getName() {
      return this->name;
    }
    
    string getDescription() {
      return this->description;
    }
    
    int getHealth() {
      return this->health;
    }
    
    int getDamage() {
      return this->damage;
    }
    
    int getDefense() {
      return this->defense;
    }
    
    int getSpeed() {
      return this->speed;
    }
    
    int getInfection() {
      return this->infection;
    }
    // A method for the zombie to attack the player
    void attack(Player* player) {
      // zombie damage is the damage of zombie mines player defence
      int actualDamage = this->damage - player->getDefense();
      // if the actual damage is positive, reduce the player's health by that amount
      if (actualDamage > 0) {
        player->setHealth(player->getHealth() - actualDamage);
      }
      // a random number between 0 and 100
      int random = rand() % 100 + 1;
      // if the random number is less or equal the infection chance of the zombie, infect the player
      if (random <= this->infection) {
        player->setInfected(true);
      }
    }
};

// class of strong zombies
class StrongZombie : public Zombie {
  private:
    // The special ability of the strong zombie
    string ability;
  public:
    // constructor for the strong zombie class
    StrongZombie(int level, string name, string description, int health, int damage, int defense, int speed, int infection, string ability) : Zombie(level, name, description, health, damage, defense, speed, infection) {
      this->ability = ability;
    }
    //getter for the special ability of the strong zombie
    string getAbility() {
      return this->ability;
    }
    // A method for the strong zombie to use its special ability on the player
    void useAbility(//about player) {
      // if the zombie is Brute,deal double damage to the player
      if (this->ability == "Brute") {
        int actualDamage = this->damage * 2 - player->getDefense();
        if (actualDamage > 0) {
          player->setHealth(player->getHealth() - actualDamage);
        }
      }
      // if the zombie is "Spitter", deal damage to the player and reduce their defense by half
      else if (this->ability == "Spitter") {
        int actualDamage = this->damage - player->getDefense();
        if (actualDamage > 0) {
          player->setHealth(player->getHealth() - actualDamage);
        }
        player->setDefense(player->getDefense() / 2);
      }
      // If the zombie is "Exploder", deal damage to the player and itself, and die
      else if (this->ability == "Exploder") {
        int actualDamage = this->damage - player->getDefense();
        if (actualDamage > 0) {
          player->setHealth(player->getHealth() - actualDamage);
        }
        this->setHealth(0);
      }
      // If the ability is "Hunter", deal damage to the player and increase its speed by half
      else if (this->ability == "Hunter") {
        int actualDamage = this->damage - player->getDefense();
        if (actualDamage > 0) {
          player->setHealth(player->getHealth() - actualDamage);
        }
        this->setSpeed(this->getSpeed() * 1.5);
      }
    }
};
}

int main() {
    cout << "In this world torn apart by the Cordyceps fungus outbreak,\n"
    << "once-thriving cities now lay in ruins, overgrown with nature's relentless reclaiming.\n"
    << "Buildings stand as hollow shells, haunted by the echoes of lost lives and abandoned dreams.\n"
    << "The streets, once bustling with activity, now echo with the eerie silence of decay.\n"
    << "Write your character's name :\n";
    string name;
    getline(cin, name);
    Story(name);
}

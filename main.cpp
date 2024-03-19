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
class Zombie {
protected:
    string name;
    string description;
    string ability = "None";
    int level = 1;
    int health = 50;
    int stamina = 20;
    int damage;
    int infection;

public:
    // Constructor
    Zombie(string _name) {
        name = _name;
    }

    // Getters for zombie attributes
    string getName() const { return name; }
    string getDescription() const { return description; }
    string getAbility() const { return ability; }
    int getLevel() const { return level; }
    int getHealth() const { return health; }
    int getStamina() const { return stamina; }
    int getDamage() const { return damage; }
    int getInfection() const { return infection; }

    void setHealth(int newHealth) {
        health = newHealth;
    }
    
    void setStamina(int newStamina) {
        stamina = newStamina;
    }

    // Method for the zombie to attack the player
    virtual void attack(Player player) {
        // Calculate actual damage
        int actualDamage = damage - player.getDefense();
        // Apply damage to the player
        if (actualDamage > 0) {
            player.setHealth(player.getHealth() - actualDamage);
        }
        // Check for infection
        int random = rand() % 100 + 1; // Generate random number between 1 and 100
        if (random <= infection) {
            player.setInfected(true);
        }
    }

    void printZombieInfo() {
        cout << "Zombie's Information:" << endl << " -Name: " << name << endl
        << " -Ability: " << ability << endl
        << " -Level: " << level << endl;

    }
};

class StrongZombie : public Zombie {
public:
    StrongZombie(string _name, int _level) 
     : Zombie(_name)
    {
        level = _level;
    }

    void setAbility(int level) {
        if (level == 1) {
            ability = "None";
        }
        else if (level == 2) {
            ability = "Exploder";
        }
        else if(level == 3) {
           ability = "Hunter";
        }
        else if(level == 4) {
           ability = "Spitter";
        }
        else if(level == 5) {
           ability = "Brute";
        }
    }

    void attack(Player player) override {
        int actualDamage = 0;

        if (ability == "None") {
            actualDamage = damage - player.getDefense();
        }
        // If the zombie is an "Exploder", deal damage to the player and itself, and die
        else if (ability == "Exploder") {
            actualDamage = damage - player.getDefense();
            setHealth(0);
        }
        // If the zombie is a "Hunter", deal damage to the player and Increase stamina by half
        else if (ability == "Hunter") {
            actualDamage = damage - player.getDefense();
            player.setStamina(player.getStamina()/2);
        }
        // If the zombie is a "Spitter", deal damage to the player and reduce their defense by half
        else if (ability == "Spitter") {
            actualDamage = damage - player.getDefense();
            player.setDefense(player.getDefense() / 2);
        }
        // If the zombie is a "Brute", deal double damage to the player
        else if (ability == "Brute") {
            actualDamage = damage * 2 - player.getDefense();
        }

        // Apply damage to the player if it's positive
        if (actualDamage > 0) {
            player.setHealth(player.getHealth() - actualDamage);
        }

        // Check for infection
        int random = rand() % 100 + 1; // Generate random number between 1 and 100
        if (random <= infection) {
            player.setInfected(true);
        }
    }
};
int chooseZombieLevel(Player player) {
    int n = player.getLevel();
    int randomNumber = rand() % n + 1;
    return randomNumber;
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

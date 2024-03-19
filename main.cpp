#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib> 
#include <vector>
#include <limits>
#include <windows.h>
#include <ctime>

using namespace std;

void gotoxy(int x, int y)
//function to go to the first place 
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
// Function to read names from the file into a vector
vector<string> readNamesFromFile(const string& filename) {
    vector<string> names;
    ifstream file(filename);
    if (file.is_open()) {
        string name;
        while (getline(file, name)) {
            names.push_back(name);
        }
        file.close();
    } else {
        cerr << "Error: Unable to open file: " << filename << endl;
    }
    return names;
}
// Function to choose a random name from the vector
string chooseRandomName(const vector<string>& names) {
    int randomIndex = rand() % names.size();
    return names[randomIndex];
}

struct Stats {
    int levelNumber;
    int strength;              
    int intelligence;
    int agility;
    int firearmSkill;
    int coldWeaponSkill;
};

class Player {
protected: 
    string name;
    string gender; 
    int age;
    int health = 100; 
    int stamina = 50;
    int attackDamage;
    int defense = 0;
    int money = 100;
    int skillPoints = 0;
    bool infected = false;
    Stats playerStats;
public :

    Player(string newName, string newGender, int newAge) {
        age = newAge;
        gender = newGender;
        name = newName;
        playerStats.levelNumber = 1;
        playerStats.strength = 0;
        playerStats.intelligence = 0;
        playerStats.agility = 0;
        playerStats.firearmSkill = 0;
        playerStats.coldWeaponSkill = 0;
    }

    void setHealth(int newHealth) {
        health = newHealth; 
    }
    void setStamina(int newStamina) {
        stamina = newStamina; 
    }
    void setAttack (int newAttackDamage) {
        attackDamage = newAttackDamage;
    }
    void setDefense (int newDefense) {
        defense = newDefense;
    }
    void setMoney (int newMoney) {
        money = newMoney;
    }
    string getName() {return name;}

    string getGender() {return gender;}

    int getAge() {return age;}
    
    int getHealth() {return health;}

    int getStamina() {return stamina;}

    int getAttackDamage() {return attackDamage;}

    int getDefense() {return defense;}

    int getMoney() {return money;}

    int getSkillPoints() {return skillPoints;}

    int getLevel() {return playerStats.levelNumber;}

    void setInfected(bool infectionStatus) {
        infected = infectionStatus;
    }

    void printPlayeInfo() {
        cout << "Your character:" << endl << " -Name: " << name << endl
        << " -Gender: " << gender << endl
        << " -Age: " << age << endl << endl
        << " -Level: " << playerStats.levelNumber << endl
        << " -Strength: " << playerStats.strength << endl
        << " -Intelligence: " << playerStats.intelligence <<endl
        << " -Agility: " << playerStats.agility << endl
        << " -Firearm Skill: " << playerStats.firearmSkill << endl
        << " -Cold Weapon Skill: " << playerStats.coldWeaponSkill << endl;
    }

    void addLevel() {
        playerStats.levelNumber += 1;
    }
    void addStats(int number) {
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
            playerStats.coldWeaponSkill += 1;
        }
    }   
};



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

void Story(string name) {
    cout << "there's a survivor named " << name <<".\n"
    << "They're thrown into a chaotic world, where they fight to hold onto their humanity.\n"
    << "In this harsh reality, " << name << " encounters both kind and cruel individuals.\n"
    << "They learn to survive in unknown places and find peace in memories and friendships.\n"
    << "Despite the dangers, " << name << " perseveres. They're determined to find redemption in a world where survival is crucial.";
}

int main() {
    system("cls");
    gotoxy(0, 0);
    srand(static_cast<unsigned int>(time(nullptr))); // Seed for random number generation
    cout << "- Day 0: Introduction\n" 
    << "In this world torn apart by the Cordyceps fungus outbreak,\n"
    << "once-thriving cities now lay in ruins, overgrown with nature's relentless reclaiming.\n"
    << "Buildings stand as hollow shells, haunted by the echoes of lost lives and abandoned dreams.\n"
    << "The streets, once crowded with activity, now echo with the eerie silence of decay.\n"
    << "What's your name survivor?\n";
    string name;
    string gender;
    int age;
    getline(cin, name);
    Story(name);
    int choice;
    cout << "What is your gender?\n" << "[1] Male\n" << "[2] Female\n";
    cin >> choice;
    while (cin.fail() || choice < 1 || choice > 2)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid choice. Please enter a valid option (1-2): ";
        cin >> choice;
    }
    if (choice == 1) {
        gender = "Male";
    }
    else {
        gender = "Female";
    }
    cout << "How old are you " << name << "?" << endl;
    cin >> age;
    while (cin.fail() || age < 11)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Sorry, your character needs to be older than 10. enter a new age: ";
        cin >> age;
    }
    Player player1{name, gender, age};
    player1.printPlayeInfo();
    int currentDay = 1;
    vector<string> zombieNames = readNamesFromFile("lists/zombie_names.txt");
    do {
        // Generate a random number between 1 and 2
        int randomNumber = rand() % 2 + 1;
        switch(randomNumber) {
            case 1:
            {
                string zombieName = chooseRandomName(zombieNames);
                int zombieLevel = chooseZombieLevel(player1);
                StrongZombie zombie{zombieName,zombieLevel};
                zombie.printZombieInfo();
                int n;
                cin >> n;
                break;
            }
            case 2:
            {
                cout << "Welcome to shop" << endl;
                //shop
                int n;
                cin >> n;
            }
        }
    } while (1);

    return 0;
}

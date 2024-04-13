#include <iostream>
#include <cstdlib>
#include <ctime>

class Animal {
protected:
    std::string name;
    bool pet;
    int fed;
    bool feed;
    double chance;

public:
    Animal(std::string name) : name(name), pet(false), fed(0), feed(false) {}

    void feedAnimal() {
        if (!pet) {
            std::cout << name << " is not a pet and cannot be fed!" << std::endl;
            return;
        }

        if (feed) {
            std::cout << name << " is already fed!" << std::endl;
            return;
        }

        fed++;
        std::cout << "Fed " << name << "! Total fed count: " << fed << std::endl;

        if (fed >= rand() % 3 + 1) {
            feed = true;
            std::cout << name << " is now full!" << std::endl;
        }
    }

    void makePet(double chance) {
        if (!pet) {
            double randNum = ((double) rand() / RAND_MAX);
            if (randNum <= chance) {
                pet = true;
                std::cout << name << " is now your pet!" << std::endl;
            } else {
                std::cout << name << " did not become your pet." << std::endl;
            }
        } else {
            std::cout << name << " is already your pet!" << std::endl;
        }
    }

    void Animal_Attack() {
        if (pet) {
            std::cout << name << " is attacking!" << std::endl;
        } else {
            std::cout << name << " is not your pet and cannot attack!" << std::endl;
        }
    }

    void Pet_Control (Animal& animal)
    {
        
        int choice;
        do {
            std::cout << "You entered the store." << std::endl;
            std::cout << "[1]. Pet The Animal" << std::endl;
            std::cout << "[2]. Feed The Animal" << std::endl;
            std::cout << "[3]. The Animal Attacks" << std::endl;
            std::cout << "[0]. Exit" << std::endl;
            std::cout << "Enter your choice: ";
            std::cin >> choice;
            switch (choice)
            {
                case 1:
                    makePet(0.5);
                    break;
                case 2:
                    feedAnimal();
                    break;
                case 3:
                    Animal_Attack();
                    break;
                case 0:
                    std::cout << "Exiting the Pets Control." << std::endl;
                    break;
                default:
                    std::cout << "Invalid choice. Please try again." << std::endl;
            }
        } while (choice != 0);
    }
};

class MasterShifu : public Animal {
public:
    MasterShifu(std::string name) : Animal(name) {}

};

class Dog : public Animal {
public:
    Dog(std::string name) : Animal(name) {}

};

class Skooby_Doo : public Animal {
public:
    Skooby_Doo(std::string name) : Animal(name) {}

};

class Shreks_Donkey : public Animal {
public:
    Shreks_Donkey(std::string name) : Animal(name) {}

};

class Professor_Suske : public Animal {
public:
    Professor_Suske(std::string name) : Animal(name) {}

};

int main() {
    srand(time(nullptr));

    MasterShifu shifu("Master Shifu");
    Dog dog("Dog");
    Skooby_Doo Skooby_Doo("Cave Owner's Dog");
    Shreks_Donkey Shreks_Donkey("Shreks_Donkey");
    Professor_Suske Professor_Suske("Professor_Suske");

    shifu.feedAnimal();
    shifu.makePet(0.5);
    shifu.Animal_Attack();

    dog.feedAnimal();
    dog.makePet(0.5);
    dog.Animal_Attack();

    Skooby_Doo.feedAnimal();
    Skooby_Doo.makePet(0.5);
    Skooby_Doo.Animal_Attack();

    Shreks_Donkey.feedAnimal();
    Shreks_Donkey.makePet(0.5);
    Shreks_Donkey.Animal_Attack();

    Professor_Suske.feedAnimal();
    Professor_Suske.makePet(0.5);
    Professor_Suske.Animal_Attack();

    return 0;
}

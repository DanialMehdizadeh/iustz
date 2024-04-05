#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <limits>
#include <ctime>
#include <conio.h>
#include "Utilities.h"
#include "Bar.h"
#include "Player.h"
#include "Zombie.h"
#include "Item.h"
#include "consumableItem.h"
#include "permanentItem.h"
#include "throwableItem.h"
#include "BackPack.h"
#include "Shop.h"
#include <windows.h>



void Story(std::string name) {
    std::cout << std::endl << "there's a survivor named " << name <<".\n"
    << "They're thrown into a chaotic world, where they fight to hold onto their humanity.\n"
    << "In this harsh reality, " << name << " encounters both kind and cruel individuals.\n"
    << "They learn to survive in unknown places and find peace in memories and friendships.\n"
    << "Despite the dangers, " << name << " perseveres. They're determined to find redemption in a world where survival is crucial.";
}

void Battle(Player &player, StrongZombie zombie) {
    while(true) {
        bool isZombiesTurn = true;
        player.printPlayerStatus();
        zombie.printZombieStatus();
        std::cout << std::endl << "What do you want to do? (Attacks or Throwables will end your turn.)" << std::endl
        << "[1]. Attack |" << " [2]. Inventory |" << " [3]. Skill Tree |" << " [4]. End Turn" << std::endl ;
        int choice;
        std::cin >> choice;
        while (std::cin.fail() || choice > 4 || choice < 1)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Sorry, choose between 1 and 4: ";
            std::cin >> choice;
        }
        switch (choice) {
            case 1: {
                zombie.takeDamage(player);
                Sleep(1000);
                break;
            }
            case 2: {
                player.visitBackpackInventory(zombie);
                break;
            }
            case 3: {
                player.printPlayerInfo();
                std::cout << std::endl << "You have " << player.getSkillPoints() << " skill points " << "Which stat do you want to upgrade? (each upgrade costs 5 skill points)\n";
                std::cout << "[1]. Strength |" << " [2]. Intelligence |" << " [3]. Agility |" << " [4]. Firearm Skill |" << " [5]. Melee Skill |" << " [6]. Back" << std::endl;
                int statChoice;
                std::cin >> statChoice;
                while (std::cin.fail() || statChoice > 6 || statChoice < 1)
                {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Sorry, choose between 1 and 6: ";
                    std::cin >> statChoice;
                }
                isZombiesTurn = player.addStats(statChoice);
                break;
            }
            case 4: {
                break;
            }
            defualt : {
                break;
            }
        }
        if (zombie.getHealth() == 0) {
            std::cout << std::endl << "You killed " << zombie.getName() << "." << std::endl;
            player.addKill();
            player.addSkillPointsRandom();
            player.addRandomMoney();
            player.setHealth(player.getMaxHealth());
            player.setStamina(player.getMaxStamina());
            if ((player.getKillCount() != 0) && (player.getKillCount() % 10 == 0)){
                player.addLevel();
            }
            return;
        }
        else if(isZombiesTurn) {
            zombie.setStamina(zombie.getStamina() + 1);
            std::cout << std::endl << zombie.getName() << " gained 1 stamina." << std::endl;
            zombie.attack(player);
            if (player.getHealth() == 0)
            {
                std::cout << std::endl << "You got killed by " << zombie.getName() << "." << std::endl;
                return;
            }
            player.setStamina(player.getStamina()+2);
            std::cout << std::endl << "You gained 2 stamina." << std::endl;
        }

    }
}

int main() {
    
    SetConsoleOutputCP(CP_UTF8);
    
    srand(static_cast<unsigned int>(time(nullptr))); // Seed for random number generation
    std::cout << "\n\t\t\t\t";
    std::cout << "\n\n\t\t\t\t" << "███████╗██╗  ██╗███████╗    ██╗      █████╗ ███████╗████████╗     ██████╗ ███╗   ██╗███████╗███████╗";
    std::cout << "\n\t\t\t\t" << "╚══██╔══╝██║  ██║██╔════╝    ██║     ██╔══██╗██╔════╝╚══██╔══╝    ██╔═══██╗████╗  ██║██╔════╝██╔════╝";
    std::cout << "\n\t\t\t\t" << "   ██║   ███████║█████╗      ██║     ███████║███████╗   ██║       ██║   ██║██╔██╗ ██║█████╗  ███████╗";
    std::cout << "\n\t\t\t\t" << "   ██║   ██╔══██║██╔══╝      ██║     ██╔══██║╚════██║   ██║       ██║   ██║██║╚██╗██║██╔══╝  ╚════██║";
    std::cout << "\n\t\t\t\t" << "   ██║   ██║  ██║███████╗    ███████╗██║  ██║███████║   ██║       ╚██████╔╝██║ ╚████║███████╗███████║";
    std::cout << "\n\t\t\t\t" << "   ╚═╝   ╚═╝  ╚═╝╚══════╝    ╚══════╝╚═╝  ╚═╝╚══════╝   ╚═╝        ╚═════╝ ╚═╝  ╚═══╝╚══════╝╚══════╝\n";
    std::cout << "- Day 0: Introduction\n" 
    << "In this world torn apart by the Cordyceps fungus outbreak,\n"
    << "once-thriving cities now lay in ruins, overgrown with nature's relentless reclaiming.\n"
    << "Buildings stand as hollow shells, haunted by the echoes of lost lives and abandoned dreams.\n"
    << "The streets, once crowded with activity, now echo with the eerie silence of decay.\n"
    << "What's your name survivor?\n";
    std::string name;
    std::string gender;
    int age;
    std::getline(std::cin, name);
    Story(name);
    int choice;
    std::cout << std::endl << "What is your gender?\n" << "[1] Male\n" << "[2] Female\n";
    std::cin >> choice;
    while (std::cin.fail() || choice < 1 || choice > 2)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid choice. Please enter a valid option (1-2): ";
        std::cin >> choice;
    }
    if (choice == 1) {
        gender = "Male";
    }
    else {
        gender = "Female";
    }
    std::cout << std::endl << "How old are you " << name << "?" << std::endl;
    std::cin >> age;
    while (std::cin.fail() || age < 11 || age > 90)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Sorry, your character needs to be older than 10 and younger than 90. enter a new age: ";
        std::cin >> age;
    }
    Player player1{name, gender, age};
    player1.printPlayerInfo();
    int currentDay = 1;
    std::vector<std::string> zombieNames = readFromFile("lists/zombie_names.txt");
    std::vector<std::string> dialogues = readFromFile("lists/dialogues.txt");
    do {
        // Generate a random number between 1 and 2
        int randomNumber = rand() % 2 + 1;
        switch(randomNumber) {
            case 1:
            {
                std::string dialogue = chooseRandomLine(dialogues);
                std::cout << std::endl << "- Day " << currentDay << ": Fight" << std::endl << player1.getName() << ": " << dialogue << std::endl << std::endl;
                std::string zombieName = chooseRandomLine(zombieNames);
                int zombieLevel = chooseZombieLevel(player1);
                StrongZombie zombie{zombieName,zombieLevel};
                zombie.printZombieInfo();
                Battle(player1, zombie);
                break;
            }
            case 2:
            {
                std::cout << std::endl << "- Day " << currentDay << ": Shop" << std::endl << "You enter the shop." << std::endl;
                //shop
                Shop shop;
                player1.visitStore(shop);
                break;
            }
        }
        currentDay++;
    } while (1);

    return 0;
}

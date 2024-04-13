#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <limits>
#include <ctime>
#include <dirent.h>
#include <conio.h>
#include "Utilities.h"
#include "Bar.h"
#include "Player.h"
#include "Zombie.h"
#include "HumanEnemy.h"
#include "Item.h"
#include "consumableItem.h"
#include "permanentItem.h"
#include "throwableItem.h"
#include "BackPack.h"
#include "Shop.h"
#include <windows.h>
#include <mmsystem.h>

#pragma comment(lib, "winmm.lib")


void Story(std::string name) {
    std::cout << std::endl << "\t\t\t\t" <<  "there's a survivor named " << name <<".\n"
     << "\t\t\t\t" << "They're thrown into a chaotic world, where they fight to hold onto their humanity.\n"
     << "\t\t\t\t" << "In this harsh reality, " << name << " encounters both kind and cruel individuals.\n"
     << "\t\t\t\t" << "They learn to survive in unknown places and find peace in memories and friendships.\n"
     << "\t\t\t\t" << "Despite the dangers, " << name << " perseveres. They're determined to find redemption in a world where survival is crucial.";
}
void Battle(Player &player, Enemy* enemy) {
    while(true) {
        bool isEnemysTurn = false;
        player.printPlayerStatus();
        enemy->printEnemyStatus();
        std::cout << std::endl << "\t\t\t\t"  << "What do you want to do? (Attacks or Throwables will end your turn.)" << std::endl
         << "\t\t\t\t" << "[1]. Attack |" << " [2]. Inventory |" << " [3]. Skill Tree |" << " [4]. End Turn" << std::endl << "\t\t\t\t"  ;
        int choice = _getch() - '0';
        while (choice < 1 || choice > 4) {
            choice = _getch() - '0';
        }
        switch (choice) {
            case 1: {
                enemy->takeDamage(player);
                isEnemysTurn = true;
                Sleep(1000);
                break;
            }
            case 2: {
                system("cls");
                gotoxy(0, 0);
                player.visitBackpackInventory(enemy, isEnemysTurn);
                break;
            }
            case 3: {
                system("cls");
                gotoxy(0, 0);
                player.printPlayerInfo();
                std::cout << std::endl << "\t\t\t\t"  << "You have " << player.getSkillPoints() << " skill points " << "Which stat do you want to upgrade? (each upgrade costs 5 skill points)\n";
                std::cout << "\t\t\t\t"  << "[1]. Strength |" << " [2]. Intelligence |" << " [3]. Agility |" << " [4]. Firearm Skill |" << " [5]. Melee Skill |" << " [6]. Back" << std::endl << "\t\t\t\t" ;
                int statChoice;
                std::cin >> statChoice;
                while (std::cin.fail() || statChoice > 6 || statChoice < 1)
                {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "\t\t\t\t"  << "Sorry, choose between 1 and 6: ";
                    std::cin >> statChoice;
                }
                isEnemysTurn = player.addStats(statChoice);
                std::cout << "\t\t\t\t"  << "Press any key to continue... " << std::endl;
                char s = _getch();
                break;
            }
            case 4: {
                break;
            }
        }
        if (enemy->getHealth() == 0) {
            std::cout << std::endl << "\t\t\t\t"  << "You killed " << enemy->getName() << "." << std::endl;
            player.addKill();
            player.addSkillPointsRandom();
            player.addRandomMoney();
            player.setHealth(player.getMaxHealth());
            player.setStamina(player.getMaxStamina());
            if ((player.getKillCount() != 0) && (player.getKillCount() % 10 == 0)){
                player.addLevel();
            }
            std::cout << "\t\t\t\t"  << "Press any key to continue... " << std::endl;
            char s = _getch();
            return;
        }
        else if(isEnemysTurn) {
            enemy->setStamina(enemy->getStamina() + 1);
            std::cout << std::endl << "\t\t\t\t"  << enemy->getName() << " gained 1 stamina." << std::endl;
            enemy->attack(player);
            if (player.getHealth() == 0)
            {
                std::cout << std::endl << "\t\t\t\t"  << "You got killed by " << enemy->getName() << "." << std::endl;
                Sleep(1000);
                exit(0);
                return;
            }
            player.setStamina(player.getStamina()+2);
            std::cout << std::endl << "\t\t\t\t"  << "You gained 2 stamina." << std::endl;
            std::cout << "\t\t\t\t"  << "Press any key to continue... " << std::endl;
            char s = _getch();
        }
        system("cls");
        gotoxy(0, 0);

    }
}
Enemy *build(int level, Player player){
    std::vector<std::string> zombieNames = readFromFile("lists/zombie_names.txt");
    if (level == 1) {
        std::string zombieName = chooseRandomLine(zombieNames);
        return new Zombie(zombieName);
    }
    else if (level == 2 || level == 3) {
        std::string zombieName = chooseRandomLine(zombieNames);
        int zombieLevel = chooseZombieLevel(player);
        return new StrongZombie(zombieName, zombieLevel);
    }
    else {
        std::string name = chooseRandomLine(zombieNames);
        if ((rand() % 2))
        {
            return new HumanEnemy(name, rand()%81 + 18);
        }
        int zombieLevel = chooseZombieLevel(player);
        return new StrongZombie(name,zombieLevel);
    }
}


void travel(Player &player){
    bool alreadyVisitedShop = false;
    std::vector<std::string> dialogues = readFromFile("lists/dialogues.txt");
    std::vector<std::string> places = readFromFile("list/places.txt");
    std::vector<std::string> chefs = readFromFile("list/chefs.txt");
    std::vector<std::string> food = readFromFile("list/food.txt");
    int placeCounter = 0;
    std::string saveFile = "./save/" + player.getName() + ".txt";
    int foodMinigameCounter = 0;
    // Generate a random number between 1 and 2
    int randomNumber = rand() % 4 + 1;
    switch(randomNumber) {
        case 1: {
            system("cls");
            gotoxy(0, 0);
            std::string dialogue = chooseRandomLine(dialogues);
            std::cout << std::endl << "\t\t\t\t"  << "- Day " << player.getDay() << ": Fight" << std::endl << "\t\t\t\t"  << player.getName() << ": " << dialogue << std::endl << std::endl;
            Enemy* enemy = build(player.getLevel(),player);
            enemy->printEnemyInfo();
            Battle(player, enemy);
            alreadyVisitedShop = false;
            player.nextDay();
            break;
        }
        case 2: {
            if (!alreadyVisitedShop) {
                system("cls");
                gotoxy(0, 0);
                //shop
                Shop shop;
                player.visitStore(shop);
                alreadyVisitedShop = true;
                player.nextDay();
                break;
            }
            break;
        }
        case 3:
        {
            if (placeCounter < places.size())
            {
                system("cls");
                gotoxy(0, 0);
                std::cout << std::endl << "\t\t\t\t"  << "- Day " << player.getDay() << ": travel " << std::endl;
                std::cout << places[placeCounter] << std::endl;
                if (placeCounter % 5 == 0 && placeCounter!= 0) {
                    std::cout << "\t\t\t\t" << "This seems like a cool place to rest!! " << std::endl << "\t\t\t\t" << "game saved." << std::endl;
                    player.savePlayer(saveFile);
                }
                placeCounter++;
                player.nextDay();
                break;
            }
            break;
        }
        case 4:
        {
            if (foodMinigameCounter < 3) {
                system("cls");
                gotoxy(0, 0);
                std::string chef = chooseRandomLine(chefs);
                std::string randomFood = chooseRandomLine(food);
                std::cout << std::endl << "\t\t\t\t"  << "- Day " << player.getDay() << ": FOOD ROULETTE " << std::endl;
                std::cout << "\t\t\t\t"  << chef << " wants to cook " << randomFood << " for you." << std::endl;
                if (rand() % 7 == 0) { // 1 in 7 chance of being poisoned
                    std::cout << "\t\t\t\t"  << "Uh-oh! The food is poisoned! You died!" << std::endl;
                    player.setHealth(0);
                    exit(0);
                } else {
                    std::cout << "\t\t\t\t"  << "Enjoy your meal!" << std::endl;
                    std::cout << "\t\t\t\t" << "game saved." << std::endl;
                    player.savePlayer(saveFile);
                }
                foodMinigameCounter++;
                player.nextDay();
                break;
            }
            break;
        }
    }
    player.savePlayer(saveFile);
}
void newGame() {
                system("cls");
                gotoxy(0, 0);
                std::cout << "\t\t\t\t"  << "- Day 0: Introduction\n" 
                << "\t\t\t\t" << "In this world torn apart by the Cordyceps fungus outbreak,\n"
                << "\t\t\t\t" << "once-thriving cities now lay in ruins, overgrown with nature's relentless reclaiming.\n"
                << "\t\t\t\t" << "Buildings stand as hollow shells, haunted by the echoes of lost lives and abandoned dreams.\n"
                << "\t\t\t\t" << "The streets, once crowded with activity, now echo with the eerie silence of decay.\n"
                << "\t\t\t\t" << "What's your name survivor?";
                std::string name;
                std::string gender;
                int age;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "\n\t\t\t\t"; 
                std::getline(std::cin, name);
                ScreenShake(10, 500);
                Story(name);
                int choice;
                std::cout << std::endl << "\t\t\t\t"  << "What is your gender?\n" << "\t\t\t\t"  << "[1] Male\n" << "\t\t\t\t"  << "[2] Female\n" << "\t\t\t\t" ;
                std::cin >> choice;
                while (std::cin.fail() || choice < 1 || choice > 2)
                {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "\t\t\t\t"  << "Invalid choice. Please enter a valid option (1-2): ";
                    std::cin >> choice;
                }
                if (choice == 1) {
                    gender = "Male";
                }
                else {
                    gender = "Female";
                }
                std::cout << std::endl << "\t\t\t\t"  << "How old are you " << name << "?" << std::endl << "\t\t\t\t" ;
                std::cin >> age;
                while (std::cin.fail() || age < 11 || age > 90)
                {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "\t\t\t\t"  << "Sorry, your character needs to be older than 10 and younger than 90. enter a new age: ";
                    std::cin >> age;
                }
                std::cout << "\t\t\t\t"  << "Press any key to start... " << std::endl;
                char s = _getch();
                Player player1{name, gender, age};
                do {
                    char  gameLoop;
                    do {
                        system("cls");
                        gotoxy(0, 0);
                        std::cout << "\n\t\t\t\t";
                        std::cout << "\n\n\t\t\t\t" << "███████╗██╗  ██╗███████╗    ██╗      █████╗ ███████╗████████╗     ██████╗ ███╗   ██╗███████╗███████╗";
                        std::cout << "\n\t\t\t\t" << "╚══██╔══╝██║  ██║██╔════╝    ██║     ██╔══██╗██╔════╝╚══██╔══╝    ██╔═══██╗████╗  ██║██╔════╝██╔════╝";
                        std::cout << "\n\t\t\t\t" << "   ██║   ███████║█████╗      ██║     ███████║███████╗   ██║       ██║   ██║██╔██╗ ██║█████╗  ███████╗";
                        std::cout << "\n\t\t\t\t" << "   ██║   ██╔══██║██╔══╝      ██║     ██╔══██║╚════██║   ██║       ██║   ██║██║╚██╗██║██╔══╝  ╚════██║";
                        std::cout << "\n\t\t\t\t" << "   ██║   ██║  ██║███████╗    ███████╗██║  ██║███████║   ██║       ╚██████╔╝██║ ╚████║███████╗███████║";
                        std::cout << "\n\t\t\t\t" << "   ╚═╝   ╚═╝  ╚═╝╚══════╝    ╚══════╝╚═╝  ╚═╝╚══════╝   ╚═╝        ╚═════╝ ╚═╝  ╚═══╝╚══════╝╚══════╝\n";
                        std::cout << "\t\t\t\t" << "[1]. Travel " << "\n\t\t\t\t" << "[2]. Player Card " << "\n\t\t\t\t" <<  "[3]. Exit ";
                        gameLoop = _getch();
                        switch (gameLoop) {
                            case '1': {
                                travel(player1);
                                break;
                            }
                            case '2': {
                                system("cls");
                                gotoxy(0, 0);
                                player1.printPlayerInfo();
                                std::cout << "\t\t\t\t"  << "Press any key to continue... " << std::endl;
                                char s = _getch();
                                break;
                            }
                            default : {
                            }
                        }
                    }while (gameLoop != '3'); 
                    break;
                } while(player1.getHealth() > 0);
}

void listOfSaves(std::string savePath) {
            std::string folderPath = "./Maps/";

            DIR *dir = opendir(folderPath.c_str());

            if (dir)
            {
                std::vector<std::string> fileNames;

                struct dirent *entry;
                int index = 1;
                while ((entry = readdir(dir)) != nullptr)
                {
                    // Exclude . and ..
                    if (std::string(entry->d_name) != "." && std::string(entry->d_name) != "..")
                    {
                        std::cout << "\033[93m" << index << ". " << "\033[0m" << entry->d_name << std::endl;
                        fileNames.push_back(entry->d_name);
                        index++;
                    }
                }

                closedir(dir);

                std::cout << "Choose a file by entering its index: ";
                int choice;
                std::cin >> choice;

                if (choice >= 1 && choice <= static_cast<int>(fileNames.size()))
                {
                    std::string selectedFile = fileNames[choice - 1];
                    savePath = folderPath + selectedFile;
                }
            }
}

void loadGame() {
                system("cls");
                gotoxy(0, 0);
                std::cout << "\t\t\t\t"  << "Press any key to start... " << std::endl;
                char s = _getch();
                std::string name = "PlayerName";
                std::string gender = "Male";
                int age = 25;
                Player player1(name, gender, age);
                std::string savePath = "";
                listOfSaves(savePath);
                player1.loadPlayer(savePath);

                do {
                    char  gameLoop;
                    do {
                        system("cls");
                        gotoxy(0, 0);
                        std::cout << "\n\t\t\t\t";
                        std::cout << "\n\n\t\t\t\t" << "███████╗██╗  ██╗███████╗    ██╗      █████╗ ███████╗████████╗     ██████╗ ███╗   ██╗███████╗███████╗";
                        std::cout << "\n\t\t\t\t" << "╚══██╔══╝██║  ██║██╔════╝    ██║     ██╔══██╗██╔════╝╚══██╔══╝    ██╔═══██╗████╗  ██║██╔════╝██╔════╝";
                        std::cout << "\n\t\t\t\t" << "   ██║   ███████║█████╗      ██║     ███████║███████╗   ██║       ██║   ██║██╔██╗ ██║█████╗  ███████╗";
                        std::cout << "\n\t\t\t\t" << "   ██║   ██╔══██║██╔══╝      ██║     ██╔══██║╚════██║   ██║       ██║   ██║██║╚██╗██║██╔══╝  ╚════██║";
                        std::cout << "\n\t\t\t\t" << "   ██║   ██║  ██║███████╗    ███████╗██║  ██║███████║   ██║       ╚██████╔╝██║ ╚████║███████╗███████║";
                        std::cout << "\n\t\t\t\t" << "   ╚═╝   ╚═╝  ╚═╝╚══════╝    ╚══════╝╚═╝  ╚═╝╚══════╝   ╚═╝        ╚═════╝ ╚═╝  ╚═══╝╚══════╝╚══════╝\n";
                        std::cout << "\t\t\t\t" << "[1]. Travel " << "\n\t\t\t\t" << "[2]. Player Card " << "\n\t\t\t\t" <<  "[3]. Exit ";
                        gameLoop = _getch();
                        switch (gameLoop) {
                            case '1': {
                                travel(player1);
                                break;
                            }
                            case '2': {
                                system("cls");
                                gotoxy(0, 0);
                                player1.printPlayerInfo();
                                std::cout << "\t\t\t\t"  << "Press any key to continue... " << std::endl;
                                char s = _getch();
                                break;
                            }
                            default : {
                            }
                        }
                    }while (gameLoop != '3'); 
                    break;
                } while(player1.getHealth() > 0);
}
HANDLE hConsole; // Declare a handle to the console


int main() {
    PlaySound(TEXT("Song/The-Last-of-Us.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
    SetConsoleOutputCP(CP_UTF8);
    HWND hwnd = GetConsoleWindow();
    ShowWindow(hwnd, SW_MAXIMIZE); // Maximize the console window

    COORD fontSize;
    fontSize.X = 20; // Set the desired width
    fontSize.Y = 20; // Set the desired height

    SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), fontSize); // Set the console buffer size

    SetConsoleTitle(TEXT("THE LAST ONES"));
    HANDLE hIcon = LoadImage(NULL, TEXT("Designer.ico"), IMAGE_ICON, 0, 0, LR_LOADFROMFILE);
    if (hIcon != NULL) {
        SendMessage(hwnd, WM_SETICON, ICON_SMALL, (LPARAM)hIcon);
        SendMessage(hwnd, WM_SETICON, ICON_BIG, (LPARAM)hIcon);
    }
    
    srand(static_cast<unsigned int>(time(nullptr))); // Seed for random number generation
    char choice;
    do {
        system("cls");
        gotoxy(0, 0);
        std::cout << "\n\t\t\t\t";
        std::cout << "\n\n\t\t\t\t" << "███████╗██╗  ██╗███████╗    ██╗      █████╗ ███████╗████████╗     ██████╗ ███╗   ██╗███████╗███████╗";
        std::cout << "\n\t\t\t\t" << "╚══██╔══╝██║  ██║██╔════╝    ██║     ██╔══██╗██╔════╝╚══██╔══╝    ██╔═══██╗████╗  ██║██╔════╝██╔════╝";
        std::cout << "\n\t\t\t\t" << "   ██║   ███████║█████╗      ██║     ███████║███████╗   ██║       ██║   ██║██╔██╗ ██║█████╗  ███████╗";
        std::cout << "\n\t\t\t\t" << "   ██║   ██╔══██║██╔══╝      ██║     ██╔══██║╚════██║   ██║       ██║   ██║██║╚██╗██║██╔══╝  ╚════██║";
        std::cout << "\n\t\t\t\t" << "   ██║   ██║  ██║███████╗    ███████╗██║  ██║███████║   ██║       ╚██████╔╝██║ ╚████║███████╗███████║";
        std::cout << "\n\t\t\t\t" << "   ╚═╝   ╚═╝  ╚═╝╚══════╝    ╚══════╝╚═╝  ╚═╝╚══════╝   ╚═╝        ╚═════╝ ╚═╝  ╚═══╝╚══════╝╚══════╝\n";
        std::cout << "\t\t\t\t" << "[1]. New Game " << "\n\t\t\t\t" << "[2]. Load Game " << "\n\t\t\t\t" <<  "[3]. Multiplayer " << "\n\t\t\t\t" << "[4]. Exit\n";
        choice = _getch();
        switch (choice) {
            case '1':
            {
                newGame();
                break;
            }           
            case '2':
                loadGame();
                break;
            case '3':
                // Start multiplayer
                break;
            case '4':
                // Exit program
                exit(0);
                break;
            default:
                // Invalid input
                break;
        }
        
    }while (choice != '4');
    PlaySound(0, 0, 0);
    return 0;
}
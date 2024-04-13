#include "Shop.h"
#include "Player.h"
#include <limits>
#include <conio.h>
#include <ctime>

void Shop::startShopping(Player& player)
    {
        bool isInShop = true;
        int choice;
        do {
            std::cout << std::endl << "\t\t\t\t"  << "- Day " << player.getDay() << ": Shop" << std::endl << "\t\t\t\t"  << "You enter the shop." << std::endl;
            std::cout << "\t\t\t\t"  << "[1]. Permanent Items" << std::endl;
            std::cout << "\t\t\t\t"  << "[2]. Consumable Items" << std::endl;
            std::cout << "\t\t\t\t"  << "[3]. Throwable Items" << std::endl;
            std::cout << "\t\t\t\t"  << "[0]. Exit" << std::endl;

            char ch = _getch();
            choice = ch - '0';
            switch (choice)
            {
                case 1:
                    shopPermanentItems(player);
                    break;
                case 2:
                    shopConsumableItems(player);
                    break;
                case 3:
                    shopThrowableItems(player);
                    break;
                case 0:
                    std::cout << "\t\t\t\t"  << "Exiting the store." << std::endl;
                    break;
            }
            system("cls");
            gotoxy(0, 0);
        } while (choice != 0);
        return;
    }

void Shop::shopPermanentItems(Player& player)
{

        int choice;
        
         
 
        // std::vector of pointers to stock variables
        std::vector<int*> stockPointers = { &w1  , &w2 , &w3  , &w4  , &w5 , &w6 };

    do {
        system("cls");
            gotoxy(0, 0);
        std::cout << "\t\t\t\t"  << "You go to take a look at the Permanent Items : (your money: " << player.getMoney() << "$)" << std::endl;
        std::cout << "\t\t\t\t"  << "You need to select a permanent item:" << std::endl;
        std::cout << "\t\t\t\t"  << "          <. Firearms .>" << std::endl;
        std::cout << "\t\t\t\t"  << "[1]. Rifle (+10HP) / stock: " <<  *stockPointers[0] << " / price: (25$)" << std::endl;
        std::cout << "\t\t\t\t"  << "[2]. Pistol (+10HP) / stock: " << *stockPointers[1] << " / price: (25$)" << std::endl;
        std::cout << "\t\t\t\t"  << "[3]. Shotgun (+10HP) / stock: " << *stockPointers[2] << " / price: (25$)" << std::endl;
        std::cout << "\t\t\t\t"  << "          <. Melee .>" << std::endl;
        std::cout << "\t\t\t\t"  << "[4]. Knife (+10HP) / stock: " << *stockPointers[3] << " / price: (15$)" << std::endl;
        std::cout << "\t\t\t\t"  << "[5]. Katana (+10HP) / stock: " << *stockPointers[4] << " / price: (15$)" << std::endl;
        std::cout << "\t\t\t\t"  << "[6]. Axe (+10HP) / stock: " << *stockPointers[5] << " / price: (15$)" << std::endl;
        std::cout << "\t\t\t\t"  << "[0]. Back" << std::endl;

        char ch = _getch();
        choice = ch - '0';

        switch (choice)
        {
            case 1:
                if (player.getMoney() >= 25 && *stockPointers[0] > 0)
                {
                    player.setMoney(player.getMoney() - 25);
                    std::cout << "\t\t\t\t"  << "Successful purchase! Added Rifle to your backpack." << std::endl;
                    player.addPermanentItemToBackpack(new Rifle("Rifle", 25, +10) );
                    (*stockPointers[0])--; // Decrease stock of rifles
                    std::cout << "\t\t\t\t"  << "Press any key to continue... " << std::endl;
                    char s = _getch();
                }
                else if (player.getMoney() < 25)
                {
                    std::cout << "\t\t\t\t"  << "Not enough money to purchase Rifle!" << std::endl;
                    std::cout << "\t\t\t\t"  << "Press any key to continue... " << std::endl;
                    char s = _getch();
                }
                else
                {
                    std::cout << "Rifle out of stock!" << std::endl;
                    std::cout << "\t\t\t\t"  << "Press any key to continue... " << std::endl;
                    char s = _getch();
                }
                break;

            case 2:
                if (player.getMoney() >= 25 && *stockPointers[1] > 0)
                {
                    player.setMoney(player.getMoney() - 25);
                    std::cout << "\t\t\t\t"  << "Successful purchase! Added Pistol to your backpack." << std::endl;
                    player.addPermanentItemToBackpack(new Pistol("Pistol", 25, +10) );
                    (*stockPointers[1])--; // Decrease stock of pistols
                    std::cout << "\t\t\t\t"  << "Press any key to continue... " << std::endl;
                    char s = _getch();
                }
                else if (player.getMoney() < 25)
                {
                    std::cout << "\t\t\t\t"  << "Not enough money to purchase Pistol!" << std::endl;
                    std::cout << "\t\t\t\t"  << "Press any key to continue... " << std::endl;
                    char s = _getch();
                }
                else
                {
                    std::cout << "\t\t\t\t"  << "Pistol out of stock!" << std::endl;
                    std::cout << "\t\t\t\t"  << "Press any key to continue... " << std::endl;
                    char s = _getch();
                }
                break;
                
            case 3:
               if (player.getMoney() >= 25 && *stockPointers[2] > 0)
               {
                   player.setMoney(player.getMoney() - 25);
                   std::cout << "\t\t\t\t"  << "Successful purchase! Added Shotgun to your backpack." << std::endl;
                   player.addPermanentItemToBackpack(new Shotgun("Shotgun", 25, +10) );
                   (*stockPointers[2])--; // Decrease stock of shotguns
                   std::cout << "\t\t\t\t"  << "Press any key to continue... " << std::endl;
                    char s = _getch();
                }
                else if (player.getMoney() < 25)
                {
                   std::cout << "\t\t\t\t"  << "Not enough money to purchase Shotgun!" << std::endl;
                   std::cout << "\t\t\t\t"  << "Press any key to continue... " << std::endl;
                    char s = _getch();
                }
                else
                {
                   std::cout << "\t\t\t\t"  << "Shotgun out of stock!" << std::endl;
                   std::cout << "\t\t\t\t"  << "Press any key to continue... " << std::endl;
                    char s = _getch();
                }
                break;    

            case 4:
                 if (player.getMoney() >= 15 && *stockPointers[3] > 0)
                 {
                     player.setMoney(player.getMoney() - 15);
                     std::cout << "\t\t\t\t"  << "Successful purchase! Added Knife to your backpack." << std::endl;
                     player.addPermanentItemToBackpack(new Knife("Knife", 15, +10) );
                     (*stockPointers[3])--; // Decrease stock of knives
                     std::cout << "\t\t\t\t"  << "Press any key to continue... " << std::endl;
                    char s = _getch();
                }
                else if (player.getMoney() < 15)
                {
                    std::cout << "\t\t\t\t"  << "Not enough money to purchase Knife!" << std::endl;
                    std::cout << "\t\t\t\t"  << "Press any key to continue... " << std::endl;
                    char s = _getch();
                }
                else
                {
                    std::cout << "\t\t\t\t"  << "Knife out of stock!" << std::endl;
                    std::cout << "\t\t\t\t"  << "Press any key to continue... " << std::endl;
                    char s = _getch();
                }
                break;

            case 5:
                 if (player.getMoney() >= 15 && *stockPointers[4] > 0)
                 {
                     player.setMoney(player.getMoney() - 15);
                     std::cout << "\t\t\t\t"  << "Successful purchase! Added Katana to your backpack." << std::endl;
                     player.addPermanentItemToBackpack(new Katana("Katana", 15, +10) );
                     (*stockPointers[4])--; // Decrease stock of katanas
                     std::cout << "\t\t\t\t"  << "Press any key to continue... " << std::endl;
                    char s = _getch();
                }
                else if (player.getMoney() < 15)
                {
                     std::cout << "\t\t\t\t"  << "Not enough money to purchase Katana!" << std::endl;
                     std::cout << "\t\t\t\t"  << "Press any key to continue... " << std::endl;
                    char s = _getch();
                }
                else
                {
                     std::cout << "\t\t\t\t"  << "Katana out of stock!" << std::endl;
                     std::cout << "\t\t\t\t"  << "Press any key to continue... " << std::endl;
                    char s = _getch();
                }
                break;

            case 6:
                if (player.getMoney() >= 15 && *stockPointers[5] > 0)
                {
                     player.setMoney(player.getMoney() - 15);
                     std::cout << "\t\t\t\t"  << "Successful purchase! Added Axe to your backpack." << std::endl;
                     player.addPermanentItemToBackpack(new Axe("Axe", 15, +10) );
                     (*stockPointers[5])--; // Decrease stock of axes
                     std::cout << "\t\t\t\t"  << "Press any key to continue... " << std::endl;
                    char s = _getch();
                }
                else if (player.getMoney() < 15)
                {
                     std::cout << "\t\t\t\t"  << "Not enough money to purchase Axe!" << std::endl;
                     std::cout << "\t\t\t\t"  << "Press any key to continue... " << std::endl;
                    char s = _getch();
                }
                else
                {
                     std::cout << "\t\t\t\t"  << "Axe out of stock!" << std::endl;
                     std::cout << "\t\t\t\t"  << "Press any key to continue... " << std::endl;
                    char s = _getch();
                }
                break;  

            case 0:

                std::cout << "\t\t\t\t"  << "Returning to main shop menu." << std::endl;
                Sleep(500);
                break;

        }

    } while (choice != 0);
    return;
}  
    

void Shop::shopConsumableItems(Player& player)
{
        
     int choice;  
     

        // std::vector of pointers to stock variables
        std::vector<int*> stockPointers_of_Consumable = { &c1  , &c2 , &c3  , &c4 };

    do {
        system("cls");
        gotoxy(0, 0);
        std::cout  << "\t\t\t\t" << "You go to take a look at the Consumable Items : (your money: " << player.getMoney() << "$)" << std::endl;
        std::cout << "\t\t\t\t"  << "You need to select a Consumable Item:" << std::endl;
        std::cout << "\t\t\t\t"  << "          <. HealthBooster .>" << std::endl;
        std::cout << "\t\t\t\t"  << "[1]. HealthPotion (+10 HP) / stock: " <<  *stockPointers_of_Consumable[0] << " / price: (10$)" << std::endl;
        std::cout << "\t\t\t\t"  << "[2]. CannedFood (+10 HP) / stock: " << *stockPointers_of_Consumable[1] << " / price: (10$)" << std::endl;
        std::cout << "\t\t\t\t"  << "          <. StaminaBooster .>" << std::endl;
        std::cout << "\t\t\t\t"  << "[3]. EnergyDrink (+10 ST) / stock: " << *stockPointers_of_Consumable[2] << " / price: (10$)" << std::endl;
        std::cout << "\t\t\t\t"  << "[4]. ChocolateBar (+10 ST) / stock: " << *stockPointers_of_Consumable[3] << " / price: (10$)" << std::endl;
        std::cout << "\t\t\t\t"  << "[0]. Back" << std::endl;


        char ch = _getch();
        choice = ch - '0';

        switch (choice)
        {

            case 1:
                if (player.getMoney() >= 10 && *stockPointers_of_Consumable[0] > 0)
                {
                    player.setMoney(player.getMoney() - 10);
                    std::cout << "\t\t\t\t"  << "Successful purchase! Added  1x HealthPotion to your backpack." << std::endl;
                    player.addConsumableItemToBackpack(new HealthPotion("HealthPotion", 10, +10) );
                    (*stockPointers_of_Consumable[0])--; // Decrease stock of rifles
                    std::cout << "\t\t\t\t"  << "Press any key to continue... " << std::endl;
                    char s = _getch();
                }
                else if (player.getMoney() < 10)
                {
                    std::cout << "\t\t\t\t"  << "Not enough money to purchase HealthPotion!" << std::endl;
                    std::cout << "\t\t\t\t"  << "Press any key to continue... " << std::endl;
                    char s = _getch();
                }
                else
                {
                    std::cout << "\t\t\t\t"  << "HealthPotion out of stock!" << std::endl;
                    std::cout << "\t\t\t\t"  << "Press any key to continue... " << std::endl;
                    char s = _getch();
                }
                break;

            case 2:

                if (player.getMoney() >= 10 && *stockPointers_of_Consumable[1] > 0)
                {
                    player.setMoney(player.getMoney() - 10);
                    std::cout << "\t\t\t\t"  << "Successful purchase! Added 1x CannedFood to your backpack." << std::endl;
                    player.addConsumableItemToBackpack(new CannedFood("CannedFood", 10, +10) );
                    (*stockPointers_of_Consumable[1])--; // Decrease stock of pistols
                    std::cout << "\t\t\t\t"  << "Press any key to continue... " << std::endl;
                    char s = _getch();
                }
                else if (player.getMoney() < 10)
                {
                    std::cout << "\t\t\t\t"  << "Not enough money to purchase CannedFood!" << std::endl;
                    std::cout << "\t\t\t\t"  << "Press any key to continue... " << std::endl;
                    char s = _getch();
                }
                else
                {
                    std::cout << "\t\t\t\t"  << "CannedFood out of stock!" << std::endl;
                    std::cout << "\t\t\t\t"  << "Press any key to continue... " << std::endl;
                    char s = _getch();
                }
                break;
                
            case 3:

               if (player.getMoney() >= 10 && *stockPointers_of_Consumable[2] > 0)
               {
                   player.setMoney(player.getMoney() - 10);
                   std::cout << "\t\t\t\t"  << "Successful purchase! Added 1x EnergyDrink to your backpack." << std::endl;
                   player.addConsumableItemToBackpack(new EnergyDrink("EnergyDrink", 10, +10) );
                   (*stockPointers_of_Consumable[2])--; // Decrease stock of shotguns
                   std::cout << "\t\t\t\t"  << "Press any key to continue... " << std::endl;
                    char s = _getch();
                }
                else if (player.getMoney() < 10)
                {
                   std::cout << "\t\t\t\t"  << "Not enough money to purchase EnergyDrink!" << std::endl;
                   std::cout << "\t\t\t\t"  << "Press any key to continue... " << std::endl;
                    char s = _getch();
                }
                else
                {
                   std::cout << "\t\t\t\t"  << "EnergyDrink out of stock!" << std::endl;
                   std::cout << "\t\t\t\t"  << "Press any key to continue... " << std::endl;
                    char s = _getch();
                }
                break;  

            case 4:

                 if (player.getMoney() >= 10 && *stockPointers_of_Consumable[3] > 0)
                 {
                     player.setMoney(player.getMoney() - 10);
                     std::cout << "\t\t\t\t"  << "Successful purchase! Added 1x ChocolateBar to your backpack." << std::endl;
                     player.addConsumableItemToBackpack(new ChocolateBar("ChocolateBar", 10, +10) );
                     (*stockPointers_of_Consumable[3])--; // Decrease stock of knives
                     std::cout << "\t\t\t\t"  << "Press any key to continue... " << std::endl;
                    char s = _getch();
                }
                else if (player.getMoney() < 10)
                {
                    std::cout << "\t\t\t\t"  << "Not enough money to purchase ChocolateBar!" << std::endl;
                    std::cout << "\t\t\t\t"  << "Press any key to continue... " << std::endl;
                    char s = _getch();
                }
                else
                {
                    std::cout << "\t\t\t\t"  << "ChocolateBar out of stock!" << std::endl;
                    std::cout << "\t\t\t\t"  << "Press any key to continue... " << std::endl;
                    char s = _getch();
                }
                break;

            case 0:

                std::cout << "\t\t\t\t"  << "Returning to main shop menu." << std::endl;
                Sleep(500);
                break;

        }
    } while (choice != 0);
    return;
}

void Shop::shopThrowableItems(Player& player)
{

        int choice;
        
         
 
        // std::vector of pointers to stock variables
        std::vector<int*> stockPointers_of_Throwable = { &t1  , &t2 , &t3  };

    do {
        system("cls");
        gotoxy(0, 0);
        std::cout << "\t\t\t\t"  << "You go to take a look at the Throwable Items : (your money: " << player.getMoney() << "$)" << std::endl;
        std::cout << "\t\t\t\t"  << "You need to select a Throwable Item:" << std::endl;
        std::cout << "\t\t\t\t"  << "[1]. Molotov (+10HP) / stock: " <<  *stockPointers_of_Throwable[0] << " / price: (15$)" << std::endl;
        std::cout << "\t\t\t\t"  << "[2]. Brick (+10HP) / stock: " << *stockPointers_of_Throwable[1] << " / price: (15$)" << std::endl;
        std::cout << "\t\t\t\t"  << "[3]. Grenade (+10HP) / stock: " << *stockPointers_of_Throwable[2] << " / price: (15$)" << std::endl;
        std::cout << "\t\t\t\t"  << "[0]. Back" << std::endl;


        char ch = _getch();
        choice = ch - '0';
        switch (choice)
        {
            case 1:
                if (player.getMoney() >= 15 && *stockPointers_of_Throwable[0] > 0)
                {
                    player.setMoney(player.getMoney() - 15);
                    std::cout << "\t\t\t\t"  << "Successful purchase! Added 1x Molotov to your backpack." << std::endl;
                    player.addThrowableItemToBackpack(new Molotov("Molotov", 15 ) );
                    (*stockPointers_of_Throwable[0])--; // Decrease stock of rifles
                }
                else if (player.getMoney() < 15)
                {
                    std::cout << "\t\t\t\t"  << "Not enough money to purchase Molotov!" << std::endl;
                    std::cout << "\t\t\t\t"  << "Press any key to continue... " << std::endl;
                    char s = _getch();
                }
                else
                {
                    std::cout << "\t\t\t\t"  << "Molotov out of stock!" << std::endl;
                    std::cout << "\t\t\t\t"  << "Press any key to continue... " << std::endl;
                    char s = _getch();
                }
                break;

            case 2:
                if (player.getMoney() >= 15 && *stockPointers_of_Throwable[1] > 0)
                {
                    player.setMoney(player.getMoney() - 15);
                    std::cout << "\t\t\t\t"  << "Successful purchase! Added 1x Brick to your backpack." << std::endl;
                    player.addThrowableItemToBackpack(new Brick("Brick", 15 ) );
                    (*stockPointers_of_Throwable[1])--; // Decrease stock of pistols
                    std::cout << "\t\t\t\t"  << "Press any key to continue... " << std::endl;
                    char s = _getch();
                }
                else if (player.getMoney() < 15)
                {
                    std::cout << "\t\t\t\t"  << "Not enough money to purchase Brick!" << std::endl;
                    std::cout << "\t\t\t\t"  << "Press any key to continue... " << std::endl;
                    char s = _getch();
                }
                else
                {
                    std::cout << "\t\t\t\t"  << "Brick out of stock!" << std::endl;
                    std::cout << "\t\t\t\t"  << "Press any key to continue... " << std::endl;
                    char s = _getch();
                }
                break;
                
            case 3:
               if (player.getMoney() >= 15 && *stockPointers_of_Throwable[2] > 0)
               {
                   player.setMoney(player.getMoney() - 15);
                   std::cout << "\t\t\t\t"  << "Successful purchase! Added 1x Grenade to your backpack." << std::endl;
                   player.addThrowableItemToBackpack(new Grenade("Grenade", 15 ) );
                   (*stockPointers_of_Throwable[2])--; // Decrease stock of shotguns
                   std::cout << "\t\t\t\t"  << "Press any key to continue... " << std::endl;
                   char s = _getch();
                }
                else if (player.getMoney() < 15)
                {
                   std::cout << "\t\t\t\t"  << "Not enough money to purchase Grenade!" << std::endl;
                   std::cout << "\t\t\t\t"  << "Press any key to continue... " << std::endl;
                   char s = _getch();
                }
                else
                {
                   std::cout << "\t\t\t\t"  << "Grenade out of stock!" << std::endl;
                   std::cout << "\t\t\t\t"  << "Press any key to continue... " << std::endl;
                   char s = _getch();

                }
                break;      

            case 0:

                std::cout << "\t\t\t\t"  << "Returning to main shop menu." << std::endl;
                Sleep(500);
                break;
        }
    } while (choice != 0);
    return;
}

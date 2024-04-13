#include "BackPack.h"
#include "ConsumableItem.h"
#include "Player.h"
#include <limits>
#include <conio.h>
#include <ctime>


void Backpack::addPermanentItem(Item* item)
{
    std::string itemName = item->getName();
 
        if (itemStock.find(itemName) != itemStock.end()) {
           std::cout << "\t\t\t\t"  << "Added " << itemName << " to your permanent items." << std::endl;
            itemStock[itemName]++;
        } else {
            permanentItems.push_back(item);
           std::cout << "\t\t\t\t"  << "Added " << itemName << " to your permanent items." << std::endl;
            itemStock[itemName] = 1;
        }
}

void Backpack::addConsumableItem(Item* item)
{
    std::string itemName = item->getName();

        if (itemStock.find(itemName) != itemStock.end()) {
            std::cout << "\t\t\t\t"  << "Added " << itemName << " to your consumable items." << std::endl;
            itemStock[itemName]++;
        } else {
            consumableItems.push_back(item);
            std::cout << "\t\t\t\t"  << "Added " << itemName << " to your consumable items." << std::endl;
            itemStock[itemName] = 1;
        }
}

void Backpack::addThrowableItem(Item* item)
{
    std::string itemName = item->getName();
 
        if (itemStock.find(itemName) != itemStock.end()) {
            std::cout << "\t\t\t\t"  << "Added " << itemName << " to your throwable items." << std::endl;
            itemStock[itemName]++;
        } else {
            throwableItems.push_back(item);
            std::cout << "\t\t\t\t"  << "Added " << itemName << " to your throwable items." << std::endl;
            itemStock[itemName] = 1;
        }
}


std::map<std::string, int> Backpack::getItemStock() const{ return itemStock; }


Item* Backpack::findItem(const std::string& itemName, const std::vector<Item*>& items) {
    for (Item* item : items) {
        if (item->getName() == itemName) {
            return item;
        }
    }
    return nullptr;
}

void Backpack::updateItemStock(const std::string& itemName, std::vector<Item*>& items) {
    Item* item = findItem(itemName, items);
    if (item != nullptr) {
        itemStock[itemName]--;
        if (itemStock[itemName] == 0) {
            items.erase(std::remove_if(items.begin(), items.end(),
                [&](Item* item){ return item->getName() == itemName; }), items.end());
            itemStock.erase(itemName);
        }
    }
}

void Backpack::updatePermanentItemStock(const std::string& itemName)
{
    updateItemStock(itemName, permanentItems);
}

void Backpack::updateConsumableItemStock(const std::string& itemName)
{
    updateItemStock(itemName, consumableItems);
}

void Backpack::updateThrowableItemStock(const std::string& itemName)
{
    updateItemStock(itemName, throwableItems);
}




void Backpack::showInventoryMenu(Player& player, Enemy* enemy,bool &isEnemysTurn)
{
    int choice;
    do {
        system("cls");
        gotoxy(0, 0);
        std::cout << "\t\t\t\t"  << "Your backpack inventory:" << std::endl;
        std::cout << "\t\t\t\t"  << "[1]. Permanent Items" << std::endl;
        std::cout << "\t\t\t\t"  << "[2]. Consumable Items" << std::endl;
        std::cout << "\t\t\t\t"  << "[3]. Throwable Items" << std::endl;
        std::cout << "\t\t\t\t"  << "[0]. Back" << std::endl;
        std::cout << "\t\t\t\t"  << "Enter your choice: ";
        std::cin >> choice;
        while (std::cin.fail() || choice < 0 || choice > 3) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "\t\t\t\t"  << "Invalid choice. Please enter a valid option (0-3): ";
            std::cin >> choice;
        }

        switch (choice) {
            case 1:
                showPermanentItems(player, enemy, isEnemysTurn);
                break;
            case 2:
                showConsumableItems(player, enemy, isEnemysTurn);
                break;
            case 3: {
                bool isUsed = false;
                showThrowableItems(player, enemy,  isEnemysTurn, isUsed);
                if (isUsed)
                {
                    return;
                }
                break;
            }    
            case 0:
                std::cout << "\t\t\t\t"  << "Returning ." << std::endl;
                return;
        }
    } while (true);
}

void Backpack::showPermanentItems(Player& player, Enemy* enemy,bool &isEnemysTurn) {
        int choice;
        do {
            system("cls");
            gotoxy(0, 0);
            std::cout << "\t\t\t\t"  << "Permanent Items:" << std::endl;
            for (int i = 0; i < permanentItems.size(); ++i) {
                std::cout << "\t\t\t\t"  << "[" << i + 1 << "]. " << permanentItems[i]->getName() << " (stock = " << itemStock[permanentItems[i]->getName()] << ")" << std::endl;
            }
            std::cout << "\t\t\t\t"  << "[0]. Back to inventory menu" << std::endl;
            std::cout << "\t\t\t\t"  << "Enter your choice: ";
            std::cin >> choice;
            while (std::cin.fail() || choice < 0 || choice > permanentItems.size()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "\t\t\t\t"  << "Invalid choice. Please enter a valid option (0-" << permanentItems.size() << "): ";
                std::cin >> choice;
            }
            if (choice == 0) {
                std::cout << "\t\t\t\t"  << "Returning to inventory menu." << std::endl;
                return;
            } else {
                Item* selectedItem = permanentItems[choice - 1];
                equipedWeapon = selectedItem->getName();
                selectedItem->use(player, enemy);
                std::cout << "\t\t\t\t"  << "Press any key to continue... " << std::endl;
                char s = _getch();
            }
        } while (true);
}

void Backpack::showConsumableItems(Player& player, Enemy* enemy,bool &isEnemysTurn) {
        int choice;
        do {
            system("cls");
            gotoxy(0, 0);
            std::cout << "\t\t\t\t"  << "Consumable Items:" << std::endl;
            for (int i = 0; i < consumableItems.size(); ++i) {
                std::cout << "\t\t\t\t"  << "[" << i + 1 << "]. " << consumableItems[i]->getName() << " (stock = " << itemStock[consumableItems[i]->getName()] << ")" << std::endl;
            }
            std::cout << "\t\t\t\t"  << "[0]. Back to inventory menu" << std::endl;
            std::cout << "\t\t\t\t"  << "Enter your choice: ";
            std::cin >> choice;
            while (std::cin.fail() || choice < 0 || choice > consumableItems.size()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "\t\t\t\t"  << "Invalid choice. Please enter a valid option (0-" << consumableItems.size() << "): ";
                std::cin >> choice;
            }

            if (choice == 0) {
                std::cout << "\t\t\t\t"  << "Returning to inventory menu." << std::endl;
                return;
            } else {
                Item* selectedItem = consumableItems[choice - 1];
                selectedItem->use(player, enemy);
                updateConsumableItemStock(selectedItem->getName());
                std::cout << "\t\t\t\t"  << "Press any key to continue... " << std::endl;
                char s = _getch();
            }
        } while (true);
}

void Backpack::showThrowableItems(Player& player, Enemy* enemy,bool &isEnemysTurn, bool &isUsed) {
        int choice;
        do {
            system("cls");
            gotoxy(0, 0);
            std::cout << "\t\t\t\t"  << "Throwable Items:" << std::endl;
            for (int i = 0; i < throwableItems.size(); ++i) {
                std::cout << "\t\t\t\t"  << "[" << i + 1 << "]. " << throwableItems[i]->getName() << " (stock = " << itemStock[throwableItems[i]->getName()] << ")" << std::endl;
            }
            std::cout << "\t\t\t\t"  << "[0]. Back to inventory menu" << std::endl;
            std::cout << "\t\t\t\t"  << "Enter your choice: ";
            std::cin >> choice;
            while (std::cin.fail() || choice < 0 || choice > throwableItems.size()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "\t\t\t\t"  << "Invalid choice. Please enter a valid option (0-" << throwableItems.size() << "): ";
                std::cin >> choice;
            }

            if (choice == 0) {
                std::cout << "\t\t\t\t"  << "Returning to inventory menu." << std::endl;
                return;
            }
            else {
                Item* selectedItem = throwableItems[choice - 1];
                selectedItem->use(player, enemy);
                isUsed = true;
                isEnemysTurn = true;
                updateThrowableItemStock(selectedItem->getName());
                break;
            }
        } while (true);
}

void Backpack::saveBackPack(std::ofstream &file) {
    if (file.is_open()) {
        // Serialize permanent items
        file << permanentItems.size() << "\n";
        for (Item* item : permanentItems) {
            file << item->getName() << " " << itemStock[item->getName()] << "\n";
        }

        // Serialize consumable items
        file << consumableItems.size() << "\n";
        for (Item* item : consumableItems) {
            file << item->getName() << " " << itemStock[item->getName()] << "\n";
        }

        // Serialize throwable items
        file << throwableItems.size() << "\n";
        for (Item* item : throwableItems) {
            file << item->getName() << " " << itemStock[item->getName()] << "\n";
        }

        file.close();
    }
}

void Backpack::loadBackPack(const std::string& filename) { 
    std::ifstream file(filename); 
    if (file.is_open()) { 
        size_t permanentSize, consumableSize, throwableSize; 
        file >> permanentSize >> consumableSize >> throwableSize; 
 
        std::string itemName, itemType; 
        int itemQuantity; 
 
        // Load permanent items 
        for (size_t i = 0; i < permanentSize; ++i) { 
            file >> itemName; 
            // استفاده از کانستراکتور مناسب برای هر آیتم با توجه به نام آن 
            if (itemName == "Rifle") { 
                permanentItems.push_back(new Rifle("Rifle", 25, +10)); 
            } else if (itemName == "Pistol") { 
                permanentItems.push_back(new Pistol("Pistol", 25, +10)); 
            } else if (itemName == "Shotgun") { 
                permanentItems.push_back(new Shotgun("Shotgun", 25, +10)); 
            } else if (itemName == "Knife") { 
                permanentItems.push_back(new Knife("Knife", 15, +10)); 
            } else if (itemName == "Katana") { 
                permanentItems.push_back(new Katana("Katana", 15, +10)); 
            } else if (itemName == "Axe") { 
                permanentItems.push_back(new Axe("Axe", 15, +10)); 
            } 
            file >> itemQuantity; 
            itemStock[itemName] = itemQuantity; 
        } 
 
        // Load consumable items 
        for (size_t i = 0; i < consumableSize; ++i) { 
            file >> itemName; 
            // استفاده از کانستراکتور مناسب برای هر آیتم با توجه به نام آن 
            if (itemName == "HealthPotion") { 
                consumableItems.push_back(new HealthPotion("HealthPotion", 10, +10)); 
            } else if (itemName == "CannedFood") { 
                consumableItems.push_back(new CannedFood("CannedFood", 10, +10)); 
            } else if (itemName == "EnergyDrink") { 
                consumableItems.push_back(new EnergyDrink("EnergyDrink", 10, +10)); 
            } else if (itemName == "ChocolateBar") { 
                consumableItems.push_back(new ChocolateBar("ChocolateBar", 10, +10)); 
            } 
            file >> itemQuantity; 
            itemStock[itemName] = itemQuantity; 
        } 
 
        // Load throwable items 
        for (size_t i = 0; i < throwableSize; ++i) { 
            file >> itemName; 
            // استفاده از کانستراکتور مناسب برای هر آیتم با توجه به نام آن 
            if (itemName == "Molotov") { 
                throwableItems.push_back(new Molotov("Molotov", 15)); 
            } else if (itemName == "Brick") { 
                throwableItems.push_back(new Brick("Brick", 15)); 
            } else if (itemName == "Grenade") { 
                throwableItems.push_back(new Grenade("Grenade", 15)); 
            } 
            file >> itemQuantity; 
            itemStock[itemName] = itemQuantity; 
        } 
 
        file.close(); 
        std::cout << "Backpack data loaded successfully from " << filename << std::endl; 
    } else { 
        std::cerr << "Error: Unable to open file " << filename << " for reading!" << std::endl; 
    } 
}
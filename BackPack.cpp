#include "BackPack.h"
#include "ConsumableItem.h"
#include "Player.h"
#include <limits>
#include <ctime>


void Backpack::addPermanentItem(Item* item)
{
    std::string itemName = item->getName();
 
        if (itemStock.find(itemName) != itemStock.end()) {
           std::cout << itemName << " already exists in your permanent items." << std::endl;
            itemStock[itemName]++;
        } else {
            permanentItems.push_back(item);
           std::cout << "Added " << itemName << " to your permanent items." << std::endl;
            itemStock[itemName] = 1;
        }
}

void Backpack::addConsumableItem(Item* item)
{
    std::string itemName = item->getName();

        if (itemStock.find(itemName) != itemStock.end()) {
            std::cout << itemName << " already exists in your permanent items." << std::endl;
            itemStock[itemName]++;
        } else {
            consumableItems.push_back(item);
            std::cout << "Added " << itemName << " to your permanent items." << std::endl;
            itemStock[itemName] = 1;
        }
}

void Backpack::addThrowableItem(Item* item)
{
    std::string itemName = item->getName();
 
        if (itemStock.find(itemName) != itemStock.end()) {
            std::cout << itemName << " already exists in your permanent items." << std::endl;
            itemStock[itemName]++;
        } else {
            throwableItems.push_back(item);
            std::cout << "Added " << itemName << " to your permanent items." << std::endl;
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




void Backpack::showInventoryMenu(Player& player, StrongZombie& zombie)
{
    int choice;
    do {
        std::cout << "Your backpack inventory:" << std::endl;
        std::cout << "[1]. Permanent Items" << std::endl;
        std::cout << "[2]. Consumable Items" << std::endl;
        std::cout << "[3]. Throwable Items" << std::endl;
        std::cout << "[0]. Back to main menu" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        while (std::cin.fail() || choice < 0 || choice > 3) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid choice. Please enter a valid option (0-3): ";
            std::cin >> choice;
        }

        switch (choice) {
            case 1:
                showPermanentItems(player, zombie);
                break;
            case 2:
                showConsumableItems(player, zombie);
                break;
            case 3:
                showThrowableItems(player, zombie);
                break;
            case 0:
                std::cout << "Returning to main menu." << std::endl;
                return;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (true);
}

void Backpack::showPermanentItems(Player& player, StrongZombie& zombie) {
        int choice;
        do {
            std::cout << "Permanent Items:" << std::endl;
            for (int i = 0; i < permanentItems.size(); ++i) {
                std::cout << "[" << i + 1 << "]. " << permanentItems[i]->getName() << " (stock = " << itemStock[permanentItems[i]->getName()] << ")" << std::endl;
            }
            std::cout << "[0]. Back to inventory menu" << std::endl;
            std::cout << "Enter your choice: ";
            std::cin >> choice;
            while (std::cin.fail() || choice < 0 || choice > permanentItems.size()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid choice. Please enter a valid option (0-" << permanentItems.size() << "): ";
                std::cin >> choice;
            }
            if (choice == 0) {
                std::cout << "Returning to inventory menu." << std::endl;
                return;
            } else {
                Item* selectedItem = permanentItems[choice - 1];
                attackinventory.push_back(selectedItem);
            }
        } while (true);
}

void Backpack::showConsumableItems(Player& player, StrongZombie& zombie) {
        int choice;
        do {
            std::cout << "Consumable Items:" << std::endl;
            for (int i = 0; i < consumableItems.size(); ++i) {
                std::cout << "[" << i + 1 << "]. " << consumableItems[i]->getName() << " (stock = " << itemStock[consumableItems[i]->getName()] << ")" << std::endl;
            }
            std::cout << "[0]. Back to inventory menu" << std::endl;
            std::cout << "Enter your choice: ";
            std::cin >> choice;
            while (std::cin.fail() || choice < 0 || choice > consumableItems.size()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid choice. Please enter a valid option (0-" << consumableItems.size() << "): ";
                std::cin >> choice;
            }

            if (choice == 0) {
                std::cout << "Returning to inventory menu." << std::endl;
                return;
            } else {
                Item* selectedItem = consumableItems[choice - 1];
                selectedItem->use(player, zombie);
                updateConsumableItemStock(selectedItem->getName());
            }
        } while (true);
}

void Backpack::showThrowableItems(Player& player, StrongZombie& zombie) {
        int choice;
        do {
            std::cout << "Throwable Items:" << std::endl;
            for (int i = 0; i < throwableItems.size(); ++i) {
                std::cout << "[" << i + 1 << "]. " << throwableItems[i]->getName() << " (stock = " << itemStock[throwableItems[i]->getName()] << ")" << std::endl;
            }
            std::cout << "[0]. Back to inventory menu" << std::endl;
            std::cout << "Enter your choice: ";
            std::cin >> choice;
            while (std::cin.fail() || choice < 0 || choice > throwableItems.size()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid choice. Please enter a valid option (0-" << throwableItems.size() << "): ";
                std::cin >> choice;
            }

            if (choice == 0) {
                std::cout << "Returning to inventory menu." << std::endl;
                return;
            } else {
                Item* selectedItem = throwableItems[choice - 1];
                selectedItem->use(player, zombie);
                updateThrowableItemStock(selectedItem->getName());
            }
        } while (true);
}

#ifndef BACKPACK_H
#define BACKPACK_H


#include "Item.h"
#include "permanentItem.h"
#include "consumableItem.h"
#include "throwableItem.h"
#include <vector>
#include <map>
#include <algorithm>


class Player;
class Backpack
{
private:
    std::vector<Item*> permanentItems;
    std::vector<Item*> consumableItems;
    std::vector<Item*> throwableItems;
    std::vector<Item*> attackinventory;

    std::map<std::string, int> itemStock; // Map to keep track of item stock

public:

    void addPermanentItem(Item* item);
    void addConsumableItem(Item* item);
    void addThrowableItem(Item* item);

    std::map<std::string, int> getItemStock() const;

    void showInventoryMenu(Player& player, StrongZombie& zombie);
    void showPermanentItems(Player& player, StrongZombie& zombie);
    void showConsumableItems(Player& player, StrongZombie& zombie);
    void showThrowableItems(Player& player, StrongZombie& zombie);

private:
    Item* findItem(const std::string& itemName, const std::vector<Item*>& items);
    void updateItemStock(const std::string& itemName, std::vector<Item*>& items);
    void updatePermanentItemStock(const std::string& itemName);
    void updateConsumableItemStock(const std::string& itemName);
    void updateThrowableItemStock(const std::string& itemName);
};

#endif //BACKPACK_H
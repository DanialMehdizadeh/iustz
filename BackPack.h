#ifndef BACKPACK_H
#define BACKPACK_H


#include "Item.h"
#include "permanentItem.h"
#include "consumableItem.h"
#include "throwableItem.h"
#include <vector>
#include <sstream>
#include <map>
#include <algorithm>


class Player;
class Backpack
{
private:
    std::vector<Item*> permanentItems;
    std::vector<Item*> consumableItems;
    std::vector<Item*> throwableItems;
    std::string equipedWeapon = "Hands";

    std::map<std::string, int> itemStock; // Map to keep track of item stock

public:

    void addPermanentItem(Item* item);
    void addConsumableItem(Item* item);
    void addThrowableItem(Item* item);

    std::map<std::string, int> getItemStock() const;

    void showInventoryMenu(Player& player, Enemy* enemy,bool &isEnemysTurn);
    void showPermanentItems(Player& player, Enemy* enemy,bool &isEnemysTurn);
    void showConsumableItems(Player& player, Enemy* enemy,bool &isEnemysTurn);
    void showThrowableItems(Player& player, Enemy* enemy,bool &isEnemysTurn, bool &isUsed);
    void saveBackPack(std::ofstream &file);
    void loadBackPack(const std::string& filename);

private:
    Item* findItem(const std::string& itemName, const std::vector<Item*>& items);
    void updateItemStock(const std::string& itemName, std::vector<Item*>& items);
    void updatePermanentItemStock(const std::string& itemName);
    void updateConsumableItemStock(const std::string& itemName);
    void updateThrowableItemStock(const std::string& itemName);
};

#endif //BACKPACK_H
#include <iostream>
#include <string>
#include <cstdlib> 
#include <vector>

using namespace std;

// Forward declaration of Enemy class
class Enemy;

// Base class for all items
class Item
{
protected:
    string name;
    int price;

public:
    Item(string _name, int _price) : name(_name), price(_price) {}

    virtual void use()
    {
        // Placeholder for future use
    }

    string getName() const
    {
        return name;
    }

    int getPrice() const
    {
        return price;
    }
};

// Derived class for consumable items
class Consumable : public Item
{
public:
    Consumable(string _name, int _price) : Item(_name, _price) {}

    virtual void use()
    {
        // Placeholder for future use
    }
};

// Derived class for health potions
class HealthPotion : public Consumable
{
    int effectValue;

public:
    HealthPotion(string _name, int _price, int _effectValue) : Consumable(_name, _price), effectValue(_effectValue) {}

    void use() override
    {
        cout << "Consumed " << getName() << " and gained " << effectValue << " health." << endl;
    }
};

// Derived class for energy drinks
class EnergyDrink : public Consumable
{
    int effectValue;

public:
    EnergyDrink(string _name, int _price, int _effectValue) : Consumable(_name, _price), effectValue(_effectValue) {}

    void use() override
    {
        cout << "Consumed " << getName() << " and gained " << effectValue << " energy." << endl;
    }
};

// Class for representing enemies
class Enemy
{
    string name;
    int health;

public:
    Enemy(string _name, int _health) : name(_name), health(_health) {}

    void takeDamage(int damage)
    {
        health -= damage;
        cout << name << " received " << damage << " damage. Remaining health: " << health << endl;
    }
};

// Derived class for throwable items
class Throwable : public Item
{
public:
    Throwable(string _name, int _price) : Item(_name, _price) {}

    void use(Enemy& enemy)
    {
        cout << "Threw " << getName() << " at the enemy." << endl;
        enemy.takeDamage(10); // Assuming the grenade causes 10 damage to the enemy
    }
};

// Class for representing the player's backpack
class Backpack
{
    vector<Item*> items;

public:
    void addItem(Item* item, int quantity)
    {
        for (int i = 0; i < quantity; ++i)
        {
            items.push_back(item);
        }
        cout << "Added " << quantity << " " << item->getName() << " to your backpack." << endl;
    }
};

// Class for the shop
class Shop
{

    vector<Item*> items;

public:

    void addItem(Item* item)
    {
        items.push_back(item);
    }

    void displayItems()
    {
        cout << "Items available in the shop:" << endl;
        for (size_t i = 0; i < items.size(); ++i)
        {
            cout << i + 1 << ". " << items[i]->getName() << " - Price: " << items[i]->getPrice() << endl;
        }
    }

    Item* getItem(int choice)
    {
        if (choice < 1 || choice > items.size())
        {
            cout << "Invalid choice! Please choose an item from the list." << endl;
            return nullptr;
        }
        return items[choice - 1];
    }

    size_t getItemCount() const
    {
        return items.size();
    }
};




void Story(string name) {
    cout << "there's a survivor named " << name <<".\n"
    << "They're thrown into a chaotic world, where they fight to hold onto their humanity.\n"
    << "In this harsh reality, " << name << " encounters both kind and cruel individuals.\n"
    << "They learn to survive in unknown places and find peace in memories and friendships.\n"
    << "Despite the dangers, " << name << " perseveres. They're determined to find redemption in a world where survival is crucial.";
}

int main() 
{
    
    cout << "In this world torn apart by the Cordyceps fungus outbreak,\n"
    << "once-thriving cities now lay in ruins, overgrown with nature's relentless reclaiming.\n"
    << "Buildings stand as hollow shells, haunted by the echoes of lost lives and abandoned dreams.\n"
    << "The streets, once bustling with activity, now echo with the eerie silence of decay.\n"
    << "Write your character's name :\n";
    string name;
    getline(cin, name);
    Story(name);



    // Creating items
    HealthPotion healthPotion("Health Potion", 10, 20);
    EnergyDrink energyDrink("Energy Drink", 15, 30);
    Throwable grenade("Grenade", 25);



    // Creating shop
    Shop shop;
    shop.addItem(&healthPotion);
    shop.addItem(&energyDrink);
    shop.addItem(&grenade);



    // Displaying items in the shop
    shop.displayItems();



    // Choosing an item from the shop
    int choice;
    int quantity;
    
    do {
        cout << "Choose an item from the shop (1-" << shop.getItemCount() << "): ";
        cin >> choice;



        // Check if choice is valid
        Item* selectedItem = shop.getItem(choice);
        if (selectedItem != nullptr)
        {
            cout << "Enter quantity: ";
            cin >> quantity;

            if (quantity > 0)
            {
                // Add the selected item to the backpack
                Backpack backpack;
                backpack.addItem(selectedItem, quantity);
                break;
            }
            else
            {
                cout << "Quantity must be greater than zero." << endl;
            }
        }
    } while (choice < 1 || choice > shop.getItemCount());

return 0;
}

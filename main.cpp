#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

// Forward declaration for  classes

class Item;
class Backpack;
class Shop;
class Enemy;

class Player
{
private:

Backpack backpack;

protected:
    int money = 100;

    int getMoney()
    {
        return money;
    }

    void setMoney (int newMoney)
    {
        money = newMoney;
    }
public:

    void visitStore(Shop& shop)
    {
        shop.startShopping(*this);
    }

    void addItemToBackpack(Item* item, int quantity)
    {
        backpack.addItem(item, quantity);
    }

};


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

class PermanentItem : public Item
{
public:

    PermanentItem(string _name, int _price) : Item(_name, _price) {}

    virtual void use()
    {
        // Placeholder for future use
    }

};

class Weapon : public PermanentItem
{
protected:

    int damage;

public:

    Weapon(string _name, int _price, int _damage) : PermanentItem(_name, _price), damage(_damage) {}

    virtual void use()
    {
        // Placeholder for future use
    }
};

class ColdWeapon : public Weapon
{
public:

    ColdWeapon(string _name, int _price, int _damage) : Weapon(_name, _price, _damage) {}

    virtual void use()
    {
        // Placeholder for future use
    }

};

class HotWeapon : public Weapon
{
public:

    HotWeapon(string _name, int _price, int _damage) : Weapon(_name, _price, _damage) {}

    virtual void use()
    {
        // Placeholder for future use
    }

};

class Rifle : public HotWeapon
{
public:

    Rifle(string _name, int _price, int _damage) : HotWeapon(_name, _price, _damage) {}

    void use() 
    {
        cout << "Fired " << getName() << " and dealt " << damage << " damage." << endl;
    }

};

class Pistol : public HotWeapon
{
public:

    Pistol(string _name, int _price, int _damage) : HotWeapon(_name, _price, _damage) {}

    void use() 
    {
        cout << "Fired " << getName() << " and dealt " << damage << " damage." << endl;
    }

};


class Shotgun : public HotWeapon
{
public:

    Shotgun(string _name, int _price, int _damage) : HotWeapon(_name, _price, _damage) {}

    void use() 
    {
        cout << "Fired " << getName() << " and dealt " << damage << " damage." << endl;
    }

};

class Knife : public ColdWeapon
{
public:

    Knife(string _name, int _price, int _damage) : ColdWeapon(_name, _price, _damage) {}

    void use() 
    {
        cout << "Stabbed with " << getName() << " and dealt " << damage << " damage." << endl;
    }

};

class Katana : public ColdWeapon
{
public:

    Katana(string _name, int _price, int _damage) : ColdWeapon(_name, _price, _damage) {}

    void use() 
    {
        cout << "Slashed with " << getName() << " and dealt " << damage << " damage." << endl;
    }

};

class Axe : public ColdWeapon
{
public:

    Axe(string _name, int _price, int _damage) : ColdWeapon(_name, _price, _damage) {}

    void use() 
    {
        cout << "Swung " << getName() << " and dealt " << damage << " damage." << endl;
    }
};

class Consumable : public Item
{
public:

    Consumable(string _name, int _price) : Item(_name, _price) {}

    virtual void use()
    {
        // Placeholder for future use
    }
};

class HealthBooster : public Consumable
{

    int effectValue;
    
public:

    HealthBooster(string _name, int _price, int _effectValue) : Consumable(_name, _price), effectValue(_effectValue) {}

    void use() override
    {
        cout << "Consumed " << getName() << " and gained " << effectValue << " health." << endl;
    }
};

class StaminaBooster : public Consumable
{
    int effectValue;

public:
    StaminaBooster(string _name, int _price, int _effectValue) : Consumable(_name, _price), effectValue(_effectValue) {}

    void use() override
    {
        cout << "Consumed " << getName() << " and gained " << effectValue << " stamina." << endl;
    }
};

class HealthPotion : public HealthBooster
{

public:

    HealthPotion(string _name, int _price, int _effectValue) : HealthBooster(_name, _price, _effectValue) {}
};

class CannedFood : public HealthBooster
{

public:

    CannedFood(string _name, int _price, int _effectValue) : HealthBooster(_name, _price, _effectValue) {}
};

class EnergyDrink : public StaminaBooster
{

public:

    EnergyDrink(string _name, int _price, int _effectValue) : StaminaBooster(_name, _price, _effectValue) {}
};

class ChocolateBar : public StaminaBooster
{

public:

    ChocolateBar(string _name, int _price, int _effectValue) : StaminaBooster(_name, _price, _effectValue) {}
};

class Throwable : public Item
{
public:

    Throwable(string _name, int _price) : Item(_name, _price) {}

    void use(Enemy& enemy) 
    {
        cout << "Threw " << getName() << " at the enemy." << endl;
        enemy.takeDamage(10); // Assuming the throwable item causes 10 damage to the enemy
    }
};

class Molotov : public Throwable
{

public:

    Molotov(string _name, int _price) : Throwable(_name, _price) {}
};

class Brick : public Throwable
{
public:

    Brick(string _name, int _price) : Throwable(_name, _price) {}

};

class Grenade : public Throwable
{
public:

    Grenade(string _name, int _price) : Throwable(_name, _price) {}
};


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

class Shop {
public:
    void startShopping(Player& player)
    {
        int choice;
        do {
            cout << "You entered the store." << endl;
            cout << "[1]. Permanent Items" << endl;
            cout << "[2]. Consumable Items" << endl;
            cout << "[3]. Throwable Items" << endl;
            cout << "[0]. Exit" << endl;
            cout << "Enter your choice: ";
            cin >> choice;
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
                    cout << "Exiting the store." << endl;
                    break;
                default:
                    cout << "Invalid choice. Please try again." << endl;
            }
        } while (choice != 0);
    }

    void shopPermanentItems(Player& player)
    {

        int choice;
        int w1 =1;
        int w2 =1;
        int w3 =1;
        int w4 =1;
        int w5 =1;
        int w6 =1;
         
 
        // Vector of pointers to stock variables
        vector<int*> stockPointers = { &w1  , &w2 , &w3  , &w4  , &w5 , &w6 };

    do {
        cout << "You go to take a look at the Permanent Items : (your money: " << player.getMoney() << "$)" << endl;
        cout << "You need to select a permanent item:" << endl;
        cout << "          <. HotWeapon .>" << endl;
        cout << "[1]. Rifle (-10HP) / stock: " <<  *stockPointers[0] << " / price: (25$)" << endl;
        cout << "[2]. Pistol (-10HP) / stock: " << *stockPointers[1] << " / price: (25$)" << endl;
        cout << "[3]. Shotgun (-10HP) / stock: " << *stockPointers[2] << " / price: (25$)" << endl;
        cout << "          <. ColdWeapon .>" << endl;
        cout << "[4]. Knife (-10HP) / stock: " << *stockPointers[3] << " / price: (15$)" << endl;
        cout << "[5]. Katana (-10HP) / stock: " << *stockPointers[4] << " / price: (15$)" << endl;
        cout << "[6]. Axe (-10HP) / stock: " << *stockPointers[5] << " / price: (15$)" << endl;
        cout << "[0]. Back" << endl;
        cout << "Enter your choice: ";

        cin >> choice;

        switch (choice)
        {
            case 1:
                if (player.getMoney() >= 25 && *stockPointers[0] > 0)
                {
                    player.setMoney(player.getMoney() - 25);
                    cout << "Successful purchase! Added Rifle to your backpack." << endl;
                    player.addItemToBackpack(new Rifle("Rifle", 25, -10), 1);
                    (*stockPointers[0])--; // Decrease stock of rifles
                }
                else if (player.getMoney() < 25)
                {
                    cout << "Not enough money to purchase Rifle!" << endl;
                }
                else
                {
                    cout << "Rifle out of stock!" << endl;
                }
                break;

            case 2:
                if (player.getMoney() >= 25 && *stockPointers[1] > 0)
                {
                    player.setMoney(player.getMoney() - 25);
                    cout << "Successful purchase! Added Pistol to your backpack." << endl;
                    player.addItemToBackpack(new Pistol("Pistol", 25, -10), 1);
                    (*stockPointers[1])--; // Decrease stock of pistols
                }
                else if (player.getMoney() < 25)
                {
                    cout << "Not enough money to purchase Pistol!" << endl;
                }
                else
                {
                    cout << "Pistol out of stock!" << endl;
                }
                break;
                
            case 3:
               if (player.getMoney() >= 25 && *stockPointers[2] > 0)
               {
                   player.setMoney(player.getMoney() - 25);
                   cout << "Successful purchase! Added Shotgun to your backpack." << endl;
                   player.addItemToBackpack(new Shotgun("Shotgun", 25, -10), 1);
                   (*stockPointers[2])--; // Decrease stock of shotguns
                }
                else if (player.getMoney() < 25)
                {
                   cout << "Not enough money to purchase Shotgun!" << endl;
                }
                else
                {
                   cout << "Shotgun out of stock!" << endl;
                }
                break;    

            case 4:
                 if (player.getMoney() >= 15 && *stockPointers[3] > 0)
                 {
                     player.setMoney(player.getMoney() - 15);
                     cout << "Successful purchase! Added Knife to your backpack." << endl;
                     player.addItemToBackpack(new Knife("Knife", 15, -10), 1);
                     (*stockPointers[3])--; // Decrease stock of knives
                }
                else if (player.getMoney() < 15)
                {
                    cout << "Not enough money to purchase Knife!" << endl;
                }
                else
                {
                    cout << "Knife out of stock!" << endl;
                }
                break;

            case 5:
                 if (player.getMoney() >= 15 && *stockPointers[4] > 0)
                 {
                     player.setMoney(player.getMoney() - 15);
                     cout << "Successful purchase! Added Katana to your backpack." << endl;
                     player.addItemToBackpack(new Katana("Katana", 15, -10), 1);
                     (*stockPointers[4])--; // Decrease stock of katanas
                }
                else if (player.getMoney() < 15)
                {
                     cout << "Not enough money to purchase Katana!" << endl;
                }
                else
                {
                     cout << "Katana out of stock!" << endl;
                }
                break;

            case 6:
                if (player.getMoney() >= 15 && *stockPointers[5] > 0)
                {
                     player.setMoney(player.getMoney() - 15);
                     cout << "Successful purchase! Added Axe to your backpack." << endl;
                     player.addItemToBackpack(new Axe("Axe", 15, -10), 1);
                     (*stockPointers[5])--; // Decrease stock of axes
                }
                else if (player.getMoney() < 15)
                {
                     cout << "Not enough money to purchase Axe!" << endl;
                }
                else
                {
                     cout << "Axe out of stock!" << endl;
                }
                break;  

            case 0:

                cout << "Returning to main shop menu." << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 0);
    startShopping(player);
}  
    

    void shopConsumableItems(Player& player)
    {
        
     int choice;  
     int c1 =3;
     int c2 =3;
     int c3 =3;
     int c4 =3;

        // Vector of pointers to stock variables
        vector<int*> stockPointers_of_Consumable = { &c1  , &c2 , &c3  , &c4 };

    do {
        cout << "You go to take a look at the Consumable Items : (your money: " << player.getMoney() << "$)" << endl;
        cout << "You need to select a Consumable Item:" << endl;
        cout << "          <. HealthBooster .>" << endl;
        cout << "[1]. HealthPotion (+10 HP) / stock: " <<  *stockPointers_of_Consumable[0] << " / price: (10$)" << endl;
        cout << "[2]. CannedFood (+10 HP) / stock: " << *stockPointers_of_Consumable[1] << " / price: (10$)" << endl;
        cout << "          <. StaminaBooster .>" << endl;
        cout << "[3]. EnergyDrink (+10 ST) / stock: " << *stockPointers_of_Consumable[2] << " / price: (10$)" << endl;
        cout << "[4]. ChocolateBar (+10 ST) / stock: " << *stockPointers_of_Consumable[3] << " / price: (10$)" << endl;
        cout << "[0]. Back" << endl;

        cout << "Enter your choice: ";

        cin >> choice;

        switch (choice)
        {

            case 1:
                if (player.getMoney() >= 10 && *stockPointers_of_Consumable[0] > 0)
                {
                    player.setMoney(player.getMoney() - 10);
                    cout << "Successful purchase! Added  1x HealthPotion to your backpack." << endl;
                    player.addItemToBackpack(new HealthPotion("HealthPotion", 10, +10), 1);
                    (*stockPointers_of_Consumable[0])--; // Decrease stock of rifles
                }
                else if (player.getMoney() < 10)
                {
                    cout << "Not enough money to purchase HealthPotion!" << endl;
                }
                else
                {
                    cout << "HealthPotion out of stock!" << endl;
                }
                break;

            case 2:

                if (player.getMoney() >= 10 && *stockPointers_of_Consumable[1] > 0)
                {
                    player.setMoney(player.getMoney() - 10);
                    cout << "Successful purchase! Added 1x CannedFood to your backpack." << endl;
                    player.addItemToBackpack(new CannedFood("CannedFood", 10, +10), 1);
                    (*stockPointers_of_Consumable[1])--; // Decrease stock of pistols
                }
                else if (player.getMoney() < 10)
                {
                    cout << "Not enough money to purchase CannedFood!" << endl;
                }
                else
                {
                    cout << "CannedFood out of stock!" << endl;
                }
                break;
                
            case 3:

               if (player.getMoney() >= 10 && *stockPointers_of_Consumable[2] > 0)
               {
                   player.setMoney(player.getMoney() - 10);
                   cout << "Successful purchase! Added 1x EnergyDrink to your backpack." << endl;
                   player.addItemToBackpack(new EnergyDrink("EnergyDrink", 10, +10), 1);
                   (*stockPointers_of_Consumable[2])--; // Decrease stock of shotguns
                }
                else if (player.getMoney() < 10)
                {
                   cout << "Not enough money to purchase EnergyDrink!" << endl;
                }
                else
                {
                   cout << "EnergyDrink out of stock!" << endl;
                }
                break;  

            case 4:

                 if (player.getMoney() >= 10 && *stockPointers_of_Consumable[3] > 0)
                 {
                     player.setMoney(player.getMoney() - 10);
                     cout << "Successful purchase! Added 1x ChocolateBar to your backpack." << endl;
                     player.addItemToBackpack(new ChocolateBar("ChocolateBar", 10, +10), 1);
                     (*stockPointers_of_Consumable[3])--; // Decrease stock of knives
                }
                else if (player.getMoney() < 10)
                {
                    cout << "Not enough money to purchase ChocolateBar!" << endl;
                }
                else
                {
                    cout << "ChocolateBar out of stock!" << endl;
                }
                break;

            case 0:

                cout << "Returning to main shop menu." << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;

        }

    } while (choice != 0);
    startShopping(player);
  }

    void shopThrowableItems(Player& player)
    {

        int choice;
        int t1 =3;
        int t2 =3;
        int t3 =3;
         
 
        // Vector of pointers to stock variables
        vector<int*> stockPointers_of_Throwable = { &t1  , &t2 , &t3  };

    do {
        cout << "You go to take a look at the Throwable Items : (your money: " << player.getMoney() << "$)" << endl;
        cout << "You need to select a Throwable Item:" << endl;
        cout << "[1]. Molotov (-10HP) / stock: " <<  *stockPointers_of_Throwable[0] << " / price: (15$)" << endl;
        cout << "[2]. Brick (-10HP) / stock: " << *stockPointers_of_Throwable[1] << " / price: (15$)" << endl;
        cout << "[3]. Grenade (-10HP) / stock: " << *stockPointers_of_Throwable[2] << " / price: (15$)" << endl;
        cout << "[0]. Back" << endl;

        cout << "Enter your choice: ";

        cin >> choice;

        switch (choice)
        {
            case 1:
                if (player.getMoney() >= 15 && *stockPointers_of_Throwable[0] > 0)
                {
                    player.setMoney(player.getMoney() - 15);
                    cout << "Successful purchase! Added 1x Molotov to your backpack." << endl;
                    player.addItemToBackpack(new Molotov("Molotov", 15 ), 1);
                    (*stockPointers_of_Throwable[0])--; // Decrease stock of rifles
                }
                else if (player.getMoney() < 15)
                {
                    cout << "Not enough money to purchase Molotov!" << endl;
                }
                else
                {
                    cout << "Molotov out of stock!" << endl;
                }
                break;

            case 2:
                if (player.getMoney() >= 15 && *stockPointers_of_Throwable[1] > 0)
                {
                    player.setMoney(player.getMoney() - 15);
                    cout << "Successful purchase! Added 1x Brick to your backpack." << endl;
                    player.addItemToBackpack(new Brick("Brick", 15 ), 1);
                    (*stockPointers_of_Throwable[1])--; // Decrease stock of pistols
                }
                else if (player.getMoney() < 15)
                {
                    cout << "Not enough money to purchase Brick!" << endl;
                }
                else
                {
                    cout << "Brick out of stock!" << endl;
                }
                break;
                
            case 3:
               if (player.getMoney() >= 15 && *stockPointers_of_Throwable[2] > 0)
               {
                   player.setMoney(player.getMoney() - 15);
                   cout << "Successful purchase! Added 1x Grenade to your backpack." << endl;
                   player.addItemToBackpack(new Grenade("Grenade", 15 ), 1);
                   (*stockPointers_of_Throwable[2])--; // Decrease stock of shotguns
                }
                else if (player.getMoney() < 15)
                {
                   cout << "Not enough money to purchase Grenade!" << endl;
                }
                else
                {
                   cout << "Grenade out of stock!" << endl;
                }
                break;      

            case 0:

                cout << "Returning to main shop menu." << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 0);
    startShopping(player);
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

    
    return 0;
}




  

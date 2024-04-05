#ifndef SHOP_H
#define SHOP_H

#include "Item.h"

#include <vector>

class Player;
class Shop {
public:
    
    void startShopping(Player& player);
    void shopPermanentItems(Player& player);
    void shopConsumableItems(Player& player);
    void shopThrowableItems(Player& player);
    int w1 =1;
    int w2 =1;
    int w3 =1;
    int w4 =1;
    int w5 =1;
    int w6 =1;
    int c1 =3;
    int c2 =3;
    int c3 =3;
    int c4 =3;
    int t1 =3;
    int t2 =3;
    int t3 =3;
};

#endif //SHOP_H
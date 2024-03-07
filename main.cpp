#include <iostream>
#include <string>
#include <cstdlib> 
#include <vector>

using namespace std;
// #include <iostream> 
// #include <string> 

// using namespace std ; 

// class player {
// protected : 
// string name ;
// string gender; 
// //choose class and special skills and stat
// //string class ;
// int age ;
// double health ; 
// double stamina ;
// int attackdamage ;
// /* define number in meeting 
//   level playerlevel ;
//   playerlevel.level = 1 ;*/
// /* diffrent skill 
// int coldweapon
// int warmweapon 
// ...
// */
// public : 
// player() {} ;
// player(string newname,double newhealth,double newstamina,int newattackdamage,int newage,string newgender) : name(newname),
// health(newhealth),stamina(newstamina),attackdamage(newattackdamage),age(newage),gender(newgender) {}; 
// player(string newname){
//     name = newname; 
// }
// player(double newhealth,double newstamina){
//     health = newhealth ; 
//     stamina = newstamina ; 
// }
// player (int newattackdamge){
//     attackdamage = newattackdamge;
// }
// player(int newage,string newgender,string newname){
//     age = newage ;
//     gender = newgender ;
//     name = newname ;
// }

// string getname() {return name ;}

// //int getlevel() {return level ; }

// double gethealth() {return health ;}

// double getstamina() {return stamina ;}

// int getattackdamage() {return attackdamage ;}

// int getage() {return age ;}
// string getgender() {return gender ;}

// };
// /*struct level 
// struct level {
// int levelnumber ;
// int strength ;
// int intelligence ;
// int agility ;
// };

// */
// /* function niaz
// void getdamage (int attackdamage) { 
// health -= attackdamage ;
// }
// void increaselevel(){
//     playerlevel.level += 1 ;
// }
// void increasestat(int number) {
//     if (number == 1 )
//     playerlevel.strengt += 1 ;
//     if (number == 2 )
//     playerlevel.strengt += 1 ;
//     if (number == 3 )
//     playerlevel.strengt += 1 ;

// }
// void staminaloss(int num) {
//     stamina -= num ; 
// }



void Story(string name) {
    cout << "there's a survivor named " << name <<".\n"
    << "They're thrown into a chaotic world, where they fight to hold onto their humanity.\n"
    << "In this harsh reality, " << name << " encounters both kind and cruel individuals.\n"
    << "They learn to survive in unknown places and find peace in memories and friendships.\n"
    << "Despite the dangers, " << name << " perseveres. They're determined to find redemption in a world where survival is crucial.";
}

int main() {
    cout << "In this world torn apart by the Cordyceps fungus outbreak,\n"
    << "once-thriving cities now lay in ruins, overgrown with nature's relentless reclaiming.\n"
    << "Buildings stand as hollow shells, haunted by the echoes of lost lives and abandoned dreams.\n"
    << "The streets, once bustling with activity, now echo with the eerie silence of decay.\n"
    << "Write your character's name :\n";
    string name;
    getline(cin, name);
    Story(name);
}

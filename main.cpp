#include <iostream>
#include <string>
#include <cstdlib> 
#include <vector>

using namespace std;

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

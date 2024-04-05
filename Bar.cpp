#include "Bar.h"

void zombieHealthBar(int current, int max, int increment) {
    std::string bar = "";
    for (int i = 0; i < (max / increment); i++) {
        if (current > 0) {
            bar += "\U0001F49A"; //  Green Heart emoji(💚) is U+1F49A.
        } else {
            bar += ".";
        }
        current -= increment;
    }
    // Print the colored bar and numbers
    std::cout << "[";
    SetConsoleColor(2);
    std::cout << bar;
    SetConsoleColor(7);
    std::cout << "] " << current + max << "/" << max;
}

void playerHealthBar(int current, int max, int increment) {
    std::string bar = "";
    for (int i = 0; i < (max / increment); i++) {
        if (current > 0) {
            bar += "\u2764\uFE0F"; // Heart emoji: ❤️ (U+2764)
        } else {
            bar += ".";
        }
        current -= increment;
    }
    // Print the colored bar and numbers
    std::cout << "[";
    SetConsoleColor(12);
    std::cout << bar;
    SetConsoleColor(7);
    std::cout << "] " << current + max << "/" << max;
}
void staminaBar (int current, int max, int increment) {
    std::string bar = "";
    for (int i = 0; i < (max / increment); i++) {
        if (current > 0) {
            bar += "\u26A1"; //  Lightning Bolt: ⚡ (U+26A1)
        } else {
            bar += ".";
        }
        current -= increment;
    }
    // Print the colored bar and numbers
    std::cout << "[";
    SetConsoleColor(6);
    std::cout << bar;
    SetConsoleColor(7);
    std::cout << "] " << current + max << "/" << max;
}
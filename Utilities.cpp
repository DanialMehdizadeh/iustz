#include "Utilities.h"
#include <chrono>
#include <thread>

void TypeSlow (std::string print, int i)
{
	while ( print [i] != '\0')
	{
	    std::cout << print[i];
		Sleep(300);
		i++;
	}
}	
		
void TypeFast (std::string print, int i)
{
	while ( print [i] != '\0')
	{
	    std::cout << print[i];
		Sleep(10);
		i++;
	}
}


void SetConsoleColor(int val)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), val);
    //(Black: 0)(Blue: 1)(Green: 2)(Cyan: 3)(Red: 4)(Magenta: 5)(Yellow: 6)(White: 7)(Gray: 8)
    //(Intense Blue: 9)(Intense Green: 10)(Intense Cyan: 11)(Intense Red: 12)(Intense Magenta: 13)(Intense Yellow: 14)(Bright White: 15)
    //Background Colors: (Black: 0)(Blue: 16)(Green: 32)(Cyan: 48)(Red: 64)(Magenta: 80)(Yellow: 96)(White: 112)
}
void gotoxy(int x, int y)
// Function to set the cursor position to the specified coordinates (x, y) on the console window.
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


// Function to read names from the file into a vector
std::vector<std::string> readFromFile(const std::string& filename) {
    std::vector<std::string> lines;
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string line;
        while (getline(file, line)) {
            lines.push_back(line);
        }
        file.close();
    } else {
        std::cerr << "\t\t\t\t"  << "Error: Unable to open file: " << filename << std::endl;
    }
    return lines;
}
// Function to choose a random name from the vector
std::string chooseRandomLine(const std::vector<std::string>& lines) {
    int randomIndex = rand() % lines.size();
    return lines[randomIndex];
}

void printAscii(){
    std::vector<std::string> ascii = readFromFile("ASCII-Designer.txt");
    for (int i = 0; i <= ascii.size(); i++)
    {
        TypeFast(ascii[i], 0);
        if (i != ascii.size() -1) {
            std::cout<<std::endl;
        }
    }
}

void ScreenShake(int intensity, int duration) {
    auto start = std::chrono::steady_clock::now();
    auto end = start + std::chrono::milliseconds(duration);

    while (std::chrono::steady_clock::now() < end) {
        int dx = rand() % (2 * intensity) - intensity;
        int dy = rand() % (2 * intensity) - intensity;
        HWND hwnd = GetConsoleWindow();
        RECT rect;
        GetWindowRect(hwnd, &rect);
        MoveWindow(hwnd, rect.left + dx, rect.top + dy, rect.right - rect.left, rect.bottom - rect.top, TRUE);
        std::this_thread::sleep_for(std::chrono::milliseconds(20)); // Adjust the delay for shake intensity
    }
}
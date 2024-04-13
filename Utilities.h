#ifndef UTILITIES_H
#define UTILITIES_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <windows.h>


void TypeSlow(std::string print, int i);
void TypeFast(std::string print, int i);
void SetConsoleColor(int val);
void gotoxy(int x, int y);
std::vector<std::string> readFromFile(const std::string& filename);
std::string chooseRandomLine(const std::vector<std::string>& lines);
void printAscii();
void ScreenShake(int intensity, int duration) ;

#endif // UTILITIES_H
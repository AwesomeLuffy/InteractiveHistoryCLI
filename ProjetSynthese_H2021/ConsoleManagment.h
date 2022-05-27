#pragma once
#include <iostream>
#include <string>
#include <Windows.h>
#include "Functions.h"
using namespace std;

void placeCursor(unsigned int x, unsigned int y);
void placeFixPosCursor(string name, unsigned int x, unsigned int y);
COORD GetConsoleCursorPosition();
void printMsgInColor(string colorChoice, string backgroundChoice);
void printTransition(string transition);
void snakeTransition();
void squareTransition();
void circleTransition();
void printSquare(char character, string color, unsigned int L, unsigned int l);
void printSquareFromFixPos(char character, string fixPos, string color, unsigned int L, unsigned int l);
void defaultSquare();
map<string, vector<int>> getFixPos();
map<string, int> getColors();
int printMsgFromFixPos(string msg, string fixPos, string color, unsigned int Lsquare);
void printMsgInSquare(string msg, string fixPos, string color, unsigned int width, char caracter);
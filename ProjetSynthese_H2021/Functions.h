#pragma once
#include <ctime>
#include <iostream>
#include <string>
#include "Character.h"
#include "FileManagment.h"
#include <Windows.h>
#include <map>

int ranDice(int max, int min);
Character createCharacter(bool rdm);
void fightCharacters(Character mainUser);
string replaceString(string text, string characterName, string weaponName, string placeName);
string getKey(int x, int y, int z);
bool checkEnd(vector<vector<int>> choices);
void readHistory(string name);
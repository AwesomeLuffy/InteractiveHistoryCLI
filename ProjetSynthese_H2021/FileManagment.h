#pragma once
#include "FileManagment.h"
#include "ListeHistoire.h"
#include "Character.h"
#include "Structs.h"
#include "Functions.h"
#include <filesystem>
#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

void initVecHist(History &history);
void initVecChoice(vector<vector<int>>&v, string sent);
History getHistoryFile(); //Fonction qui crée l'histoire
string getCharacterFile(); //Fonction pour obtenir les information d'un personnage
string getPlaceFile();//Fonction pour obtenir les lieux
void getWeaponFile(Character &character);//Recupérer le fichier pour les armes du personnage
void setHistoryFile(ListeHistoire listehistoire, string name); //FOnction pour crée un fichier texte et mettre l'histoire qui vient d'être terminer dedans
vector<string> getHistoryByFile(string name); //Fonction qui récupère toute les bulles (les textes choisit) d'une histoire
void getHistories();//Pour récupérer la liste de toute les histoires


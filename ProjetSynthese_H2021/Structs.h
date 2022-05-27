#pragma once
#include <string>
#include <vector>
#include <map>
using namespace std;

struct History {
	vector<vector<vector<string>>> history; //1D -> Which history // 2D -> Which branch // 3D -> Where
	map<string, vector<vector<int>>> choices;
	int x, y, z, xx, yy;
}; 
struct Objet
{
	string nom = "";
	int degat = 0;
};
struct Nom
{
	string personnage = "";
	string lieu = "";
	Objet objet;
};
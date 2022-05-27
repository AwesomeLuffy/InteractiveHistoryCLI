#include "Functions.h"
using namespace std;



int ranDice(int max, int min) {
	return rand() % max + (min);
}

Character createCharacter(bool rdm) {
	Character character;
	string name;
	if (rdm) { name = getCharacterFile(); }
	else {
		cout << "Entrez un nom" << endl;
		cin >> name;
	}
	character = Character(name);
	getWeaponFile(character);
	return character;
}

void fightCharacters(Character mainUser) {
	Character enemy = createCharacter(true);
	vector<string> Santences = { " attaque avec frénésie ",
							" se défoule sur ",
							" assène tant bien que mal un coup à ",
							" donne un coup de toute ses forces à ",
							" détruit les jambes de ",
							" prend le dessus sur ",
							" foudroie ",
							" met un coup à " };

	while (enemy.isAlive()) {
		mainUser.attack(enemy);
		enemy.attack(mainUser);
		if (!mainUser.isAlive()) { mainUser.healHP(); }
		cout << mainUser.getName() << Santences[ranDice(Santences.size(), 0)] << enemy.getName() << endl;
		//cout << mainUser.getName() << " (Vous) :" <<
		//	"HP -> " << mainUser.getHP() << endl;
		//cout << enemy.getName() << " :" <<
		//	"HP -> " << enemy.getHP() << endl << endl;
		///TODO Mise en forme affichage
	}
}


string replaceString(string text, string characterName, string weaponName, string placeName) {
	while (text.find("NOM") != string::npos || text.find("OBJET") != string::npos || text.find("PLACE") != string::npos) {
		text.replace(text.find("NOM"), 3, characterName);
		text.replace(text.find("OBJET"), 5, weaponName);
		text.replace(text.find("PLACE"), 5, placeName);
	}
	return text;
}

string getKey(int x, int y, int z) {
	return to_string(x) + to_string(y) + to_string(z);
}

bool checkEnd(vector<vector<int>> choices) {

	if (choices[0][0] == -1 && choices[0][1] == -1 && choices[0][2] == -1) {
		return true;
	}
	return false;
}

void readHistory(string name) {
	vector<string>bubbles = getHistoryByFile(name);
	cout << bubbles[0];

	for (int i = 0; i < bubbles.size(); i++) {
		system("cls");
		cout << bubbles[i];
		system("pause");
	}
}

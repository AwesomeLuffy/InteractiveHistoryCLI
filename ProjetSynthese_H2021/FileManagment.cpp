#include "FileManagment.h"

void initVecHist(History &history) {
	string lineRead = "", actRead = "";
	string const fileName("./datFile/history1.dat");
	stringstream lineStream, diviseChoices, diviseNumberChoice;
	fstream readFile;
	readFile.open(fileName, fstream::in);
	int maxX = -1, maxY = -1, maxZ = -1, maxXChoice = -1, maxYChoice = -1, numberChoice = 0;
	bool isSuccess = false;
	if (readFile) {
		do {
			getline(readFile, lineRead);
			if (!readFile.eof()) {
				lineStream.clear();
				lineStream << lineRead;
				getline(lineStream, actRead, ';');
				history.x = stoi(actRead);
				(maxX > history.x) ? maxX = maxX : maxX = history.x;
				getline(lineStream, actRead, ';');
				history.y = stoi(actRead);
				(maxY > history.y) ? maxY = maxY : maxY = history.y;
				getline(lineStream, actRead, ';');
				history.z = stoi(actRead);
				(maxZ > history.z) ? maxZ = maxZ : maxZ = history.z;
				getline(lineStream, actRead, ';');
			}
		} while (!readFile.eof());
	}
	else { cout << "FILE NOT FOUND"; }
	readFile.close();

	maxX += 1; maxY += 1; maxZ += 1;

	history.history.resize(maxX);
	for (int i = 0; i < maxX; i++) {
		history.history[i].resize(maxY);
		for (int j = 0; j < maxY; j++) {
			history.history[i][j].resize(maxZ);
		}
	}
}

void initVecChoice(vector<vector<int>>& v, string sent) {
	string actRead = "";
	stringstream diviseChoices, diviseNumberChoice;
	int maxXChoice = 0, maxYChoice = 0, actualX = -1, actualY = -1;
	diviseChoices << sent;
	do {
		getline(diviseChoices, actRead, '$');
		maxXChoice++;
		v.clear();
	} while (!diviseChoices.eof());
	cout << endl << endl;
	v.resize(maxXChoice);
	for (int i = 0; i < maxXChoice; i++) {
		v[i].resize(3);
	}
}

History getHistoryFile() {
	History history;
	vector<vector<int>>v;
	initVecHist(history);
	string lineRead = "", actRead = "", toMap = "";
	string const fileName("./datFile/history1.dat");
	stringstream lineStream, diviseChoices, diviseNumberChoice;
	fstream readFile;
	readFile.open(fileName, fstream::in);
	int maxX = -1, maxY = -1, maxZ = -1, numberChoice = 0, h = 0, g = 0, index = 0;
	bool isSuccess = false;
	if (readFile) {
		do {
			getline(readFile, lineRead);
			if (!readFile.eof()) {
				lineStream.clear();
				lineStream << lineRead;
				getline(lineStream, actRead, ';');
				history.x = stoi(actRead);
				getline(lineStream, actRead, ';');
				history.y = stoi(actRead);
				getline(lineStream, actRead, ';');
				history.z = stoi(actRead);
				getline(lineStream, actRead, ';');
				history.history[history.x][history.y][history.z] = actRead;
				getline(lineStream, actRead, ';');
				diviseChoices.clear();
				diviseChoices << actRead;
				toMap = to_string(history.x) + to_string(history.y) + to_string(history.z);
				initVecChoice(v, actRead);
				do{
					getline(diviseChoices, actRead, '$');
					diviseNumberChoice.clear();
					diviseNumberChoice << actRead;
					index = 0;
					do{
						getline(diviseNumberChoice, actRead, ',');
						v[numberChoice][index] = stoi(actRead);
						index++;
					}while (!diviseNumberChoice.eof());
					numberChoice++;
				} while (!diviseChoices.eof());
				cout << v.size() << endl;
				system("pause");
				numberChoice = 0;
				history.choices[toMap] = v;
				
				v.clear();
			}
			
		} while (!readFile.eof());
	}
	else { cout << "FILE NOT FOUND"; }
	system("pause");
	readFile.close();
	return history;
	
}

string getCharacterFile() {
	string lineRead = "";
	string const fileName("./datFile/personnage.dat");
	fstream readFile;
	readFile.open(fileName, fstream::in);
	vector<string> name;

	if (readFile) {
		do {
			if (!readFile.eof()) {
				getline(readFile, lineRead);
				name.push_back(lineRead);
			}
		} while (!readFile.eof());
	}
	else { cout << "FILE NOT FOUND"; }
	string toReturn = name[ranDice(name.size(), 1) - 1];
	return toReturn;
}

string getPlaceFile()
{
	string lineRead = "";
	string const fileName("./datFile/lieu.dat");
	fstream readFile;
	readFile.open(fileName, fstream::in);
	vector<string> name;

	if (readFile) {
		do {
			if (!readFile.eof()) {
				getline(readFile, lineRead);
				name.push_back(lineRead);
			}
		} while (!readFile.eof());
	}
	else { cout << "FILE NOT FOUND"; }
	string toReturn = name[ranDice(name.size(), 1) - 1];
	return toReturn;
}

void getWeaponFile(Character &character) {
	string lineRead = "", actRead = "";
	string const fileName("./datFile/objet.dat");
	fstream readFile;
	readFile.open(fileName, fstream::in);
	int i = 0, j = 0;
	string weapon[20][20];
	stringstream lineStream;
	

	if (readFile) {
		do {
			getline(readFile, lineRead);
			if (!readFile.eof()) {
				lineStream.clear();
				lineStream << lineRead;
				getline(lineStream, weapon[i][j], ';');
				j++;
				getline(lineStream, weapon[i][j], ';');
				i++;
				
			}
		} while (!readFile.eof());
	}

	else { cout << "FILE NOT FOUND"; }
	readFile.close();
	int rand = ranDice(i - 1, 1);
	character.setWeapon(weapon[rand][rand], stoi(weapon[rand][rand + 1]));
	
}
void setHistoryFile(ListeHistoire histoire, string name) {
	string const fileName("./histories/" + name + ".txt");
	fstream readFile;
	readFile.open(fileName, fstream::out);

	histoire.avancer();
	if (readFile) {
		for (int i = 0; i < histoire.nombreDeBulle; i++) {
			histoire.getHistoire() = histoire.getHistoire();
			cout << histoire.getHistoire() << endl;
			readFile << histoire.getHistoire() << endl;
			if (i < histoire.nombreDeBulle) { histoire.avancer(); }
		}

	}
	else { cout << "FILE NOT FOUND"; }

	readFile.close();
}

vector<string> getHistoryByFile(string name) {
	string fileName("./histories/" + name + ".txt"), lineRead;
	vector<string>historyBubbles;
	fstream readFile;
	readFile.open(fileName, fstream::in);
	
	if (readFile) {
		do {
			if (!readFile.eof()) {
				getline(readFile, lineRead);
				historyBubbles.push_back(lineRead);
			}
		} while (!readFile.eof());
	}
	readFile.close();
	return historyBubbles;
}

void getHistories() {
	string const path("./histories");
	string file_n;
	stringstream divisePath;
	for (const auto &entry : experimental::filesystem::directory_iterator(path)) {
		divisePath.clear();
		divisePath.str("");
		divisePath << entry.path().filename();
		getline(divisePath, file_n, '.');

		cout << file_n << endl;
	}
}

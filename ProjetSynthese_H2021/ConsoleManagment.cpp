#include "ConsoleManagment.h"

void placeCursor(unsigned int x, unsigned int y) {
	HANDLE manipio = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coordinates;
	coordinates.X = x;
	coordinates.Y = y;
	SetConsoleCursorPosition(manipio, coordinates);
}
//placeCursor from a defined pos (center, right, top_right, bottom_right, left, top_left, bottom_left, top, bottom)
void placeFixPosCursor(string name, unsigned int x=0, unsigned int y=0) {
	HANDLE manipio = GetStdHandle(STD_OUTPUT_HANDLE);

	map<string, vector<int>>pos = getFixPos();

	COORD coordinates;
	coordinates.X = pos[name][0] - x;
	coordinates.Y = pos[name][1] - y;
	SetConsoleCursorPosition(manipio, coordinates);
}

COORD GetConsoleCursorPosition() {
	HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO cbsi;
	if (GetConsoleScreenBufferInfo(hConsoleOutput, &cbsi)) {
		return cbsi.dwCursorPosition;
	}
	else {
		COORD invalid = { 0, 0 };
		return invalid;
	}
}
void printMsgInColor(string colorChoice, string backgroundChoice = "") {
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	
	map<string, int>colors = getColors();

	SetConsoleTextAttribute(console, colors[colorChoice] + (colors[backgroundChoice] * 16));
}
//Function to call a transition from a name
void printTransition(string transition) {
	map<string, int> transitionToIndex{
		{"snake", 0}, {"square", 1}, {"circle", 2}
	};
	void (*funcptr[])() = { snakeTransition, squareTransition, circleTransition };
	(*funcptr[transitionToIndex[transition]])();
}

void snakeTransition() {
	system("cls");
	printMsgInColor("grey");
	char caracter;
	int speed = 70;
	int lenght = 20;
	for(int v = 0; v < 2; v++){
		(v % 2 == 0) ? caracter = '#' : caracter = ' ';
		for (int k = 0; k < 20; k++) {
			for (int i = 0; i < 6; i++) {
				for (int j = 0; j < 28 - k; j++) {
					(i % 2 == 0) ? placeCursor((20 * i) + k, j) : placeCursor((20 * i) + k, 28 - j);
					cout << caracter;
					Sleep((1000 / 28) / speed);
				}
				(i % 2 == 0) ? lenght = 21 : lenght = 20;
				for (int j = 0; j < lenght; j++) {
					(i % 2 == 0) ? placeCursor((20 * i + j) + k, 28 - k) : placeCursor((20 * i + j) + k, 0 + k);
					cout << caracter;
					Sleep((1000 / lenght) / speed);
				}
			}
		}
	}

	printMsgInColor("default");
}

void squareTransition(){
	system("cls");
	map<string, int>colors = getColors();
	map<string, vector<int>>pos = getFixPos();
	map<string, vector<int>> toErase;

	map<string, int>::iterator it_c = colors.begin();
	map<string, vector<int>>::iterator it_p = pos.begin();
	
	

	for (int i = 0; i < pos.size(); i++) {
		int x = ranDice(20, 5);
		int y = ranDice(12, 5);
		printSquareFromFixPos('#', it_p->first, it_c->first, x, y);
		toErase[it_p->first] = vector<int>{ x, y };
		it_c++;
		it_p++;
		Sleep(100);
	}

	map<string, vector<int>>::iterator it_e = toErase.begin();
	for (int i = 0; i < toErase.size(); i++) {
		printSquareFromFixPos(' ', it_e->first, "white", it_e->second[0], it_e->second[1]);
		it_e++;
		Sleep(100);
	}
}

void circleTransition() {
	int x = 119;
	int y = 28;
	int speed = 70;
	char caracter;
	for (int k = 0; k < 2; k++) {
		(k % 2 == 0) ? caracter = '#' : caracter = ' ';
		for (int i = 0; i < 15; i++) {
			for (int v = 0; v < 2; v++) {
				for (int j = x; j > (119 - x) - 1; j--) {
					(v % 2 == 0) ? placeCursor(119 - j, 28 - y) : placeCursor(j, y);
					cout << caracter;
					Sleep(50 / speed);
				}
				for (int j = y; j > (28 - y) - 1; j--) {
					(v % 2 == 0) ? placeCursor(x, 28 - j) : placeCursor((119 - x), j);
					cout << caracter;
					Sleep(50 / speed);
				}
			}
			y--;
			x--;
		}
		x = 119;
		y = 28;
	}
}

void printSquare(char character, string color, unsigned int L, unsigned int l) {
	printMsgInColor(color, "");
	int baseX, baseY;
	COORD p = GetConsoleCursorPosition();
	baseX = p.X;
	baseY = p.Y;
	for (int i = 0; i < L; i++) {
		cout << character;
	}
	for(int i = 0; i < l; i++){
		placeCursor(baseX, baseY + i);
		cout << character;
		(baseX + L == 120) ? placeCursor(119, baseY + i) : placeCursor(baseX + L, baseY + i);
		cout << character;
		Sleep(1);
	}
	placeCursor(baseX, baseY + l );
	(baseX + L == 120) ? L=L: L+=1;
	for (int i = 0; i < L; i++) {
		cout << character;
	}
	printMsgInColor("default", "");
}
//Draw a circle from a defined position (center, right, etc...)
void printSquareFromFixPos(char character, string fixPos, string color, unsigned int L, unsigned int l) {
	placeFixPosCursor(fixPos, L / 2, l / 2);
	printSquare(character, color, L, l);
}
void defaultSquare() {//Default square
	placeFixPosCursor("default");
	printSquare('#', "gold", 120, 29);
}

map<string, vector<int>> getFixPos()
{
	map<string, vector<int>>fixPos{
	{"center", {59,14}}, {"top", {59, 7}}, {"bottom", {59, 21}},
	{"left", {29, 14}}, {"top_left", {29, 7}}, {"bottom_left", {29, 21}},
	{"right", {89, 14}}, {"top_right", {89, 7}}, {"bottom_right", {89, 21}},
	{"default", {0, 0}}
	};
	return fixPos;
}

map<string, int> getColors()
{
	map<std::string, int>colors{
	{"dark_blue", 1}, {"green", 2}, {"aqua", 3},
	{"dark_red", 4}, {"purple", 5}, {"gold", 6},
	{"white", 7}, {"grey", 8}, {"blue", 9}, {"light_green", 10},
	{"light_blue", 11}, {"red", 12}, {"pink", 13},
	{"yellow", 14}, {"default", 15}
	};
	return colors;
}
//Print a message from defined pos (center, right, etc..)
int printMsgFromFixPos(string msg, string fixPos, string color, unsigned int Lsquare) {
	vector<string> toPrint;
	string temp;
	stringstream toDivise;
	int max = msg.size(), whereSpace = Lsquare, lastSpace = 0, numberBL = 0, width = ((Lsquare / 2) - 1);
	for (int i = 0; i < max; i++) {
		if (msg[i] == ' ') { lastSpace = i; }
		if (i % whereSpace == 0 && i != 0) {
			msg.replace(lastSpace, 1, ";");
			whereSpace = lastSpace + Lsquare;			
			i = lastSpace;
			numberBL++;
		}
	}
	msg.replace((msg.size() - 1), 1, ";");
	toDivise << msg;
	for (int i = (numberBL + 1); i > 0; i--) {
		getline(toDivise, temp, ';');
		toPrint.push_back(temp);
	}
	for (int i = 0; i < toPrint.size(); i++) {
		placeFixPosCursor(fixPos, width, (numberBL/2) - i);
		printMsgInColor(color);
		cout << toPrint[i];
		printMsgInColor("default");
	}
	return toPrint.size() + 1;
}

//Print a message in an adaptative square
void printMsgInSquare(string msg, string fixPos, string color, unsigned int width, char caracter) {
	int height = printMsgFromFixPos(msg, fixPos, "white", width);
	printSquareFromFixPos(caracter, fixPos, color, width, height);
}



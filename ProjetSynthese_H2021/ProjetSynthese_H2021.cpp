#include "MenuManagment.h"
/*
	Fonctionnement Histoire :
	x;y;z;"TEXT";cx1,cx2,cx3$cx1,cx2,cx3
	x -> Histoire
	y -> Branche
	z -> Bulle
	"TEXT" -> Texte � afficher
	cx1,cx2,cx3 -> Pointage 1e choix
	$S�paration nombre de choix
*/

int main()
{
	srand(time(nullptr));

	int choixMenu = 1;
	initialisationCouleurConsole();
	do
	{
		afficherMenu(siChoixMenuValide(choixMenu));
		placeCursor(34, 30);
		while (!(cin >> choixMenu))
		{
			cin.clear();
			cin.ignore(256, '\n');
			break;
		}
		switch (choixMenu)
		{
		case 1:
			system("cls");
			gererFichierBase();
			break;
		case 2:
			system("cls");
			ecrireHistoire();
			break;
		case 3:
			system("cls");
			///relireHistoire(); TODO -> (Affichage du menu qui demande quel histoire relire)
			///ta la fonction getHistories() pour la liste des histoires et la fonction readHistory() qui lit automatiquement
			break;
		case 4:
			break;
		default:
			afficherMsgErreur("Choix invalide");
			break;
		}
	} while (choixMenu != 4);

	printMsgInSquare("SALUT C MOI MOI MOI MOI MOI MOI MOI MOI MOI MOI MOI MOI MOI MOI MOI MOI MOI MOI MOI", "center", "red", 10, '#');
	printSquareFromFixPos('#', "center", "gold", 15, 15);
	Character c = createCharacter(true);
	fightCharacters(c);

	return 0;
}
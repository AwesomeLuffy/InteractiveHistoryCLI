#include "MenuManagment.h"

void afficherMenu(bool siEffacerEcran)
{
	if (siEffacerEcran)
	{
		system("cls");
	}
	placeCursor(20, 3);
	cout << "Menu principal ";
	placeCursor(25, 5);
	cout << "1 - G\x82rer les fichiers de base.";
	placeCursor(25, 7);
	cout << "2 - \x90" << "crire une histoire interactive";
	placeCursor(25, 9);
	cout << "3 - Relire une histoire pr\x82" << "c\x82" << "demment cr\x82" << "\x82" << "e";
	placeCursor(25, 11);
	cout << "4 - Quitter";
	placeCursor(20, 30);
	cout << "Votre choix : ";
}
bool siChoixMenuValide(int choixMenu)
{
	bool siChoixMenuValide = false;
	if ((choixMenu >= 1 && choixMenu <= 3) || choixMenu == 4)
	{
		siChoixMenuValide = true;
	}
	else
	{
		siChoixMenuValide = false;
	}
	return siChoixMenuValide;
}
void initialisationCouleurConsole()
{
	printMsgInColor("default", "");
}
void afficherMsgErreur(string msg)
{
	system("cls");
	HANDLE manipConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	printMsgInColor("red", "");
	placeCursor(1, 1);
	cout << msg;
	initialisationCouleurConsole();
}
void gererFichierBase()
{
	int choixMenu = 1;
	do
	{
		system("cls");
		afficherMenuFichierBase(choixMenu);
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
			optionChoix(choixMenu);
			break;
		case 2:
			optionChoix(choixMenu);
			break;
		case 3:
			optionChoix(choixMenu);
			break;
		case 4:
			break;
		case 5:
			exit(1);
			break;
		default:
			afficherMsgErreur("Choix invalide");
			break;
		}
		if (choixMenu == 4)
		{
			break;
		}
	} while (choixMenu != 5);
}
void afficherMenuFichierBase(int choixMenuFichier)
{
	placeCursor(20, 3);
	cout << "Menu fichiers de base ";
	placeCursor(25, 5);
	cout << "1 - G\x82rer le fichier des noms de personnages";
	placeCursor(25, 7);
	cout << "2 - G\x82rer le fichier des noms de lieux";
	placeCursor(25, 9);
	cout << "3 - G\x82rer le fichier des objets";
	placeCursor(25, 11);
	cout << "4 - Pr\x82" << "c\x82" << "dent";
	placeCursor(25, 13);
	cout << "5 - Quitter";
	placeCursor(20, 30);
	cout << "Votre choix : ";
}
void afficherMenuOption(int choixMenuOption)
{
	placeCursor(20, 3);
	cout << "Menu des options ";
	placeCursor(25, 5);
	cout << "1 - Afficher";
	placeCursor(25, 7);
	cout << "2 - Ajouter";
	placeCursor(25, 9);
	cout << "3 - Modifier";
	placeCursor(25, 11);
	cout << "4 - Supprimer";
	placeCursor(25, 13);
	cout << "5 - Pr\x82" << "c\x82" << "dent";
	placeCursor(25, 15);
	cout << "6 - Quitter";
	placeCursor(20, 30);
	cout << "Votre choix : ";
}
void optionChoix(int choixMenuFichier)
{
	int choixMenu = 1;
	do
	{
		system("cls");
		afficherMenuOption(choixMenu);
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
			switch (choixMenuFichier)
			{
			case 1:
				affichierFichierPersonnage();
				break;
			case 2:
				affichierFichierLieu();
				break;
			case 3:
				affichierFichierObjet();
				break;
			default:
				break;
			}
			break;
		case 2:
			switch (choixMenuFichier)
			{
			case 1:
				ajouterFichierPersonnage();
				break;
			case 2:
				ajouterFichierLieu();
				break;
			case 3:
				ajouterFichierObjet();
				break;
			default:
				break;
			}
			break;
		case 3:
			switch (choixMenuFichier)
			{
			case 1:
				modifierFichierPersonnage();
				break;
			case 2:
				modifierFichierLieu();
				break;
			case 3:
				modifierFichierObjet();
				break;
			default:
				break;
			}
			break;
		case 4:
			switch (choixMenuFichier)
			{
			case 1:
				supprimerPersonnage();
				break;
			case 2:
				supprimerLieu();
				break;
			case 3:
				supprimerObjet();
				break;
			default:
				break;
			}
			break;
		case 5:
			break;
		case 6:
			exit(1);
			break;
		default:
			afficherMsgErreur("Choix invalide");
			break;
		}
		if (choixMenu == 5)
		{
			break;
		}
	} while (choixMenu != 6);
}
void affichierFichierPersonnage()
{
	system("cls");
	Nom nom;
	int positionX = 10;
	int positionY = 7;
	string ligneLue = "";
	stringstream ligneStream;
	ifstream fichierLecture("./datFile/personnage.dat", ios::in);
	if (fichierLecture)
	{
		placeCursor(positionX, positionY);
		cout << "Le contenu du fichier des noms de personnages";
		positionY += 2;
		do
		{
			getline(fichierLecture, ligneLue);
			if (!fichierLecture.eof())
			{
				ligneStream.clear();
				ligneStream << ligneLue;
				getline(ligneStream, nom.personnage);
				placeCursor(positionX, positionY);
				cout << nom.personnage;
				positionY++;
			}
		} while (!fichierLecture.eof());
	}
	else
	{
		placeCursor(25, 15);
		cout << "ERREUR : Ouverture du fichier impossible.";
	}
	fichierLecture.close();
	positionY += 2;
	placeCursor(positionX, positionY);
	system("pause");
}
void affichierFichierLieu()
{
	system("cls");
	Nom nom;
	int positionX = 10;
	int positionY = 7;
	string ligneLue = "";
	stringstream ligneStream;
	ifstream fichierLecture("./datFile/lieu.dat", ios::in);
	if (fichierLecture)
	{
		placeCursor(positionX, positionY);
		cout << "Le contenu du fichier des lieux";
		positionY += 2;
		do
		{
			getline(fichierLecture, ligneLue);
			if (!fichierLecture.eof())
			{
				ligneStream.clear();
				ligneStream << ligneLue;
				getline(ligneStream, nom.lieu);
				placeCursor(positionX, positionY);
				cout << nom.lieu;
				positionY++;
			}
		} while (!fichierLecture.eof());
	}
	else
	{
		placeCursor(25, 15);
		cout << "ERREUR : Ouverture du fichier impossible.";
	}
	fichierLecture.close();
	positionY += 2;
	placeCursor(positionX, positionY);
	system("pause");
}
void affichierFichierObjet()
{
	system("cls");
	Nom nom;
	int positionX = 10;
	int positionY = 7;
	string ligneLue = "";
	string champLue = "";
	stringstream ligneStream;
	ifstream fichierLecture("./datFile/objet.dat", ios::in);
	if (fichierLecture)
	{
		placeCursor(positionX, positionY);
		cout << "Le contenu du fichier des objets";
		positionY += 2;
		do
		{
			getline(fichierLecture, ligneLue);
			if (!fichierLecture.eof())
			{
				ligneStream.clear();
				ligneStream << ligneLue;
				getline(ligneStream, nom.objet.nom, ';');
				getline(ligneStream, champLue);
				nom.objet.degat = stoi(champLue);
				placeCursor(positionX, positionY);
				cout << setw(25) << nom.objet.nom
					<< setw(5) << nom.objet.degat;
				positionY++;
			}
		} while (!fichierLecture.eof());
	}
	else
	{
		placeCursor(25, 15);
		cout << "ERREUR : Ouverture du fichier impossible.";
	}
	fichierLecture.close();
	positionY += 2;
	placeCursor(positionX, positionY);
	system("pause");
}
void ajouterFichierPersonnage()
{
	system("cls");
	Nom nom;
	placeCursor(10, 8);
	cout << "Nom du personnage : ";
	cin.ignore();
	getline(cin, nom.personnage);
	placeCursor(10, 10);
	cout << "Voici le contenu que vous avez entr\x82" << "e : ";
	placeCursor(50, 10);
	cout << nom.personnage;
	ecrireInformationPersonnage(nom);
	placeCursor(25, 12);
	system("pause");
}
void ecrireInformationPersonnage(Nom nom)
{
	string const nomFichier("./datFile/personnage.dat");
	ofstream monFlux(nomFichier.c_str(), ios::app);
	if (monFlux)
	{
		monFlux << nom.personnage << endl;
	}
	else
	{
		cout << "ERREUR - Impossible d'ouvrir le fichier." << endl;
	}
	monFlux.close();
}
void ajouterFichierLieu()
{
	system("cls");
	Nom nom;
	placeCursor(10, 8);
	cout << "Nom du lieu : ";
	cin.ignore();
	getline(cin, nom.lieu);
	placeCursor(10, 10);
	cout << "Voici le contenu que vous avez entr\x82" << "e : ";
	placeCursor(50, 10);
	cout << nom.lieu;
	ecrireInformationLieu(nom);
	placeCursor(25, 12);
	system("pause");
}
void ecrireInformationLieu(Nom nom)
{
	string const nomFichier("./datFile/lieu.dat");
	ofstream monFlux(nomFichier.c_str(), ios::app);
	if (monFlux)
	{
		monFlux << nom.lieu << endl;
	}
	else
	{
		cout << "ERREUR - Impossible d'ouvrir le fichier." << endl;
	}
	monFlux.close();
}
void ajouterFichierObjet()
{
	system("cls");
	Nom nom;
	placeCursor(10, 8);
	cout << "Nom de l'objet : ";
	cin.ignore();
	getline(cin, nom.objet.nom);
	placeCursor(10, 10);
	cout << "D\x82g\x83t de l'objet : ";
	cin >> nom.objet.degat;
	cin.clear();
	cin.ignore(256, '\n');
	placeCursor(10, 12);
	cout << "Voici le contenu que vous avez entr\x82" << "e : ";
	placeCursor(50, 12);
	cout << nom.objet.nom << ", " << nom.objet.degat;
	ecrireInformationObjet(nom);
	placeCursor(25, 14);
	system("pause");
}
void ecrireInformationObjet(Nom nom)
{
	string const nomFichier("./datFile/objet.dat");
	ofstream monFlux(nomFichier.c_str(), ios::app);
	if (monFlux)
	{
		monFlux << nom.objet.nom << ";";
		monFlux << nom.objet.degat << endl;
	}
	else
	{
		cout << "ERREUR - Impossible d'ouvrir le fichier." << endl;
	}
	monFlux.close();
}
void modifierFichierPersonnage()
{
	system("cls");
	Nom nom;
	int positionX = 10;
	int positionY = 7;
	int ligne = 0;
	bool isSuccess = false;
	string ligneLue = "";
	string nomCible;
	string nouveauNom;
	stringstream ligneStream;
	fstream fichierLecture("./datFile/personnage.dat", ios::in | ios::out);
	if (fichierLecture)
	{
		placeCursor(42, 5);
		cout << "MODIFICATION PERSONNAGE";
		placeCursor(42, 6);
		cout << "=======================";
		placeCursor(10, 9);
		cout << "Entrez le nom du personnage \x85 modifier : ";
		cin.ignore();
		getline(cin, nomCible);

		do
		{
			getline(fichierLecture, ligneLue);
			if (!fichierLecture.eof())
			{
				ligneStream.clear();
				ligneStream << ligneLue;
				getline(ligneStream, nom.personnage);
				ligne++;
				if (nom.personnage == nomCible)
				{
					placeCursor(10, 11);
					cout << "Personnage trouv\x82" << "e. Son nom actuel : " << nom.personnage;
					placeCursor(10, 13);
					cout << "Entrez un nouveau nom pour le personnage : ";
					getline(cin, nouveauNom);

					modifierligne(ligne, "./datFile/personnage.dat", nouveauNom);

					isSuccess = true;
					placeCursor(10, 15);
					cout << "Contenu modifi\x82 ";
					placeCursor(10, 17);
					system("pause");
				}
			}
			ligneStream.str("");
		} while (!fichierLecture.eof() && !isSuccess);
	}
}
void modifierFichierLieu()
{
	system("cls");
	Nom nom;
	int positionX = 10;
	int positionY = 7;
	int ligne = 0;
	bool isSuccess = false;
	string ligneLue = "";
	string nomCible;
	string nouveauNom;
	stringstream ligneStream;
	fstream fichierLecture("./datFile/lieu.dat", ios::in | ios::out);
	if (fichierLecture)
	{
		placeCursor(42, 5);
		cout << "MODIFICATION LIEU";
		placeCursor(42, 6);
		cout << "=================";
		placeCursor(10, 9);
		cout << "Entrez le nom du lieu \x85 modifier : ";
		cin.ignore();
		getline(cin, nomCible);

		do
		{
			getline(fichierLecture, ligneLue);
			if (!fichierLecture.eof())
			{
				ligneStream.clear();
				ligneStream << ligneLue;
				getline(ligneStream, nom.lieu);
				ligne++;
				if (nom.lieu == nomCible)
				{
					placeCursor(10, 11);
					cout << "Lieu trouv\x82" << "e. Son nom actuel : " << nom.lieu;
					placeCursor(10, 13);
					cout << "Entrez un nouveau nom pour le lieu : ";
					getline(cin, nouveauNom);

					modifierligne(ligne, "./datFile/lieu.dat", nouveauNom);

					isSuccess = true;
					placeCursor(10, 15);
					cout << "Contenu modifi\x82 ";
					placeCursor(10, 17);
					system("pause");
				}
			}
			ligneStream.str("");
		} while (!fichierLecture.eof() && !isSuccess);
	}
}
void modifierligne(int ligneModifier, string nomFichier, string nom)
{
	int ligne = 0;
	string ligneLue = "";
	string tampon = "";
	ifstream fichierLecture(nomFichier);

	if (fichierLecture)
	{
		while (getline(fichierLecture, ligneLue))
		{
			ligne++;
			if (ligne == ligneModifier)
			{
				ligneLue = nom;
			}
			tampon += ligneLue + "\n";
		}
	}
	fichierLecture.close();
	ofstream fichierEcriture(nomFichier);
	fichierEcriture << tampon;
	fichierEcriture.close();
}
void modifierFichierObjet()
{
	system("cls");
	Nom nom;
	int positionX = 10;
	int positionY = 7;
	int ligne = 0;
	bool isSuccess = false;
	string ligneLue = "";
	string champLue = "";
	string nomCible;
	string nouveauNom;
	int nouveauDegat;
	stringstream ligneStream;
	fstream fichierLecture("./datFile/objet.dat", ios::in | ios::out);
	if (fichierLecture)
	{
		placeCursor(42, 5);
		cout << "MODIFICATION OBJET";
		placeCursor(42, 6);
		cout << "===================";
		placeCursor(10, 9);
		cout << "Entrez le nom de l'objet \x85 modifier : ";
		cin.ignore();
		getline(cin, nomCible);

		do
		{
			getline(fichierLecture, ligneLue);
			if (!fichierLecture.eof())
			{
				ligneStream.clear();
				ligneStream << ligneLue;
				getline(ligneStream, nom.objet.nom, ';');
				getline(ligneStream, champLue);
				nom.objet.degat = stoi(champLue);
				ligne++;
				if (nom.objet.nom == nomCible)
				{
					placeCursor(10, 11);
					cout << "Objet trouv\x82" << "e. Son nom actuel : " << nom.objet.nom;
					placeCursor(10, 13);
					cout << "Entrez un nouveau nom pour l'objet : ";
					getline(cin, nouveauNom);
					placeCursor(10, 15);
					cout << "Entrez un nouveau nombre de d\x82g\x83 pour l'objet : ";
					cin >> nouveauDegat;

					modifierligneObjet(ligne, nouveauNom, nouveauDegat);

					isSuccess = true;
					placeCursor(10, 17);
					cout << "Contenu modifi\x82 ";
					placeCursor(10, 19);
					system("pause");
				}
			}
			ligneStream.str("");
		} while (!fichierLecture.eof() && !isSuccess);
	}
}
void modifierligneObjet(int ligneModifier, string nom, int degat)
{
	int ligne = 0;
	string ligneLue = "";
	string champLue = "";
	string tampon = "";
	string concatener;
	ifstream fichierLecture("./datFile/objet.dat");

	if (fichierLecture)
	{
		while (getline(fichierLecture, ligneLue))
		{
			ligne++;
			if (ligne == ligneModifier)
			{
				concatener = nom + ";";
				to_string(degat);
				concatener += to_string(degat);
				ligneLue = concatener;

			}
			tampon += ligneLue + "\n";
		}
	}
	fichierLecture.close();
	ofstream fichierEcriture("./datFile/objet.dat");
	fichierEcriture << tampon;
	fichierEcriture.close();
}
void supprimerPersonnage()
{
	system("cls");
	Nom nom;
	int positionX = 10;
	int positionY = 7;
	int ligne = 0;
	bool isSuccess = false;
	string ligneLue = "";
	string nomCible;
	stringstream ligneStream;
	fstream fichierLecture("./datFile/personnage.dat", ios::in);

	if (fichierLecture)
	{
		placeCursor(42, 5);
		cout << "SUPPRESSION PERSONNAGE";
		placeCursor(42, 6);
		cout << "======================";
		placeCursor(10, 9);
		cout << "Entrez le nom du personnage a supprimer : ";
		cin.ignore();
		getline(cin, nomCible);
		do
		{
			getline(fichierLecture, ligneLue);
			if (!fichierLecture.eof())
			{
				ligneStream.clear();
				ligneStream << ligneLue;
				getline(ligneStream, nom.personnage);
				ligne++;
				if (nom.personnage == nomCible)
				{
					supprimerligne(ligne, "./datFile/personnage.dat");
					isSuccess = true;
				}
			}
			ligneStream.str("");
		} while (!fichierLecture.eof() && !isSuccess);
	}
	else
	{
		exit(0);
	}
	fichierLecture.close();
	if (!isSuccess)
	{
		placeCursor(10, 11);
		cout << "Le personnage << " << nomCible << " >> n'existe pas.";
	}
	else
	{
		placeCursor(10, 11);
		cout << "Le personnage << " << nomCible << " >> a \x82t\x82 supprim\x82.";
	}
	placeCursor(10, 22);
	system("pause");
}
void supprimerLieu()
{
	system("cls");
	Nom nom;
	int positionX = 10;
	int positionY = 7;
	int ligne = 0;
	bool isSuccess = false;
	string ligneLue = "";
	string nomCible;
	stringstream ligneStream;
	fstream fichierLecture("./datFile/lieu.dat", ios::in);

	if (fichierLecture)
	{
		placeCursor(42, 5);
		cout << "SUPPRESSION LIEU";
		placeCursor(42, 6);
		cout << "================";
		placeCursor(10, 9);
		cout << "Entrez le nom du lieu a supprimer : ";
		cin.ignore();
		getline(cin, nomCible);
		do
		{
			getline(fichierLecture, ligneLue);
			if (!fichierLecture.eof())
			{
				ligneStream.clear();
				ligneStream << ligneLue;
				getline(ligneStream, nom.lieu);
				ligne++;
				if (nom.lieu == nomCible)
				{
					supprimerligne(ligne, "./datFile/lieu.dat");
					isSuccess = true;
				}
			}
			ligneStream.str("");
		} while (!fichierLecture.eof() && !isSuccess);
	}
	else
	{
		exit(0);
	}
	fichierLecture.close();
	if (!isSuccess)
	{
		placeCursor(10, 11);
		cout << "Le lieu << " << nomCible << " >> n'existe pas.";
	}
	else
	{
		placeCursor(10, 11);
		cout << "Le lieu << " << nomCible << " >> a \x82t\x82 supprim\x82.";
	}
	placeCursor(10, 22);
	system("pause");
}
void supprimerObjet()
{
	system("cls");
	Nom nom;
	int positionX = 10;
	int positionY = 7;
	int ligne = 0;
	bool isSuccess = false;
	string ligneLue = "";
	string champLue = "";
	string nomCible;
	stringstream ligneStream;
	fstream fichierLecture("./datFile/objet.dat", ios::in);

	if (fichierLecture)
	{
		placeCursor(42, 5);
		cout << "SUPPRESSION OBJET";
		placeCursor(42, 6);
		cout << "=================";
		placeCursor(10, 9);
		cout << "Entrez le nom de l'objet a supprimer : ";
		cin.ignore();
		getline(cin, nomCible);
		do
		{
			getline(fichierLecture, ligneLue);
			if (!fichierLecture.eof())
			{
				ligneStream.clear();
				ligneStream << ligneLue;
				getline(ligneStream, nom.lieu, ';');
				getline(ligneStream, champLue);
				nom.objet.degat = stoi(champLue);
				ligne++;
				if (nom.lieu == nomCible)
				{
					supprimerligne(ligne, "./datFile/objet.dat");
					isSuccess = true;
				}
			}
			ligneStream.str("");
		} while (!fichierLecture.eof() && !isSuccess);
	}
	else
	{
		exit(0);
	}
	fichierLecture.close();
	if (!isSuccess)
	{
		placeCursor(10, 11);
		cout << "Le objet << " << nomCible << " >> n'existe pas.";
	}
	else
	{
		placeCursor(10, 11);
		cout << "Le objet << " << nomCible << " >> a \x82t\x82 supprim\x82.";
	}
	placeCursor(10, 22);
	system("pause");
}
void supprimerligne(int ligneSupprimer, string nomFichier)
{
	int ligne = 0;
	string ligneLue = "";
	string tampon = "";
	ifstream fichierLecture(nomFichier);

	if (fichierLecture)
	{
		while (getline(fichierLecture, ligneLue))
		{
			ligne++;
			if (ligne != ligneSupprimer)
			{
				tampon += ligneLue + "\n";
			}
		}
	}
	fichierLecture.close();
	ofstream fichierEcriture(nomFichier);
	fichierEcriture << tampon;
	fichierEcriture.close();
}
void ecrireHistoire()
{
	History history = getHistoryFile();
	Character c = createCharacter(true);
	vector<vector<int>> choices;
	const int bulletWidth = 40;
	int histoire = 0, branche = 0, bulle = 0, choice = 0;
	bool aleatoire = true;
	///TODO
	///-Demander personnage avec ou sans aléatoire -> Character personnagePrincipal = createCharacter(bool)
	///		true -> Aléatoire | false -> Choisit à la main
	///-Combat
	///Demander si il veut que le choix soit fait automatiquement
	///-Validation
	do {
		system("cls");
		string actualBullet = history.history[histoire][branche][bulle];
		replaceString(actualBullet, c.getName(), c.getWeapon(), getPlaceFile());
		///TODO
		///AFFICHER
		///REMPLACER PAR LES OBJETS/LIEUX/PERSONNAGE DANS LE TEXTE
		///AJOUT DANS LA LISTE CHAÎNÉE

		printTransition("snake");
		choices = history.choices[getKey(histoire, branche, bulle)]; //Obtention des choix
		//DEMANDER SI CHOIX ALEATOIRE
		if (aleatoire) { choice = ranDice(choices.size() - 1, 0); }//Retourne un choix en fonction de ceux disponible pour la bulle
		else {
		}
		///Fonction combat -> esthétisme à faire
		//if (ranDice(4, 1) == 4) { fightCharacters(personnagePrincipal); }

		histoire = choices[choice][0];
		branche = choices[choice][1];
		bulle = choices[choice][2];
		system("pause");
	} while (!checkEnd(choices));//Retourne vrai si le choix redirige vers -1,-1,-1
}
void relireHistoire()
{
	string name;
	///Affiche listes histoires & demande laquelle relire
	getHistories(); ///Modifie l'esthétisme de cette fonction
	readHistory(name); ///Modifie l'esthétisme de cette fonction
}
void choixAleatoire()
{
	int choixFaireChoix = 0;
	do
	{
		afficherChoixAleatoire();
		placeCursor(34, 30);
		while (!(cin >> choixFaireChoix))
		{
			cin.clear();
			cin.ignore(256, '\n');
			break;
		}
		switch (choixFaireChoix)
		{
		case 1:
			system("cls");
			break;
		case 2:
			system("cls");
			break;
		default:
			break;
		}
	} while (choixFaireChoix != 2);
}
void afficherChoixAleatoire()
{
	placeCursor(20, 3);
	cout << "Voulez-vous effectuer vos choix par vous m\x88me ou de mani\x8Are al\x82" << "atoire ? ";
	placeCursor(25, 5);
	cout << "1 - Faire ces choix soi-m\x88me";
	placeCursor(25, 7);
	cout << "2 - Faire ces choix mani\x8Are al\x82" << "atoire";
	placeCursor(20, 30);
	cout << "Votre choix : ";
}
void choixChoisiNonAleatoire()
{
	string nomPersonnage = "";
	placeCursor(20, 3);
	cout << "Cr\x82" << "ation du personnage";
	placeCursor(25, 5);
	cout << "- Inscrivez le nom/surnom de votre personnage : ";
	cin >> nomPersonnage;

	string intro = "...";
	ListeHistoire listehistoire = ListeHistoire();
	cout << intro;
	listehistoire.push_back(intro);

	//On offre un choix à effectuer, pour le choix du chapitre suivant
	//...
	system("cls");

	string nomHistoire = "";
	cout << "Donner un titre à votre histoire : ";
	cin >> nomHistoire;

	//On parcourt la liste chainée, afin d’enregistrer l’histoire dans un fichier, nommé selon le titre précédemment saisi
	//...
}
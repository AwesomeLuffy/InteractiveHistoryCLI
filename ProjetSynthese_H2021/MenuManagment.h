#pragma once
#include <iostream>
#include <Windows.h>
#include <string>
#include <fstream>
#include <iomanip>
#include <sstream>
#include "ListeHistoire.h"
#include "Structs.h"
#include "ConsoleManagment.h"

using namespace std;

void afficherMenu(bool siEffacerEcran);
bool siChoixMenuValide(int choixMenu);
void initialisationCouleurConsole();
void afficherMsgErreur(string msg);
void gererFichierBase();
void afficherMenuFichierBase(int choixMenuFichier);
void optionChoix(int choixMenuFichier);
void afficherMenuOption(int choixMenuOption);
void affichierFichierPersonnage();
void affichierFichierLieu();
void affichierFichierObjet();
void ajouterFichierPersonnage();
void ecrireInformationPersonnage(Nom nom);
void ajouterFichierLieu();
void ecrireInformationLieu(Nom nom);
void ajouterFichierObjet();
void ecrireInformationObjet(Nom nom);
void modifierFichierPersonnage();
void modifierFichierLieu();
void modifierligne(int ligneModifier, string nomFichier, string nom);
void modifierFichierObjet();
void modifierligneObjet(int ligneModifier, string nom, int degat);
void supprimerPersonnage();
void supprimerLieu();
void supprimerObjet();
void supprimerligne(int ligneSupprimer, string nomFichier);
void ecrireHistoire();
void relireHistoire();
void choixAleatoire();
void afficherChoixAleatoire();
void choixChoisiNonAleatoire();

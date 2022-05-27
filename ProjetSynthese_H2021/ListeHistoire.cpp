#include <iostream>
#include "ListeHistoire.h"

ListeHistoire::ListeHistoire()
{
	NoeudListe* TETE = new NoeudListe();
	NoeudListe* QUEUE = new NoeudListe();

	debutListe = TETE;
	TETE->suivante = QUEUE;
	TETE->precedent = QUEUE;
	QUEUE->precedent = TETE;

	noeudCourant = nullptr;
	nombreDeBulle = 0;
}
ListeHistoire::~ListeHistoire()
{
	NoeudListe* TETE = debutListe;
	NoeudListe* QUEUE = TETE->precedent;

	clear();

	delete(TETE);
	delete(QUEUE);
	debutListe = nullptr;
}
bool ListeHistoire::empty()
{
	bool siVide = false;

	NoeudListe* TETE = debutListe;
	if (TETE->suivante == TETE->precedent)
	{
		siVide = true;
	}
	return siVide;
}
void ListeHistoire::clear()
{
	while (!empty())
	{
		//pop_back();
	}
	nombreDeBulle = 0;
}
void ListeHistoire::push_back(std::string & text_)
{
	NoeudListe* TETE = debutListe;
	NoeudListe* QUEUE = TETE->precedent;
	NoeudListe* dernierNoeud = QUEUE->precedent;
	NoeudListe* nouveauNoeud = new NoeudListe();

	nouveauNoeud->suivante = QUEUE;
	nouveauNoeud->precedent = QUEUE->precedent;
	nouveauNoeud->histoire = text_;
	
	QUEUE->precedent = nouveauNoeud;
	dernierNoeud->suivante = nouveauNoeud;

	nombreDeBulle++;
}
std::string ListeHistoire::pop_back()
{
	std::string histoire;

	if (!empty())
	{
		NoeudListe* TETE = debutListe;
		NoeudListe* QUEUE = TETE->precedent;
		NoeudListe* dernierNoeud = QUEUE->precedent;
		NoeudListe* avantDernierNoeud = dernierNoeud->precedent;

		histoire = dernierNoeud->histoire;
		nombreDeBulle--;

		QUEUE->precedent = dernierNoeud->precedent;
		avantDernierNoeud->suivante = QUEUE;

		delete(dernierNoeud);
	}

	return histoire;
}
bool ListeHistoire::debut()
{
	bool isSuccess = false;

	NoeudListe* TETE = debutListe;
	NoeudListe* QUEUE = TETE->precedent;


	if (TETE->suivante != QUEUE)
	{
		noeudCourant = TETE->suivante;
		isSuccess = true;
	}
	return isSuccess;
}
void ListeHistoire::avancer()
{
	if (noeudCourant != nullptr)
	{
		if (!estNeudDeQUEUE())
		{
			noeudCourant = noeudCourant->suivante;
		}
	}
	else if (!empty())
	{
		NoeudListe* TETE = debutListe;
		noeudCourant = TETE->suivante;
	}
}
std::string ListeHistoire::getHistoire()
{
	return noeudCourant->histoire;
}
bool ListeHistoire::estNeudDeQUEUE()
{
	bool estQueue = false;

	NoeudListe* TETE = debutListe;
	NoeudListe* QUEUE = TETE->precedent;

	if (noeudCourant == QUEUE)
	{
		estQueue = true;
	}
	return estQueue;
}
std::string ListeHistoire::pop_front()
{
	std::string histoire;

	if (!empty())
	{
		NoeudListe* TETE = debutListe;
		NoeudListe* QUEUE = TETE->precedent;
		NoeudListe* premierNoeud = TETE->suivante;
		NoeudListe* secondNoeud = premierNoeud->suivante;

		histoire = premierNoeud->histoire;
		nombreDeBulle--;

		TETE->suivante = premierNoeud->suivante;
		secondNoeud->precedent = TETE;

		delete(premierNoeud);
	}
	return histoire;
}
void ListeHistoire::push_front(const std::string & text_)
{
	NoeudListe* TETE = debutListe;
	NoeudListe* QUEUE = TETE->precedent;
	NoeudListe* premierNoeud = TETE->suivante;
	NoeudListe* nouveauNoeud = new NoeudListe();

	nouveauNoeud->precedent = TETE;
	nouveauNoeud->suivante = TETE->suivante;
	nouveauNoeud->histoire = text_;

	TETE->suivante = nouveauNoeud;
	premierNoeud->precedent = nouveauNoeud;

	nombreDeBulle++;
}
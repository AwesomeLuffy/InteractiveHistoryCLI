#pragma once
#include "NoeudListe.h"

struct ListeHistoire
{
private:
	NoeudListe* debutListe;
	NoeudListe* noeudCourant;

public:
	unsigned int nombreDeBulle;
	ListeHistoire();
	~ListeHistoire();
	bool empty();
	void clear();
	void push_back(std::string &text_);
	std::string pop_back();
	bool debut();
	void avancer();
	std::string getHistoire();
	bool estNeudDeQUEUE();
	std::string pop_front();
	void push_front(const std::string& text_);
};
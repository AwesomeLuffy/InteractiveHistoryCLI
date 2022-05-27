#pragma once
#include "Structs.h"

struct NoeudListe
{
public:
	NoeudListe* suivante;
	NoeudListe* precedent;
	std::string histoire;
	NoeudListe();
};

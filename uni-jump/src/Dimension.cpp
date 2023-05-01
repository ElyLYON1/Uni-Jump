#include "Dimension.h"

#include <cassert>

#include <iostream>
using namespace std;

//Initailisation des attributs pour Dimension
Dimension::Dimension()
{
    Dim_Largeur = 1;
    Dim_Hauteur = 1;
}

//Initialisation des attributs avec les paramettre en donné pour Dimension
Dimension::Dimension(unsigned int Largeur, unsigned int Hauteur)
{
    assert(Largeur >= 0);
    assert(Hauteur >= 0);
    Dim_Largeur = Largeur;
    Dim_Hauteur = Hauteur;
}

//Destructeur de Dimension
Dimension::~Dimension()
{
    Dim_Largeur = 0;
    Dim_Hauteur = 0;
}

//Retourne la largeur de la dimension
unsigned int Dimension::getLargeur() const
{
    return Dim_Largeur;
}

//Retourne la hauteur de la dimension
unsigned int Dimension::getHauteur() const
{
    return Dim_Hauteur;
}

//Modifie la largeur de la dimension
void Dimension::setLargeur(unsigned int Largeur)
{
    assert(Largeur > 0);
    Dim_Largeur = Largeur;
}

//Modifie la hauteur de la dimension    
void Dimension::setHauteur(unsigned int Hauteur)
{
    assert(Hauteur > 0);
    Dim_Hauteur = Hauteur;
}

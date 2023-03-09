#include "Couleur.h"

#include <cassert>

#include <iostream>
using namespace std;

//Initialisation des attributs pour Couleur
Couleur::Couleur()
{
    Red = 0;
    Green = 0;
    Blue = 0;
}

//Initialisation des attributs avec les paramettre en donné pour Couleur
Couleur::Couleur(unsigned char Red, unsigned char Green, unsigned char Blue)
{
    assert(Red >= 0);
    assert(Green >= 0);
    assert(Blue >= 0);
    this->Red = Red;
    this->Green = Green;
    this->Blue = Blue;
}

//Destructeur de Couleur
Couleur::~Couleur()
{
    Red = 0;    
    Green = 0;
    Blue = 0;
}


//Retourne la valeur de Red
unsigned char Couleur::getRed() const
{
    return Red;
}

//Retourne la valeur de Green
unsigned char Couleur::getGreen() const
{
    return Green;
}

//Retourne la valeur de Blue
unsigned char Couleur::getBlue() const
{
    return Blue;
}

//Modifie la valeur de Red
void Couleur::setRed(unsigned char Red)
{
    assert(Red >= 0);
    this->Red = Red;
}

//Modifie la valeur de Green
void Couleur::setGreen(unsigned char Green)
{
    assert(Green >= 0);
    this->Green = Green;
}

//Modifie la valeur de Blue
void Couleur::setBlue(unsigned char Blue)
{
    assert(Blue >= 0);
    this->Blue = Blue;
}

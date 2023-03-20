#include "Couleur.h"

#include <cassert>

#include <iostream>
using namespace std;

//Initialisation des attributs pour Couleur
Couleur::Couleur():Couleur_Red(0), Couleur_Green(0), Couleur_Blue(0)
{
   
}

//Initialisation des attributs avec les paramettre en donné pour Couleur
Couleur::Couleur(unsigned char Red, unsigned char Green, unsigned char Blue):Couleur_Red(Red), Couleur_Green(Green), Couleur_Blue(Blue)
{
    assert(Red >= 0);
    assert(Green >= 0);
    assert(Blue >= 0);
 
}

//Destructeur de Couleur
Couleur::~Couleur()
{

}


//Retourne la valeur de Red
unsigned char Couleur::getRed() const
{
    return Couleur_Red;
}

//Retourne la valeur de Green
unsigned char Couleur::getGreen() const
{
    return Couleur_Green;
}

//Retourne la valeur de Blue
unsigned char Couleur::getBlue() const
{
    return Couleur_Blue;
}

//Modifie la valeur de Red
void Couleur::setRed(unsigned char Red)
{
    assert(Red >= 0);
    Couleur_Red = Red;
}

//Modifie la valeur de Green
void Couleur::setGreen(unsigned char Green)
{
    assert(Green >= 0);
    Couleur_Green = Green;
}

//Modifie la valeur de Blue
void Couleur::setBlue(unsigned char Blue)
{
    assert(Blue >= 0);
    Couleur_Blue = Blue;
}

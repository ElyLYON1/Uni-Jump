#include "Position.h"

#include <cassert>
#include <math.h>
#include <cmath>


#include <iostream>
using namespace std;

//Initialisation des attributs pour Position
Position::Position()
{
    Pos_abscisse = 0;
    Pos_ordonnee = 0;
}

//Initialisation des attributs avec les paramettre en donné pour Position
Position::Position(unsigned int abscisse, unsigned int ordonnee)
{
    assert(abscisse >= 0);
    assert(ordonnee >= 0);
    this->Pos_abscisse = abscisse;
    this->Pos_ordonnee = ordonnee;
}

//Destructeur de Position
Position::~Position()
{
    Pos_abscisse = 0;
    Pos_ordonnee = 0;
}

//Retourne la valeur de Pos_abscisse
unsigned int Position::getAbscisse() const
{
    return Pos_abscisse;
}

//Retourne la valeur de Pos_ordonnee
unsigned int Position::getOrdonnee() const
{
    return Pos_ordonnee;
}

//Retourne la distance entre deux positions
unsigned int Position::getDistance(const Position &Pos) const
{
    return sqrt(pow(Pos_abscisse - Pos.Pos_abscisse, 2) + pow(Pos_ordonnee - Pos.Pos_ordonnee, 2));
}

//Modifie la valeur de Pos_abscisse
void Position::setAbscisse(unsigned int abscisse)
{
    assert(abscisse >= 0);
    this->Pos_abscisse = abscisse;
}

//Modifie la valeur de Pos_ordonnee
void Position::setOrdonnee(unsigned int ordonnee)
{
    assert(ordonnee >= 0);
    this->Pos_ordonnee = ordonnee;
}




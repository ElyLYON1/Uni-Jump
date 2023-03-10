#include "Personnage.h"
#include <iostream>
#include <cassert>

unsigned int Personnage::getSaut() const
{
    return Perso_saut;
}

unsigned int Personnage::getGravité() const
{
    return Perso_gravité;
}

unsigned int Personnage::getVitesse() const
{
    return Perso_vitesse;
}

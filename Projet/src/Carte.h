#ifndef _CARTE_H
#define _CARTE_H
#include <iostream>
#include "Personnage.h"
#include "Block.h"


class Carte
{
    unsigned int Carte_hauteur ,Carte_largeur;

    Personnage Carte_perso;

    Block * Carte_TabBlock;


};

#endif /* _CARTE_H */

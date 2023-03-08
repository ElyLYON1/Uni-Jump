#ifndef _PERSSONNAGE_H
#define _PERSSONNAGE_H
#include <iostream>
#include <cassert>
#include <cstring>
#include "Dimension.h"

class Personnage
{

    Personnage();
    Personnage(std::string nom);

    private :
    std::string Perso_pseudo;

    // vitesse du saut. Temps en seconde pour faire un saut. 
    int Perso_vitesse;

    // puissance de saut,  hauteur de chaque saut. Nb de carreau monté par saut 
    int Perso_saut;

    // Vitesse à laquelle le personnage descend vers le bas. Combien de carreau descendu (Carte_Hauteur) par seconde ou autre unité de temps
    int Perso_gravité;

    
    Dimension Perso_Dim;
    



};
#endif
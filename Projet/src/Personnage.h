#ifndef _PERSSONNAGE_H
#define _PERSSONNAGE_H
#include <iostream>
#include <cassert>
#include <cstring>
#include "Dimension.h"
#include "Position.h"

class Personnage
{
    private :
        //nom du personnage
        std::string Perso_pseudo;
        //position du personnage
        Position Perso_Position;
        //dimension du personnage
        Dimension Perso_Dim;
        //nom ficher image du personnage
        std::string Perso_image;
        
        
        // vitesse du saut. Temps en seconde pour faire un saut. 
        unsigned int Perso_vitesse;
        // puissance de saut,  hauteur de chaque saut. Nb de pixel monté par saut 
        unsigned int Perso_saut;
        // Vitesse à laquelle le personnage descend vers le bas. temps en second pour descendre le nombre de pixel de Perso_saut 
        unsigned int Perso_gravité;

    public :

    unsigned int getSaut()const;
    unsigned int getGravité()const;  
    unsigned int getVitesse()const;



};
#endif
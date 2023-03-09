#ifndef _CARTE_H
#define _CARTE_H
#include <iostream>
#include "Personnage.h"
#include "Block.h"


class Carte
{
    private;
        //dimension de la carte
        Dimension Carte_Dimension;
        
        //Personnage dans la carte
        Personnage Carte_perso;
        
        //Tableau dynamique de block
        Block * Carte_TabBlock;
        int taille_TabBlock;

    public:
        Carte();
        Carte(Dimension Dimension, Personnage Perso, Block * TabBlock);
        ~Carte();

        Dimension getDimCarte() const;
        Personnage getPerso() const;
        Block * getTabBlock() const;
        int getTailleTabBlock() const;
        

        void setDimension(Dimension Dimension);
        void setPerso(Personnage Perso);
        void setTabBlock(Block * TabBlock);


};

#endif /* _CARTE_H */

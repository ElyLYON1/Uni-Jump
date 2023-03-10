#ifndef _CARTE_H
#define _CARTE_H
#include <iostream>
#include "Personnage.h"
#include "Block.h"
#include <vector>


class Carte
{

    private:
        //dimension de la carte
        Dimension Carte_Dimension;
        
        //Personnage dans la carte
        Personnage Carte_perso;
        
        //Tableau dynamique de block
       std::vector<Block> * Carte_TabBlock;
       // int Carte_taille_TabBlock;


    public:
        Carte();
        Carte(Dimension Dim, Personnage Perso, Block * TabBlock);

        Dimension getDimCarte() const;
        Personnage getPerso() const;
        Block * getTabBlock() const;
        Block getBlock(int numBlock)const;
        int getTailleTabBlock() const;
        int getTailleUtilisee() const;
        

        void setDimension(Dimension Dimension);
        void setPerso(Personnage Perso);
        void setTabBlock(Block * TabBlock);
        void suppBlock(const Block &b);
        void ajoutBlock(const Block &b);
        int getnbEtage();
        void remplirModeFacile(int difficulté);
        void viderTabBlock();
};

#endif /* _CARTE_H */

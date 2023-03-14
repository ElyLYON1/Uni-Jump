#ifndef _CARTE_H
#define _CARTE_H
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
       std::vector<Block>  Carte_TabBlock;
       // int Carte_taille_TabBlock;


    public:
        Carte();
        Carte(Dimension Dim, Personnage Perso, std::vector<Block> TabBlock);

        Dimension getDimCarte() const;
        Personnage getPerso() const;
        Block getBlock(int numBlock)const;

        int getTailleTabBlock() const;
        int getTailleUtilisee() const;
        

        void setDimension(Dimension Dimension);
        void setPerso(Personnage Perso);

        int getnbEtage();
        void remplirModeFacile(int difficulté);

        bool PersoSurBlock();
};

#endif /* _CARTE_H */

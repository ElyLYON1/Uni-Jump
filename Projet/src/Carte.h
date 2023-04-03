#ifndef _CARTE_H
#define _CARTE_H
#include "Personnage.h"
#include "Block.h"

#include <vector>

/**
 * @class Carte [Carte.hpp].
 * @brief 'Carte' Regroupe toutes les caractéristiques d'une carte de jeu (The background of the game).
*/
class Carte
{

    private:
        Dimension Carte_Dimension;
        
        Personnage Carte_perso;
        
        //Tableau dynamique de block
       std::vector<Block>  Carte_TabBlock;
       // int Carte_taille_TabBlock;
        unsigned int nbSautmax;
    
    public:

      /// @brief Le constructeur de la class 'Carte'.  
        Carte();
        Carte(Dimension Dim, Personnage Perso, std::vector<Block> TabBlock);

    ///@brief Le destructeur de la class 'Carte'. 
        ~Carte();

        Dimension getDimCarte() const;
        Personnage getPerso() const;
        Block getBlock(int numBlock)const;
        std::vector<Block> getTabBlock() const;

        int getTailleTabBlock() const;
        int getTailleUtilisee() const;

        void remplirTabBlockTxt();

        bool blockSurPos(int x, int y)const;
        void setBlock(int numBlock, Block b);
        void ajouterBlock(Block b);

        void setDimension(Dimension Dimension);
        void setPerso(Personnage Perso);


        int getnbEtage();
        void remplirModeFacile(int difficulté);

        bool PersoSurBlock();
        void actionClavier(const char touche);

        void Block_PersoInit1();
        void Block_Init2();

        unsigned int getnbSaut() const;
        void ajouteSaut();
        void PersoGravite();
        bool persoSurBlock2();
        


        void testRegression();

        void boucleJeu();
        void tout_deplacer();

};

#endif /* _CARTE_H */

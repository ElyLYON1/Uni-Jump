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

        //Tableau dynamique d'objet
       std::vector<Block> Carte_TabObjet;

       // int Carte_taille_TabBlock;
        unsigned int nbSautmax;

        
        //Score de jeu quand il tape un block
        unsigned int score;

        //bool objet
        unsigned int objet;
    
    public:
        
        Carte();
        Carte(Dimension Dim, Personnage Perso, std::vector<Block> TabBlock, std::vector<Block> TabObjet);

        ~Carte();

        Dimension getDimCarte() const;
        Personnage getPerso() const;
        Block getBlock(int numBlock)const;
        Block getObjet(int numObjet)const;
        std::vector<Block> getTabBlock() const;

        int getTailleTabBlock() const;
        int getTailleTabObjet() const;
        int getTailleUtilisee() const;

        void remplirTabBlockTxt();

        bool blockSurPos(int x, int y)const;
        bool objetSurPos(unsigned int x,unsigned int y)const;
        void setBlock(int numBlock, Block b);
        void ajouterBlock(Block b);
        void ajouterObjet(Block o);

        void setDimension(Dimension Dimension);
        void setPerso(Personnage Perso);


        int getnbEtage();
        void remplirModeFacile(int difficulté);

        bool PersoSurBlock();
        bool PersoSurObjet();
        void actionClavier(const char touche);

        void Block_PersoInit1();
        void Block_Init2();

        unsigned int getnbSaut() const;
        void ajouteSaut();
        void PersoGravite();
        bool persoSurBlock2();
        bool persoSurBlock3(Block b);
        bool persoSurObjet2();
        bool persoSurObjet3(Block o);
        


        void testRegression();


        void boucleJeu();
        void tout_deplacer();
        void deplacerBlockmobile();
        void deplacerObjetmobile();
        void deplacerSiObjet();
        void viePerdue();
        bool getViePerso();


        void actionsAutomatiques();

};

#endif /* _CARTE_H */

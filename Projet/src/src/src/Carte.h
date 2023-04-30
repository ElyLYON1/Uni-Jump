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
        //dimension de la carte
        Dimension Carte_Dimension;
        
        //Personnage dans la carte
        Personnage Carte_perso;
        
        //Tableau dynamique de block
       std::vector<Block>  Carte_TabBlock;
       // int Carte_taille_TabBlock;


    public:
        /// @brief Constructeur de la class carte.
        Carte();
        Carte(Dimension Dim, Personnage Perso, std::vector<Block> TabBlock);
        /// @brief Destructeur de la class Carte.
        ~Carte();

        /// @brief Récupère la dimension de la carte du jeu. 
        /// @return Dimension.
        Dimension getDimCarte() const;

        /// @brief Récupère la position de personnage sur la carte du jeu.
        /// @return Position.
        Personnage getPerso() const;

        /// @brief Récupère la position de block "block".
        /// @param [in] numBlock Le numéro de block à récupèrer.
        /// @return Block.
        Block getBlock(int numBlock)const;

        /// @brief Avoir le tableau de blocks du jeu.
        /// @return un array de Block.
        std::vector<Block> getTabBlock() const;

        /// @brief Récupère la taille de tableau utilisé pour stocker les blocks.
        /// @return Taille de tableau utilisé.
        int getTailleTabBlock() const;

        /// @brief Récupère le nombre d'éléments dans la tabeleau de block.
        /// @return Nombre de blocks utilisés. 
        int getTailleUtilisee() const;

      //  void remplirTabBlockTxt();
        /// @brief Vérifie la position d'un Block à une position.
        /// @param[in] Position du Block, son abscisse x et ordonné y.   
        /// @return 'True' si c'y est, 'false' sinon.
        bool blockSurPos(int x, int y)const;

        /// @brief inialisation du block.
        void Block_Init2();
        void Block_PersoInit1();
        bool persoSurBlock2();
        void PersoGravite();

        /// @brief Ajout d'un block b passé en param.
        /// @param[in] b Nouveau Block à mettre. 
        void ajouterBlock(Block b);

        /// @brief Redimensioner la taille de la carte. 
        /// @param[in] Dimension Nouvelle dimension. 
        void setDimension(Dimension Dimension);

        /// @brief Redimensionner le personnage sur la carte.
        /// @param[in] Perso  
        void setPerso(Personnage Perso);

        int getnbEtage();
        void remplirModeFacile(int difficulté);

        /// @brief Verification du positionnement du personnage sur un Block.
        /// @return 'True' si le personnage est dessus, 'false' sinon.
        bool PersoSurBlock();

        /// @brief Enchainer une actoin sur le jeu à partir de la touche pressée.
        /// @param[in] touche L'évènement à lire et à effectuer.
        void actionClavier(const char touche);

        void actionauto();
        /// @brief Test de régression de la class pour tester son fonctionnement. 
        void testRegression();

};

#endif /* _CARTE_H */

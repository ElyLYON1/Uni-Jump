#ifndef _BLOCK_H
#define _BLOCK_H
#include "Position.h"
#include "Couleur.h" 
#include "Dimension.h"
/**
 * @class Block [Block.hpp]
 * @brief Regroupe tous les caractéristique d'un block.
 * @details 'Block' précise la manière dont les blocks sont construits, leurs mouvements 
 * ainsi que leurs régidités.   
*/

class Block
{
    private:
    
        Position Block_Position;
        Dimension Block_Dimension;

        Couleur Block_Couleur;
        
        //Si c'est égal a true on peut se poser dessus. Sinon on le casse et on tombe
        bool Block_Solide;
        bool Block_mobile;
    public:

        /// @brief Constructeur de Block initialisé avec les paramètre en donnée de couleur noir.
        Block();
        Block(Position Pos);
        Block(bool solide,bool mobile);
        Block(Dimension Dim, Position Pos, bool Solide, bool mobile);

        /// @brief Destructeur de la class.
        ~Block();

        /// @brief Récupère la position de block sur la carte de jeu. 
        /// @return Position.
        Position getPosition() const;

        /// @brief Récupère la dimension de block. 
        Dimension getDimension() const;

        /// @brief Récupère La couleur de block.
        Couleur getCouleur() const;

        /// @brief Récupère 'true' si le block est solide, 'false' sinon. 
        bool getSolide() const;

        /// @brief Modifie la position de block avec une nouvelle position.
        /// @param[in] Position Nouvelle position de block.
        void setPosition(Position Position);

        /// @brief Modifie la dimension de block avec une nouvelle dimension.
        /// @param[in] Dimension Nouvelle dimension de block.
        void setDimension(Dimension Dimension);

        /// @brief Modifie la couleur de block avec une nouvelle couleur.
        /// @param[in] Couleur Nouvelle couleur de block. 
        void setCouleur(Couleur Couleur);

        /// @brief Mettre le block solide.
        /// @param[in] Solide Nouvel état du block.
        void setSolide(bool Solide);
    


};

#endif /* _BLOCK_H */

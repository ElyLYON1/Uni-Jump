#ifndef _BLOCK_H
#define _BLOCK_H
#include "Position.h"
#include "Couleur.h"
#include "Dimension.h"



class Block
{
    private:
    
        Position Block_Position;
        Dimension Block_Dimension;

        Couleur Block_Couleur;
        
        //Si c'est égal a true on peut se poser dessus. Sinon on le casse et on tombe
        //si Block_direction est égal a true alors le block va vers la gouche sinon vers la droite
        bool Block_Solide;
        bool Block_mobile;
        bool Block_direction;
        unsigned int Block_intervalle[2]; 
    public:

        Block();
        Block(Position Pos);
        Block(bool solide,bool mobile);


        /// @brief Constructeur de block initialisé avec les paramètre en donnée de couleur noir
        /// @param Pos 
        /// @param Dim 
        /// @param Coul 
        /// @param Solide 
        /// @param mobile 
        Block(Dimension Dim, Position Pos, bool Solide, bool mobile,bool direction, unsigned int intervalle[2]);

        ~Block();

        Position getPosition() const;

        Dimension getDimension() const;

        Couleur getCouleur() const;

        bool getSolide() const;

        bool getMobile() const;

        bool getDirection() const;

        unsigned int getIntervalle(int i) const;

        void setPosition(Position Position);

        void setDimension(Dimension Dimension);

        void setCouleur(Couleur Couleur);

        void setSolide(bool Solide);

        void setMobile(bool mobile);

        void setDirection(bool direction);

        void setIntervalle(unsigned int intervalle[2]);
    


};

#endif /* _BLOCK_H */

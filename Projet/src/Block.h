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
        bool Block_Solide;

    public:

        Block();
        Block(Position Position, Dimension Dimension, Couleur Couleur, bool Solide);
        ~Block();

        Position getPosition() const;
        Dimension getDimension() const;
        Couleur getCouleur() const;
        bool getSolide() const;

        void setPosition(Position Position);
        void setDimension(Dimension Dimension);
        void setCouleur(Couleur Couleur);
        void setSolide(bool Solide);
    



};

#endif /* _BLOCK_H */

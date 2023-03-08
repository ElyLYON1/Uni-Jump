#ifndef _BLOCK_H
#define _BLOCK_H
#include "Position.h"
#include "Couleur.h"


class Block
{

    Position Block_Position;

    Couleur Block_Couleur;

//Si c'est égal a true on peut se poser dessus. Sinon on le casse et on tombe
    bool Block_Solide;
    



};

#endif /* _BLOCK_H */

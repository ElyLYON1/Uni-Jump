#include "Block.h"
#include "Position.h"
#include "Dimension.h"
#include "Couleur.h"

#include <cassert>

#include <iostream>
using namespace std;


//Initialisation des attributs pour Block
Block::Block()
{
    Block_Position = Position();
    Block_Dimension = Dimension();
    Block_Couleur = Couleur();
    Block_Solide = false;
}

//Initialisation des attributs avec les paramettre en donné pour Block
Block::Block(Position Position, Dimension Dimension, Couleur Couleur, bool Solide)
{
    assert(Position.getPosX() >= 0);
    assert(Position.getPosY() >= 0);
    assert(Dimension.getLargeur() > 0);
    assert(Dimension.getHauteur() > 0);
    assert(Couleur.getRed() >= 0);
    assert(Couleur.getGreen() >= 0);
    assert(Couleur.getBlue() >= 0);
    Block_Position = Position;
    Block_Dimension = Dimension;
    Block_Couleur = Couleur;
    Block_Solide = Solide;
}

//Destructeur de Block
Block::~Block()
{
    Block_Position = Position();
    Block_Dimension = Dimension();
    Block_Couleur = Couleur();
    Block_Solide = false;
}

//Retourne la position du block
Position Block::getPosition() const
{
    return Block_Position;
}

//Retourne la dimension du block
Block::getDimension() const
{
    return Block_Dimension;
}

//Retourne la couleur du block
Block::getCouleur() const
{
    return Block_Couleur;
}

//Retourne la valeur de solide
bool Block::getSolide() const
{
    return Block_Solide;
}

//Modifie la position du block
void Block::setPosition(Position Position)
{
    assert(Position.getPosX() >= 0);
    assert(Position.getPosY() >= 0);
    Block_Position = Position;
}

//Modifie la dimension du block
void Block::setDimension(Dimension Dimension)
{
    assert(Dimension.getLargeur() > 0);
    assert(Dimension.getHauteur() > 0);
    Block_Dimension = Dimension;
}

//Modifie la couleur du block
void Block::setCouleur(Couleur Couleur)
{
    assert(Couleur.getRed() >= 0);
    assert(Couleur.getGreen() >= 0);
    assert(Couleur.getBlue() >= 0);
    Block_Couleur = Couleur;
}

//Modifie la valeur de solide
void Block::setSolide(bool Solide)
{
    Block_Solide = Solide;
}

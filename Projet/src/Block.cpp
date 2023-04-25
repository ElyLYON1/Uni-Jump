#include "Block.h"
#include "Position.h"
#include "Dimension.h"
#include "Couleur.h"

#include <cassert>

#include <iostream>
using namespace std;


//Initialisation des attributs pour Block
//4 types de block  mobiles, statiques et les cassables (par defaut ils sont solides statique)
Block::Block()
{
    Block_Position = Position();
    Block_Dimension = Dimension();
    Block_Couleur = Couleur();
    Block_Solide = true;
    Block_mobile=false;
    Block_direction=false;
    Block_intervalle[0]=0;
    Block_intervalle[1]=0;
}

Block::Block(Position Pos):Block_Position(Pos),Block_Dimension(),Block_Couleur(),Block_Solide(true),Block_mobile(false), Block_direction(false),Block_intervalle{0,0}
{
}


Block::Block(bool solide, bool mobile):Block_Position(),Block_Dimension(),Block_Couleur(),Block_Solide(solide),Block_mobile(mobile), Block_direction(false), Block_intervalle{0,0}
{
}

//Initialisation des attributs avec les paramettre en donné pour Block
Block::Block(Dimension Dim, Position Pos, bool Solide,bool Mobile,bool direction, unsigned int intervalle[2]):Block_Position(Pos),Block_Dimension(Dim),Block_Couleur(),Block_Solide(Solide),Block_mobile(Mobile),Block_direction(direction), Block_intervalle{intervalle[0],intervalle[1]}
{
    /*Je crois que les assertions sont inutiles car on a deja fait les verifications dans les constructeurs des classes Position, Dimension et Couleur

    assert(Position.getAbscisse() >= 0);
    assert(Position.getOrdonnee() >= 0);
    assert(Dimension.getLargeur() > 0);
    assert(Dimension.getHauteur() > 0);
    assert(Couleur.getRed() >= 0);
    assert(Couleur.getGreen() >= 0);
    assert(Couleur.getBlue() >= 0);

*/
}
  

//Faire peut etre une fonction perimètre 

//Destructeur de Block
Block::~Block()
{
    Block_Position = Position();
    Block_Dimension = Dimension();
    Block_Couleur = Couleur();
    Block_Solide = false;
    Block_mobile=false;
    Block_direction=false;
    Block_intervalle[0]=0;
    Block_intervalle[1]=0;
}

//Retourne la position du block
Position Block::getPosition() const
{
    return Block_Position;
}


//Retourne la dimension du bloc
Dimension Block::getDimension() const
{
    return Block_Dimension;
}

//Retourne la couleur du block
Couleur Block::getCouleur() const
{
    return Block_Couleur;
}

//Retourne la valeur de solide
bool Block::getSolide() const {  return Block_Solide; }

bool Block::getMobile() const {  return Block_mobile; }

bool Block::getDirection() const {  return Block_direction; }

unsigned int Block::getIntervalle(int i) const {  return Block_intervalle[i]; }

//Modifie la position du block
void Block::setPosition(Position Position)
{
    assert(Position.getAbscisse() >= 0);
    assert(Position.getOrdonnee() >= 0);
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

void Block::setMobile(bool mobile)
{
    Block_mobile = mobile;
}

void Block::setDirection(bool direction)
{
    Block_direction = direction;
}

void Block::setIntervalle(unsigned int intervalle[2])
{
    Block_intervalle[0]=intervalle[0];
    Block_intervalle[1]=intervalle[1];
}   
#include "Carte.h"
#include "Personnage.h"
#include "Block.h"
#include "Dimension.h"
#include "Position.h"


Carte::Carte():Carte_Dimension(Dimension()),Carte_perso(Personnage()),Carte_TabBlock(nullptr),taille_TabBlock(0
{
}

Carte::Carte(Dimension Dim, Personnage Perso, Block *TabBlock):Carte_Dimension(Dim),Carte_perso(Perso),Carte_TabBlock(TabBlock)
{
}

Carte::~Carte():Carte_Dimension(Dimension()),Carte_perso(Personnage()),Carte_TabBlock(nullptr),taille_TabBlock(0)
{
}

Dimension Carte::getDimCarte() const
{
    return Dimension();
}

Personnage Carte::getPerso() const
{
    return Personnage();
}

Block *Carte::getTabBlock() const
{
    return nullptr;
}

Block Carte::getBlock(int numBlock) const
{
    return Block();
}

int Carte::getTailleTabBlock() const
{
    return 0;
}

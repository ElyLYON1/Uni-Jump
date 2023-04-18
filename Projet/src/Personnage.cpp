#include "Personnage.h"
#include "Carte.h"
#include "Position.h"
#include "Dimension.h"

#include <cassert>

#include <unistd.h>
#include <cstring>
#include <iostream>
using namespace std;

// Initialisation des attributs pour Personnage
Personnage::Personnage()
{
    Perso_pseudo = "";
    Perso_Position = Position();
    Perso_Dim = Dimension();
    Perso_Vie = true;
    nbPixelParCarreau = 1;
    Perso_Saute = 0;
}

// Initialisation des attributs avec les paramettre en donné pour Personnage
Personnage::Personnage(string Pseude, Position Pos, Dimension Dim, unsigned int nbPixelParCarreau, unsigned int Saute)
{
    assert(Pos.getAbscisse() >= 0);
    assert(Pos.getOrdonnee() >= 0);
    assert(Dim.getLargeur() > 0);
    assert(Dim.getHauteur() > 0);
    assert(nbPixelParCarreau > 0);
    assert(Saute > 0);
    Perso_pseudo = Pseude;
    Perso_Position = Pos;
    Perso_Dim = Dim;
    Perso_Vie = true;
    nbPixelParCarreau = nbPixelParCarreau;
    Perso_Saute = Saute;
}

// Destructeur de Personnage
Personnage::~Personnage()
{
    Perso_pseudo = "";
    Perso_Position = Position();
    Perso_Dim = Dimension();
    Perso_Vie = false;
    nbPixelParCarreau = 0;
    Perso_Saute = 0;
}

// Retourne le pseudo du personnage
string Personnage::getPseudo() const
{
    return Perso_pseudo;
}

// Retourne la position du personnage
Position Personnage::getPosition() const
{
    return Perso_Position;
}

// Retourne la dimension du personnage
Dimension Personnage::getDimension() const
{
    return Perso_Dim;
}

// Retourne la vie du personnage
bool Personnage::getVie() const
{
    return Perso_Vie;
}

// Retourne le nombre de pixel par carreau
unsigned int Personnage::getNbPixelParCarreau() const
{
    return nbPixelParCarreau;
}

// Retourne la hauteur du saut du personnage
unsigned int Personnage::getSaut() const
{
    return Perso_Saute;
}

// Modifie le pseudo du personnage
void Personnage::setPseudo(string pseudo)
{
    Perso_pseudo = pseudo;
}

// Modifie la position du personnage
void Personnage::setPosition(Position Pos)
{
    assert(Pos.getAbscisse() >= 0);
    assert(Pos.getOrdonnee() >= 0);
    Perso_Position = Pos;
}

// Modifie l'abscisse du personnage
void Personnage::setAbscisse(unsigned int abscisse)
{
    assert(abscisse >= 0);
    Perso_Position.setAbscisse(abscisse);
}

// Modifie l'ordonnée du personnage
void Personnage::setOrdonnee(unsigned int ordonnee)
{
    assert(ordonnee >= 0);
    Perso_Position.setOrdonnee(ordonnee);
}

// Modifie la dimension du personnage
void Personnage::setDimension(Dimension Dimension)
{
    assert(Dimension.getLargeur() > 0);
    assert(Dimension.getHauteur() > 0);
    Perso_Dim = Dimension;
}

// Modifie la vie du personnage
void Personnage::setVie(bool vie)
{
    assert(vie == true || vie == false);
    Perso_Vie = vie;
}

// Modifie le nombre de pixel par carreau
void Personnage::setNbPixelParCarreau(unsigned int nbPixel)
{
    assert(nbPixel > 0);
    nbPixelParCarreau = nbPixel;
}

// Modifie la hauteur du saut du personnage
void Personnage::setSaut(unsigned int saut)
{
    assert(saut > 0);
    Perso_Saute = saut;
}

// Fonction qui permet de faire sauter le personnage
void Personnage::perso_versGauche()
{
    Perso_Position.setAbscisse(Perso_Position.getAbscisse() - nbPixelParCarreau);
}

// Fonction qui permet de faire tomber le personnage
void Personnage::perso_versDroite()
{
    Perso_Position.setAbscisse(Perso_Position.getAbscisse() + nbPixelParCarreau);
}

// Fonction qui permet de faire sauter le personnage
void Personnage::perso_sauter()
{ 
     //   unsigned int i;
    //for(i=0;i<Perso_Saute;i++)
    //{
    Perso_Position.setOrdonnee(Perso_Position.getOrdonnee() + 1);
    //    usleep(500000);

    //}
}


// Fonction qui permet de faire tomber le personnage
void Personnage::perso_tomber()
{
    Perso_Position.setOrdonnee(Perso_Position.getOrdonnee() - nbPixelParCarreau);
}

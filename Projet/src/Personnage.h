#ifndef _PERSSONNAGE_H
#define _PERSSONNAGE_H
#include <iostream>
#include <cassert>
#include <cstring>
#include "Dimension.h"
#include "Position.h"

class Personnage
{
private:
    // nom du personnage
    std::string Perso_pseudo;
    // position du personnage
    Position Perso_Position;
    // dimension du personnage
    Dimension Perso_Dim;
    // nom ficher image du personnage
    // std::string Perso_image;
    // si est vivant ou mort
    bool Perso_Vie;

    // nombre de pixel par carreau
    unsigned int nbPixelParCarreau;
    // puissance de saut,  hauteur de chaque saut. Nb de carre monté par saut
    unsigned int Perso_Saute;

public:
    Personnage();
    Personnage(std::string Pseudo, Position Pos, Dimension Dim, unsigned int nbPixelParCarreau, unsigned int Saut);
    ~Personnage();

    std::string getPseudo() const;
    Position getPosition() const;
    Dimension getDimension() const;
    // std::string getImage() const;
    bool getVie() const;
    unsigned int getNbPixelParCarreau() const;
    unsigned int getSaut() const;

    void setPseudo(std::string pseudo);
    void setPosition(Position Pos);
    void setAbscisse(unsigned int abscisse);
    void setOrdonnee(unsigned int ordonnée);
    void setDimension(Dimension Dim);
    // void setImage(std::string image);
    void setVie(bool vie);
    void setNbPixelParCarreau(unsigned int nbPixelParCarreau);
    void setSaut(unsigned int saut);

    void perso_versGauche();
    void perso_versDroite();
    void perso_sauter();
    void perso_tomber();

};
#endif
#ifndef _PERSSONNAGE_H
#define _PERSSONNAGE_H
#include <iostream>
#include <cassert>
#include <cstring>
#include "Dimension.h"
#include "Position.h"
/**
 * @class Personnage[Personnage.hpp]
 * @brief Regroupe les caractéristiques de notre joueur.
 * @details 'Personnage' précise toutes les caractéristiques et fonctions nécessaire à notre joueur dans le 'Jeu'.
 */ 
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
    /// @brief Constructeur de la class 'Personnage'
    Personnage();
    Personnage(std::string Pseudo, Position Pos, Dimension Dim, unsigned int nbPixelParCarreau, unsigned int Saut);
    
    ///@brief Destructeur de la class 'Personnage'
    ~Personnage();

    /// @brief Avoir le Pseudo de personnage.
    /// @return Une chaine de caractères représentant le pseudo du joueur.
    std::string getPseudo() const;

    /// @brief Avoir la position de notre joueur.
    /// @return Position de joueur sur la carte. 
    Position getPosition() const;

    /// @brief Avoir la dimension de notre personnage. 
    /// @return Dimension de personnage.
    Dimension getDimension() const;
    // std::string getImage() const;

    /// @brief Verifie la vie de notre joueur.
    /// @return 'True' si le personnage est vivant, 'false' sinon.
    bool getVie() const;

    /// @brief Le nombre de pixel par Carreau pour avoir les dimensions. 
    /// @return Nombre de pixel par carreau.
    unsigned int getNbPixelParCarreau() const;

    /// @brief Avoir le niveau de saut de personnage sur la carte.
    /// @return Saut de joueur.
    unsigned int getSaut() const;

    /// @brief Modifie le psudo de personnage.
    /// @param[in] pseudo le nouveau pseudo à mettre. 
    void setPseudo(std::string pseudo);

    /// @brief Nouvelle position de notre joueur.
    /// @param[in] Pos Nouvelle position de notre personnage sur la carte. 
    void setPosition(Position Pos);

    /// @brief Changer l'abscisse pour le déplacement horizental du personnage sur la carte. 
    /// @param[in] abscisse Nouveau abscisse.
    void setAbscisse(unsigned int abscisse);

    /// @brief Changer l'ordonné pour le déplacement vertical du personnage sur la carte.
    /// @param[in] ordonnée Nouveau ordonnée. 
    void setOrdonnee(unsigned int ordonnée);

    /// @brief Modifier la dimension.
    /// @param[in] Dim La nouvelle dimension à remplacer avec.  
    void setDimension(Dimension Dim);
    // void setImage(std::string image);

    /// @brief Modifier la vie de notre personnage.
    /// @param[in] vie La nouvelle 'vie' à mettre. 
    void setVie(bool vie);

    /// @brief Changement du nombre de pixel par chaque carreau sur la carte.
    /// @param[in] nbPixelParCarreau Le nouveau nombre de pixels à mettre par carreau.
    void setNbPixelParCarreau(unsigned int nbPixelParCarreau);

    /// @brief Modifie le niveau de saut du personnage sur la carte.
    /// @param[in] saut Le nouveau saut à adopter.
    void setSaut(unsigned int saut);

    /// @brief Changement du direction du personnage vers la gauche. 
    void perso_versGauche();

    /// @brief Changement du direction du personnage vers la droite.
    void perso_versDroite();

    /// @brief Faire sauter le personnage.  
    void perso_sauter();

    /// @brief Faire tomber le personnage. 
    void perso_tomber();

};
#endif
#ifndef _DIMENSION_H
#define _DIMENSION_H
/**
 * @class Dimension [Dimension.hpp]
 * @brief Regroupe Le côté dimensionnement des caractéristique du jeu.
 * @details Récupèrer et modifier les dimensionnements de nos objets du jeu Carte, Personnage, Block...
 * et les utiliser pour ajuster les positinements. 
*/

class Dimension
{
    private:
        /// @brief les Attributs utilisés pour les dimensions. 
        unsigned int Dim_Largeur,Dim_Hauteur;

    public:
        /// @brief Contructeur de la class.
        Dimension();
        Dimension(unsigned int Largeur, unsigned int Hauteur);

        ///@brief Destructeur de la class.
        ~Dimension();

        /// @brief Avoir les largueurs et les hauteurs de nos objets du jeu.
        /// @return Largueur et hauteur. 
        unsigned int getLargeur() const;
        unsigned int getHauteur() const;

        /// @brief Modifier la hauteur ou la largueur d'un objet.
        
        /// @param[in] Largeur Nouvelle Largeur. 
        void setLargeur(unsigned int Largeur); 

        /// @param Hauteur Nouvelle Hauteur.
        void setHauteur(unsigned int Hauteur);


};
#endif /* _DIMENSION_H */

#ifndef _POSITION_H
#define _POSITION_H
/**
 * @class Position[Position.hpp]
 * @brief Gère le positionnement de nos objets du jeu.
 * @details Regroupe les fonctions nécessaires au traitement du positionement lié au jeu. 
*/
class Position
{
private:
    /// @brief Le système de positionnement avec des abs X et ord Y.
    int Pos_abscisse,Pos_ordonnee;



public:
    /// @brief Constructeur de la class.
    Position(/* args */);
    Position(unsigned int abscisse, unsigned int ordonnee);

    ///@brief Destructeur de la class.
    ~Position();

    /// @brief Récupèrer l'abscisse 'x' d'objet.
    /// @return Abscisse 'x'.
    unsigned int getAbscisse() const;

    /// @brief Récupèrer l'ordonnée 'Y' d'objet.
    /// @return Ordonnée 'Y'
    unsigned int getOrdonnee() const;

    /// @brief Avoir la distance à l'objet à partir d'une position.
    /// @param[in] Pos La position à partir de laquelle on calcule la distance. 
    /// @return Distance.
    unsigned int getDistance(const Position &Pos) const;

    /// @brief Avoir la disctance suivant l'axe des abscisses 'x'.
    /// @param [in] Point2 
    /// @return Distance suivant 'x'.
    unsigned int getDistanceAbs(const Position &Point2) const;

    /// @brief Modifier la composante des abscisses 'x'.
    /// @param abscisse Nouveau abscisse 'x'.
    void setAbscisse(unsigned int abscisse);

    /// @brief Modifier la composante des ordonnées 'Y'.
    /// @param ordonnee Nouvel ordonnée 'Y'.
    void setOrdonnee(unsigned int ordonnee);

   /// @brief Surcharger l'operateur d'affectation pour les positions.
   /// @param [in] positon Position à affecter. 
   /// @return Position.
   Position& operator = (const Position &positon);

   /// @brief Surcharge d'operateur d'égalité pour pour la comparison des positions.
   /// @param[in] p la position comparée. 
   /// @return 'True' si les deux positions sont égales, 'false' sinon.
   bool operator ==(const Position &p);
};

#endif /* _POSITION_H */

#ifndef _COULEUR_H
#define _COULEUR_H
/**
 * @class Couleur [Couleur.hpp]
 * @brief Traite le côté couleur du jeu avec le système RGB.
*/
class Couleur
{
    private:
    
        /* data */
        unsigned char Couleur_Red, Couleur_Green, Couleur_Blue;
        
    public :
        /// @brief Constructeur de la class.
        Couleur();
        Couleur(unsigned char Red, unsigned char Green, unsigned char Blue);

        ///@brief Destructeur de la class.
        ~Couleur();

        /// @brief Récupère les composantes RGB des couleurs.
        /// @return R G B 
        unsigned char getRed() const;
        unsigned char getGreen() const;
        unsigned char getBlue() const;

        /// @brief Changer les pixels avec le système RGB.
        /// @param[in] Red La composante RGB à mettre.
        void setRed(unsigned char Red);
        void setGreen(unsigned char Green);
        void setBlue(unsigned char Blue);
};




#endif // _COULEUR_H_

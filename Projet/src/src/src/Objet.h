#ifndef _OBJET_H
#define _OBJET_H
#include "Block.h"
#include "Dimension.h"

/**
 * @class Objet[Objet.hpp]
 * @brief Regroupe nos objets du jeu.
*/

class Objet
{
private:
    /// @brief Les objets du jeu. 
    Block Objet_Block;
    Dimension Objet_Dim;
    

    /* data */
public:
    /// @brief Contructeur de la class.
    Objet(/* args */) {}

    ///@brief Destructeur de la class. 
    ~Objet() {}
};

#endif /* _OBJET_H */

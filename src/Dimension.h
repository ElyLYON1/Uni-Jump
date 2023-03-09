#ifndef _DIMENSION_H
#define _DIMENSION_H

class Dimension
{
    private:

        unsigned int Dim_Largeur,Dim_Hauteur;

    public:
        Dimension(){};
        Dimension(unsigned int Largeur, unsigned int Hauteur);
        ~Dimension() {};

        unsigned int getLargeur() const;
        unsigned int getHauteur() const;
        void setLargeur(unsigned int Largeur);
        void setHauteur(unsigned int Hauteur);


};
#endif /* _DIMENSION_H */

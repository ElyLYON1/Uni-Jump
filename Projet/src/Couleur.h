#ifndef _COULEUR_H
#define _COULEUR_H

class Couleur
{
    private:
    
        /* data */
        unsigned char Couleur_Red, Couleur_Green, Couleur_Blue;
        
    public :
        Couleur();
        Couleur(unsigned char Red, unsigned char Green, unsigned char Blue);
        ~Couleur();

        unsigned char getRed() const;
        unsigned char getGreen() const;
        unsigned char getBlue() const;
        void setRed(unsigned char Red);
        void setGreen(unsigned char Green);
        void setBlue(unsigned char Blue);
};




#endif // _COULEUR_H_

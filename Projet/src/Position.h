#ifndef _POSITION_H
#define _POSITION_H

class Position
{
private:

    int Pos_abscisse,Pos_ordonnee;



public:
    Position(/* args */);

    Position(unsigned int abscisse, unsigned int ordonnee);

    ~Position();

//Accesseurs
    unsigned int getAbscisse() const;
    unsigned int getOrdonnee() const;
    unsigned int getDistance(const Position &Pos) const;
    unsigned int getDistanceAbs(const Position &Point2) const;

    // Mutateurs
    void setAbscisse(unsigned int abscisse);
    void setOrdonnee(unsigned int ordonnee);

//Surcharge d'opérateurs

   Position& operator = (const Position &positon);

   bool operator ==(const Position &p);
};

#endif /* _POSITION_H */

#ifndef _POSITION_H
#define _POSITION_H

class Position
{
private:

    int Pos_abscisse,Pos_ordonnee;



public:
    Position(/* args */) {}
    Position(int abscisse, int ordonnee);
    ~Position() {}

    unsigned int getAbscisse() const;
    unsigned int getOrdonnee() const;
    unsigned int getDistance(Position Pos) const;
    void setAbscisse(unsigned int abscisse);
    void setOrdonnee(unsigned int ordonnee);
    
};

#endif /* _POSITION_H */

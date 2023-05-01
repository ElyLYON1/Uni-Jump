#include "Carte.h"
#include "Personnage.h"
#include "Position.h"
#include "Block.h"
#include <ctime>
#include <random>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <iostream>
#include <cassert>
using namespace std;



Carte::Carte():Carte_Dimension(),Carte_perso(),Carte_TabBlock(), Carte_TabObjet(), nbSautmax(0),score(0),objet(0)
{
    
}

Carte::Carte(Dimension Dim, Personnage Perso, std::vector<Block> tabBlock, std::vector<Block> tabObjet) : Carte_Dimension(Dim), Carte_perso(Perso), Carte_TabBlock(tabBlock), Carte_TabObjet(tabObjet), nbSautmax(0), score(0),objet(0)
{
    //Ou je mets un if ici et en fonction de la difficulté je change les valeurs du nb de block et des proba et de la dimension de la carte
    //Ou je mets en paramètre un tableau de block qui auront deja été definis en fonctions de la difficulté donc plus besoin de nbblock ni de difficulté.

}


Carte::~Carte()
{
    Carte_Dimension = Dimension(0,0);
    Carte_TabBlock.clear();    
}


Dimension Carte::getDimCarte() const
{
    return Carte_Dimension;
}

Personnage Carte::getPerso() const
{
    return Carte_perso;
}


Block Carte::getBlock(int numBlock) const
{
    return Carte_TabBlock[numBlock];
}

std::vector<Block> Carte::getTabBlock() const
{
    return std::vector<Block>();
}



void Carte::setDimension(Dimension Dim)
{
    Carte_Dimension = Dim;
}




void Carte::setPerso(Personnage Perso)
{
    Carte_perso=Perso;
}






bool Carte::PersoSurBlock()
{
    for (long unsigned int i = 0; i < Carte_TabBlock.size(); i++)
    {
        if(Carte_perso.getPosition()==Carte_TabBlock[i].getPosition())
        return true;
    }
    return false;

}

bool Carte::PersoSurObjet()
{
    for (long unsigned int i = 0; i < Carte_TabObjet.size(); i++)
    {
        if(Carte_perso.getPosition()==Carte_TabObjet[i].getPosition())
        return true;
    }
    return false;

}

void Carte::actionClavier (const char touche)
 {
	
    switch(touche) 
    {
		case 'g' :
				if (Carte_perso.getPosition().getAbscisse() > 0){
                    Carte_perso.perso_versGauche();
                }
                else if (Carte_perso.getPosition().getAbscisse() == 0)
                {
                    Carte_perso.setAbscisse(Carte_Dimension.getLargeur() - 1);
                }
        
                
				break;
		case 'd' :
				Carte_perso.perso_versDroite();
                if (Carte_perso.getPosition().getAbscisse() >= Carte_Dimension.getLargeur())
                {
                    Carte_perso.setAbscisse(0);
                }
                
                
				break;
		case 's' :
				
                
                
                
                if(nbSautmax ==0){
                    Carte_perso.perso_sauter();
                    ajouteSaut();
                }
                
                    
                
				break;
	
    }
}

unsigned int Carte::getnbSaut() const{
    return nbSautmax;
}


unsigned int Carte::getScore() const{
    return score;
}

void Carte::ajouteSaut(){
    nbSautmax++;
}

void Carte::PersoGravite()
{
    if(persoSurBlock2()==false)
    {
        Carte_perso.setOrdonnee(Carte_perso.getPosition().getOrdonnee() - 1);
    }
}

bool Carte::persoSurBlock2(){
    unsigned int i = Carte_perso.getPosition().getOrdonnee();
    unsigned int j = Carte_perso.getPosition().getAbscisse();
    for (long unsigned int k = 0; k < Carte_TabBlock.size(); k++)
    {
        if (Carte_TabBlock[k].getPosition().getOrdonnee() == i && Carte_TabBlock[k].getPosition().getAbscisse() == j)
        {
            return true;
        }
    }
    return false;
}

bool Carte::persoSurBlock3(Block b){
    unsigned int i = Carte_perso.getPosition().getOrdonnee();
    unsigned int j = Carte_perso.getPosition().getAbscisse();
    if (b.getPosition().getOrdonnee() == i && b.getPosition().getAbscisse() == j)
    {
        return true;
    }
    if( b.getPosition().getOrdonnee() == i && b.getPosition().getAbscisse() == j-1)
    {
        return true;
    }
    if (b.getPosition().getOrdonnee() == i && b.getPosition().getAbscisse() == j+1)
    {
        return true;
    }

    return false;
}

bool Carte::persoSurObjet2(){
    unsigned int i = Carte_perso.getPosition().getOrdonnee();
    unsigned int j = Carte_perso.getPosition().getAbscisse();
    if(Carte_TabObjet.empty()==false){
        for (long unsigned int k = 0; k < Carte_TabObjet.size(); k++)
        {
            if (Carte_TabObjet[k].getMobile()==false)
                if (Carte_TabObjet[k].getPosition().getOrdonnee() == i && Carte_TabObjet[k].getPosition().getAbscisse() == j)
                {
                    return true;
                }
            if (Carte_TabObjet[k].getMobile()==true)
                if (Carte_TabObjet[k].getPosition().getOrdonnee() == i && Carte_TabObjet[k].getPosition().getAbscisse() == j)
                {
                    return true;
                }
            if (Carte_TabObjet[k].getMobile()==true)
                if (Carte_TabObjet[k].getPosition().getOrdonnee() == i && Carte_TabObjet[k].getPosition().getAbscisse() == j-1)
                {
                    return true;
                }
            if (Carte_TabObjet[k].getMobile()==true)
                if (Carte_TabObjet[k].getPosition().getOrdonnee() == i && Carte_TabObjet[k].getPosition().getAbscisse() == j+1)
                {
                    return true;
                }
            
            
        }
    }
    return false;
}


bool Carte::persoSurBlockGravite(){
    if (persoSurBlock2() && nbSautmax % (Carte_perso.getSaut() +1) == 0)
    {
        return true;
    }
    return false;
}





//fonction qui place le personage sur le premier block avec ordonnèe 2 dans la carte
void Carte::Block_PersoInit1()
{
    int abscisse = (rand() % Carte_Dimension.getLargeur());
    int ordonnee = 2;
    Position pos1(abscisse, ordonnee);
    Carte_perso.setPosition(pos1);
    Block b(pos1);
    ajouterBlock(b);
    nbSautmax = 0;
    objet = 0;
    score = 0;
}

//fonction qui place le block sur la carte
void Carte::Block_Init2()
{
    int i = Carte_TabBlock.size()-1;
    int saut = Carte_perso.getSaut();
    int maxLargeur = Carte_Dimension.getLargeur();
    while (getBlock(i).getPosition().getOrdonnee() <= Carte_Dimension.getHauteur() - 3 ){
        int abscisse = (rand() % maxLargeur);
        int ordonnee = getBlock(i).getPosition().getOrdonnee() + rand() % (saut-2) +1;
        int type = rand() % (i+1);
        Position pos1(abscisse, ordonnee);
        Block b(pos1);
        if (type<5){
            b.setMobile(false);
        }
        else{
            b.setMobile(true);
               
        }
        b.setDirection(rand() % 2);
        unsigned int interval[2];
        interval[0] = rand() % (abscisse + 1) - 1;
        interval[1] = rand() % (maxLargeur - abscisse) + abscisse;
        b.setIntervalle(interval);
        ajouterBlock(b);
        
        if (i>7){
            if(rand()%100 + 1  > 85){
                ajouterObjet(b);
            }
        }
        
        i++;


    }

}





int Carte::getTailleTabBlock() const
{
 
    return Carte_TabBlock.size();
}

int Carte::getTailleTabObjet() const
{
    return Carte_TabObjet.size();
}


bool Carte::blockSurPos(int x ,int y)const
{
    Position p(x,y);
    for (long unsigned int i = 0; i < Carte_TabBlock.size(); i++)
        {
            if(Carte_TabBlock[i].getPosition()==p)
            {
            return  true;
            }

        }
             
            
                return false ;
}

bool Carte::objetSurPos(unsigned int x ,unsigned int y)const
{
    Position p(x,y);
    //si le tableau est null renvoie false
    if (Carte_TabObjet.empty()){
        return false;
    }
    for (long unsigned int i = 0; i < Carte_TabObjet.size(); i++)
        {
            if(Carte_TabObjet[i].getPosition()==p)
            {
            return  true;
            }
        } 
                return false ;
}


//fonction qui remplace le block sur la carte
void Carte::setBlock(int numBlock, Block b)
{
    if( numBlock < getTailleTabBlock()){
        Carte_TabBlock[numBlock] = b;
    }
    else    {
        std::cout << "Erreur : le numéro de block est trop grand" << std::endl;
    }    
}

//fonction qui ajoute un block à la carte
void Carte::ajouterBlock(Block b)
{
    Carte_TabBlock.push_back(b);
}

void Carte::ajouterObjet(Block b)
{
    Carte_TabObjet.push_back(b);
}






void Carte::tout_deplacer()
{
    const int positionordonee = 2;
    int difference = Carte_perso.getPosition().getOrdonnee()-positionordonee;
    for(int i=0; i<getTailleTabBlock();i++){
        Position pos = Carte_TabBlock[i].getPosition();
        pos.setOrdonnee(pos.getOrdonnee()-difference);
        Carte_TabBlock[i].setPosition(pos);
    }
     
    if (Carte_TabObjet.empty() == false )
    {
        for(int i=0; i<getTailleTabObjet();i++){
            Position pos2 = Carte_TabObjet[i].getPosition();
            pos2.setOrdonnee(pos2.getOrdonnee()-difference);
            Carte_TabObjet[i].setPosition(pos2);
        }    
    }
    Carte_perso.setOrdonnee(positionordonee);
}

void Carte::deplacerBlockmobile(){
    for(int i=0; i<getTailleTabBlock();i++){
        if (Carte_TabBlock[i].getMobile()==true){
            Position pos = Carte_TabBlock[i].getPosition();
            if(pos.getAbscisse() == Carte_TabBlock[i].getIntervalle(1)){
                Carte_TabBlock[i].setDirection(0);
            }
            if (pos.getAbscisse() == Carte_TabBlock[i].getIntervalle(0)){
                Carte_TabBlock[i].setDirection(1);
            }
            if(Carte_TabBlock[i].getDirection()==1){    
                pos.setAbscisse(pos.getAbscisse()+ 1);
            }
            if(Carte_TabBlock[i].getDirection()==0){
                pos.setAbscisse(pos.getAbscisse()-1);
            }
            
            Carte_TabBlock[i].setPosition(pos);
        }
    }
}

void Carte::deplacerObjetmobile(){
    for(int i=0; i<getTailleTabObjet();i++){
        if (Carte_TabObjet[i].getMobile()==true){
            Position pos = Carte_TabObjet[i].getPosition();
            if(pos.getAbscisse() == Carte_TabObjet[i].getIntervalle(1)){
                Carte_TabObjet[i].setDirection(0);
            }
            if (pos.getAbscisse() == Carte_TabObjet[i].getIntervalle(0)){
                Carte_TabObjet[i].setDirection(1);
            }
            if(Carte_TabObjet[i].getDirection()==1){    
                pos.setAbscisse(pos.getAbscisse()+ 1);
            }
            if(Carte_TabObjet[i].getDirection()==0){
                pos.setAbscisse(pos.getAbscisse()-1);
            }
            
            Carte_TabObjet[i].setPosition(pos);
        }
    }
}

void Carte::deplacerSiObjet(){
    if (persoSurObjet2()){
        objet = 1;
    }
    if(objet == 1){
        if (Carte_perso.getPosition().getOrdonnee() != Carte_Dimension.getHauteur()*2/3){
            Carte_perso.setOrdonnee(Carte_perso.getPosition().getOrdonnee()+1);
        }
        if(Carte_perso.getPosition().getOrdonnee() == Carte_Dimension.getHauteur()*2/3){
            objet = 0;
        }
    }
    
}


void Carte::viePerdue(){
    if (Carte_perso.getPosition().getOrdonnee() == 0){
        Carte_perso.setVie(false);
    }
}

bool Carte::getViePerso(){
    return Carte_perso.getVie();
}


void Carte::compteurScore(){
    if (persoSurBlock2()==true && Carte_perso.getPosition().getOrdonnee() != 2){
        score=score+1;
    }
    
}



void Carte::boucleJeu(){
        if (persoSurBlockGravite()){
                tout_deplacer();
                Block_Init2();
                compteurScore();
            
        }
        if (Carte_TabObjet.empty() == false )
            {
                deplacerObjetmobile();
                deplacerSiObjet();
            }
        if (objet == 1){
            deplacerSiObjet();
        }    
        if (persoSurBlock2() || nbSautmax % (Carte_perso.getSaut() +1) > 0){
            Carte_perso.perso_sauter();
            ajouteSaut();
        }    
        if (nbSautmax % (Carte_perso.getSaut() +1) == 0)
        {
            if (persoSurBlock2()==false && Carte_perso.getPosition().getOrdonnee() > 0)
            {
                PersoGravite();
            }
        }
        deplacerBlockmobile();
        
    viePerdue();
}


void Carte::testRegression()
{
    Carte c1;
    Dimension d1(100,100);
    assert(c1.getDimCarte().getLargeur()==0);
    assert(c1.getDimCarte().getHauteur()==0);

    assert(c1.getTailleTabBlock()==0);
    assert(c1.getPerso().getPosition().getAbscisse()==0);
    assert(c1.getPerso().getPosition().getOrdonnee()==0);

    c1.setDimension(d1);
    assert(c1.getDimCarte().getLargeur()==100);
    assert(c1.getDimCarte().getHauteur()==100);

    c1.actionClavier('g');
    assert(c1.getPerso().getPosition().getAbscisse()==c1.getDimCarte().getLargeur()-1);

    c1.actionClavier('d');
    assert(c1.getPerso().getPosition().getAbscisse()==1);
    
}
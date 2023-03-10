#include "Carte.h"
#include "Personnage.h"
#include "Block.h"
#include "Dimension.h"
#include "Position.h"
#include <ctime>
#include <random>
#include <stdlib.h>
#include <time.h>

Carte::Carte():Carte_Dimension(),Carte_perso(),Carte_TabBlock(nullptr)
{
}

Carte::Carte(Dimension Dim, Personnage Perso, Block *tabBlock) : Carte_Dimension(Dim), Carte_perso(Perso), Carte_TabBlock()
{
    //Ou je mets un if ici et en fonction de la difficulté je change les valeurs du nb de block et des proba et de la dimension de la carte
    //Ou je mets en paramètre un tableau de block qui auront deja été definis en fonctions de la difficulté donc plus besoin de nbblock ni de difficulté.


}


Carte::~Carte()
{
    delete[] Carte_TabBlock;
}

void Carte::setDimension(Dimension Dim)
{
    Carte_Dimension = Dim;
}

void Carte::setPerso(Personnage Perso)
{
    Carte_perso=Perso;
}
/*
void Carte::setTabBlock(Block *TabBlock)
{
    if(Carte_taille_TabBlock >= sizeof(TabBlock)/sizeof(TabBlock[0]))
    {
        Carte_TabBlock = new Block[sizeof(TabBlock) / sizeof(TabBlock[0])];
    }
 
    for (int i = 0; i < Carte_taille_TabBlock; i++)
    {
        Carte_TabBlock[i] = TabBlock[i];
    }
}

*/
int Carte::getnbEtage()
{  
     return Carte_Dimension.getHauteur()/Carte_perso.getSaut();

}

//Boucle for pour definir l'étage et le while pour remplir l'étage de block et le switch pour definir le type de block
void Carte::remplirModeFacile(int difficulté)
{
   for(int i=0;i<=getnbEtage();i++)
   {
       int nbBlockEtage = (rand() % 3) + 1;

       do
       {
           int TypeBlock = (rand() % 4) + 1;
           int TailleBlock= (rand() % 2) + 1;
           Dimension d(Carte_Dimension.getLargeur() / 10, 1);

           //Position aléatoire en largeur mais toujours sur le même étage (Vérifier la distance entre les blocks du meme etage)

           int abscisse = (rand() % Carte_Dimension.getLargeur());
           Position p(abscisse, Carte_perso.getSaut()-1);

           switch (TypeBlock)
           {

           case 1:
               Block b(d,p, 1, 1);
               break;
           case 2:
               Block b(d,p, 1, 0);
               break;
           case 3:
               Block b(d,p, 0, 1);
               break;
           case 4:
               Block b(d,p, 0,0);
               break;

           }


           Dimension d (Carte_Dimension.getLargeur()/10, 1);

           b.setDimension(d);

            Carte_TabBlock.push_back(b);
        
  





           nbBlockEtage--;

        } while (nbBlockEtage != 0)

   }



}

void Carte::viderTabBlock()
{

}

Dimension Carte::getDimCarte() const
{
    return Carte_Dimension;
}

Personnage Carte::getPerso() const
{
    return Carte_perso;
}

Block *Carte::getTabBlock() const
{
    return nullptr;
}

Block Carte::getBlock(int numBlock) const
{
    return Carte_TabBlock[numBlock];
}

int Carte::getTailleTabBlock() const
{
  //  sizeof(Carte_TabBlock) / sizeof(Carte_TabBlock[0]);
    return Carte_taille_TabBlock;
}

int Carte::getTailleUtilisee() const
{
    if(sizeof(Carte_TabBlock=!0))
{
    return sizeof(Carte_TabBlock) / sizeof(Carte_TabBlock[0]);

}
else
{
    return 0;
}
}


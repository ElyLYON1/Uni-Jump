#include "Carte.h"
#include <ctime>
#include <random>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <cassert>
#include <unistd.h>

Carte::Carte():Carte_Dimension(),Carte_perso(),Carte_TabBlock()
{

}

Carte::Carte(Dimension Dim, Personnage Perso, std::vector<Block> tabBlock) : Carte_Dimension(Dim), Carte_perso(Perso), Carte_TabBlock(tabBlock)
{
    //Ou je mets un if ici et en fonction de la difficulté je change les valeurs du nb de block et des proba et de la dimension de la carte
    //Ou je mets en paramètre un tableau de block qui auront deja été definis en fonctions de la difficulté donc plus besoin de nbblock ni de difficulté.

}


Carte::~Carte()
{
    Carte_Dimension = Dimension(0,0);
    Carte_TabBlock.clear();    
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
   for(int i=1;i<=getnbEtage();i++)
   {
       int nbBlockEtage = (rand() % 3) + 1;

       do
       {
           int TypeBlock = (rand() % 4) + 1;
           int TailleBlock= (rand() % 2) + 1;

           int abscisse = (rand() % Carte_Dimension.getLargeur());
           int ordonnee = Carte_perso.getSaut() * i;


           // Position aléatoire  en largeur mais toujours sur le même étage (sans chevauchement)
           if (nbBlockEtage > 1)
           {
               Block blockprecedent = Carte_TabBlock.back();
               Position p(abscisse, ordonnee);

               do
               {

                   int abscisse = (rand() % Carte_Dimension.getLargeur());

                     p.setAbscisse(abscisse);

               } while (p.getDistanceAbs(blockprecedent.getPosition()) > Carte_Dimension.getLargeur() * (30 / 100)); // Un block double fait 20% de la map donc on prend au dessus  

           

            // Si la valeur aléatoire est 2 c'est un block simple sinon un block double
            //Le num de l'étage multiplié par la hauteur de chaque saut - 10% du saut pour pouvoir atterir dessus
               Dimension d(Carte_Dimension.getLargeur() / TailleBlock * 5, i * Carte_perso.getSaut() - Carte_perso.getSaut()/10);

           switch (TypeBlock)
           {

           case 1:
           {
               Block b1(d,p, 1, 1);
               Carte_TabBlock.push_back(b1);

               break;
           }
           case 2:
           {
               Block b2(d,p, 1, 0);
               Carte_TabBlock.push_back(b2);

               break;
           }
           case 3:
           {
               Block b3(d,p, 0, 1);
               Carte_TabBlock.push_back(b3);

               break;
           }
           case 4:
           {
               Block b4(d,p, 0,0);
               Carte_TabBlock.push_back(b4);

               break;
           }

            default:
            {

            Block b1,b2,b3,b4;

            }



           }
           }
           nbBlockEtage--;


        } while (nbBlockEtage != 0);

   


}

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

void Carte::actionClavier (const char touche)
 {


	switch(touche) 
    {
		case 'g' :
				Carte_perso.perso_versGauche();
                if (Carte_perso.getPosition().getAbscisse() <= 0)
                {
        Carte_perso.setAbscisse(Carte_Dimension.getLargeur() - 1);
                }
                break;
		case 'd' :
				Carte_perso.perso_versDroite();
                if (Carte_perso.getPosition().getAbscisse() >= Carte_Dimension.getLargeur())
                {
        Carte_perso.setAbscisse(1);
                }
                break;
		case 's' :
                unsigned int i;
                for (i = 0; i < Carte_perso.getSaut(); i++)
                {
        Carte_Perso.getPosition().setOrdonnee(Carte_Perso.getPosition().getOrdonnee() + 1);

        usleep(500000);

                }
        if ((Carte_perso.getPosition().getOrdonnee() + Carte_perso.getSaut()) > Carte_Dimension.getHauteur())
        {
           Carte_perso.setOrdonnee(0);
        }

        PersoGravite();
        break;
                }
}

void Carte::actionauto()
{
    Carte_perso.perso_tomber();
    

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

int Carte::getTailleTabBlock() const
{
  //  sizeof(Carte_TabBlock) / sizeof(Carte_TabBlock[0]);
    return Carte_TabBlock.size();
}

int Carte::getTailleUtilisee() const
{
    if(getTailleTabBlock()!=0)
{
    return sizeof(Carte_TabBlock) / sizeof(Carte_TabBlock[0]);

}
else
{
    return 0;
}

}

/*
Fonction simplifié du remplissage des blocks pout l'affichage txt

void Carte::remplirTabBlockTxt () 
{
    for(int i=1;i<=getnbEtage();i++)
    {
        int nbBlockEtage = (rand() % 3) + 1;
}

}


*/

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
// fonction qui place le block sur la carte
void Carte::Block_Init2()
{
                int i = 0;
                int saut = Carte_perso.getSaut();
                int maxLargeur = Carte_Dimension.getLargeur();
                while (getBlock(i).getPosition().getOrdonnee() <= Carte_Dimension.getHauteur() - 3)
                {
            int abscisse = (rand() % maxLargeur);
            int ordonnee = getBlock(i).getPosition().getOrdonnee() + rand() % (saut - 1) + 1;
            Position pos1(abscisse, ordonnee);
            Block b(pos1);
            ajouterBlock(b);
            i++;
                }
}

void Carte::Block_PersoInit1()
{
                int abscisse = (rand() % Carte_Dimension.getLargeur());
                int ordonnee = 2;
                Position pos1(abscisse, ordonnee);
                Carte_perso.setPosition(pos1);
                Block b(pos1);
                ajouterBlock(b);
}

bool Carte::persoSurBlock2()
{
                int i = Carte_perso.getPosition().getOrdonnee();
                int j = Carte_perso.getPosition().getAbscisse();
                return blockSurPos(j, i);
}

void Carte::PersoGravite()
{
    unsigned int a = 1;
                do 
                {
            Carte_perso.setOrdonnee(Carte_perso.getPosition().getOrdonnee() - a);
            a++;
            usleep(50000);
                } while (persoSurBlock2()!=true);   


}


void Carte::ajouterBlock(Block b)
{
                Carte_TabBlock.push_back(b);
}
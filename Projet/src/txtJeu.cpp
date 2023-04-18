#include <iostream>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif // WIN32
#include "WinTxt.h"


#include "Carte.h"

void txtAff(WinTXT &win, const Carte &UneCarte)
{
  //  const Terrain &ter = jeu.getConstTerrain();
    const Personnage &PersoAff = UneCarte.getPerso();
    const std::vector <Block> &TabBlock = UneCarte.getTabBlock();

    win.clear();

    // Affichage des murs et des pastilles
    for (unsigned int x = 0; x < UneCarte.getDimCarte().getLargeur(); ++x)
        for (unsigned int y = 0; y < UneCarte.getDimCarte().getHauteur(); ++y)
            if(UneCarte.blockSurPos(x,y)==true)
            {
                win.print(x, UneCarte.getDimCarte().getHauteur() - y, '_');
            }
            else
            {
                win.print(x, UneCarte.getDimCarte().getHauteur()- y, ' ');
            }

    //affichage des limites de la carte
    for(unsigned int i = 0; i<= UneCarte.getDimCarte().getLargeur(); i++)
    {
        for (unsigned int j = 0; j<=UneCarte.getDimCarte().getHauteur(); j++)
        {
            if (i==0 ){
                win.print(i,j,'*');
            }
            if (i==UneCarte.getDimCarte().getLargeur()){
                win.print(i,j,'*');
            }
            if (j==UneCarte.getDimCarte().getHauteur())
            {
                win.print(i,j,'*');
            }
        }
        
    }


    // Affichage de Pacman
    win.print( PersoAff.getPosition().getAbscisse(), UneCarte.getDimCarte().getHauteur() - PersoAff.getPosition().getOrdonnee(), 'P');
    // Affichage du Fantome
    

    win.draw();
}





void txtBoucle(Carte &UneCarte)
{
    Dimension dimcarte=UneCarte.getDimCarte();
    // Creation d'une nouvelle fenetre en mode texte
    // => fenetre de dimension et position (WIDTH,HEIGHT,STARTX,STARTY)
    WinTXT win(dimcarte.getLargeur()+1, dimcarte.getHauteur()+1);
    int i=0;
    bool ok = true;
    int c;

    do
    {
       
        txtAff(win, UneCarte);

#ifdef _WIN32
        Sleep(100);
#else
        usleep(100000);
#endif // WIN32

       //jeu.actionsAutomatiques();
        
        c = win.getCh();
        switch (c)
        {
        case 'a':
            UneCarte.actionClavier('g');
            break;
        case 'e':
            UneCarte.actionClavier('d');
            break;
        case ' ':
            do{
                UneCarte.actionClavier('s');
                UneCarte.ajouteSaut();
                i++;
            }while(i%3!=0);
            
            break;
        case 'q':
            ok = false;
            break;
        }
        
        
    } while (ok);
}

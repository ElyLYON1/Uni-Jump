#ifndef _CARTE_H
#define _CARTE_H
#include "Personnage.h"
#include "Block.h"

#include <vector>

class Carte
{

private:
  // dimension de la carte
  Dimension Carte_Dimension;

  // Personnage dans la carte
  Personnage Carte_perso;

  // Tableau dynamique de block
  std::vector<Block> Carte_TabBlock;
  // int Carte_taille_TabBlock;
  unsigned int nbSautmax;

public:
  Carte();
  Carte(Dimension Dim, Personnage Perso, std::vector<Block> TabBlock);

  ~Carte();

  Dimension getDimCarte() const;
  Personnage getPerso() const;
  Block getBlock(int numBlock) const;
  std::vector<Block> getTabBlock() const;

  int getTailleTabBlock() const;
  int getTailleUtilisee() const;

  bool blockSurPos(int x, int y) const;
  void setBlock(int numBlock, Block b);
  void ajouterBlock(Block b);

  void setDimension(Dimension Dimension);
  void setPerso(Personnage Perso);

  int getnbEtage();
  void remplirModeFacile(int difficulté);

  bool PersoSurBlock();
  void actionClavier(const char touche);

  void Block_PersoInit1();
  void Block_Init2();

  unsigned int getnbSaut() const;
  void ajouteSaut();
  void PersoGravite();
  bool persoSurBlock2();

  void testRegression();

  void boucleJeu();
  void tout_deplacer();
  void viePerdue();
  bool getViePerso();
};

#endif /* _CARTE_H */
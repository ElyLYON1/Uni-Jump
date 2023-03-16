#include "WinTxt.h"
#include "txtJeu.h"
#include <vector>

int main(int argc, char **argv)
{
    termClear();
    Position pos1(1, 10);
    Position pos2(3, 7);

    Block unblock(pos1);
    Block unblock2(pos2);

    Dimension UneDimension(5, 10);
    Personnage UnPersonnage;
    std::vector<Block> UnTabBlock;
    UnTabBlock.push_back(unblock);
    UnTabBlock.push_back(unblock2);

    Carte UneDcarte(UneDimension, UnPersonnage, UnTabBlock);
    txtBoucle(UneDcarte);

    termClear();
    return 0;

}

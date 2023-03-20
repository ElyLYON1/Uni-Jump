#include "WinTxt.h"
#include "txtJeu.h"
#include <vector>

int main(int argc, char **argv)
{
    termClear();
    Position pos1(1, 5);
    Position pos2(3, 7);

    Block unblock(pos1);
    Block unblock2(pos2);

    Dimension UneDimension(10, 20);
    Personnage UnPersonnage;
    UnPersonnage.setPosition(Position(2, 1));
    std::vector<Block> UnTabBlock;
    UnTabBlock.push_back(unblock);
    UnTabBlock.push_back(unblock2);

    Carte UneDcarte(UneDimension, UnPersonnage, UnTabBlock);
    txtBoucle(UneDcarte);

    termClear();
    return 0;

}

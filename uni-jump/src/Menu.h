#ifndef _MENU_H
#define _MENU_H
#include "Position.h"
#include <iostream>
#include <vector>
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <string>



class menuElement
{

    private:

        // Texte du lien
        std::string m_text;

        // Position du lien à l'image
        Position m_Elpos;

        public:

        menuElement();
        menuElement(std::string text,int abscisse, int ordronnee);
        Position getPosEl() const;
        std::string getText() const;


};


class Menu
{

private:

    // Permet de savoir qu'elle lien a le focus
    long unsigned int m_currentIndex;

    // Permet de savoir si un lien est sélectionné ou non
    bool m_select;

    // Position du menu à l'image, pas nécessaire 
    Position m_pos;

    // Style du texte [taille + chemin vers la police]
    int m_fontSize;
    std::string m_fontPath;

    TTF_Font * m_font;

    // Couleur du texte
    SDL_Color m_colorHover;
    SDL_Color m_colorNormal;

    // Tableau qui contiendra tous nos liens (structure menuElement)
    std::vector<menuElement> m_menuElementList;

public:

    Menu();
    ~Menu();
    void MoveUp();
    void MoveDown();
    void Select();
    bool getSelect() const;
    void addElementMenu(std::string element);
    long unsigned int getIndex() const;
    void Init();
    void eventMenu(bool quit);
    void setColor(SDL_Color colorHover, SDL_Color colorNormal);
    void setFontStyle(std::string path, int size);
    void render();
    void quit();
    void InitAffichage();
    TTF_Font * getFont() const;
    SDL_Color getColorHover() const;
    SDL_Color getColorNormal() const;
    std::vector<menuElement> getMenuElementList() const;

    /// @brief Accesseurs
    Position getPos()const;



};




#endif /* _MENU_H */

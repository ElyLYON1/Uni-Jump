#include "Menu.h"

#include <iostream>
using namespace std;

Menu::Menu():m_currentIndex(0),m_select(false), m_pos(), m_fontSize(0), m_fontPath(""),m_font(NULL), m_colorHover({0,0,0,0}), m_colorNormal({0,0,0,0}), m_menuElementList()
{

}

Menu::~Menu()
{
}

void Menu::MoveUp()
{   
    m_currentIndex--;
    if (m_currentIndex < 1)
    {
        m_currentIndex = m_menuElementList.size();
    }
}

void Menu::MoveDown()
{
    m_currentIndex++;
    if (m_currentIndex > m_menuElementList.size())
    {
        m_currentIndex = 1;
    }

}


void Menu::Select()
{
    m_select = true;
}

void Menu::addElementMenu(std::string nom)
{
    Position p = getPos();
    int abs=p.getAbscisse()+10;
    int ord=p.getOrdonnee();

    menuElement element(nom,abs,ord);
    m_menuElementList.push_back(element);

}
long unsigned int Menu::getIndex() const
{
    return m_currentIndex;
}

void Menu::Init()
{

    // Défini la police et la taille à utiliser dans tout le menu
    m_fontPath="src/data/arial.ttf";
    setFontStyle(m_fontPath, 22);


    // Défini les couleurs
    SDL_Color hoverColor = {26, 62, 137};
    SDL_Color normalColor = {150, 150, 150};
    setColor(normalColor, hoverColor);

    // Ajoute les liens de notre menu
    addElementMenu("New Game");
    addElementMenu("Network Game");
    addElementMenu("Options");
    addElementMenu("Credits");
    addElementMenu("Quitter");


}



void Menu::eventMenu(bool quit)
{
    
        SDL_Event events = {0}; // Initialise tous les champs de la structure à 0
        

        while (!quit)
        {
            // tant que ce n'est pas la fin ...

            switch (events.type)
            {
            case SDL_QUIT:

                quit = true;

                break;

            case SDL_MOUSEBUTTONDOWN:

                if (events.button.button == SDL_BUTTON_LEFT)
                {
                    Position posclic;
                    posclic.setAbscisse(events.button.x);
                    posclic.setOrdonnee(events.button.y);
                    // endroit du clic ici ce sera le bouton start
                    if (events.motion.x > m_menuElementList[1].getPosEl().getAbscisse() && events.motion.x < 100 && events.motion.y > m_menuElementList[1].getPosEl().getOrdonnee() && events.motion.y < 100)
                    {
                        quit = true;
                    }
                    else if (events.motion.x > 0 && events.motion.x < 100 && events.motion.y > 0 && events.motion.y < 100)
                    {
                        quit = true;
                    }
                }
                break;

            case SDL_MOUSEMOTION:

                // endroit de la souris ici ce sera le bouton start
                if (events.motion.x > 0 && events.motion.x < 100 && events.motion.y > 0 && events.motion.y < 100)
                {
                    m_currentIndex=1;

                    // Afficher un message pour le bouton start
                }

                else if (events.motion.x > 0 && events.motion.x < 100 && events.motion.y > 0 && events.motion.y < 100)
                {
                    // Afficher un message pour le bouton guide jeu
                }

                else if (events.motion.x > 0 && events.motion.x < 100 && events.motion.y > 0 && events.motion.y < 100)
                {
                    // Afficher un message pour le bouton quitter
                }
                break;


            
            case SDL_KEYDOWN:
                switch (events.key.keysym.sym)
                {
                    case SDLK_UP:
                        MoveUp();
                        break;
                    case SDLK_DOWN:
                        MoveDown();
                        break;
                    case SDLK_RETURN:
                        Select();
                        break;

                    default:
                        break;
                 }
            }


        }

}











menuElement::menuElement(): m_text(""), m_Elpos()
{
}


menuElement::menuElement(std::string text, int abscisse, int ordronnee) : m_text(text), m_Elpos(abscisse, ordronnee)
{


}

Position menuElement::getPosEl() const
{
        return m_Elpos;

}

std::string menuElement::getText() const
{
        return m_text;
}

void Menu::setColor(SDL_Color colorHover, SDL_Color colorNormal)
{

    m_colorHover = colorHover;
    m_colorNormal = colorNormal;

}

void Menu::setFontStyle(std::string path, int size)
{
     m_font = TTF_OpenFont(path.c_str(), size);

}

TTF_Font * Menu::getFont() const
{
    return m_font;
}

Position Menu::getPos() const
{
    return m_pos;
}

SDL_Color Menu::getColorHover() const
{
    return m_colorHover;
}

SDL_Color Menu::getColorNormal() const
{
    return m_colorNormal;
}

std::vector<menuElement> Menu::getMenuElementList() const
{
    return m_menuElementList;

}



// Arrêt
void Menu::quit()
{

    // Arrête SDl_ttf
    TTF_Quit();

    // Arrête la SDL
    SDL_Quit();
}


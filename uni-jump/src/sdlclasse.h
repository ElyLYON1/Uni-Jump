#ifndef _SDLCLASSE_H
#define _SDLCLASSE_H

#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <SDL_mixer.h>

#include "Carte.h"
#include "Menu.h"

//! \brief Pour gérer une image avec SDL2
class Image
{

private:

    SDL_Surface *m_surface;
    SDL_Texture *m_texture;
    bool m_hasChanged;

public:

    Image();
    ~Image();
    void loadFromFile(const char *filename, SDL_Renderer *renderer);
    void loadFromCurrentSurface(SDL_Renderer *renderer);
    void draw(SDL_Renderer *renderer, int x, int y, int w = -1, int h = -1);
    SDL_Texture *getTexture() const;
    void setSurface(SDL_Surface *surf);

};

/*
    La classe gerant le jeu avec un affichage SDL
*/
class SDLSimple
{

private:
    Carte UneCarte;
    Menu UnMenu;


    SDL_Window *window;
    SDL_Renderer *renderer;

    TTF_Font *font;
    Image font_im;
    SDL_Color font_color;

    Mix_Chunk *sound;
    bool withSound;

    Image im_personnage;
    Image im_block;
    Image im_objet;
    Image im_menu;
    Image im_message;


    bool souris;
    bool touche;

public:
    SDLSimple();
    void loadMenu();
    void sdlInitMenu();
    void sdlInitCarte();
    void loadCarte();
    ~SDLSimple();
    void sdlAffmenu();
    void sdlBoucle();
    void BoucleTitre();
    void BoucleMenu(bool quit);
    void sdlAff();
    void AffTabMenu();
    void sdlBoucleMenu();
    void surfacePolice(std::string file ,int size ,int numEl,std::string text,bool SurfaceColor);
    void BoucleMenuTb();
};

class SDLSimpleMenu
{

    SDL_Window *window;
    SDL_Renderer *renderer;

    TTF_Font *font;
    Image font_im;
    SDL_Color font_color;



    Image im_start;
    Image im_aide;
    Image im_lvlfacile;
    Image im_lvlmoyen;
    Image im_lvldifficile;

};
#endif

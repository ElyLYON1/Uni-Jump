#include <cassert>
#include <time.h>
#include "sdlclasse.h"
#include <stdlib.h>
#include <vector>

#include <iostream>
#include "Carte.h"
#include "Menu.h"
using namespace std;

const int TAILLE_SPRITE = 32;

float temps()
{
    return float(SDL_GetTicks()) / CLOCKS_PER_SEC; // conversion des ms en secondes en divisant par 1000
}

// ============= CLASS IMAGE =============== //

Image::Image() : m_surface(nullptr), m_texture(nullptr), m_hasChanged(false)
{
}

Image::~Image()
{
    SDL_FreeSurface(m_surface);
    SDL_DestroyTexture(m_texture);

    m_surface = nullptr;
    m_texture = nullptr;
    m_hasChanged = false;
}

void Image::loadFromFile(const char *filename, SDL_Renderer *renderer)
{
    m_surface = IMG_Load(filename);
    if (m_surface == nullptr)
    {
        string nfn = string("../") + filename;
        cout << "Error: cannot load " << filename << ". Trying " << nfn << endl;
        m_surface = IMG_Load(nfn.c_str());
        if (m_surface == nullptr)
        {
            nfn = string("../") + nfn;
            m_surface = IMG_Load(nfn.c_str());
        }
    }
    if (m_surface == nullptr)
    {
        cout << "Error: cannot load " << filename << endl;
        SDL_Quit();
        exit(1);
    }

    SDL_Surface *surfaceCorrectPixelFormat = SDL_ConvertSurfaceFormat(m_surface, SDL_PIXELFORMAT_ARGB8888, 0);
    SDL_FreeSurface(m_surface);
    m_surface = surfaceCorrectPixelFormat;

    m_texture = SDL_CreateTextureFromSurface(renderer, surfaceCorrectPixelFormat);
    if (m_texture == NULL)
    {
        cout << "Error: problem to create the texture of " << filename << endl;
        SDL_Quit();
        exit(1);
    }
}

void Image::loadFromCurrentSurface(SDL_Renderer *renderer)
{
    m_texture = SDL_CreateTextureFromSurface(renderer, m_surface);
    if (m_texture == nullptr)
    {
        cout << "Error: problem to create the texture from surface " << endl;
        SDL_Quit();
        exit(1);
    }
}

/// @brief
/// @param renderer
/// @param x the x location of the rectangle's upper left corner
/// @param y the y location of the rectangle's upper left corner
/// @param w largueur de l'image
/// @param h hauteur de l'image
void Image::draw(SDL_Renderer *renderer, int x, int y, int w, int h)
{
    int ok;
    SDL_Rect r;
    r.x = x;
    r.y = y;
    r.w = (w < 0) ? m_surface->w : w;
    r.h = (h < 0) ? m_surface->h : h;

    if (m_hasChanged)
    {
        ok = SDL_UpdateTexture(m_texture, nullptr, m_surface->pixels, m_surface->pitch);
        assert(ok == 0);
        m_hasChanged = false;
    }

    ok = SDL_RenderCopy(renderer, m_texture, nullptr, &r);
    assert(ok == 0);
}

SDL_Texture *Image::getTexture() const { return m_texture; }

void Image::setSurface(SDL_Surface *surf) { m_surface = surf; }

// ============= CLASS SDLJEU =============== //

SDLSimple::SDLSimple() : UneCarte(), UnMenu()
{
    // Initialisation de la SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        cout << "Erreur lors de l'initialisation de la SDL : " << SDL_GetError() << endl;
        SDL_Quit();
        exit(1);
    }

    if (TTF_Init() != 0)
    {
        cout << "Erreur lors de l'initialisation de la SDL_ttf : " << TTF_GetError() << endl;
        SDL_Quit();
        exit(1);
    }

    int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG;
    if (!(IMG_Init(imgFlags) & imgFlags))
    {
        cout << "SDL_image could not initialize! SDL_image Error: " << IMG_GetError() << endl;
        SDL_Quit();
        exit(1);
    }

    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
    {
        cout << "SDL_mixer could not initialize! SDL_mixer Error: " << Mix_GetError() << endl;
        cout << "No sound !!!" << endl;
        // SDL_Quit();exit(1);
        withSound = false;
    }
    else
    {
        withSound = true;
    }
    // Initialise SDL
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) != 0)
    {
        // Gestion d'erreur en cas d'échec de l'initialisation
        SDL_Log("Erreur lors de l'initialisation de SDL : %s", SDL_GetError());
        SDL_Quit();
        exit(1);
    }

    // initialisation de la carte
    Position pos1(1, 5);
    Position pos2(3, 7);


    int dimx =50;
    int dimy =50;
    Dimension dim(dimx, dimy);
    UneCarte.setDimension(dim);
   // dimx = UneCarte.getDimCarte().getLargeur();
   // dimy = UneCarte.getDimCarte().getHauteur();

    dimx = 50 * TAILLE_SPRITE; //dimension du menu en pixel, valeur de test 
    dimy = 50 *TAILLE_SPRITE;

    // Creation de la fenetre
    window = SDL_CreateWindow("doodle jump", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, dimx, dimy, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    if (window == nullptr)
    {
        cout << "Erreur lors de la creation de la fenetre : " << SDL_GetError() << endl;
        SDL_Quit();
        exit(1);
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if(renderer == nullptr)
    {
        cout << "Erreur lors de la creation du renderer : " << SDL_GetError() << endl;
        SDL_Quit();
        exit(1);
    }
}
void SDLSimple::loadMenu()
{


    // initialisation de la carte

    int dimx = 50;
    int dimy = 50;
    Dimension dim(dimx, dimy);
    UneCarte.setDimension(dim);
    // dimx = UneCarte.getDimCarte().getLargeur();
    // dimy = UneCarte.getDimCarte().getHauteur();

    dimx = 50 * TAILLE_SPRITE; // dimension du menu en pixel, valeur de test
    dimy = 50 * TAILLE_SPRITE;


    // IMAGES

    im_menu.loadFromFile("data/menu.png", renderer);
    if (im_menu.getTexture() == nullptr)
    {
        im_menu.loadFromFile("../data/menu.png", renderer);
    }
    if (im_menu.getTexture() == nullptr)
    {
        cout << "Failed to load menu.png! SDL Error: " << SDL_GetError() << endl;
        SDL_Quit();
        exit(1);
    }


}



void SDLSimple::loadCarte()
{
    // initialisation de la carte
    Position pos1(1, 5);
    Position pos2(3, 7);

    Block unblock(pos1);
    Block unblock2(pos2);

    Dimension UneDimension(10, 20);
    Personnage UnPersonnage;
    UnPersonnage.setPosition(Position(2, 1));
    UnPersonnage.setSaut(3);
    std::vector<Block> UnTabBlock;
    UnTabBlock.push_back(unblock);
    UnTabBlock.push_back(unblock2);

    Carte UneDcarte;
    UneDcarte.setDimension(UneDimension);
    UneDcarte.setPerso(UnPersonnage);
    UneDcarte.Block_PersoInit1();
    UneDcarte.Block_Init2();

    UneCarte = UneDcarte;

    int dimx, dimy;
    dimx = UneCarte.getDimCarte().getLargeur();
    dimy = UneCarte.getDimCarte().getHauteur();
    dimx = dimx * TAILLE_SPRITE;
    dimy = dimy * TAILLE_SPRITE;

/* 
    // Création de la fenêtre
    SDL_Window *fenetre = SDL_CreateWindow("Ma fenêtre", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);

    // Changer les dimensions de la fenêtre
    SDL_SetWindowSize(fenetre, 800, 600);

    // Création du renderer
    SDL_Renderer *renderer = SDL_CreateRenderer(fenetre, -1, SDL_RENDERER_ACCELERATED);

    // Changer les dimensions du renderer
    SDL_RenderSetLogicalSize(renderer, 800, 600);

*/

    // IMAGES

    im_personnage.loadFromFile("data/personnage.jpg", renderer);
    if (im_personnage.getTexture() == nullptr)
    {
        im_personnage.loadFromFile("../data/personnage.jpg", renderer);
    }
    if (im_personnage.getTexture() == nullptr)
    {
        cout << "Failed to load personnage.jpg! SDL Error: " << SDL_GetError() << endl;
        SDL_Quit();
        exit(1);
    }

    im_block.loadFromFile("data/block.png", renderer);
    if (im_block.getTexture() == nullptr)
    {
        im_block.loadFromFile("../data/block.png", renderer);
    }
    if (im_block.getTexture() == nullptr)
    {
        cout << "Failed to load block.png! SDL Error: " << SDL_GetError() << endl;
        SDL_Quit();
        exit(1);
    }


    // FONTS
    font = TTF_OpenFont("data/DejaVuSansCondensed.ttf", 50);
    if (font == nullptr)
        font = TTF_OpenFont("../data/DejaVuSansCondensed.ttf", 50);
    if (font == nullptr)
    {
        cout << "Failed to load DejaVuSansCondensed.ttf! SDL_TTF Error: " << TTF_GetError() << endl;
        SDL_Quit();
        exit(1);
    }
    font_color.r = 50;
    font_color.g = 50;
    font_color.b = 255;
    font_im.setSurface(TTF_RenderText_Solid(font, "doodle jump", font_color));
    font_im.loadFromCurrentSurface(renderer);

    // SONS
    if (withSound)
    {
        sound = Mix_LoadWAV("data/son.wav");
        if (sound == nullptr)
            sound = Mix_LoadWAV("../data/son.wav");
        if (sound == nullptr)
        {
            cout << "Failed to load son.wav! SDL_mixer Error: " << Mix_GetError() << endl;
            SDL_Quit();
            exit(1);
        }
    }
}

SDLSimple::~SDLSimple()
{
    if (withSound)
        Mix_Quit();
    TTF_CloseFont(font);
    TTF_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}



void SDLSimple::sdlAffmenu()
{
    SDL_SetRenderDrawColor(renderer, 230, 240, 255, 255);
    SDL_RenderClear(renderer);

     im_menu.draw(renderer,0,0,TAILLE_SPRITE * UneCarte.getDimCarte().getLargeur(), TAILLE_SPRITE * UneCarte.getDimCarte().getHauteur());
}



    void SDLSimple::sdlAff()
{
    // Remplir l'écran de blanc
    SDL_SetRenderDrawColor(renderer, 230, 240, 255, 255);
    SDL_RenderClear(renderer);

    const Personnage &PersoAff = UneCarte.getPerso();
    const std::vector<Block> &TabBlock = UneCarte.getTabBlock();


   // UneCarte.ActionAuto();

    // Affichage des murs et des pastilles
    for (unsigned int x = 0; x < UneCarte.getDimCarte().getLargeur(); ++x)
        for (unsigned int y = 0; y < UneCarte.getDimCarte().getHauteur(); ++y)
            if (UneCarte.blockSurPos(x, y) == true)
            {

                im_block.draw(renderer, x * TAILLE_SPRITE, (UneCarte.getDimCarte().getHauteur() - y) * TAILLE_SPRITE, TAILLE_SPRITE, TAILLE_SPRITE / 3);
            }

    // Afficher le sprite du personnage
    im_personnage.draw(renderer, (PersoAff.getPosition().getAbscisse()) * TAILLE_SPRITE, (UneCarte.getDimCarte().getHauteur() - PersoAff.getPosition().getOrdonnee()) * TAILLE_SPRITE, TAILLE_SPRITE, TAILLE_SPRITE);

    //im_menu.draw(renderer,0,0,TAILLE_SPRITE * UneCarte.getDimCarte().getLargeur(), TAILLE_SPRITE * UneCarte.getDimCarte().getHauteur());
    
    // Ecrire un titre par dessus
    SDL_Rect positionTitre;

    positionTitre.x = 270;
    positionTitre.y = 49;
    positionTitre.w = 100;
    positionTitre.h = 30;

    SDL_RenderCopy(renderer, font_im.getTexture(), nullptr, &positionTitre);

}
void SDLSimple::AffTabMenu()
{
    SDL_SetRenderDrawColor(renderer, 230, 240, 255, 255);
    SDL_RenderClear(renderer);




}

void SDLSimple::sdlBoucle()
{

    SDL_Event events = {0}; // Initialise tous les champs de la structure à 0

    bool quit = false;
    bool quitMenu=false;

   // loadMenu();

    Uint32 t = SDL_GetTicks(), nt;
    while (!quit)
    {
        BoucleMenu(quitMenu);
        // tant que ce n'est pas la fin ...

                nt = SDL_GetTicks();

                if (nt - t > 500)
                {

                    t = nt;

                }

                // tant qu'il y a des évenements à traiter (cette boucle n'est pas bloquante)
                while (SDL_PollEvent(&events))
                {
                    if (events.type == SDL_QUIT)
                        quit = true; // Si l'utilisateur a clique sur la croix de fermeture
                    else if (events.type == SDL_KEYDOWN)
                    { 
                        // Si une touche est enfoncee
                        bool mangePastille = false;
                        switch (events.key.keysym.scancode)
                        {

                        case SDL_SCANCODE_LEFT:
                            UneCarte.actionClavier('g');
                            break;
                        case SDL_SCANCODE_RIGHT:
                            UneCarte.actionClavier('d');
                            break;
                        case SDL_SCANCODE_UP:
                            UneCarte.actionClavier('s');
                            UneCarte.ajouteSaut();
                            break;

                        case SDL_SCANCODE_Q:
                            quit = true;
                            break;
                        default:
                            break;
                        }

                        if ((withSound) && (mangePastille))
                            Mix_PlayChannel(-1, sound, 0);
                    }
                }

                // on affiche le jeu sur le buffer caché
                   sdlAff();

                // on permute les deux buffers (cette fonction ne doit se faire qu'une seule fois dans la boucle)
                SDL_RenderPresent(renderer);
    }

}
void SDLSimple::BoucleTitre()
{
    UnMenu.Init();

        for(long unsigned int i=0;i<UnMenu.getMenuElementList().size();i++)
        {
            if(UnMenu.getIndex()==i)
            {
                    surfacePolice("data/DejaVuSansCondensed.ttf", 20, 1, UnMenu.getMenuElementList()[i].getText(),true);
            }
    surfacePolice("data/DejaVuSansCondensed.ttf",20,1,UnMenu.getMenuElementList()[i].getText(),false);
        
        }
}












void SDLSimple::BoucleMenu(bool quit)
{
    SDL_Event events = {0}; // Initialise tous les champs de la structure à 0

     quit = false;
  //  bool go = false;

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
                            if (events.motion.x > 0 && events.motion.x < 100 && events.motion.y > 0 && events.motion.y < 100)
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

                            //  message.draw(renderer, 110, 50, -1, -1); // Afficher la surface d'affichage mise à jour
                            font_color.r = 50;
                            font_color.g = 50;
                            font_color.b = 255;
                            font_im.setSurface(TTF_RenderText_Solid(font, "Lancement de la partie", font_color));
                            font_im.loadFromCurrentSurface(renderer);

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

                    }
                

                // on affiche le jeu sur le buffer caché
                sdlAffmenu();

                // on permute les deux buffers (cette fonction ne doit se faire qu'une seule fois dans la boucle)
                SDL_RenderPresent(renderer);

                }

}

void SDLSimple::BoucleTitre()
{
                UnMenu.Init();

                for (long unsigned int i = 0; i < UnMenu.getMenuElementList().size(); i++)
                {
                if (UnMenu.getIndex() == i)
                {
                        surfacePolice("data/DejaVuSansCondensed.ttf", 20, 1, UnMenu.getMenuElementList()[i].getText(), true);
                }
                surfacePolice("data/DejaVuSansCondensed.ttf", 20, 1, UnMenu.getMenuElementList()[i].getText(), false);
                }
}

void SDLSimple::surfacePolice(string file, int size,int numEl,string text,bool SurfaceColor)
{

                // Ouvre la police
               // TTF_Font *police = TTF_OpenFont(file.c_str(), size);

                UnMenu.setFontStyle(file, size);

                SDL_Rect positionTitre;

                positionTitre.x = UnMenu.getMenuElementList()[numEl].getPosEl().getAbscisse();
                positionTitre.y = UnMenu.getMenuElementList()[numEl].getPosEl().getOrdonnee();
                positionTitre.w = 50;
                positionTitre.h = 10;

                // Ecriture du texte passé dans une surface

                if(SurfaceColor==true)
                {

                SDL_Surface *surfaceText = TTF_RenderText_Blended(UnMenu.getFont(), text.c_str(), UnMenu.getColorHover());
                SDL_Texture *textTexture = SDL_CreateTextureFromSurface(renderer, surfaceText);
                SDL_RenderCopy(renderer, textTexture, nullptr, &positionTitre);

                // Libère la mémoire utilisé par la police
                }
                else if(SurfaceColor==false)
                {

                SDL_Surface *surfaceText = TTF_RenderText_Blended(UnMenu.getFont(), text.c_str(), UnMenu.getColorNormal());
                SDL_Texture *textTexture = SDL_CreateTextureFromSurface(renderer, surfaceText);
                SDL_RenderCopy(renderer, textTexture, nullptr, &positionTitre);

                }
                // Retourne la surface texte
                TTF_CloseFont(UnMenu.getFont());

}

void SDLSimple:: BoucleMenuTb()
{

                bool quit = false;

            while (!quit)

                {

    UnMenu.eventMenu(quit);

               BoucleTitre();

               SDL_RenderPresent(renderer);
               
                }

}
void Carte::testRegression()
{
                Carte c1;
                Dimension d1(100, 100);
                assert(c1.getDimCarte().getLargeur() == 0);
                assert(c1.getDimCarte().getHauteur() == 0);

                assert(c1.getTailleTabBlock() == 0);
                assert(c1.getPerso().getPosition().getAbscisse() == 0);
                assert(c1.getPerso().getPosition().getOrdonnee() == 0);

                c1.setDimension(d1);
                assert(c1.getDimCarte().getLargeur() == 100);
                assert(c1.getDimCarte().getHauteur() == 100);

                c1.actionClavier('g');
                assert(c1.getPerso().getPosition().getAbscisse() == c1.getDimCarte().getLargeur() - 1);

                c1.actionClavier('d');
                assert(c1.getPerso().getPosition().getAbscisse() == 1);
}

void Carte::boucleJeu()
{
                if (persoSurBlockGravite())
                {
               tout_deplacer();
               Block_Init2();
               compteurScore();
                }
                if (Carte_TabObjet.empty() == false)
                {
               deplacerObjetmobile();
               deplacerSiObjet();
                }
                if (objet == 1)
                {
               deplacerSiObjet();
                }
                if (persoSurBlock2() || nbSautmax % (Carte_perso.getSaut() + 1) > 0)
                {
               Carte_perso.perso_sauter();
               ajouteSaut();
                }
                if (nbSautmax % (Carte_perso.getSaut() + 1) == 0)
                {
               if (persoSurBlock2() == false && Carte_perso.getPosition().getOrdonnee() > 0)
               {
                        PersoGravite();
               }
                }
                deplacerBlockmobile();

                viePerdue();
}
void Carte::viePerdue()
{
                if (Carte_perso.getPosition().getOrdonnee() == 0)
                {
               Carte_perso.setVie(false);
                }
}

bool Carte::getViePerso()
{
                return Carte_perso.getVie();
}

void Carte::compteurScore()
{
                if (persoSurBlock2() == true && Carte_perso.getPosition().getOrdonnee() != 2)
                {
               score = score + 1;
                }
}

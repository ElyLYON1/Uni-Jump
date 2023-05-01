#include <cassert>
#include <time.h>
#include "sdlclasse.h"
#include <stdlib.h>
#include <vector>

#include <iostream>
using namespace std;

const int TAILLE_SPRITE = 32;

float temps () {
    return float(SDL_GetTicks()) / CLOCKS_PER_SEC;  // conversion des ms en secondes en divisant par 1000
}

// ============= CLASS IMAGE =============== //

Image::Image () : m_surface(nullptr), m_texture(nullptr), m_hasChanged(false) {
}

Image::~Image()
{
    SDL_FreeSurface(m_surface);
    SDL_DestroyTexture(m_texture);

    m_surface = nullptr;
    m_texture = nullptr;
    m_hasChanged = false;
}

void Image::loadFromFile (const char* filename, SDL_Renderer * renderer) {
    m_surface = IMG_Load(filename);
    if (m_surface == nullptr) {
        string nfn = string("../") + filename;
        cout << "Error: cannot load "<< filename <<". Trying "<<nfn<<endl;
        m_surface = IMG_Load(nfn.c_str());
        if (m_surface == nullptr) {
            nfn = string("../") + nfn;
            m_surface = IMG_Load(nfn.c_str());
        }
    }
    if (m_surface == nullptr) {
        cout<<"Error: cannot load "<< filename <<endl;
        SDL_Quit();
        exit(1);
    }

    SDL_Surface * surfaceCorrectPixelFormat = SDL_ConvertSurfaceFormat(m_surface,SDL_PIXELFORMAT_ARGB8888,0);
    SDL_FreeSurface(m_surface);
    m_surface = surfaceCorrectPixelFormat;

    m_texture = SDL_CreateTextureFromSurface(renderer,surfaceCorrectPixelFormat);
    if (m_texture == NULL) {
        cout << "Error: problem to create the texture of "<< filename<< endl;
        SDL_Quit();
        exit(1);
    }
}

void Image::loadFromCurrentSurface (SDL_Renderer * renderer) {
    m_texture = SDL_CreateTextureFromSurface(renderer,m_surface);
    if (m_texture == nullptr) {
        cout << "Error: problem to create the texture from surface " << endl;
        SDL_Quit();
        exit(1);
    }
}

void Image::draw (SDL_Renderer * renderer, int x, int y, int w, int h) {
    int ok;
    SDL_Rect r;
    r.x = x;
    r.y = y;
    r.w = (w<0)?m_surface->w:w;
    r.h = (h<0)?m_surface->h:h;

    if (m_hasChanged) {
        ok = SDL_UpdateTexture(m_texture,nullptr,m_surface->pixels,m_surface->pitch);
        assert(ok == 0);
        m_hasChanged = false;
    }

    ok = SDL_RenderCopy(renderer,m_texture,nullptr,&r);
    assert(ok == 0);
}

SDL_Texture * Image::getTexture() const {return m_texture;}

void Image::setSurface(SDL_Surface * surf) {m_surface = surf;}










// ============= CLASS SDLJEU =============== //

SDLSimple::SDLSimple () : UneCarte() {
    // Initialisation de la SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        cout << "Erreur lors de l'initialisation de la SDL : " << SDL_GetError() << endl;
        SDL_Quit();
        exit(1);
    }

    if (TTF_Init() != 0) {
        cout << "Erreur lors de l'initialisation de la SDL_ttf : " << TTF_GetError() << endl;
        SDL_Quit();
        exit(1);
    }

    int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG;
    if( !(IMG_Init(imgFlags) & imgFlags)) {
        cout << "SDL_image could not initialize! SDL_image Error: " << IMG_GetError() << endl;
        SDL_Quit();
        exit(1);
    }

    if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
    {
        cout << "SDL_mixer could not initialize! SDL_mixer Error: " << Mix_GetError() << endl;
        cout << "No sound !!!" << endl;
        //SDL_Quit();exit(1);
        withSound = false;
    }
    else withSound = true;

    //initialisation de la carte
    Position pos1(1, 5);
    Position pos2(3, 7);

    Block unblock(pos1);
    Block unblock2(pos2);

    Dimension UneDimension(10, 20);
    Personnage UnPersonnage;
    //UnPersonnage.setPosition(Position(2, 1));
    UnPersonnage.setSaut(4);
    UnPersonnage.setVie(true);
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

    // Creation de la fenetre
    window = SDL_CreateWindow("doodle jump", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, dimx, dimy, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    if (window == nullptr) {
        cout << "Erreur lors de la creation de la fenetre : " << SDL_GetError() << endl; 
        SDL_Quit(); 
        exit(1);
    }

    renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);

    // IMAGES
    im_personnage.loadFromFile("data/personnage.jpg",renderer);
    if (im_personnage.getTexture() == nullptr) {
        im_personnage.loadFromFile("../data/personnage.jpg",renderer);
    } 
    if (im_personnage.getTexture() == nullptr) {
        cout << "Failed to load personnage.jpg! SDL Error: " << SDL_GetError() << endl; 
        SDL_Quit(); 
        exit(1);
    }

    im_block.loadFromFile("data/block.png",renderer);
    if (im_block.getTexture() == nullptr) {
        im_block.loadFromFile("../data/block.png",renderer);
    }
    if (im_block.getTexture() == nullptr) {
        cout << "Failed to load block.png! SDL Error: " << SDL_GetError() << endl; 
        SDL_Quit(); 
        exit(1);
    }
    
    im_objet.loadFromFile("data/pastille.png",renderer);
    if (im_objet.getTexture() == nullptr) {
        im_objet.loadFromFile("..data/pastille.png",renderer);
    }
    if (im_objet.getTexture() == nullptr) {
        cout << "Failed to load block.png! SDL Error: " << SDL_GetError() << endl; 
        SDL_Quit(); 
        exit(1);
    }

    // FONTS
    font = TTF_OpenFont("data/HFFFireDancer.ttf",50);
    if (font == nullptr)
        font = TTF_OpenFont("../data/HFFFireDancer.ttf",50);
    if (font == nullptr) {
            cout << "Failed to load HFFFireDancer.ttf! SDL_TTF Error: " << TTF_GetError() << endl; 
            SDL_Quit(); 
            exit(1);
	}
	font_color.r = 250;font_color.g = 60;font_color.b = 60;
	font_im.setSurface(TTF_RenderText_Solid(font,"doodle jump",font_color));
	font_im.loadFromCurrentSurface(renderer);
    


    // SONS
    if (withSound)
    {
        sound = Mix_LoadWAV("data/son.wav");
        if (sound == nullptr) 
            sound = Mix_LoadWAV("../data/son.wav");
        if (sound == nullptr) {
                cout << "Failed to load son.wav! SDL_mixer Error: " << Mix_GetError() << endl; 
                SDL_Quit();
                exit(1);
        }
    }
}


SDLSimple::~SDLSimple () {
    if (withSound) Mix_Quit();
    TTF_CloseFont(font);
    TTF_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void SDLSimple::sdlAff () {
	//Remplir l'écran de blanc
    SDL_SetRenderDrawColor(renderer, 230, 240, 255, 255);
    SDL_RenderClear(renderer);


    const Personnage &PersoAff = UneCarte.getPerso();
    const std::vector <Block> &TabBlock = UneCarte.getTabBlock();

    unsigned int largeur = UneCarte.getDimCarte().getLargeur();
    unsigned int hauteur = UneCarte.getDimCarte().getHauteur();
    
    // Affichage des murs et des pastilles
    for (unsigned int x = 0; x < largeur; ++x)
        for (unsigned int y = 0; y < hauteur ; ++y){
            if(UneCarte.blockSurPos(x,y)==true)
            {
                
                im_block.draw(renderer,x * TAILLE_SPRITE,(UneCarte.getDimCarte().getHauteur()-y+1)*TAILLE_SPRITE-1,TAILLE_SPRITE,TAILLE_SPRITE/3);
            }
            if(UneCarte.objetSurPos(x,y)==true)
            {
                im_objet.draw(renderer,x * TAILLE_SPRITE,(UneCarte.getDimCarte().getHauteur()-y+1)*TAILLE_SPRITE-1,TAILLE_SPRITE/3,TAILLE_SPRITE/3);
            }
        }
            
    

    // Afficher le sprite du personnage
	im_personnage.draw(renderer,(PersoAff.getPosition().getAbscisse())*TAILLE_SPRITE,(UneCarte.getDimCarte().getHauteur() - PersoAff.getPosition().getOrdonnee())*TAILLE_SPRITE,TAILLE_SPRITE,TAILLE_SPRITE);


    // Ecrire un titre par dessus
    SDL_Rect positionTitre;
    positionTitre.x = (UneCarte.getDimCarte().getLargeur()-3)*TAILLE_SPRITE/2;positionTitre.y = 49;positionTitre.w = 100;positionTitre.h = 30;
    SDL_RenderCopy(renderer,font_im.getTexture(),nullptr,&positionTitre);

    std::string scoreStr = "Score: " + std::to_string(UneCarte.getScore());
    font_imScore.setSurface(TTF_RenderText_Solid(font, scoreStr.c_str(), font_color));
    font_imScore.loadFromCurrentSurface(renderer);

    // Ecrire le score
    SDL_Rect positionScore;
    positionScore.x = 0;positionScore.y = 0;positionScore.w = 100;positionScore.h = 30;
    SDL_RenderCopy(renderer,font_imScore.getTexture(),nullptr,&positionScore);


}


void SDLSimple::sdlBoucle () {
    SDL_Event events;
	bool quit = false;

    Uint32 t = SDL_GetTicks(), nt;

	// tant que ce n'est pas la fin ...
	while (!quit) {

        nt = SDL_GetTicks();
        if (nt-t>500) {
            UneCarte.boucleJeu();
            /*for (unsigned int i = 0; i < UneCarte.getTailleTabBlock(); ++i)
            {
                
                UneCarte.getBlock(i).deplacement(UneCarte.getDimCarte());
            }*/
            if (UneCarte.getViePerso() == false)
                    {
                        quit = true;
                        SDL_Quit();
                    }
            
            t = nt;
        }
    
        if ((withSound) && UneCarte.persoSurBlockGravite())
            Mix_PlayChannel(-1,sound,0);
         
        
		// tant qu'il y a des évenements à traiter (cette boucle n'est pas bloquante)
		while (SDL_PollEvent(&events)) {
			if (events.type == SDL_QUIT) quit = true;           // Si l'utilisateur a clique sur la croix de fermeture
			else if (events.type == SDL_KEYDOWN) {              // Si une touche est enfoncee
        
                    switch (events.key.keysym.scancode) {
                    case SDL_SCANCODE_LEFT:
                        UneCarte.actionClavier('g');
                        break;
                    case SDL_SCANCODE_RIGHT:
                        UneCarte.actionClavier('d');
                        break;
                    case SDL_SCANCODE_SPACE:
                        UneCarte.actionClavier('s');
                        UneCarte.ajouteSaut();
                        break;
        case SDL_SCANCODE_ESCAPE:
        case SDL_SCANCODE_Q:
            quit = true;
            break;    
                    default: break;
                    }
                    
                    
                    
                    
                }
		    }

            // on affiche le jeu sur le buffer cach�
            sdlAff();

		// on permute les deux buffers (cette fonction ne doit se faire qu'une seule fois dans la boucle)
        SDL_RenderPresent(renderer);
	}
}



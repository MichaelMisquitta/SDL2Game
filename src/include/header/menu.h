#ifndef MENU_H
#define MENU_H
#include <SDL2/SDL.h>
#include <SDL2_ttf/SDL_ttf.h>


class menu{
    public:
    SDL_Renderer* renderer;
    SDL_Rect menuRect {100, 100, 600,200};
    //constructor
    menu(SDL_Renderer*);
    SDL_Surface *fontSurface;
    SDL_Texture *fontTexture;
    TTF_Font* font;
    SDL_Color color {255,255,0,255};
    //destructor
    
    //methods
    void drawMenu();

};


#endif
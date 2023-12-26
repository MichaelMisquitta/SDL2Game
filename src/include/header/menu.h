#ifndef MENU_H
#define MENU_H
#include <SDL2/SDL.h>
#include <SDL2_ttf/SDL_ttf.h>

class menu{
    public:
    SDL_Renderer* renderer;
    //constructor
    menu(SDL_Renderer*);
    TTF_Font* font = TTF_OpenFont("Raleway-Heavy.ttf",13); //testing out sdl_ttf

    //destructor
    
    //methods
    void drawMenu();

};


#endif
#ifndef MENU_H
#define MENU_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

class menu{
    public:
    SDL_Renderer* renderer;
    //constructor
    menu(SDL_Renderer*);
    TTF_Font* font = NULL; //testing out sdl_ttf

    //destructor
    
    //methods
    void drawMenu();

};


#endif
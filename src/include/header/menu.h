#ifndef MENU_H
#define MENU_H
#include <SDL2/SDL.h>


class menu{
    public:
    SDL_Renderer* renderer;
    SDL_Rect menuRect {100, 100, 600,200};
    //constructor
    menu(SDL_Renderer*);
    

    //destructor
    
    //methods
    void drawMenu();

};


#endif
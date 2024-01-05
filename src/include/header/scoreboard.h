#ifndef SCOREBOARD_H
#define SCOREBOARD_H
#include <SDL2/SDL.h>
#include <SDL2_ttf/SDL_ttf.h>

class scoreboard{
    public:
    //constructors
    scoreboard(SDL_Renderer*);
    //variables
    SDL_Renderer* renderer;
    SDL_Rect scoreRect {0,0,50,50};


    //methods
    void drawScoreBoard();
    

    
};



#endif
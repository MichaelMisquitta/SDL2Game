#ifndef SCOREBOARD_H
#define SCOREBOARD_H
#include <SDL2/SDL.h>
#include <SDL2_ttf/SDL_ttf.h>

class scoreboard{
    public:
    //constructors
    scoreboard(SDL_Renderer*);
    ~scoreboard();
    //variables
    SDL_Renderer* renderer;
    SDL_Rect scoreRect {0,0,50,50};
    TTF_Font* font = TTF_OpenFont("Raleway-Heavy.ttf",28); 
    SDL_Surface *fontSurface = NULL;
    SDL_Texture *fontTexture = NULL; 
    SDL_Color color {255,255,0,255};
    //methods
    void drawScoreBoard();
    

    
};



#endif
#include <header/scoreboard.h>

scoreboard::scoreboard(SDL_Renderer* rend){
    renderer = rend;


}

void scoreboard::drawScoreBoard(){
    SDL_Surface *fontSurface;
    SDL_Texture *fontTexture; 
    
    TTF_Font* font = TTF_OpenFont("Raleway-Heavy.ttf",28); 
    SDL_Color color {255,255,0,255};
    fontSurface = TTF_RenderText_Blended_Wrapped(font, "Score: ", color, 600);
    fontTexture = SDL_CreateTextureFromSurface(renderer,fontSurface);
    SDL_RenderCopyEx(renderer,fontTexture,NULL,&scoreRect,0,NULL, SDL_FLIP_NONE);

}
#include <header/scoreboard.h>

scoreboard::scoreboard(SDL_Renderer* rend){
    renderer = rend;
    
    fontSurface = TTF_RenderText_Blended_Wrapped(font, "Score: ", color, 600);
    fontTexture = SDL_CreateTextureFromSurface(renderer,fontSurface);

}
scoreboard::~scoreboard(){
    SDL_DestroyTexture(fontTexture);
    SDL_FreeSurface(fontSurface);
}

void scoreboard::drawScoreBoard(){
    
    
    
    SDL_RenderCopyEx(renderer,fontTexture,NULL,&scoreRect,0,NULL, SDL_FLIP_NONE);   
    
    
   
}
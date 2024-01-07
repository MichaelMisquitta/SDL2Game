#include <header/menu.h>
#include<SDL2/SDL.h>


menu::menu(SDL_Renderer *rend){
    renderer = rend;
    font = TTF_OpenFont("Raleway-Heavy.ttf",28);
    fontSurface = TTF_RenderText_Blended_Wrapped(font, "Menu -- L-CTRL to Continue -- L-Alt to Quit ", color, 600);
    fontTexture = SDL_CreateTextureFromSurface(renderer,fontSurface);
}

void menu::drawMenu(){
    
    SDL_SetRenderDrawColor(renderer,0,0,0,255);
    SDL_RenderClear(renderer); 
    
    SDL_RenderCopyEx(renderer,fontTexture,NULL,&menuRect,0,NULL, SDL_FLIP_NONE);

    SDL_RenderPresent(renderer); // render back buffer to screen. 
    // if renderpresent isnt called and renderclear is being called continuously, it will
    //use up a lot of memory since the buffer isnt being cleared

    // no need to clear surface and texture pointer because they point to objects on the stack
    // which will automatically delete themselves when they go out of scope.
    
}
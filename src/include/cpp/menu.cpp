#include <header/menu.h>
#include<SDL2/SDL.h>
#include <SDL2_ttf/SDL_ttf.h>

menu::menu(SDL_Renderer *rend){
    renderer = rend;

}

void menu::drawMenu(){
    SDL_Surface *fontSurface;
    SDL_Texture *fontTexture;
    SDL_SetRenderDrawColor(renderer,0,0,0,255);
    SDL_RenderClear(renderer);
    TTF_Font* font = TTF_OpenFont("Raleway-Heavy.ttf",28); 
    SDL_Color color {255,255,0,255};
    fontSurface = TTF_RenderText_Blended_Wrapped(font, "Menu --- Left Alt to Continue --- ESC to Quit ", color, 100);
    fontTexture = SDL_CreateTextureFromSurface(renderer,fontSurface);
    SDL_RenderCopyEx(renderer,fontTexture,NULL,&menuRect,0,NULL, SDL_FLIP_NONE);

    SDL_RenderPresent(renderer); // render back buffer to screen.

    // no need to clear surface and texture pointer because they point to objects on the stack
    // which will automatically delete themselves when they go out of scope.
    
}
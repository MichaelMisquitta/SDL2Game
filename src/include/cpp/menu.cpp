#include <header/menu.h>
#include<SDL2/SDL.h>

menu::menu(SDL_Renderer *rend){
    renderer = rend;

}

void menu::drawMenu(){
    SDL_SetRenderDrawColor(renderer,0,0,0,255);
    SDL_RenderClear(renderer);
    

}
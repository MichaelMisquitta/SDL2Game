#include <iostream>
#include <SDL2/SDL.h>
#include <header/bird.h>
#include <header/pipe.h>
#include <header/collision.h>
#include <header/globals.h>
#include <list>
#include <header/menu.h>
#include <SDL2_ttf/SDL_ttf.h>
#include <header/pipePair.h>
#include <header/scoreboard.h>
// #include "cpp/bird.cpp"

// const int WIDTH = 800, HEIGHT = 600;

int main(int charc, char *argv[])
{

    bool gameOn = true;
    int collisions = 0;
    int fps = 60;
    float elapsedMS = 16;
    float dt = 0.016;
    float fpsTime = 1.0000 / float(fps) * 1000.0000;
    Uint64 start = 0;
    Uint64 end = 0;
    global Global;
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        printf("Error initializing SDL: %s\n", SDL_GetError());
        return 0;
    }
    TTF_Init();
    // SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *window = SDL_CreateWindow("test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, Global.WIDTH, Global.HEIGHT, 0);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    collision collisionOb;
    scoreboard scoreBoard{renderer};
    bird flappybird{renderer};
    std::list<pipePair *> pipePairs = genPipePairs(renderer);

    // pipe *pipeBottom = new pipe(false, renderer, 480);
    // pipe *pipeTop = new pipe(true, renderer, 480);
    // //pipe *pipeBottom = new pipe(flappybird.birdPosition,false, renderer, 480);
    // //pipe *pipeTop = new pipe(flappybird.birdPosition,true, renderer, 480);

    menu gameMenu{renderer};

    // std::list<pipe*> pipes {pipeBottom,pipeTop};

    if (window == NULL)
    {
        std::cout << "window error" << SDL_GetError();
        return 1;
    }
    SDL_Event Event;

    while (gameOn)
    {
        start = SDL_GetPerformanceCounter();

        if (SDL_PollEvent(&Event))
        {
            if (SDL_QUIT == Event.type)
            {
                std::cout << "exit success";
                break;
            }
            if (Event.type = SDL_KEYDOWN)
            {
                if (Event.key.keysym.sym == SDLK_SPACE)
                {
                    flappybird.updateVelocity(true, dt);
                }
                if (Event.key.keysym.sym == SDLK_ESCAPE)
                {
                    bool check = true;
                    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                    SDL_RenderClear(renderer);
                    SDL_Event EventInner;
                    std::cout << "esc called outer \n";

                    while (check)
                    {
                        gameMenu.drawMenu();
                        if (SDL_PollEvent(&EventInner))
                        {

                            // std::cout << "polled \n";
                            if (EventInner.type = SDL_KEYDOWN)
                            {
                                if (EventInner.key.keysym.sym == SDLK_LALT)
                                {
                                    check = false;
                                    gameOn = false;
                                }
                                if (EventInner.key.keysym.sym == SDLK_LCTRL)
                                {
                                    std::cout << "test \n";
                                    check = false;
                                }
                            }
                        }
                    }
                }
            }
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        // draw ground - make class and make  ground looks like its moving - TODO
        SDL_Rect groundRect = {0, int(0.75 * Global.HEIGHT), int(Global.WIDTH), int(0.25 * Global.HEIGHT)};
        SDL_SetRenderDrawColor(renderer, 159, 90, 253, 255);
        SDL_RenderFillRect(renderer, &groundRect);

        flappybird.updateVelocity(false, dt);
        flappybird.updatePosition(dt);
        flappybird.draw(renderer);

        updatePipePairs(pipePairs, dt);

        if (collisionOb.isColliding(flappybird, pipePairs))
        {
            collisions++;
            // gameOn = false;
        }
        scoreBoard.drawScoreBoard();

        end = SDL_GetPerformanceCounter();
        elapsedMS = (end - start) / (float)(SDL_GetPerformanceFrequency()) * 1000.0f;

        float delay = 1 / float(fps) * 1000.0f - elapsedMS;
        dt = 1 / float(fps); // delay and elapsed ms both change between frames by 1/60 is the time difference between frames that links them and should be used as dt
        if (delay < 0)
        {
            delay = 1 / 60.0f * 1000.0f; // line is needed to stop delay from going negative when exiting window and causing program crash.
        }
        std::cout << collisions << "\n";
        // SDL_Delay(floor(1000/float(fps)));
        SDL_Delay(delay);

        // gameMenu.drawMenu();
        SDL_RenderPresent(renderer);
    }
    // add code to delete pipe pointers. Use smart pointers next, which are objects and
    // when pointer obj goes out of scope, it deletes pointer automatically!

    // ADD CODE TO FREE POINTERS TO PIPES -USE METHOD AND LOOP THROUGH POINTERS OR USE
    // SMART POINTERS
    std::cout << "-successs bingus 2";
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;
}
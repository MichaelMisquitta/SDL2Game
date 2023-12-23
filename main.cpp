#include <iostream>
#include <SDL2/SDL.h>
#include <time.h>
#include <cmath>
#include <cstdlib>
#include <stdbool.h>

#define WIDTH 640
#define HEIGHT 480
#define SIZE 200
#define SPEED 600
#define GRAVITY 60
#define FPS 60
#define JUMP -1200

int main(int argc, char *argv[])
{
    /* Initializes the timer, audio, video, joystick,
    haptic, gamecontroller and events subsystems */
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        printf("Error initializing SDL: %s\n", SDL_GetError());
        return 0;
    }

    /* Create a window */
    SDL_Window *wind = SDL_CreateWindow(
        "Hello Platformer!",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        WIDTH, 
        HEIGHT, 
        0
    );

    if (!wind)
    {
        printf("Error creating window: %s\n", SDL_GetError());
        SDL_Quit();
        return 0;
    }

    /* Create a renderer */
    Uint32 render_flags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
    SDL_Renderer *rend = SDL_CreateRenderer(wind, -1, render_flags);
    if (!rend)
    {
        printf("Error creating renderer: %s\n", SDL_GetError());
        SDL_DestroyWindow(wind);
        SDL_Quit();
        return 0;
    }

    /* Main loop */
    bool running = true, 
        jump_pressed = false, 
        can_jump = true, 
        left_pressed = false, 
        right_pressed = false;

    float x_pos = (WIDTH - SIZE) / 2, y_pos = (HEIGHT - SIZE) / 2, x_vel = 0, y_vel = 0;
    SDL_Rect rect = {(int)x_pos, (int)y_pos, SIZE, SIZE};
    SDL_Event event;

    while (running)
    {
        /* Process events */
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                running = false;
                break;
            case SDL_KEYDOWN:
                switch (event.key.keysym.scancode)
                {
                case SDL_SCANCODE_SPACE:
                    jump_pressed = true;
                    break;
                case SDL_SCANCODE_A:
                case SDL_SCANCODE_LEFT:
                    left_pressed = true;
                    break;
                case SDL_SCANCODE_D:
                case SDL_SCANCODE_RIGHT:
                    right_pressed = true;
                    break;
                default:
                    break;
                }
                break;
            case SDL_KEYUP:
                switch (event.key.keysym.scancode)
                {
                case SDL_SCANCODE_SPACE:
                    jump_pressed = false;
                    break;
                case SDL_SCANCODE_A:
                case SDL_SCANCODE_LEFT:
                    left_pressed = false;
                    break;
                case SDL_SCANCODE_D:
                case SDL_SCANCODE_RIGHT:
                    right_pressed = false;
                    break;
                default:
                    break;
                }
                break;
            default:
                break;
            }
        }
        
        /* Clear screen */
        SDL_SetRenderDrawColor(rend, 0, 0, 0, 255);
        SDL_RenderClear(rend);
        
        /* Move the rectangle */
        x_vel = (right_pressed - left_pressed) * SPEED;
        y_vel += GRAVITY;
        
        if (jump_pressed && can_jump)
        {
            can_jump = false;
            y_vel = JUMP;
        }
        
        x_pos += x_vel / 60;
        y_pos += y_vel / 60;
        
        if (x_pos <= 0) x_pos = 0;
        if (x_pos >= WIDTH - rect.w) x_pos = WIDTH - rect.w;
        if (y_pos <= 0) y_pos = 0;
        if (y_pos >= HEIGHT - rect.h)
        {
            y_vel = 0;
            y_pos = HEIGHT - rect.h;
            if (!jump_pressed)
                can_jump = true;
        }

        rect.x = (int)x_pos;
        rect.y = (int)y_pos;

        /* Draw the rectangle */
        SDL_SetRenderDrawColor(rend, 255, 0, 0, 255);
        SDL_RenderFillRect(rend, &rect);

        /* Draw to window and loop */
        SDL_RenderPresent(rend);
        SDL_Delay(1000 / FPS);
    }
    
    /* Release resources */
    SDL_DestroyRenderer(rend);
    SDL_DestroyWindow(wind);
    SDL_Quit();
    return 0;
}

// const int WIDTH = 800, HEIGHT = 600;

//  int main(int charc,char *argv[]){

//      int b = 255;
//      float fpsTime = 0;
// //     int fps = 30;
// //     fpsTime = 1.0000/float(fps)*1000.0000;
// //     Uint64 start = 0;
// //     Uint64 end = 0;
//     SDL_Init(SDL_INIT_EVERYTHING);
//     //SDL_Init(SDL_INIT_VIDEO);
// //     SDL_Window *window = SDL_CreateWindow("test",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,WIDTH,HEIGHT,SDL_WINDOW_ALLOW_HIGHDPI);
// //     SDL_Renderer *renderer = SDL_CreateRenderer(window,-1,0);
// //     if (window == NULL){
// //         std::cout << "window error"<<SDL_GetError();
// //         return 1;

// //     }
// //     SDL_Event windowEvent;

// //     while(true){
// //     //     start = SDL_GetPerformanceCounter();

// //         if(SDL_PollEvent(&windowEvent)){
// //             if(SDL_QUIT == windowEvent.type){
// //                 std::cout << "exit success";
// //                 break;
// //             }
// //         }

// //          SDL_RenderClear(renderer);

// //     //     b -= 1;
// //     //     if (b < 0){
// //     //         b = 255;
// //     //     }
// //          SDL_SetRenderDrawColor(renderer,100,50,100,255);
// //          SDL_RenderPresent(renderer); // call once per frame to put buffer of drawings to screen

// //     //     end = SDL_GetPerformanceCounter();
// //     //     float elapsedMS = (end-start) / (float)(SDL_GetPerformanceFrequency()) * 1000.0f;

// //          SDL_Delay(floor(1000));
// //     }
// //     std::cout << "-successs bingus 2";
// //     SDL_DestroyRenderer(renderer);
// //     SDL_DestroyWindow(window);
//     SDL_Delay((20000));
//      SDL_Quit();

//      return EXIT_SUCCESS;
// }
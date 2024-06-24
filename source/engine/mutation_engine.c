#include "mutation_engine.h"

#include <stdbool.h>
#include <SDL2/SDL.h>

static bool running = true;
static SDL_Window *window = NULL;
static SDL_Renderer *renderer = NULL;

int init_sdl() {
    // Initialize the mutation engine
    // Initialize SDL2
    if (SDL_Init(SDL_INIT_VIDEO) != 0) 
    {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        return 1;
    }

    window = SDL_CreateWindow("Mutation Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);
    if (window == NULL) 
    {
        SDL_Log("Unable to create window: %s", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) 
    {
        SDL_DestroyWindow(window);
        SDL_Log("Unable to create renderer: %s", SDL_GetError());
        SDL_Quit();
        return 1;
    }
    return 0;
}

int mutation_engine_init() {
    if (init_sdl() != 0)
    {
        return 1;
    }

    return 0;
}

int mutation_engine_run() {
    while(running)
    {
        SDL_Event event;
        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT)
            {
                running = false;
            }
            else if(event.type == SDL_KEYDOWN)
            {
                if(event.key.keysym.sym == SDLK_ESCAPE)
                {
                    running = false;
                }
            }
        }

        SDL_SetRenderDrawColor(renderer, 94, 25, 20, 255);
        SDL_RenderClear(renderer);

        SDL_RenderPresent(renderer);
    }
    return 0;
}

int mutation_engine_quit()
{
    if (renderer != NULL)
    {
        SDL_DestroyRenderer(renderer);
    }

    if (window != NULL)
    {
        SDL_DestroyWindow(window);
    }

    SDL_Quit();
    return 0;
}

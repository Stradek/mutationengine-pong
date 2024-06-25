#include "mutation_engine.h"

#include "renderer.h"

#include <stdbool.h>
#include <SDL2/SDL.h>

static bool running = true;

int mutation_engine_init() 
{
    if (init_sdl() != 0)
    {
        return 1;
    }

    return 0;
}

int mutation_engine_run_loop() {
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

    render_frame();

    }
    return 0;
}

int mutation_engine_close()
{
    close_sdl();
    return 0;
}

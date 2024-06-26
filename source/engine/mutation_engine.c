#include "mutation_engine.h"

#include "renderer.h"

#include <stdbool.h>
#include <SDL2/SDL.h>
#include <time.h>


int mutation_engine_init() 
{
    if (init_sdl() != 0)
    {
        return 1;
    }

    return 0;
}

int mutation_engine_run_loop() 
{
    const unsigned int target_fps = 60;
    const float target_frame_time = 1.0 / (float) target_fps;

    bool running = true;

    while(running)
    {
        const clock_t frame_start_time = clock();

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

        const clock_t frame_end_time = clock();
        const float frame_elapsed_time = (float) (frame_end_time - frame_start_time) / CLOCKS_PER_SEC;
        const float time_until_target_frame = target_frame_time - frame_elapsed_time;

        const unsigned int SECONDS_TO_NANOSECONDS = 1000000000;
        const struct timespec sleep_time =
        {
            0, 
            time_until_target_frame * SECONDS_TO_NANOSECONDS
        }; 
        nanosleep(&sleep_time, NULL);
    }
    return 0;
}

int mutation_engine_close()
{
    close_sdl();
    return 0;
}

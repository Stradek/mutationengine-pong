#include "mutation_engine.h"

#include "renderer.h"
#include "utils.h"

#include <math.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <stdio.h>

int mutation_engine_init(void) 
{
    if (init_renderer() != 0)
    {
        return 1;
    }

    return 0;
}

int mutation_engine_run_loop(void) 
{
    bool running = true;
    Uint8 frames_per_second_counter = 0;
    Uint64 last_performance_logging_time = SDL_GetPerformanceCounter();

    while(running)
    {
        const Uint64 frame_time_start = SDL_GetPerformanceCounter();
        {
            const float last_performance_logging_delta_time = (frame_time_start - last_performance_logging_time) / (float)SDL_GetPerformanceFrequency() * SECONDS_TO_MILLISECONDS;
            if(last_performance_logging_delta_time >= 1000)
            {
                printf("FPS: %u\n", frames_per_second_counter);
                last_performance_logging_time = SDL_GetPerformanceCounter();
                frames_per_second_counter = 0;
            }
        }

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

        {
            ++frames_per_second_counter;
            const Uint64 frame_time_end = SDL_GetPerformanceCounter();

            const float elapsed_frame_time = (frame_time_end - frame_time_start) / (float)SDL_GetPerformanceFrequency() * SECONDS_TO_MILLISECONDS;
            const float wait_frame_time = fmax(0.0f, renderer_options.target_frame_time - elapsed_frame_time);
            SDL_Delay(floor(wait_frame_time));
        }
    }
    return 0;
}

int mutation_engine_close(void)
{
    if(close_renderer() != 0)
    {
        return 1;
    }

    return 0;
}

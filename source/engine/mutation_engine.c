#include "mutation_engine.h"

#include "renderer.h"

#include <stdbool.h>
#include <SDL2/SDL.h>
#include <stdio.h>
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
    const unsigned int SECONDS_TO_NANOSECONDS = 1000000000;
    const unsigned int CLOCKS_PER_NANOSECOND = SECONDS_TO_NANOSECONDS / CLOCKS_PER_SEC;
    const unsigned int target_frame_time = SECONDS_TO_NANOSECONDS / target_fps;

    bool running = true;
    unsigned int frames_per_second_counter = 0;
    clock_t last_second_cpu_clock_time = clock();
    while(running)
    {
        const clock_t frame_start_time = clock();

        {
            const clock_t current_cpu_clock_time = clock();
            const unsigned int elapsed_time = (current_cpu_clock_time - last_second_cpu_clock_time) * CLOCKS_PER_NANOSECOND;
            if(elapsed_time >= SECONDS_TO_NANOSECONDS)
            {
                printf("FPS: %u\n", frames_per_second_counter);
                frames_per_second_counter = 0;
                last_second_cpu_clock_time = clock();
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
            const clock_t current_cpu_clock_time = clock();
            const unsigned int frame_elapsed_time = (current_cpu_clock_time - frame_start_time) * CLOCKS_PER_NANOSECOND;
            const float time_to_reach_frame_time_target = target_frame_time - frame_elapsed_time;

            const struct timespec sleep_time =
            {
                0, 
                time_to_reach_frame_time_target 
            }; 
            nanosleep(&sleep_time, NULL);
            frames_per_second_counter++;
        }
    }
    return 0;
}

int mutation_engine_close()
{
    close_sdl();
    return 0;
}

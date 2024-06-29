#pragma once

#include "common/types.h"

typedef struct 
{
    uint target_fps;
    float target_frame_time;
} RendererOptionsInternal;

extern RendererOptionsInternal renderer_options;

int init_sdl(void);
int init_renderer(void);
int render_frame(void);
int close_sdl(void);
int close_renderer(void);

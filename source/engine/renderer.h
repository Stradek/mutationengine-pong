#ifndef RENDERER_H
#define RENDERER_H

typedef struct 
{
    unsigned int target_fps;
    float target_frame_time;
} RendererOptionsInternal;

static RendererOptionsInternal renderer_options; 

int init_sdl(void);
int init_renderer(void);
int render_frame(void);
int close_sdl(void);
int close_renderer(void);

#endif

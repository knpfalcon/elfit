#ifndef GFX_H
#define GFX_H

typedef struct
{
    ALLEGRO_BITMAP *elf;
    ALLEGRO_BITMAP *snowman;
} t_graphics;

bool load_graphics(t_graphics *g);
#endif //GFX_H
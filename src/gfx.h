#ifndef _GFX_H
#define _GFX_H

typedef struct                  //This struct holds all the bitmap pointers for loading by al_load_bitmap(...);
{
    ALLEGRO_BITMAP *player;
    ALLEGRO_BITMAP *shadow;
    ALLEGRO_BITMAP *snowball;
    ALLEGRO_BITMAP *block;
    ALLEGRO_BITMAP *ground;
} t_graphics;

//Loads all the graphics, packed into one function.
bool load_graphics(t_graphics *g);
#endif

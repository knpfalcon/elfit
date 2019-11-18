#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

#include "gfx.h"

bool load_graphics(t_graphics *g)
{
    g->player = al_load_bitmap("data/gfx/player.png");
    if (!g->player)
    {
        fprintf(stderr, "Couldn't load player.png");
    }
    printf("\nLoad player: %p\n", g->player);

    g->shadow = al_load_bitmap("data/gfx/shadow.png");
    if (!g->shadow)
    {
        fprintf(stderr, "Couldn't load shadow.png");
    }
    printf("\nLoad shadow: %p\n", g->shadow);
    
    g->snowman = al_load_bitmap("data/gfx/snowman.png");
    if (!g->snowman)
    {
        fprintf(stderr, "Couldn't load snowman.png");
    }
    printf("Load snowman: %p\n", g->snowman);

    g->block = al_load_bitmap("data/gfx/block.png");
    if (!g->block)
    {
        fprintf(stderr, "Couldn't load block.png");
    }
    printf("Load block: %p\n", g->block);

    g->ground = al_load_bitmap("data/gfx/ground.png");
    if (!g->ground)
    {
        fprintf(stderr, "Couldn't load ground.png");
    }
    printf("Load ground: %p\n", g->ground);

    return true;
}
#include <allegro5/allegro_color.h>

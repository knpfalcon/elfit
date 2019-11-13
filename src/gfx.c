#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

#include "gfx.h"

bool load_graphics(t_graphics *g)
{
    g->elf = al_load_bitmap("data/gfx/elf.png");
    if (!g->elf)
    {
        fprintf(stderr, "Couldn't load elf.png");
    }
    printf("\nLoad elf: %p\n", g->elf);
    
    g->snowman = al_load_bitmap("data/gfx/snowman.png");
    if (!g->snowman)
    {
        fprintf(stderr, "Couldn't load snowman.png");
    }
    printf("Load snowman: %p\n", g->snowman);

    return true;
}

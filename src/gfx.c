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

    g->block = al_load_bitmap("data/gfx/block.png");
    if (!g->block)
    {
        fprintf(stderr, "Couldn't load block.png");
    }
    printf("Load block: %p\n", g->block);

    g->floor = al_load_bitmap("data/gfx/floor.png");
    if (!g->floor)
    {
        fprintf(stderr, "Couldn't load floor.png");
    }
    printf("Load floor: %p\n", g->floor);

    return true;
}
#include <allegro5/allegro_color.h>

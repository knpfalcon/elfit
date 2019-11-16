#include <stdio.h>

#include "player.h"
#include "entity.h"
#include "gfx.h"
#include "game.h"

void player_init(t_entity *p, t_graphics *g)
{
    p->x = 0;
    p->y = 0;
    p->active = true;
    p->sprite_sheet = g->elf;
}

void player_move(t_entity *p, bool k[])
{
    if (k[KEY_UP]) p->y -= 32;
    if (k[KEY_DOWN]) p->y += 32;
    if (k[KEY_LEFT]) p->x -= 32;
    if (k[KEY_RIGHT]) p->x += 32;
}
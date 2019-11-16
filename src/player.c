#include <stdio.h>

#include "player.h"
#include "entity.h"
#include "gfx.h"
#include "game.h"
#include "main.h"

void player_init(t_entity *p, t_graphics *g)
{
    p->x = 32;
    p->y = 32;
    p->dir = SOUTH;
    p->speed = 4;
    p->moving = false;
    p->active = true;
    p->sprite_sheet = g->elf;
}

void player_move(t_entity *p, bool k[])
{
    if (p->moving)
    {
        if (p->dir == NORTH)
        {
            p->y -= p->speed;
            if (p->y % 32 == 0) p->moving = false;
        }
        if (p->dir == SOUTH)
        {
            p->y += p->speed;
            if (p->y % 32 == 0) p->moving = false;
        }
        if (p->dir == WEST)
        {
            p->x -= p->speed;
            if (p->x % 32 == 0) p->moving = false;
        }
        if (p->dir == EAST)
        {
            p->x += p->speed;
            if (p->x % 32 == 0) p->moving = false;
        }
    }
    
    if (!p->moving)
    {
        if (k[KEY_UP] && p->y > 0)
        {
            p->dir = NORTH;
            p->moving = true;
        }
        if (k[KEY_DOWN] && p->y < 320)
        {
            p->dir = SOUTH;
            p->moving = true;
        }
        if (k[KEY_LEFT] && p->x > 0)
        {
            p->dir = WEST;
            p->moving = true;
        }
        if (k[KEY_RIGHT] && p->x < 608)
        {
            p->dir = EAST;
            p->moving = true;
        }
        printf("%d, %d\n", p->x, p->y);
    }
    
    
}
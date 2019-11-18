#include <stdio.h>

#include "player.h"
#include "entity.h"
#include "gfx.h"
#include "game.h"
#include "main.h"

void player_init(t_entity *p, t_graphics *g, t_snowball *sb)
{
    p->x = 32;
    p->y = 32;
    p->dir = SOUTH;
    p->speed = 2;
    p->frame = 0;
    p->shoot_time = 0;
    p->aim_charge = 0;
    p->moving = false;
    p->active = true;
    p->sprite_sheet = g->player;

    for (int i = 0; i < MAX_SNOWBALLS; i++)
    {
        sb[i].active = false;
        sb[i].dir = 0;
    }
}

void player_move(t_entity *p, bool k[], unsigned char *m, t_snowball *sb)
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
    
    if (!p->moving && p->shoot_time == 0)
    {
        
        if (!k[KEY_AIM])
        {
            p->frame = 0;
            p->aim_charge = 0;
        }

        if (!k[KEY_AIM])
        {
            if (k[KEY_UP] && p->y > 0)
            {
                if (m[(p->x/32) + ((p->y/32)-1) * 20] == 0)
                {
                    p->dir = NORTH;
                    p->frame = 1;
                    p->moving = true;
                }
                
            }
            if (k[KEY_DOWN] && p->y < 320)
            {
                if (m[(p->x/32) + ((p->y/32)+1) * 20] == 0)
                {
                    p->dir = SOUTH;
                    p->frame = 1;
                    p->moving = true;
                }
            
            }
            if (k[KEY_LEFT] && p->x > 0)
            {
                if (m[((p->x/32)-1) + (p->y/32) * 20] == 0)
                {
                    p->dir = WEST;
                    p->frame = 1;
                    p->moving = true;
                }
            }
            if (k[KEY_RIGHT] && p->x < 608)
            {
                if (m[((p->x/32)+1) + (p->y/32) * 20] == 0)
                {
                    p->dir = EAST;
                    p->frame = 1;
                    p->moving = true;
                }
                
            }
        }
        if (k[KEY_AIM] && !k[KEY_FIRE] && p->shoot_time == 0)
        {
            p->frame = 5;
            p->aim_charge++;
            if (k[KEY_UP])
            {
                p->dir = NORTH;
            }
            if (k[KEY_DOWN])
            {
                p->dir = SOUTH;
            }
            if (k[KEY_LEFT] && p->x > 0)
            {
                p->dir = WEST;
            }
            if (k[KEY_RIGHT] && p->x < 608)
            {
                p->dir = EAST;
            }
        }
        if (k[KEY_AIM] && k[KEY_FIRE] && p->shoot_time == 0 && p->aim_charge >= 4) //FIRE!!
        {
            p->frame = 6;
            p->shoot_time = 5;
            p->aim_charge = 0;

            for (int i = 0; i < MAX_SNOWBALLS; i++)
            {
                if (sb[i].active == false)
                {
                    sb[i].active = true;
                    sb[i].dir = p->dir;
                    sb[i].x = p->x;
                    if (p->dir != NORTH) sb[i].y = p->y;
                    else sb[i].y = p->y - 16;
                    printf ("\nSnowball %d activate\n", i);
                    break;
                }
            }
            

            k[KEY_FIRE] = false;
            
        }
        
    }
}
    
void player_draw(t_entity *p, unsigned char dir, unsigned char frame)
{
    al_draw_bitmap_region(p->sprite_sheet, frame * PLAYER_SIZE, dir * PLAYER_SIZE, PLAYER_SIZE, PLAYER_SIZE, p->x, p->y - PLAYER_OFFSET, 0);
}

void player_animate(t_entity *p)
{
    if (p->moving)
    {
        if (p->frame < 4) p->frame++;
        else p->frame = 1;
    }
}
#ifndef _PLAYER_H
#define _PLAYER_H

#include "entity.h"
#include "gfx.h"

#define PLAYER_SIZE 32
#define PLAYER_OFFSET 8
#define MAX_SNOWBALLS 10

typedef struct
{
    int x;
    int y;
    unsigned char dir;
    bool active;
} t_snowball;

void player_init(t_entity *p, t_graphics *g, t_snowball *sb);
void player_move(t_entity *p, bool k[], unsigned char *m, t_snowball *sb);
void player_draw(t_entity *p, unsigned char dir, unsigned char frame);
void player_animate(t_entity *p);




#endif
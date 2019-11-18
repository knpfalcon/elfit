#ifndef _PLAYER_H
#define _PLAYER_H

#include "entity.h"
#include "gfx.h"

#define PLAYER_SIZE 32
#define PLAYER_OFFSET 8

void player_init(t_entity *p, t_graphics *g);
void player_move(t_entity *p, bool k[], unsigned char *m);
void player_draw(t_entity *p, unsigned char dir, unsigned char frame);
void player_animate(t_entity *p);

#endif
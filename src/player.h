#ifndef _PLAYER_H
#define _PLAYER_H

#include "entity.h"
#include "gfx.h"

void player_init(t_entity *p, t_graphics *g);
void player_move(t_entity *p, bool k[], unsigned char *m);

#endif
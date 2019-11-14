#ifndef _GAME_H
#define _GAME_H

#include "gfx.h"
//The main game loop where all the magic happens. Returns true when done.
bool game_loop(ALLEGRO_DISPLAY *display, ALLEGRO_TIMER *timer, ALLEGRO_EVENT_QUEUE *q, t_graphics *g);

#endif

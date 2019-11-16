#ifndef _GAME_H
#define _GAME_H

#include "gfx.h"

enum E_KEYS { KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT, KEY_ESC};

//The main game loop where all the magic happens. Returns true when done.
bool game_loop(ALLEGRO_DISPLAY *display, ALLEGRO_TIMER *timer, ALLEGRO_EVENT_QUEUE *q, t_graphics *g);

#endif

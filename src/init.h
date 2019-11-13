#ifndef INIT_H
#define INIT_H

#include <stdbool.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

#include "main.h"
#include "gfx.h"

//Initializes allegro and everything the game needs in one function.
bool init_all(ALLEGRO_DISPLAY **disp, ALLEGRO_TIMER **t, ALLEGRO_EVENT_QUEUE **q);

//Cleans up what needs to be cleaned at the end of main(...)
void clean_up(ALLEGRO_DISPLAY **disp, ALLEGRO_TIMER **t, ALLEGRO_EVENT_QUEUE **q, t_graphics *g);

#endif //INIT_H
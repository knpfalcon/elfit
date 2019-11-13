#ifndef GAME_H
#define GAME_H

//The main game loop where all the magic happens. Returns true when done.
bool game_loop(ALLEGRO_DISPLAY *display, ALLEGRO_TIMER *timer, ALLEGRO_EVENT_QUEUE *q);

#endif //GAME_H
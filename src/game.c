#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_color.h>

#include "game.h"

bool game_loop(ALLEGRO_DISPLAY *display, ALLEGRO_TIMER *timer, ALLEGRO_EVENT_QUEUE *q)
{
    bool redraw = true;
    bool done = false;
    int ticks = 0;
    
    al_start_timer(timer);
    /* Main Loop (Slow down instead of frame skip) */
    while (done == false)
    {
        if (redraw)
        {
            //draw_function
            redraw = false;
            ticks = 0;
        }
        do
        {
            ALLEGRO_EVENT ev;
            al_wait_for_event(q, &ev);
            if (ev.type == ALLEGRO_EVENT_TIMER)
            {
                ++ticks;
                if (ticks == 1)
                {
                    //Update Logic
                }
                redraw = true;
            }
          
            if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) done = true;

        } while (!al_is_event_queue_empty(q));
    }


    return true;
}

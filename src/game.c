#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

#include "game.h"
#include "gfx.h"
#include "entity.h"

bool game_loop(ALLEGRO_DISPLAY *display, ALLEGRO_TIMER *timer, ALLEGRO_EVENT_QUEUE *q, t_graphics *g)
{
    bool redraw = true;
    bool done = false;
    int ticks = 0;
    int f = 0;
    int anim_time = 0;
    
    al_start_timer(timer);
    /* Main Loop (Slow down instead of frame skip) */
    while (done == false)
    {
        if (redraw)
        {
            //draw_function
            
            if (anim_time == 0) 
            {
                al_clear_to_color(al_map_rgb(0,0,0));
                al_draw_bitmap(test.frame[f], 32, 32, 0);
            }
            
            al_flip_display();
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
                    anim_time++;
                    if (anim_time == 7) 
                    {
                        anim_time = 0;
                        f ^= 1;
                    }
                    
                }
                redraw = true;
            }
            if (ev.type == ALLEGRO_EVENT_KEY_UP)
            {
                if (ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE) done = true;
            }
            if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) done = true;

        } while (!al_is_event_queue_empty(q));
    }


    return true;
}

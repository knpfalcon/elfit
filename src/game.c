#include <stdio.h>
#include <stdbool.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

#include "player.h"
#include "game.h"

bool key[5] = { false };

t_entity player;

/*
*   Game Update Function
*/
void game_update()
{
    player_move(&player, key);
}

/*
*   Game Draw Function
*/
void game_draw()
{

}

/*
*   Check key events Function
*/
void key_event_check(ALLEGRO_EVENT *ev, bool *done)
{
    if (ev->type == ALLEGRO_EVENT_KEY_DOWN)
    {
        switch (ev->keyboard.keycode)
        {
            case ALLEGRO_KEY_UP:
                key[KEY_UP] = true;
                break;
            case ALLEGRO_KEY_DOWN:
                key[KEY_DOWN] = true;
                break;
            case ALLEGRO_KEY_LEFT:
                key[KEY_LEFT] = true;
                break;
            case ALLEGRO_KEY_RIGHT:
                key[KEY_RIGHT] = true;
                break;
            case ALLEGRO_KEY_ESCAPE:
                key[KEY_ESC] = true;
                break;
        }
    }
    if (ev->type == ALLEGRO_EVENT_KEY_UP)
    {
        switch (ev->keyboard.keycode)
        {
            case ALLEGRO_KEY_UP:
                key[KEY_UP] = false;
                break;
            case ALLEGRO_KEY_DOWN:
                key[KEY_DOWN] = false;
                break;
            case ALLEGRO_KEY_LEFT:
                key[KEY_LEFT] = false;
                break;
            case ALLEGRO_KEY_RIGHT:
                key[KEY_RIGHT] = false;
                break;
            case ALLEGRO_KEY_ESCAPE:
                key[KEY_ESC] = false;
                break;
        }
    }
    
    if (ev->type == ALLEGRO_EVENT_DISPLAY_CLOSE || key[KEY_ESC]) *done = true; //Exit game if escape is pressed or close window
}

/*
*   Main Game Loop
*/
bool game_loop(ALLEGRO_DISPLAY *display, ALLEGRO_TIMER *timer, ALLEGRO_EVENT_QUEUE *q, t_graphics *g)
{
    bool redraw = true;
    bool done = false;
    int ticks = 0;
    int anim_time = 0;

    player_init(&player, g);
    
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
                al_draw_bitmap(player.sprite_sheet, player.x, player.y, 0);
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
                    game_update();
                }
                redraw = true;
            }

            key_event_check(&ev, &done);
        } while (!al_is_event_queue_empty(q));
    }

    return true;
}

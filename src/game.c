#include <stdio.h>
#include <stdbool.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

#include "player.h"
#include "game.h"
#include "testmap.h"
#include "main.h"

bool key[5] = { false };

t_entity player;
ALLEGRO_BITMAP *bitmap_game = NULL;

/*
*   Game Update Function
*/
void game_update()
{
    player_move(&player, key, map);
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
    bitmap_game = al_create_bitmap(SCREEN_WIDTH, SCREEN_HEIGHT);
    
    al_start_timer(timer);
    /* Main Loop (Slow down instead of frame skip) */
    while (done == false)
    {
        if (redraw)
        {
            //draw_function
            al_set_target_bitmap(bitmap_game);
            for(int y = 0; y < 10; y++)
            {
                for(int x = 0; x < 20; x++)
                {
                    al_draw_bitmap(g->floor, x * 32, (y * 32), 0);
                    if (map[x + y * 20] == 1)
                    {
                        al_draw_bitmap_region(g->block, 0, 16, 32, 32, x * 32, y * 32, 0);
                    }
                    if (map[x + y * 20] == 2)
                    {
                        al_draw_bitmap(g->floor, x * 32, (y * 32), 0);
                        al_draw_bitmap_region(g->snowman, 0, 32, 32, 32, x * 32, y * 32, 0);
                    }
                }
            }

            player_draw(&player, player.dir, player.frame);

            for(int y = 0; y < 10; y++)
            {
                for(int x = 0; x < 20; x++)
                {
                    if (map[x + y * 20] == 1)
                    {
                        al_draw_bitmap_region(g->block, 0, 0, 32, 16, x * 32, (y * 32) -16, 0);
                    }
                    if (map[x + y * 20] == 2)
                    {
                        al_draw_bitmap_region(g->snowman, 0, 0, 32, 32, x * 32, (y * 32) -32, 0);
                    }
                }
            }

            if (anim_time == 0) 
            {
                player_animate(&player);
            }

            al_set_target_backbuffer(display);
            al_draw_scaled_bitmap(bitmap_game, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0, al_get_display_width(display), al_get_display_height(display), 0);

            al_wait_for_vsync();
            al_flip_display();
            redraw = false;
            ticks = 0;
        }
        
        do
        {
            ALLEGRO_EVENT ev;
            al_wait_for_event(q, &ev);
            key_event_check(&ev, &done);
            if (ev.type == ALLEGRO_EVENT_TIMER)
            {
                
                ++ticks;
                if (ticks == 1)
                {
                    game_update();
                    anim_time++;
                    if (anim_time == 8) anim_time = 0;
                }
                redraw = true;
            }

        } while (!al_is_event_queue_empty(q));
    }

    return true;
}

#include <stdio.h>
#include <stdbool.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

#include "player.h"
#include "game.h"
#include "testmap.h"
#include "main.h"

bool key[7] = { false };

t_entity player;
t_snowball snowball[MAX_SNOWBALLS];

ALLEGRO_BITMAP *bitmap_game = NULL;

/*
*   Game Update Function
*/
void game_update()
{

    //Update snowballs
    for (int i = 0; i < MAX_SNOWBALLS; i++)
    {
        if (snowball[i].active)
        {
            if (snowball[i].x >= 640 || snowball[i].x <= -32 || snowball[i].y <= -32 || snowball[i].y >= 304)
            {
                snowball[i].active = false;
            }
            if (map[(snowball[i].x/32) + (snowball[i].y/32) * 20] > 0)
            {
                snowball[i].active = false;
            }
            if (snowball[i].dir == NORTH) snowball[i].y -= 8;
            else if (snowball[i].dir == SOUTH) snowball[i].y += 8;
            else if (snowball[i].dir == EAST)  snowball[i].x += 8;
            else if (snowball[i].dir == WEST)  snowball[i].x -= 8;
        }
    }

    player_move(&player, key, map, snowball);
    if (player.shoot_time > 0) player.shoot_time--;

    
}

/*
*   Game Draw Function
*/
void game_draw(ALLEGRO_DISPLAY *display, t_graphics *g, int *anim_time)
{
    al_set_target_bitmap(bitmap_game);
    for(int y = 0; y < 10; y++)
    {
        for(int x = 0; x < 20; x++)
        {
            al_draw_bitmap(g->ground, x * 32, (y * 32), 0);
            if (map[x + y * 20] == 1)
            {
                al_draw_bitmap_region(g->block, 0, 16, 32, 32, x * 32, y * 32, 0);
            }
        }
    }

    al_draw_bitmap(g->shadow, player.x, player.y - PLAYER_OFFSET + 2, 0);
    player_draw(&player, player.dir, player.frame);

    //Draw Snowballs
    for (int i = 0; i < MAX_SNOWBALLS; i++)
    {
        if (snowball[i].active)
        {
            if (snowball[i].dir == EAST) al_draw_bitmap(g->snowball, snowball[i].x - 8, snowball[i].y - PLAYER_OFFSET, 0);
            if (snowball[i].dir == WEST) al_draw_bitmap(g->snowball, snowball[i].x -16 , snowball[i].y - PLAYER_OFFSET, 0);
            if (snowball[i].dir == NORTH) al_draw_bitmap(g->snowball, snowball[i].x, snowball[i].y - PLAYER_OFFSET - 16, 0);
            if (snowball[i].dir == SOUTH) al_draw_bitmap(g->snowball, snowball[i].x, snowball[i].y - PLAYER_OFFSET - 16, 0);
        }
    }

    //draw forground
    for(int y = 0; y < 10; y++)
    {
        for(int x = 0; x < 20; x++)
        {
            if (map[x + y * 20] == 1)
            {
                al_draw_bitmap_region(g->block, 0, 0, 32, 16, x * 32, (y * 32) -16, 0);
            }
        }
    }

    if (*anim_time == 0) 
    {
        player_animate(&player);
    }

    

    al_set_target_backbuffer(display);
    al_draw_scaled_bitmap(bitmap_game, 0, 0, 640, 360, 0, 0, al_get_display_width(display), al_get_display_height(display), 0);

    al_wait_for_vsync();
    al_flip_display();

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
            case ALLEGRO_KEY_Z:
                key[KEY_AIM] = true;
                break;
            case ALLEGRO_KEY_X:
                key[KEY_FIRE] = true;
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
            case ALLEGRO_KEY_Z:
                key[KEY_AIM] = false;
                break;
            case ALLEGRO_KEY_X:
                key[KEY_FIRE] = false;
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

    player_init(&player, g, snowball);
    bitmap_game = al_create_bitmap(640, 360);
    
    al_start_timer(timer);
    /* Main Loop (Slow down instead of frame skip) */
    while (done == false)
    {
        if (redraw)
        {
            game_draw(display, g, &anim_time);
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
                    if (anim_time == player.speed * 2 ) anim_time = 0;
                }
                redraw = true;
            }

        } while (!al_is_event_queue_empty(q));
    }

    return true;
}

#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

#include "init.h"
#include "gfx.h"
#include "game.h"
#include "entity.h"
#include "main.h"

/**** MAIN ****/
int main(int argc, char *argv[])
{
    ALLEGRO_DISPLAY *display = NULL;
    ALLEGRO_TIMER *timer = NULL;
    ALLEGRO_EVENT_QUEUE *event_queue = NULL;
    t_graphics graphics = { NULL };
    
    //Initialize Everything
    init_all(&display, &timer, &event_queue);
    
    //TEST load and draw a bitmap
    load_graphics(&graphics);
    al_draw_bitmap(graphics.elf, 32, 32, 0);
    al_draw_bitmap(graphics.snowman, 64, 32, 0);
    al_flip_display();

    /* GAME LOOP */
    if(!game_loop(display, timer, event_queue))
    {
        fprintf(stderr, "Game loop returned false!");
        return -1;
    }

    /* CLEAN UP AT END */
    clean_up(&display, &timer, &event_queue, &graphics);

    return 0;
}
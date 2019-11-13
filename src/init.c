#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

#include "init.h"
#include "version.h"

bool init_all(ALLEGRO_DISPLAY **disp, ALLEGRO_TIMER **t, ALLEGRO_EVENT_QUEUE **q)
{
    printf("Ah, Elf It! %d.%d%d\n", MAJOR, MINOR, PATCH);
    //Allegro Init
    if (!al_init()) {
        fprintf(stderr, "Failed to init Allegro!\n");
        return false;
    }

    //Install Keyboard
    if(!al_install_keyboard())
    {
        fprintf(stderr, "Failed to install keyboard!");
        return false;
    }

    //Install Mouse
    if(!al_install_mouse())
    {
        fprintf(stderr, "Failed to install mouse!");
        return false;
    }

    //Init the Image Addon
    if(!al_init_image_addon())
    {
      fprintf(stderr, "Failed to init image addon!");
      return false;
    }
    
    //Create Timer
    *t = al_create_timer(1.0 / FPS);
    if (!*t)
    {
        fprintf(stderr, "Failed to create timer!");
        return false;
    }

    //Create Display
    *disp = al_create_display(SCREEN_WIDTH, SCREEN_HEIGHT);
    if (!*disp)
    {
        fprintf(stderr, "Failed to create display!");
        return false;
    }

    //Create an event queue
    *q = al_create_event_queue();
    if (!*disp)
    {
        fprintf(stderr, "Failed to create event queue!");
        return false;
    }

    al_register_event_source(*q, al_get_display_event_source(*disp));
    al_register_event_source(*q, al_get_timer_event_source(*t));
    al_register_event_source(*q, al_get_keyboard_event_source());

    al_clear_to_color(al_map_rgb(0, 0, 0));
    al_flip_display();
    
    return true;
}

void clean_up(ALLEGRO_DISPLAY **disp, ALLEGRO_TIMER **t, ALLEGRO_EVENT_QUEUE **q, t_graphics *g)
{
    al_destroy_bitmap(g->snowman);
    al_destroy_bitmap(g->elf);
    if(*q != NULL) al_destroy_event_queue(*q);
    if(*t != NULL)  al_destroy_timer(*t);
    if(*disp != NULL) al_destroy_display(*disp);
}

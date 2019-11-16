#ifndef _ENTITY_H
#define _ENTITY_H

#include <stdbool.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>


#define MAX_ENTITIES 64

typedef struct                  //An entity is either the player or an enemy. It's basically an active object.
{
    unsigned int x;             //X position of an entity.
    unsigned int y;             //Y position of an entity.
    bool active;                //Is this entity active?

    ALLEGRO_BITMAP *sprite_sheet;   //A pointer to an already loaded bitmap

} t_entity;



#endif

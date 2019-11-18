#ifndef _ENTITY_H
#define _ENTITY_H

#include <stdbool.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

#define NORTH   0
#define EAST    1
#define SOUTH   2
#define WEST    3

#define MAX_ENTITIES 64

typedef struct                  //An entity is either the player or an enemy. It's basically an active object.
{
    unsigned int x;             //X position of an entity.
    unsigned int y;             //Y position of an entity.
    unsigned char dir;          //What direction is this entity moving?
    unsigned char speed;        //How many pixels at a time does the entity
    unsigned char frame;        //What is the current frame?
    unsigned char shoot_time;   //Shoot frame time
    unsigned char aim_charge;   //Charge aim
    bool moving;                //Is this entity moving?
    bool active;                //Is this entity active?

    ALLEGRO_BITMAP *sprite_sheet;   //A pointer to an already loaded bitmap

} t_entity;



#endif

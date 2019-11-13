#ifndef ENTITY_H
#define ENTITY_H

#include <stdbool.h>

#define MAX_ENTITIES 64

typedef struct          //An entity is either the player or an enemy. It's basically an active object.
{
    unsigned int x;     //X position of an entity.
    unsigned int y;     //Y position of an entity.
    bool active;        //Is this entity active?
} t_entity;

#endif //ENTITY_H
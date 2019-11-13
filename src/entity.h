#ifndef ENTITY_H
#define ENTITY_H

#include <stdbool.h>

#define MAX_ENTITIES 64

typedef struct
{
    unsigned int x;
    unsigned int y;
    bool active;
} t_entity;

#endif //ENTITY_H
#ifndef MAP_H
#define MAP_H

typedef struct              //A position on the map grid
{
    unsigned char tile;     //Does this position have a tile? If so, what type? 0 = nothing.
    unsigned char entity;   //Does this position have an entity starting point? If so, what type? 0 = nothing.
    unsigned char item;     //Does this position have an item? If so, what type? 0 = nothing.
}t_pos;

typedef struct              //This is the map struct. It hold all the information, including a pointer to a position on the map grid.
{
    char name[32];               //Name of the map.
    t_pos *pos;                 //A pointer to a position on the map grid
}t_map;

#endif //MAP_H

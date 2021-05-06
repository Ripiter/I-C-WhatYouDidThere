#pragma once
#include "Field.h"

#define MAP_HEIGHT 20
#define MAP_WIDTH 20


typedef struct Map Map_t;

struct Map {
	Field_t *fieldMap[MAP_WIDTH][MAP_HEIGHT];
};

void test(Field_t** map);
void test2(Field_t* map);

Map_t *init_map(Map_t *map);
int can_be_placed(Map_t *map, int x, int y);
int can_be_placed_around(Map_t *map, int x, int y);
int can_ship_be_placed(Map_t *map, Ship_t ship, int x, int y, int v);
void place_ship(Map_t *map, Ship_t ship, int x, int y, int v);
Field_t *get_field_at_position(Map_t *map, int x, int y);
void destroy_map(Map_t* map);

#pragma once
#include "Vector2.h"
#include "Ship.h"
typedef struct Field Field_t;

struct Field {
	Vector2_t *pos;
	Ship_t ship;
	char fieldChar;
};


void assign_ship_to_field(Field_t *field, Ship_t ship);
Field_t* create_field(char fieldChar, int x, int y);
void destoy_vector(Field_t* field);

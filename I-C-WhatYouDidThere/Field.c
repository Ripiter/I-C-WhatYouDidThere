#include "Field.h"

void assign_ship_to_field(Field_t *field, Ship_t ship)
{
	field->ship = ship;
	//field->ship.pos = field->pos;
	field->ship.init = 1;

	field->fieldChar = ship.shipChar;
}


Field_t* create_field(char _fieldChar, int x, int y)
{
	Field_t* f = malloc(sizeof(Field_t));
	if (f == NULL)
		return NULL;

	f->fieldChar = _fieldChar;

	Vector2_t* vec = malloc(sizeof(Vector2_t));
	if (vec == NULL)
		return NULL;

	
	vec->x = x;
	vec->y = y;

	f->pos = vec;

	return f;
}

void destoy_vector(Field_t* field)
{
	free(field->pos);
}

#include "Field.h"

void assign_ship_to_field(Field_t *field, Ship_t ship)
{
	ship.init = 1;
	field->ship = ship;
	
	field->fieldChar = ship.shipChar;
}


Field_t* create_field(char _fieldChar, int x, int y)
{
	Field_t* f = malloc(sizeof(Field_t));
	if (f == NULL)
		return NULL;

	f->fieldChar = _fieldChar;

	Vector2_t vec;
	
	vec.x = x;
	vec.y = y;

	f->pos = vec;

	return f;
}



void destoy_field(Field_t* field)
{
	free(field);
}

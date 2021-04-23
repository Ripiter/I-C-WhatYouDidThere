#include "Field.h"

void assign_ship_to_field(Field_t *field, Ship_t ship)
{
	field->ship = ship;
	field->ship.pos = field.pos;
	field->ship.init = 1;

	field->fieldChar = ship.shipChar;
}

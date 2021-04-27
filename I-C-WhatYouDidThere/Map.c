#include "Map.h"

Map_t* init_map(Map_t* map)
{
	for (int x = 0; x < MAP_WIDTH; x++)
	{
		for (int y = 0; y < MAP_HEIGHT; y++)
		{
			//map->fieldMap[x][y] = malloc(sizeof(Field_t));
			Field_t* f = create_field('x', x, y);

			map->fieldMap[x][y] = f;
		}
	}

	return map;
}

int can_be_placed(Map_t* map, int _x, int _y)
{
	Field_t* f = get_field_at_position(map, _x, _y);
	if (f == NULL)
		return 0;

	return can_be_placed_around(map, _x, _y);
}

int can_be_placed_around(Map_t* map, int _x, int _y)
{
	for (int x = _x - 1; x <= _x + 1; x++) {
		for (int y = _y - 1; y <= _y + 1; y++) {
			
			Field_t* f = get_field_at_position(map, x, y);
			if(f != 0)
				if (f->ship.init == 1)
					return 0;
			
		}
	}

	return 1;
}

int can_ship_be_placed(Map_t* map, Ship_t ship, int x, int y, int v)
{
	for (int i = 0; i < ship.shipLenght; i++)
	{
		if (v == 1)
		{
			if (!can_be_placed(map, x + i, y))
				return 0;
		}
		else
		{
			if (!can_be_placed(map, x, y + i))
				return 0;
		}
	}

	return 1;
}

void place_ship(Map_t* map, Ship_t ship, int x, int y, int v)
{
	for (int i = 0; i < ship.shipLenght; i++)
	{
		if (v == 1)
		{
			Field_t* f = get_field_at_position(map, x + i, y);
			assign_ship_to_field(f, ship);
		}
		else
		{
			Field_t* f = get_field_at_position(map, x , y + i);
			assign_ship_to_field(f, ship);
		}
	}
}

Field_t* get_field_at_position(Map_t* map, int x, int y)
{
	if (x < 0 || x > MAP_WIDTH - 1 || y < 0 || y > MAP_HEIGHT - 1)
		return 0;

	return map->fieldMap[x][y];
}

void destroy_map(Map_t* map)
{
	for (int x = 0; x < MAP_WIDTH; x++)
	{
		for (int y = 0; y < MAP_HEIGHT; y++)
		{
			Field_t* f = map->fieldMap[x][y];
			destoy_field(f);
		}
	}
}

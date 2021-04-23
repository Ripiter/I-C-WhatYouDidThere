#include <stdio.h>
#include <stdlib.h>
#include "Map.h"

void draw_map();
char* get_user_input();


Map_t map;

int main() {
	init_map(&map);

	draw_map();

	Ship_t ship;
	ship.shipChar = "y";
	ship.shipLenght = 3;

	// v = 1 ship is being placed vertical 
	// v = 0 ship is being placed horizontal
	int v = 1;

	int x, y;

	do {
		//printf("x: ");
		//x = get_user_input();
		//printf("y: ");
		//y = get_user_input();
		//printf("v(0/1):  ");
		//v = get_user_input();

		printf("x: ");
		x = 0;
		printf("y: ");
		y = 0;
		printf("v(0/1):  ");
		v = 1;

	} while (!can_ship_be_placed(map, ship, x, y, v));
	

	place_ship(&map, ship, x, y, v);
	printf("\n");
	draw_map();
	//int res = can_ship_be_placed(map, ship, 9, 5, v);

	//printf("result %i\n", res);

	return 0;
}

char* get_user_input() {

}

void draw_map() {
	for (int x = 0; x < MAP_WIDTH; x++)
	{
		for (int y = 0; y < MAP_HEIGHT; y++)
		{
			printf("%c", map.fieldMap[x][y].fieldChar);
		}
		printf("\n");
	}
}

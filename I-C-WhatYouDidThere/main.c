#include <stdio.h>
#include <stdlib.h>
#include "Map.h"

void draw_map();
char* get_user_input();



int main() {
	Map_t *map = malloc(sizeof(Map_t));
	map = init_map(map);

	draw_map(map);

	Ship_t ship;
	ship.shipChar = "y";
	ship.shipLenght = 4;


	// v = 1 ship is being placed vertical 
	// v = 0 ship is being placed horizontal
	int v = 1;

	int x = 0;
	int y = 0;

	char *userInput;
	userInput = malloc(10);

	do {
		printf("\nx: ");
		x = atoi(get_user_input(userInput));

		printf("y: ");
		y = atoi(get_user_input(userInput));
		printf("v(0/1): ");
		v = atoi(get_user_input(userInput));


	} while (!can_ship_be_placed(map, ship, x, y, v));
	

	place_ship(map, ship, x, y, v);
	printf("\n");
	draw_map(map);
	//int res = can_ship_be_placed(map, ship, 9, 5, v);

	//printf("result %i\n", res);
	destroy_map(map);

	free(userInput);
	return 0;
}

char* get_user_input(char *input) {
	fgets(input, sizeof(input), stdin);
	input[strcspn(input, "\n")] = 0;

	return input;
}

void draw_map(Map_t *map) {
	for (int x = 0; x < MAP_WIDTH; x++)
	{
		for (int y = 0; y < MAP_HEIGHT; y++)
		{
			printf("%c", map->fieldMap[x][y]->fieldChar);
		}
		printf("\n");
	}
}

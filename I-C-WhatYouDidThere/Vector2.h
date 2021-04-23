#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Vector2 Vector2_t;

struct Vector2 {
	int x;
	int y;
};


char* get_position_string(Vector2_t _vec);


#pragma once
#include "Vector2.h"


typedef struct Ship Ship_t;

struct Ship {
	Vector2_t pos;
	char shipChar;
	short shipLenght;
	int init;
};

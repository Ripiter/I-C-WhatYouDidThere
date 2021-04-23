#include "Vector2.h"


char* get_position_string(Vector2_t _vec)
{
	char result[800] = { 0 };
	snprintf(result, sizeof(result), "%i|%i", _vec.x, _vec.y);

	return result;
}

#include "fdf.h"

int generate_nbr(int min, int max)
{
	int result;

	result = rand() % max + min;

	return (result);
}

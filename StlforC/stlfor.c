#include "stlforc.h"
#include <stdio.h>

int main()
{
	map_t map1 = map_create();
	if (map_delete(&map1))
	{
		printf("Successfully deleted\n");

	}
	else
	{
		printf("Failed to delete\n");
	}

	map1 = map_create();

	map1.key = "John";
	map1.value = 20;
	map_set_value(&map1);

	map1.key = "Mahesh";
	map1.value = 25;
	map_set_value(&map1);

	map1.key = "Ravi";
	map1.value = 30;
	map_set_value(&map1);

	map1.key = "Mahesh";
	if (map_get_value(&map1))
	{
		printf("Mahesh's Age: %d\n", map1.value);
	}

	map1.key = "Ravi";
	if (map_get_value(&map1))
	{
		printf("Ravi's Age: %d\n", map1.value);
	}
	map_delete(&map1);
}

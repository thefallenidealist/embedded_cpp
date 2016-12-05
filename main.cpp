#include <iostream>
#include <stdio.h>
using namespace std;

#include "./src/gpio.cpp"
//using namespace sim;
#define DEBUG
#include "./src/debug.h"
#include "./src/debug.c"

int main()
{
	//DEBUG_START("sdfsdf\n");
	DEBUG_START;
	DEBUG_START2("ss");

	int varTest = 88;
	//gpio_bus_t gpioA('a');
	gpio_bus_t gpioA('A');
	//gpio_t LED("PA0");
	gpio_t LED("PA0", gpio_direction_t::OUT); // enum class gpio_direction_t

	std::string tekst;
	printf("GPIO bus filename: %s\n", gpioA.get_filename());

	if (varTest > 0)
	{
		// something
	}

	DEBUG_END
	return 0;
}

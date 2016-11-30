#include <iostream>
#include <stdio.h>
using namespace std;

#include "./src/gpio.cpp"
//using namespace sim;
#define DEBUG
#include "./src/debug.h"

int main()
{
	DEBUG_START
	//gpio_bus_t gpioA('a');
	gpio_bus_t gpioA('A');
	//gpio_t LED("PA0");
	gpio_t LED("PA0", gpio_direction_t::OUT); // enum class gpio_direction_t

	LED.test();


	DEBUG_END
	return 0;
}

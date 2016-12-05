#define USE_SIMULATOR	// TODO this should be in Makefile
#include <iostream>
#include <fstream>
#include <ctype.h> // toupper()
//#include <string.h> // strlen()
using namespace std;
#include "debug.h"
#include "debug.c"


// INFO std::string and char* are mixed. strings will be used only on PC/simulator
// TODO sprintf() -> snprintf()
// TODO gpio_bus_t should be implicitly called from gpio_t (and only if that bus is uninitialised)

class gpio_bus_t														// {{{
{
	public:
		gpio_bus_t(char port); // A, B, C or D
		~gpio_bus_t(void);
		bool init(void);
	private:
		const char* filename_prefix = "gpio";
		const char* filename_extension = ".txt";
		//const char* filename_extension = ".txt";
		static const uint8_t filename_length_max = 20;
		ofstream gpio_file;
		char filename[filename_length_max] = {};
		static bool initialised;
	//protected:
	public:
		char* get_filename(void);
}; // gpio_bus_t														// }}}
gpio_bus_t::gpio_bus_t(char port)										// {{{
// INFO opens a file and write "undefined" states of pins on that port
{
	DEBUG_START
	char port_uppercase = toupper(port);

	snprintf(filename, filename_length_max-1, "%s%c%s", filename_prefix, port_uppercase, filename_extension);

	printf("filename: %s length: %lu\n", filename, sizeof(filename)/sizeof(filename[0]));

	char tmp_buffer[] = "PA15: YYY x"; // buffer for writing line to the file

	gpio_file.open(filename);

	// write "undefined" states of pins:
	for (uint8_t i=0; i<16; i++)
	{
		//gpio_file << "P" << port_uppercase << "::" << (char)i << ": x\n";
		sprintf(tmp_buffer, "P%c%02d: YYY x", port_uppercase, i);
		gpio_file << tmp_buffer << endl;
	}

	DEBUG_END
} // constructor }}}
gpio_bus_t::~gpio_bus_t(void)											// {{{
{
	DEBUG_START;
	printy("destructor\n");

	printf("Closing file: %s\n", filename);
	gpio_file.close();
	DEBUG_END;
}	// desctructor															}}}
char *gpio_bus_t::get_filename(void)											// {{{
{
	DEBUG_START;
	return gpio_bus_t::filename;
	DEBUG_END;
}	// desctructor															}}}


enum class gpio_direction_t												// {{{
{
	in,
	IN,
	out,
	OUT
	// TODO PWM, ADC
};																		// }}}
class gpio_t															// {{{
{
	public:
		gpio_t(void);
		gpio_t(const char *pin);
		gpio_t(const char *pin, gpio_direction_t direction);
		~gpio_t(void);
		void init (const char *pin, gpio_direction_t direction);
		void write(bool state);
		bool read (void);
		void test(void);
	private:
		static constexpr const char *pin_template = "PX99"; // C++11
		static const uint8_t pin_size = strlen(pin_template);
		char port; // A, B, C or D
		//char pin[]
};																		// }}}




enum class gpio_port_t												// {{{
{
	A,
	B,
	C,
	D,
	ERROR
};																		// }}}
gpio_t::gpio_t(void) // {{{
{
	 cout << __PRETTY_FUNCTION__ << " constructor start" << endl;
}
//***************************************************************************}}}
gpio_t::gpio_t(const char* pin) //											{{{
{
	 cout << __PRETTY_FUNCTION__ << " constructor start, pin: " << pin << endl;
}
//***************************************************************************}}}
gpio_t::gpio_t(const char* pin, gpio_direction_t direction) // 				{{{
{
	 cout << __PRETTY_FUNCTION__ << " constructor start, pin: " << pin << endl;
	 // call real init:
	 gpio_t::init(pin, direction);
}
//**************************************************************************}}}
gpio_t::~gpio_t(void) // {{{
{
	cout << __PRETTY_FUNCTION__ << " destructor start" << endl;
	// TODO write x for that pin
}
//***************************************************************************}}}

void gpio_t::test(void)
{
	printf("\t\t\tsdfsdfsdfsdfsdfdsf\n");
	//printf("pin_template: %s\n", gpio_t::pin_template);
	printf("pin_template: %s\n", pin_template);
	printf("Pin size: %d\n", pin_size);

}

void gpio_t::init(const char *pin, gpio_direction_t direction) //			{{{
{
	// INFO Use to chnge port direction on the fly or when not using constructor no 3
	// this function writes gpio_direction_t to file (PA00: $direction x)

	// old: printf("%s::%s(port: %s, type: %d)\n", gpio_t::class_name(),  __func__, port.c_str(), type);
	// dobije npr PA0 i onda to postavi u IN ili OUT
	cout << __PRETTY_FUNCTION__ << " start, args: pin: " << *pin << " direction: " << static_cast<int>(direction) << endl;

	// TODO
}
//**************************************************************************}}}
void gpio_t::write(bool state)
{
	DEBUG_START;
	// write state to file (PA00: IN $state)
	//printy("Opening file: %s\n", this->filename);

}


/* vim: set ft=cpp ts=4 sw=4 tw=78 foldmethod=marker noet :*/

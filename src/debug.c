// created before 160816
#ifndef PRINT_COLOR
#define PRINT_COLOR
#include <stdio.h>
#include <stdint.h>
#include <stdarg.h>
#include <string.h>
#include <execinfo.h> // runtime backtrace
#include "debug.h"

void print_color(const char* color, const char *file, const int line, const char *func, const char *format, ...)
{
	va_list va;
	va_start(va, format);

	if (file != NULL)
	{
		printf("%s:%d ", file, line);
		printf("%s", color);
		printf("%s() ", func);
	}
	else
	{
		printf("%d ", line);
		printf("%s", color);
		printf("%s() ", func);
	}

	vprintf(format, va);
	printf(COLOR_RESET);

	va_end(va);
}

// only for start, stop and error
void print_debug(const char *color1, const char* color2, const char *file, const int line, const char *func, const char *start_stop)
{
	printf("%s", color2);
	printf("%s() ", func);
	printf("%s", start_stop);

	printf("%s", color1);
	printf("\t%s:%d ", file, line);
	printf(COLOR_RESET);

	printf(" %s", color2);
	printf(COLOR_RESET);
	printf("\n");
}

/*
void runtime_backtrace(void)
{
    void    *array[128];
    size_t   size, i;
    char   **strings;

    size = backtrace(array, 128);
    strings = backtrace_symbols(array, size);

    for (i = 0; i < size; i++)
    {
        printf("runtime bt: %p : %s\n", array[i], strings[i]);

    }

    free(strings);  // malloced by backtrace_symbols
}
*/
#endif // PRINT_COLOR

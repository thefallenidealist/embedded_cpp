#ifndef PRINT_H
#define PRINT_H
#ifdef __cplusplus	// {{{
extern "C" {
#endif				// }}}
#include <stdio.h>
#include <stdint.h>
#include <stdarg.h>
#include <string.h>

#define COLOR_FG_RED     "\x1b[31m"
#define COLOR_FG_GREEN   "\x1b[32m"
#define COLOR_FG_YELLOW  "\x1b[33m"
#define COLOR_FG_BLUE    "\x1b[34m"
#define COLOR_FG_MAGENTA "\x1b[35m"
#define COLOR_FG_CYAN    "\x1b[36m"
#define COLOR_FG_WHITE   "\x1b[97m"
#define COLOR_FG_ORANGE  "\x1b[166m"

#define COLOR_BG_RED     "\x1b[41m"
#define COLOR_BG_GREEN   "\x1b[42m"
#define COLOR_BG_YELLOW  "\x1b[43m"
#define COLOR_BG_BLUE    "\x1b[44m"
#define COLOR_BG_MAGENTA "\x1b[45m"
#define COLOR_BG_CYAN    "\x1b[46m"
#define COLOR_BG_WHITE   "\x1b[107m"

#define COLOR_BG_RESET   "\x1b[0m"
#define COLOR_FG_RESET   "\x1b[0m"
#define COLOR_RESET      "\x1b[0m"

#define print_color_base(color, fmt, ...) 		print_color(color,  NULL,    __LINE__, __func__,  fmt, ##__VA_ARGS__)
#define print_color_base_file(color, fmt, ...)  print_color(color, __FILE__, __LINE__, __func__,  fmt, ##__VA_ARGS__)

#define print1(fmt, ...)  print_color_base     ("\e[38;5;105m", 		fmt, ##__VA_ARGS__)

//#define DEBUG_START(fmt, ...)	print_color_base_file	(COLOR_FG_BLUE,	fmt, ##__VA_ARGS__, "START")


#define printb(fmt, ...)  print_color_base     (COLOR_FG_BLUE, 		fmt, ##__VA_ARGS__)
#define printbf(fmt, ...) print_color_base_file(COLOR_FG_BLUE, 		fmt, ##__VA_ARGS__)
#define printg(fmt, ...)  print_color_base     (COLOR_FG_GREEN, 	fmt, ##__VA_ARGS__)
#define printgf(fmt, ...) print_color_base_file(COLOR_FG_GREEN, 	fmt, ##__VA_ARGS__)
#define printc(fmt, ...)  print_color_base     (COLOR_FG_CYAN, 		fmt, ##__VA_ARGS__)
#define printcf(fmt, ...) print_color_base_file(COLOR_FG_CYAN, 		fmt, ##__VA_ARGS__)
#define printm(fmt, ...)  print_color_base     (COLOR_FG_MAGENTA, 	fmt, ##__VA_ARGS__)
#define printmf(fmt, ...) print_color_base_file(COLOR_FG_MAGENTA, 	fmt, ##__VA_ARGS__)
#define printr(fmt, ...)  print_color_base 	   (COLOR_FG_RED, 		fmt, ##__VA_ARGS__)
#define printrf(fmt, ...) print_color_base_file(COLOR_FG_RED, 		fmt, ##__VA_ARGS__)
#define printy(fmt, ...)  print_color_base     (COLOR_FG_YELLOW, 	fmt, ##__VA_ARGS__)
#define printyf(fmt, ...) print_color_base_file(COLOR_FG_YELLOW, 	fmt, ##__VA_ARGS__)
#define printw(fmt, ...)  print_color_base     (COLOR_FG_WHITE, 	fmt, ##__VA_ARGS__)
#define printwf(fmt, ...) print_color_base_file(COLOR_FG_WHITE, 	fmt, ##__VA_ARGS__)
#define printo(fmt, ...)  print_color_base     (COLOR_FG_ORANGE, 	fmt, ##__VA_ARGS__)
#define printof(fmt, ...) print_color_base_file(COLOR_FG_ORANGE, 	fmt, ##__VA_ARGS__)

#define printbbg(fmt, ...)  print_color_base     (COLOR_BG_BLUE, 	fmt, ##__VA_ARGS__)
#define printbfbg(fmt, ...) print_color_base_file(COLOR_BG_BLUE, 	fmt, ##__VA_ARGS__)
#define printgbg(fmt, ...)  print_color_base     (COLOR_BG_GREEN, 	fmt, ##__VA_ARGS__)
#define printgfbg(fmt, ...) print_color_base_file(COLOR_BG_GREEN, 	fmt, ##__VA_ARGS__)
#define printcbg(fmt, ...)  print_color_base     (COLOR_BG_CYAN, 	fmt, ##__VA_ARGS__)
#define printcfbg(fmt, ...) print_color_base_file(COLOR_BG_CYAN, 	fmt, ##__VA_ARGS__)
#define printmbg(fmt, ...)  print_color_base     (COLOR_BG_MAGENTA, fmt, ##__VA_ARGS__)
#define printmfbg(fmt, ...) print_color_base_file(COLOR_BG_MAGENTA, fmt, ##__VA_ARGS__)
#define printrbg(fmt, ...)  print_color_base 	 (COLOR_BG_RED, 	fmt, ##__VA_ARGS__)
#define printrfbg(fmt, ...) print_color_base_file(COLOR_BG_RED, 	fmt, ##__VA_ARGS__)
#define printybg(fmt, ...)  print_color_base     (COLOR_BG_YELLOW, 	fmt, ##__VA_ARGS__)
#define printyfbg(fmt, ...) print_color_base_file(COLOR_BG_YELLOW, 	fmt, ##__VA_ARGS__)
#define printwbg(fmt, ...)  print_color_base     (COLOR_BG_WHITE, 	fmt, ##__VA_ARGS__)
#define printwfbg(fmt, ...) print_color_base_file(COLOR_BG_WHITE, 	fmt, ##__VA_ARGS__)

//#define DEBUG_START(fmt, ...)	printb("START", fmt, ...)
//#define DEBUG_START(fmt, ...)	printb(fmt, ...)
//#define DEBUG_START(fmt,...)		print_color_base_file (COLOR_FG_BLUE, "START ", fmt, ##__VA_ARGS__) // ispise START, ne ispise argument
//#define DEBUG_START(fmt,...)		print_color_base_file (COLOR_FG_BLUE, fmt, "START ", ##__VA_ARGS__) // ispise argument, al ne i START
// TODO TODO
//#define DEBUG_START2(fmt,...) print_color_base_file (COLOR_FG_BLUE, strcat(strcat("START ", druga_boja), fmt), ##__VA_ARGS__)

#define DEBUG_START2(fmt,...) print_color_base_file (COLOR_FG_BLUE, strcat(strcat((const char*)"START ", COLOR_FG_RED), fmt), ##__VA_ARGS__)

void print_color(const char* color, const char *file, const int line, const char *func, const char *format, ...);

// simple, without arguments, just colors:
void print_debug(const char *color1, const char* color2, const char *file, const int line, const char *func);
#define DEBUG_START					print_debug(COLOR_FG_BLUE, COLOR_FG_CYAN, __FILE__, __LINE__, __func__, "START");
#define DEBUG_END					print_debug(COLOR_FG_BLUE, COLOR_FG_CYAN, __FILE__, __LINE__, __func__, "STOP ");
#ifdef __cplusplus		// {{{
}
#endif	// __cplusplus		}}}
#endif	// PRINT_H
/* vim: set ft=cpp ts=4 sw=4 tw=0 foldmethod=marker noet :*/

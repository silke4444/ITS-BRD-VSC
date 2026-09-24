#ifndef ERROR_H
#define ERROR_H
#include "display.h"

#define OK 0
#define UNKNOWNTOKEN 1
#define VALUETOOLONG 2
#define STACKFULL 3
#define STACKEMPTY 4
#define WRONGSTACKPOSITION 5
#define CALCOVERFLOW 6
#define CALCUNDERFLOW 7
#define DIVNULL 8

int print_error(int value);

#endif
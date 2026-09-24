#ifndef STACK_H
#define STACK_H

#include "myerror.h"

#define SIZE 5

int push(int value);
int pop(int *value);
int get_anz_stack_values();
int peek(int *value, int position);

#endif
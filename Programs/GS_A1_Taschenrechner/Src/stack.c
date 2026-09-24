#include "stack.h"

int my_stack[SIZE];
int stack_pointer = 0;

int push(int value) {
   int err = OK;
   if (stack_pointer < SIZE) {
      my_stack[stack_pointer] = value;
      stack_pointer++;
      err = OK;
   } else {
      err = STACKFULL;
   }
   return err;
}

int pop(int *value) {
   int err = OK;
   if (stack_pointer == 0) {
      err =  STACKEMPTY;
   } else {
      stack_pointer--;
      *value = my_stack[stack_pointer];
      err = OK;
   }
   return err;
}

int get_anz_stack_values() { return stack_pointer; }

int peek(int *value, int position) {
   int err = OK;
   if (position < 0 || position > stack_pointer) {
      err = WRONGSTACKPOSITION;
   } else {
      *value = my_stack[position];
      err = OK;
   }
   return err;
}

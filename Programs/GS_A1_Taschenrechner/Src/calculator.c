#include "calculator.h"

int add(int var1, int var2) {
   int err = 0;

   if (var1 > 0 && var2 > 0) {
      if (INT_MAX - var1 < var2) {
         return CALCOVERFLOW;
      };
   }

   if (var1 < 0 && var2 < 0) {
      if (INT_MIN - var1 > var2) {
         return CALCUNDERFLOW;
      }
   }

   err = push(var1 + var2);
   return err;
}

int sub(int var1, int var2) {
   int err = 0;

   if (var1 > 0 && var2 < 0) {
      if (INT_MAX - var1 < (var2 * (-1))) {
         return CALCOVERFLOW;
      };
   }

   if (var1 < 0 && var2 > 0) {
      if (INT_MIN - var1 > (var2 * (-1))) {
         return CALCUNDERFLOW;
      }
   }

   err = push(var1 - var2);
   return err;
}

int mul(int var1, int var2) {
   int err = 0;

   if (var1 > 0 && var2 > 0) {
      if (INT_MAX / var1 < var2) {
         return CALCOVERFLOW;
      }
   }
   if (var1 < 0 && var2 < 0) {
      if (INT_MAX / var1 > var2) {
         return CALCUNDERFLOW;
      }
   }

   if (var1 < 0 && var2 > 0) {
      if (INT_MIN / var1 > var2) {
         return CALCUNDERFLOW;
      }
   }

   if (var1 > 0 && var2 < 0) {
      if (INT_MIN / var1 < var2) {
         return CALCUNDERFLOW;
      }
   }

   err = push(var1 * var2);
   return err;
}

int div(int var1, int var2) {
   int err = 0;
   if (var2 == 0) {
      return DIVNULL;
   }
   err = push(var1 / var2);
   return err;
}

int calculate(T_token token) {
   int val1 = 0;
   int val2 = 0;
   int err = OK;

   switch (token.tok) {
   case '+':
   case '-':
   case '*':
   case '/':
   case 'r':
      // zwei Werte m�ssen geholt werden
      err = pop(&val2);
      if (err != OK){
         return err;
	  }	 
      err = pop(&val1);
      if (err != OK) {
         return err;
	  }	 
      break;
   default:
      break;
   }

   switch (token.tok) {
   case '+':
      err = add(val1, val2);
      break;
   case '-':
      err = sub(val1, val2);
      break;
   case '*':
      err = mul(val1, val2);
      break;
   case '/':
      err = div(val1, val2);
      break;
   case 'r':
      push(val2);
      err = push(val1);
      break;
   default:
      break;
   }
   return err;
}
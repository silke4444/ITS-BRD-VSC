#include "controler.h"

int anzahl_stellen(int value) {
   int anz = 1;
   while (value >= MAXANZNUMBER) {
      anz++;
      value /= MAXANZNUMBER;
   }
   return anz;
}

int print_value(int value) {
   char text[MAXAUSGABE];
   int index = 0;
   if (value < 0) {
      if (value == INTMIN) {
         strcpy(text, "-2147483648");
         print_stdout(text);
         print_stdout(" ; ");

		 // eslint-disable-next-line
         return OK;
      } else {
         text[index] = '-';
         value = value * -1;
         index++;
      }
   }
   int anz = anzahl_stellen(value);
   text[anz + index] = '\0';
   int last = 0;
   while (anz > 0) {
      last = value % TEN;
      text[index + anz - 1] = last + '0';
      value = value / TEN;
      anz--;
   }

   print_stdout(text);
   print_stdout(" ; ");
   return OK;
}

int print_full_stack() {
   int err = OK;
   int value = 0;
   int anzahl = get_anz_stack_values();
   clear_stdout();
   for (int i = 0; i < anzahl; i++) {
      peek(&value, i);
      err = print_value(value);
   }
   return err;
}

int print_top_stack() {
   int err = OK;
   int value = 0;
   err = peek(&value, 0);

   if (err == OK) {
      err = print_value(value);
   }
   return err;
}

int control() {
   int err = 0;
   T_token token = next_token();

   // Wenn Zeichen nicht bekannt
   if (token.tok == UNEXPECTED) {
      return UNKNOWNTOKEN;
   }

   // Wenn zu lange Zahlen eingelesen
   if (token.tok == OVERFLOW) {
      return VALUETOOLONG;
   }

   if (token.tok == 'n') {
      // in Stack schreiben
      err = push(token.val);
   } else if (token.tok == 'P') {
      print_full_stack();
   } else if (token.tok == 'p') {
      print_top_stack();
   } else {
      err = calculate(token);
   }

   return err;
}
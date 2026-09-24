#include "myerror.h"

int print_error(int value) {

   switch (value) {
   case OK:
      break;
   case STACKFULL:
      clear_echo_term();
      print_stdout("Der Stack ist voll!");
      break;
   case STACKEMPTY:
      clear_echo_term();
      print_stdout("Der Stack ist leer!");
      break;
   case UNKNOWNTOKEN:
      clear_echo_term();
      print_stdout("Das eingegebene Zeichen ist unbekannt!");
      break;
   case VALUETOOLONG:
      clear_echo_term();
      print_stdout("Es wurde eine zu lange Zahl eingegeben!");
      break;
   case WRONGSTACKPOSITION:
      clear_echo_term();
      print_stdout(
          "peek Fehler: Es gibt keinen Wert an der gewaehlten Position !");
      break;
   case CALCOVERFLOW:
      clear_echo_term();
      print_stdout("Die Zahlen sind zu gross");
      break;
   case CALCUNDERFLOW:
      clear_echo_term();
      print_stdout("Die Zahlen sind zu klein");
      break;
   case DIVNULL:
      clear_echo_term();
      print_stdout("Division durch 0 nicht erlaubt");
      break;
   default:
      clear_echo_term();
   }

   return OK;
}
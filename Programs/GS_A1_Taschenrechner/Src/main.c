/**
 ******************************************************************************
 * @file    main.c
 * @author  Franz Korf
 * @brief   Kleines Testprogramm fuer neu erstelle Fonts.
 ******************************************************************************
 */
/* Includes ------------------------------------------------------------------*/

#include "LCD_GUI.h"
#include "LCD_Touch.h"
#include "controler.h"
#include "display.h"
#include "init.h"
#include "lcd.h"
#include "stm32f4xx_hal.h"

int main(void) {
   int err = 0;

   initITSboard(); // Initialisierung des ITS Boards

   GUI_init(DEFAULT_BRIGHTNESS); // Initialisierung des LCD Boards mit Touch
   TP_Init(false);               // Initialisierung des LCD Boards mit Touch
   /*
   if (!checkVersionFlashFonts()) {
       // Ueberpruefe Version der Fonts im Flash passt nicht zur Software
   Version Error_Handler();
   }
      */

   init_display();

   while (1) {
      err = control();
      print_error(err);
   }
}

// EOF

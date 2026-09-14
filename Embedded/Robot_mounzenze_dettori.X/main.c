/* 
 * File:   main.c
 * Author: E306-PC2
 *
 * Created on September 8, 2026, 1:45 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include "ChipConfig.h"
#include "IO.h"
#include "timer.h"
#include "PWM.h"
#include "ADC.h"



int main (void){
/***********************************************************************************************///Initialisation oscillateur
InitOscillator();
/***********************************************************************************************/// Configuration des input et output (IO)
InitIO();

InitTimer23();
InitTimer1();
InitPWM();
InitADC1();


LED_BLANCHE_1 = 1;
LED_BLEUE_1 = 1;
LED_ORANGE_1 = 1;
LED_ROUGE_1 = 1;
LED_VERTE_1 = 1;
/***********************************************************************************************/
// Boucle Principale
/***********************************************************************************************/

while(1)
    {
    /*LED_BLANCHE_1 = !LED_BLANCHE_1;
    LED_BLEUE_1 = !LED_BLEUE_1;
    LED_ORANGE_1 = ! LED_ORANGE_1 ;
    LED_ROUGE_1 = ! LED_ROUGE_1 ; 
    LED_VERTE_1 = ! LED_VERTE_1;*/
    if(ADCIsConversionFinished()==1){
        unsigned int * result = ADCGetResult();
        unsigned int ADCValue0=result[0], ADCValue1=result[1], ADCValue2=result[2];
        ADCClearConversionFinishedFlag();
    }
    
    } // fin main
}
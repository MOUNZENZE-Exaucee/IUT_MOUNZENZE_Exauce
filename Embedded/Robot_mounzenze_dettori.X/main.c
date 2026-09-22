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
#include "Robot.h"
#include "main.h"


int main(void) {
    /***********************************************************************************************///Initialisation oscillateur
    InitOscillator();
    /***********************************************************************************************/// Configuration des input et output (IO)
    InitIO();
    
    InitTimer23();
    InitTimer1();
    InitTimer4();
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

    while (1) {
        /*LED_BLANCHE_1 = !LED_BLANCHE_1;
        LED_BLEUE_1 = !LED_BLEUE_1;
        LED_ORANGE_1 = ! LED_ORANGE_1 ;
        LED_ROUGE_1 = ! LED_ROUGE_1 ; 
        LED_VERTE_1 = ! LED_VERTE_1;*/
        ADC1StartConversionSequence();
        if (ADCIsConversionFinished() == 1) {
            unsigned int * result = ADCGetResult();
            ADCClearConversionFinishedFlag();
            float volts = ((float) result [0])* 3.3 / 4096;
            robotState.distanceTelemetreGauche = 34 / volts - 5;
            volts = ((float) result [1])* 3.3 / 4096;
            robotState.distanceTelemetreCentre = 34 / volts - 5;
            volts = ((float) result [2])* 3.3 / 4096;
            robotState.distanceTelemetreDroit = 34 / volts - 5;
            /*unsigned int ADCValue0 = result[0], ADCValue1 = result[1], ADCValue2 = result[2];
            float tensionADC0 = (3.3 * ADCValue0) / 4095;
            float tensionADC1 = (3.3 * ADCValue1) / 4095;
            float tensionADC2 = (3.3 * ADCValue2) / 4095;*/
            
            if (robotState.distanceTelemetreGauche >=30) {
                LED_BLANCHE_1 = 1;
            } else {
                LED_BLANCHE_1 = 0;
            }
            if (robotState.distanceTelemetreCentre >=30) {
                LED_BLEUE_1 = 1;
            } else {
                LED_BLEUE_1 = 0;
            }
            if (robotState.distanceTelemetreDroit >=30) {
                LED_ORANGE_1 = 1;
            } else {
                LED_ORANGE_1 = 0;
            }
            
            ADCClearConversionFinishedFlag();
            
        }


    } // fin main
}
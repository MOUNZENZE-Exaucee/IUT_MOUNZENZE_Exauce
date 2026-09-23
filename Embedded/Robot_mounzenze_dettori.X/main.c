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
unsigned char stateRobot;
unsigned char nextStateRobot = 0;
unsigned int captir =0b00000;


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
            robotState.distanceTelemetreExGauche = 34 / volts - 5;
            volts = ((float) result [1])* 3.3 / 4096;
            robotState.distanceTelemetreGauche = 34 / volts - 5;
            volts = ((float) result [2])* 3.3 / 4096;
            robotState.distanceTelemetreCentre = 34 / volts - 5;
            volts = ((float) result [3])* 3.3 / 4096;
            robotState.distanceTelemetreDroit = 34 / volts - 5;
            volts = ((float) result [4])* 3.3 / 4096;
            robotState.distanceTelemetreExDroit = 34 / volts - 5;
            /*unsigned int ADCValue0 = result[0], ADCValue1 = result[1], ADCValue2 = result[2];
            float tensionADC0 = (3.3 * ADCValue0) / 4095;
            float tensionADC1 = (3.3 * ADCValue1) / 4095;
            float tensionADC2 = (3.3 * ADCValue2) / 4095;*/
            captir=0b00000;
            if (robotState.distanceTelemetreExGauche >= 30) {
                LED_BLANCHE_1 = 0;
            } else {
                LED_BLANCHE_1 = 1;
                captir=captir+0b10000;
            }
            if (robotState.distanceTelemetreGauche >= 30) {
                LED_BLEUE_1 = 0;
            } else {
                LED_BLEUE_1 = 1;
                captir=captir+0b01000;
            }
            if (robotState.distanceTelemetreCentre >= 20) {
                LED_ORANGE_1 = 0;
            } else {
                LED_ORANGE_1 = 1;
                captir=captir+0b00100;
            }
            if (robotState.distanceTelemetreDroit >= 30) {
                LED_ROUGE_1 = 0;
            } else {
                LED_ROUGE_1 = 1;
                captir=captir+0b00010;
            }
            if (robotState.distanceTelemetreExDroit >= 30) {
                LED_VERTE_1 = 0;
            } else {
                LED_VERTE_1 = 1;
                captir=captir+0b00001;
            }

            ADCClearConversionFinishedFlag();

        }


    } // fin main

}

void OperatingSystemLoop(void) {
    /*switch (stateRobot) {
        case STATE_ATTENTE:
            timestamp = 0;
            PWMSetSpeedConsigne(0, MOTEUR_DROIT);
            PWMSetSpeedConsigne(0, MOTEUR_GAUCHE);
            stateRobot = STATE_ATTENTE_EN_COURS;
        case STATE_ATTENTE_EN_COURS:
            if (timestamp > 1000)
                stateRobot = STATE_AVANCE;
            break;
        case STATE_AVANCE:
            PWMSetSpeedConsigne(-30, MOTEUR_DROIT);
            PWMSetSpeedConsigne(30, MOTEUR_GAUCHE);
            stateRobot = STATE_AVANCE_EN_COURS;
            break;
        case STATE_AVANCE_EN_COURS:
            SetNextRobotStateInAutomaticMode();
            break;
        case STATE_TOURNE_GAUCHE:
            PWMSetSpeedConsigne(-20, MOTEUR_DROIT);
            PWMSetSpeedConsigne(0, MOTEUR_GAUCHE);
            stateRobot = STATE_TOURNE_GAUCHE_EN_COURS;
            break;
        case STATE_TOURNE_GAUCHE_EN_COURS:
            SetNextRobotStateInAutomaticMode();
            break;
        case STATE_TOURNE_DROITE:
            PWMSetSpeedConsigne(0, MOTEUR_DROIT);
            PWMSetSpeedConsigne(20, MOTEUR_GAUCHE);
            stateRobot = STATE_TOURNE_DROITE_EN_COURS;
            break;
        case STATE_TOURNE_DROITE_EN_COURS:
            SetNextRobotStateInAutomaticMode();
            break;
        case STATE_TOURNE_SUR_PLACE_GAUCHE:
            PWMSetSpeedConsigne(15, MOTEUR_DROIT);
            PWMSetSpeedConsigne(15, MOTEUR_GAUCHE);
            stateRobot = STATE_TOURNE_SUR_PLACE_GAUCHE_EN_COURS;
            break;
        case STATE_TOURNE_SUR_PLACE_GAUCHE_EN_COURS:
            SetNextRobotStateInAutomaticMode();
            break;
        case STATE_TOURNE_SUR_PLACE_DROITE:
            PWMSetSpeedConsigne(-15, MOTEUR_DROIT);
            PWMSetSpeedConsigne(-15, MOTEUR_GAUCHE);
            stateRobot = STATE_TOURNE_SUR_PLACE_DROITE_EN_COURS;
            break;
        case STATE_TOURNE_SUR_PLACE_DROITE_EN_COURS:
            SetNextRobotStateInAutomaticMode();
            break;
        default:
            stateRobot = STATE_ATTENTE;
            break;
    }*/
    switch(captir)
    {
        case 0b00000:
            PWMSetSpeedConsigne(-30, MOTEUR_DROIT);
            PWMSetSpeedConsigne(30, MOTEUR_GAUCHE);
            break;
        case 0b10010:
        case 0b01001:
        case 0b01011:
        case 0b10011:
        case 0b11010:
        case 0b11001:
        case 0b11011:
        case 0b11111:
            PWMSetSpeedConsigne(-15, MOTEUR_DROIT);
            PWMSetSpeedConsigne(-15, MOTEUR_GAUCHE);
            break;
        case 0b00100:
            PWMSetSpeedConsigne(0, MOTEUR_DROIT);
            PWMSetSpeedConsigne(20, MOTEUR_GAUCHE);
            break;
        case 0b01110:
            PWMSetSpeedConsigne(0, MOTEUR_DROIT);
            PWMSetSpeedConsigne(20, MOTEUR_GAUCHE);
            break;
        case 0b10001:
            if(robotState.distanceTelemetreExGauche<robotState.distanceTelemetreExDroit){
                PWMSetSpeedConsigne(-15, MOTEUR_DROIT);
                PWMSetSpeedConsigne(30, MOTEUR_GAUCHE);
            break;
            }if(robotState.distanceTelemetreExGauche>robotState.distanceTelemetreExDroit){
                PWMSetSpeedConsigne(-30, MOTEUR_DROIT);
                PWMSetSpeedConsigne(15, MOTEUR_GAUCHE);
            break;
            }
            PWMSetSpeedConsigne(-30, MOTEUR_DROIT);
            PWMSetSpeedConsigne(30, MOTEUR_GAUCHE);
            break;
        case 0b01010: 
            PWMSetSpeedConsigne(0, MOTEUR_DROIT);
            PWMSetSpeedConsigne(20, MOTEUR_GAUCHE);
            break;
        case 0b11000:
            PWMSetSpeedConsigne(0, MOTEUR_DROIT);
            PWMSetSpeedConsigne(20, MOTEUR_GAUCHE);
            break;
        case 0b00011:
            PWMSetSpeedConsigne(-20, MOTEUR_DROIT);
            PWMSetSpeedConsigne(0, MOTEUR_GAUCHE);
            break;
        case 0b10000:
            PWMSetSpeedConsigne(-15, MOTEUR_DROIT);
            PWMSetSpeedConsigne(30, MOTEUR_GAUCHE);
            break;
        case 0b00001:
            PWMSetSpeedConsigne(-30, MOTEUR_DROIT);
            PWMSetSpeedConsigne(15, MOTEUR_GAUCHE);
            break;
        case 0b11100:
           PWMSetSpeedConsigne(15, MOTEUR_DROIT);
           PWMSetSpeedConsigne(15, MOTEUR_GAUCHE);
           break;
        case 0b11110:
           PWMSetSpeedConsigne(15, MOTEUR_DROIT);
           PWMSetSpeedConsigne(15, MOTEUR_GAUCHE);
           break;
        case 0b00111:
           PWMSetSpeedConsigne(-15, MOTEUR_DROIT);
           PWMSetSpeedConsigne(-15, MOTEUR_GAUCHE);
           break;
        case 0b01111:
           PWMSetSpeedConsigne(-15, MOTEUR_DROIT);
           PWMSetSpeedConsigne(-15, MOTEUR_GAUCHE);
           break;
        case 0b01000:
            PWMSetSpeedConsigne(0, MOTEUR_DROIT);
            PWMSetSpeedConsigne(20, MOTEUR_GAUCHE);
            break;
        case 0b00010:
            PWMSetSpeedConsigne(-20, MOTEUR_DROIT);
            PWMSetSpeedConsigne(0, MOTEUR_GAUCHE);
            break;
        case 0b10100:
            PWMSetSpeedConsigne(0, MOTEUR_DROIT);
            PWMSetSpeedConsigne(20, MOTEUR_GAUCHE);
            break;  
        case 0b00101:
            PWMSetSpeedConsigne(-20, MOTEUR_DROIT);
            PWMSetSpeedConsigne(0, MOTEUR_GAUCHE);
            break;
        
    }
}

void SetNextRobotStateInAutomaticMode() {
    unsigned char positionObstacle = PAS_D_OBSTACLE;
    //éDtermination de la position des obstacles en fonction des ééètlmtres
    if (robotState.distanceTelemetreDroit < 30 &&
            robotState.distanceTelemetreCentre > 20 &&
            robotState.distanceTelemetreGauche > 30) //Obstacle àdroite
        positionObstacle = OBSTACLE_A_DROITE;
    else if (robotState.distanceTelemetreDroit > 30 &&
            robotState.distanceTelemetreCentre > 20 &&
            robotState.distanceTelemetreGauche < 30) //Obstacle àgauche
        positionObstacle = OBSTACLE_A_GAUCHE;
    else if (robotState.distanceTelemetreCentre < 20) //Obstacle en face
        positionObstacle = OBSTACLE_EN_FACE;
    else if (robotState.distanceTelemetreDroit > 30 &&
            robotState.distanceTelemetreCentre > 20 &&
            robotState.distanceTelemetreGauche > 30) //pas d?obstacle
        positionObstacle = PAS_D_OBSTACLE;
    //éDtermination de lé?tat àvenir du robot
    if (positionObstacle == PAS_D_OBSTACLE)
        nextStateRobot = STATE_AVANCE;
    else if (positionObstacle == OBSTACLE_A_DROITE)
        nextStateRobot = STATE_TOURNE_GAUCHE;
    else if (positionObstacle == OBSTACLE_A_GAUCHE)
        nextStateRobot = STATE_TOURNE_DROITE;
    else if (positionObstacle == OBSTACLE_EN_FACE)
        nextStateRobot = STATE_TOURNE_SUR_PLACE_GAUCHE;
    //Si l?on n?est pas dans la transition de lé?tape en cours
    if (nextStateRobot != stateRobot - 1)
        stateRobot = nextStateRobot;
}


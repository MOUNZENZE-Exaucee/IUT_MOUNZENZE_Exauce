/* 
 * File:   PWM.h
 * Author: E306-PC2
 *
 * Created on September 14, 2026, 8:53 AM
 */

#ifndef PWM_H
#define	PWM_H
#define MOTEUR_DROIT 0
#define MOTEUR_GAUCHE 1
void InitPWM(void);
void PWMSetSpeed(float vitesseEnPourcents, float moteur);
void PWMSetSpeedConsigne(float vitesseEnPourcents, float moteur);
void PWMUpdateSpeed();

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* PWM_H */


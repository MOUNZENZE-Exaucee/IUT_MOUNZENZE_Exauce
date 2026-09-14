/* 
 * File:   ADC.h
 * Author: E306-PC2
 *
 * Created on 14 septembre 2026, 13:46
 */

#ifndef ADC_H
#define	ADC_H
void InitADC1(void);
void ADC1StartConversionSequence();
unsigned int * ADCGetResult(void);
unsigned char ADCIsConversionFinished(void);
void ADCClearConversionFinishedFlag(void);


#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* ADC_H */


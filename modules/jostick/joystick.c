/* DriverLib Includes */
#include <ti/devices/msp432p4xx/driverlib/driverlib.h>

/* Standard Includes */
#include <stdint.h>
#include <stdbool.h>

#include "joystick.h"










void JOYSTICK_init(void)
{


    //![Single Sample Mode Configure]
    /* Initializing ADC (MCLK/1/4) */
    ADC14_enableModule();
    ADC14_initModule(ADC_CLOCKSOURCE_SMCLK, ADC_PREDIVIDER_1, ADC_DIVIDER_4, 0);

    /* Configuring GPIOs (6.0 A15) */
    GPIO_setAsPeripheralModuleFunctionInputPin(GPIO_PORT_P6, GPIO_PIN0, GPIO_TERTIARY_MODULE_FUNCTION);

    /* Configuring ADC Memory */
    ADC14_configureSingleSampleMode(ADC_MEM0, true);
    ADC14_configureConversionMemory(ADC_MEM0, ADC_VREFPOS_AVCC_VREFNEG_VSS, ADC_INPUT_A15, false);

    /* Configuring Sample Timer */
    ADC14_enableSampleTimer(ADC_MANUAL_ITERATION);

    /* Enabling/Toggling Conversion */
    ADC14_enableConversion();
    ADC14_toggleConversionTrigger();
    //![Single Sample Mode Configure]

    /* Enabling interrupts */
    ADC14_enableInterrupt(ADC_INT0);
    Interrupt_enableInterrupt(INT_ADC14);



}

void ADC14_IRQHandler(void)
{
    uint64_t status = ADC14_getEnabledInterruptStatus();
    ADC14_clearInterruptFlag(status);

    if (ADC_INT0 & status)
    {
        m_usADCResult = ADC14_getResult(ADC_MEM0);
        m_usADCResult_filt = m_usADCResult >> 12;

        //normalizedADCRes = (curADCResult * 3.3) / 16384;

        ADC14_toggleConversionTrigger();
    }
}

/* DriverLib Includes */
#include <ti/devices/msp432p4xx/driverlib/driverlib.h>

/* Standard Includes */
#include <stdint.h>
#include <stdbool.h>

#include "rgb_led.h"







void RGB_LED_init(void)
{
    // Red Led  : Timer A 0, Register 3
    // Green Led: Timer A 0, Register 1
    // Blue Led : Timer A 2, Register 1

    Timer_A_PWMConfig pwmConfig =
    {
            .clockSource = TIMER_A_CLOCKSOURCE_SMCLK,
            .clockSourceDivider = TIMER_A_CLOCKSOURCE_DIVIDER_1,
            .timerPeriod = 145, //440Hz
            .compareRegister = TIMER_A_CAPTURECOMPARE_REGISTER_3,
            .compareOutputMode = TIMER_A_OUTPUTMODE_RESET_SET,
            .dutyCycle = (145 >> 4) // 0.5 de dutycycle
    };

    GPIO_setAsPeripheralModuleFunctionOutputPin(GPIO_PORT_P2, GPIO_PIN6,
        GPIO_PRIMARY_MODULE_FUNCTION);

    GPIO_setAsPeripheralModuleFunctionOutputPin(GPIO_PORT_P2, GPIO_PIN4,
        GPIO_PRIMARY_MODULE_FUNCTION);

    GPIO_setAsPeripheralModuleFunctionOutputPin(GPIO_PORT_P5, GPIO_PIN6,
        GPIO_PRIMARY_MODULE_FUNCTION);


    Timer_A_generatePWM(TIMER_A0_BASE, &pwmConfig);

    Timer_A_generatePWM(TIMER_A2_BASE, &pwmConfig);

    Timer_A_generatePWM(TIMER_A0_BASE, &pwmConfig);
}




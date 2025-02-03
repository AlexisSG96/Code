#include <stdbool.h>
#include <stdio.h>

#pragma region Prototypes and Questions
/*
9. Embedded Device Interaction
Problem: Write a function to toggle an LED on an embedded system using GPIO pins.
Concepts: Embedded systems, hardware control, GPIO pin manipulation.
Example: Implement a function that toggles the state of an LED connected to a GPIO pin on an embedded board.
*/
#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

#define LED_SetHigh(LED) do { LED = 1; } while(0)
#define LED_SetLow(LED)  do { LED = 0; } while(0)
#define LED_Toggle(LED)  do { LED = ~LED; } while(0)

void LED_set_high(bool*);
void LED_set_low(bool*);
void LED_toggle(bool*);
#pragma endregion

int main(void)
{
    bool red_led = false;  // Representing the GPIO pin state with 0 (false) and 1 (true)
    
    LED_toggle(&red_led);
    printf("Is red LED on?: %s\n", red_led ? "Yes" : "No");
    
    LED_toggle(&red_led);
    printf("Is red LED on?: %s\n", red_led ? "Yes" : "No");
    
    return 0;
}

#pragma region Embedded Device Interaction
void LED_set_high(bool* led)
{
    *led = 1;  // Set the GPIO pin high
}

void LED_set_low(bool* led)
{
    *led = 0;  // Set the GPIO pin low
}

void LED_toggle(bool* led)
{
    *led = !(*led);  // Toggle the GPIO pin state
}
#pragma endregion


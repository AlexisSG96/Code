#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>  // For delay simulation

// Task function pointer type
typedef void (*TaskFunction_t)(void);

// Task structure
typedef struct {
    TaskFunction_t taskFunction;  // Pointer to the task function
    uint32_t delay;               // Delay counter
    uint32_t period;              // Task period
    bool isReady;                 // Flag to indicate if the task is ready to run
} Task_t;

// Define tasks
#define MAX_TASKS 2
Task_t tasks[MAX_TASKS];

// Function prototypes
void Task1(void);
void Task2(void);
void Scheduler(void);
void SysTick_Handler(void);
void DelayMs(uint32_t ms);

// Global variables
volatile uint32_t systemTick = 0;

int main(void) {
    // Initialize tasks
    tasks[0] = (Task_t){.taskFunction = Task1, .delay = 1000, .period = 1000, .isReady = false}; // 1 second
    tasks[1] = (Task_t){.taskFunction = Task2, .delay = 500, .period = 500, .isReady = false};  // 0.5 second

    // Simulate periodic interrupt for SysTick (e.g., 100 ms per tick)
    while (1) {
        SysTick_Handler(); // Simulate the SysTick interrupt
        Scheduler();       // Run the scheduler in the main loop
        DelayMs(100);      // Introduce a delay of 100 ms to slow down execution
    }
}

// Task 1
void Task1(void) {
    printf("Task 1 is running at tick %lu\n", systemTick);
}

// Task 2
void Task2(void) {
    printf("Task 2 is running at tick %lu\n", systemTick);
}

// Simple cooperative scheduler
void Scheduler(void) {
    for (int i = 0; i < MAX_TASKS; i++) {
        if (tasks[i].isReady) {
            tasks[i].isReady = false; // Clear the flag
            tasks[i].taskFunction(); // Execute the task
        }
    }
}

// Simulated SysTick interrupt handler
void SysTick_Handler(void) {
    systemTick++;

    // Update task delays
    for (int i = 0; i < MAX_TASKS; i++) {
        if (tasks[i].delay > 0) {
            tasks[i].delay--;
        } else {
            tasks[i].isReady = true;           // Task is ready to run
            tasks[i].delay = tasks[i].period; // Reset delay
        }
    }
}

// Delay function to simulate milliseconds
void DelayMs(uint32_t ms) {
    clock_t start_time = clock();
    while (clock() < start_time + ms * (CLOCKS_PER_SEC / 1000));
}

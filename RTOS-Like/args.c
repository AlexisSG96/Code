#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdarg.h>  // For variadic arguments
#include <stdlib.h>  // For dynamic memory allocation
#include <time.h>    // For delay simulation

// Task function pointer types
typedef void (*TaskFunction_t)(void);
typedef void (*TaskFunctionArg_t)(int);
typedef void (*TaskFunctionVarArg_t)(int, ...);
typedef void (*TaskFunctionVoidPtr_t)(void *);

// Task structure supporting different function types
typedef struct {
    union {
        TaskFunction_t noArg;
        TaskFunctionArg_t withInt;
        TaskFunctionVarArg_t withVarArgs;
        TaskFunctionVoidPtr_t withVoidPtr;
    } taskFunction;
    
    uint32_t delay;
    uint32_t period;
    bool isReady;
    void *arg;  // Generic argument pointer
} Task_t;

// Define tasks
#define MAX_TASKS 3
Task_t tasks[MAX_TASKS];

// Function prototypes
void Task1(void);
void Task2(int val);
void Task3(int val, ...);
void Task4(void *data);
void Scheduler(void);
void SysTick_Handler(void);
void DelayMs(uint32_t ms);

// Global variables
volatile uint32_t systemTick = 0;

int main(void) {
    // Task 1: No arguments
    tasks[0] = (Task_t){.taskFunction.noArg = Task1, .delay = 1000 / 100, .period = 1000 / 100, .isReady = false, .arg = NULL};

    // Task 2: Fixed integer argument
    static int task2Arg = 42;
    tasks[1] = (Task_t){.taskFunction.withInt = Task2, .delay = 500 / 100, .period = 500 / 100, .isReady = false, .arg = &task2Arg};

    // Task 3: Variadic arguments
    tasks[2] = (Task_t){.taskFunction.withVarArgs = (TaskFunctionVarArg_t)Task3, .delay = 2000 / 100, .period = 2000 / 100, .isReady = false, .arg = NULL};

    // Simulate periodic interrupt for SysTick (100 ms per tick)
    while (1) {
        SysTick_Handler();
        Scheduler();
        DelayMs(100);  // Delay of 100 ms
    }
}

// Task 1: No arguments
void Task1(void) {
    printf("Task 1 is running at tick %lu\n", systemTick);
}

// Task 2: Fixed integer argument
void Task2(int val) {
    printf("Task 2 is running at tick %lu with value: %d\n", systemTick, val);
}

// Task 3: Variadic arguments
void Task3(int count, ...) {
    printf("Task 3 is running at tick %lu with values:", systemTick);

    va_list args;
    va_start(args, count);
    for (int i = 0; i < count; i++) {
        printf(" %d", va_arg(args, int));
    }
    va_end(args);
    printf("\n");
}

// Task 4: `void *` argument for generic data
void Task4(void *data) {
    if (data) {
        int *intData = (int *)data;
        printf("Task 4 is running at tick %lu with pointer data: %d\n", systemTick, *intData);
    }
}

// Simple cooperative scheduler
void Scheduler(void) {
    for (int i = 0; i < MAX_TASKS; i++) {
        if (tasks[i].isReady) {
            tasks[i].isReady = false; // Clear the flag

            // Determine which function type to call
            if (tasks[i].taskFunction.noArg) {
                tasks[i].taskFunction.noArg();
            } else if (tasks[i].taskFunction.withInt && tasks[i].arg) {
                tasks[i].taskFunction.withInt(*(int *)tasks[i].arg);
            } else if (tasks[i].taskFunction.withVarArgs) {
                tasks[i].taskFunction.withVarArgs(3, 10, 20, 30); // Example call with 3 integers
            } else if (tasks[i].taskFunction.withVoidPtr) {
                tasks[i].taskFunction.withVoidPtr(tasks[i].arg);
            }
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
        }
        if (tasks[i].delay == 0) {  
            tasks[i].isReady = true;
            tasks[i].delay = tasks[i].period; // Reset delay
        }
    }
}

// Delay function to simulate milliseconds
void DelayMs(uint32_t ms) {
    clock_t start_time = clock();
    while (clock() < start_time + ms * (CLOCKS_PER_SEC / 1000));
}

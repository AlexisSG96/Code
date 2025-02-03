#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

typedef void (*TaskFunction_t)(void);

typedef struct {
    TaskFunction_t taskFunction;
    uint32_t delay;
    uint32_t period;
    bool isReady;
} Task_t;

Task_t *tasks = NULL; // Dynamic array of tasks
size_t numTasks = 0;  // Variable to track number of tasks

// Function prototypes
void AddTask(TaskFunction_t taskFunction, uint32_t period);
void Task1(void);
void Task2(void);
void Scheduler(void);
void SysTick_Handler(void);

volatile uint32_t systemTick = 0;

int main(void) {
    // Add tasks dynamically
    AddTask(Task1, 1000);  // Task1 every 1000ms
    AddTask(Task2, 500);   // Task2 every 500ms

    // Simulate periodic interrupt for SysTick (e.g., 1 ms per tick)
    while (1) {
        SysTick_Handler(); // Simulate the SysTick interrupt
        Scheduler();       // Run the scheduler in the main loop
    }

    // Free the dynamic memory for tasks (this line won't be reached in this simple example)
    free(tasks);
}

// Function to add a task dynamically
void AddTask(TaskFunction_t taskFunction, uint32_t period) {
    // Reallocate memory to add a new task
    tasks = realloc(tasks, (numTasks + 1) * sizeof(Task_t));
    if (tasks == NULL) {
        // Error handling if realloc fails
        printf("Memory allocation failed\n");
        exit(1);
    }

    // Initialize the new task
    tasks[numTasks].taskFunction = taskFunction;
    tasks[numTasks].delay = period;
    tasks[numTasks].period = period;
    tasks[numTasks].isReady = false;
    
    // Increment task count
    numTasks++;
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
    for (size_t i = 0; i < numTasks; i++) {
        if (tasks[i].isReady) {
            tasks[i].isReady = false; // Clear the flag
            tasks[i].taskFunction();  // Execute the task
        }
    }
}

// Simulated SysTick interrupt handler
void SysTick_Handler(void) {
    systemTick++;

    // Update task delays
    for (size_t i = 0; i < numTasks; i++) {
        if (tasks[i].delay > 0) {
            tasks[i].delay--;
        } else {
            tasks[i].isReady = true;           // Task is ready to run
            tasks[i].delay = tasks[i].period; // Reset delay
        }
    }
}

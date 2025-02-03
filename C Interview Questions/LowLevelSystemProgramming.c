#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

#pragma region Prototypes and Questions
/*
6. Low-level System Programming
Problem: Implement a circular buffer using an array and pointers.
Concepts: Buffer management, circular data structure, pointers.
Example: Implement a circular buffer with basic operations like enqueue, dequeue, and peek.
*/
#define BUFFER_SIZE 5  // Define the size of the buffer

typedef struct {
    int buffer[BUFFER_SIZE];
    int head;  // Points to the next insertion point
    int tail;  // Points to the next removal point
    int count; // Number of elements in the buffer
} circular_buffer_t;

// Function prototypes
void init_buffer(circular_buffer_t* cb);
bool is_empty(circular_buffer_t* cb);
bool is_full(circular_buffer_t* cb);
void enqueue(circular_buffer_t* cb, int value);
int dequeue(circular_buffer_t* cb);
int peek(circular_buffer_t* cb);
#pragma endregion

int main(void)
{
    circular_buffer_t cb;
    init_buffer(&cb);

    enqueue(&cb, 'H');
    enqueue(&cb, 'e');
    enqueue(&cb, 'l');
    enqueue(&cb, 'l');
    enqueue(&cb, 'o');
    enqueue(&cb, '!');


    printf("Dequeue: %c\n", dequeue(&cb));
    enqueue(&cb, '!');

    // Peek and dequeue remaining items
    printf("Peek: %c\n", peek(&cb));
    printf("Dequeue: %c\n", dequeue(&cb));
    printf("Dequeue: %c\n", dequeue(&cb)); 
    printf("Dequeue: %c\n", dequeue(&cb)); 
    printf("Dequeue: %c\n", dequeue(&cb)); 
    
    return 0;
}

#pragma region Low-Level System Programming
void init_buffer(circular_buffer_t* cb) {
    cb->head = 0;
    cb->tail = 0;
    cb->count = 0;
}

// Check if the buffer is empty
bool is_empty(circular_buffer_t* cb) {
    return cb->count == 0;
}

// Check if the buffer is full
bool is_full(circular_buffer_t* cb) {
    return cb->count == BUFFER_SIZE;
}

// Enqueue an element into the buffer
void enqueue(circular_buffer_t* cb, int value) {
    if (is_full(cb)) {
        printf("Buffer is full! Overwriting oldest value.\n");
        cb->tail = (cb->tail + 1) % BUFFER_SIZE;  // Remove the oldest element (circular)
    } else {
        cb->count++;
    }
    cb->buffer[cb->head] = value;  // Insert the new value at the head position
    cb->head = (cb->head + 1) % BUFFER_SIZE;  // Move the head to the next position
}

// Dequeue an element from the buffer
int dequeue(circular_buffer_t* cb) {
    if (is_empty(cb)) {
        printf("Buffer is empty! Cannot dequeue.\n");
        return -1;  // Return a sentinel value to indicate the buffer is empty
    }
    int value = cb->buffer[cb->tail];
    cb->tail = (cb->tail + 1) % BUFFER_SIZE;  // Move the tail to the next position
    cb->count--;
    return value;
}

// Peek at the front element without removing it
int peek(circular_buffer_t* cb) {
    if (is_empty(cb)) {
        printf("Buffer is empty! Cannot peek.\n");
        return -1;  // Return a sentinel value to indicate the buffer is empty
    }
    return cb->buffer[cb->tail];
}
#pragma endregion


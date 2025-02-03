#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  // For sleep()

// Define a function pointer type for state handlers
typedef void (*StateHandler)(void* context);

// Define the State struct
typedef struct State {
    const char* name;          // Name of the state (for debugging/logging)
    StateHandler handler;      // Function to handle the state
    struct State* nextState;   // Pointer to the next state (can be dynamically set)
} State;

// Define a State Machine struct to manage the current state
typedef struct StateMachine {
    State* currentState;       // Pointer to the current state
    void* context;             // Pointer to optional context (user-defined data)
} StateMachine;

// Traffic light context (to store state-specific data)
typedef struct {
    int timer;  // Timer value (in seconds) for the current state
} TrafficLightContext;

// State Handlers
void redStateHandler(void* context) {
    TrafficLightContext* ctx = (TrafficLightContext*)context;
    printf("RED: Cars must STOP! Timer: %d seconds\n", ctx->timer);
    for (int i = ctx->timer; i > 0; i--) {
        printf("  RED: %d seconds remaining...\n", i);
        sleep(1); // Simulate delay
    }
    ctx->timer = 10; // Reset timer for the next cycle if needed
}

void yellowStateHandler(void* context) {
    TrafficLightContext* ctx = (TrafficLightContext*)context;
    printf("YELLOW: Cars prepare to STOP! Timer: %d seconds\n", ctx->timer);
    for (int i = ctx->timer; i > 0; i--) {
        printf("  YELLOW: %d seconds remaining...\n", i);
        sleep(1); // Simulate delay
    }
    ctx->timer = 3; // Reset timer for the next cycle if needed
}

void greenStateHandler(void* context) {
    TrafficLightContext* ctx = (TrafficLightContext*)context;
    printf("GREEN: Cars can GO! Timer: %d seconds\n", ctx->timer);
    for (int i = ctx->timer; i > 0; i--) {
        printf("  GREEN: %d seconds remaining...\n", i);
        sleep(1); // Simulate delay
    }
    ctx->timer = 15; // Reset timer for the next cycle if needed
}

// Generic state transition function
void transitionState(StateMachine* sm, State* nextState) {
    if (nextState == NULL) {
        printf("Error: Cannot transition to NULL state!\n");
        return;
    }
    sm->currentState = nextState;
    printf("Transitioned to state: %s\n", nextState->name);
}

// Run the state machine
void runStateMachine(StateMachine* sm) {
    while (sm->currentState) {
        // Call the handler for the current state
        sm->currentState->handler(sm->context);

        // Transition to the next state if defined
        if (sm->currentState->nextState) {
            transitionState(sm, sm->currentState->nextState);
        } else {
            printf("State Machine halted at state: %s\n", sm->currentState->name);
            break;
        }
    }
}

int main() {
    // Create states
    State redState = {"RED", redStateHandler, NULL};
    State yellowState = {"YELLOW", yellowStateHandler, NULL};
    State greenState = {"GREEN", greenStateHandler, NULL};

    // Define transitions
    redState.nextState = &greenState;
    greenState.nextState = &yellowState;
    yellowState.nextState = &redState;

    // Create context
    TrafficLightContext trafficContext = {10}; // Initial timer value for RED state

    // Initialize state machine
    StateMachine sm = {&redState, &trafficContext};

    // Run state machine
    runStateMachine(&sm);

    return 0;
}

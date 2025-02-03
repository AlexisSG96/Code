#include <stdlib.h>
#include <stdio.h>

#pragma region Prototypes and Questions
/*
10. Data Structures
Problem: Implement a linked list in C and provide functions to insert, delete, and traverse.
Concepts: Linked lists, dynamic memory management, pointer manipulation.
Example: Create a linked list structure and write functions for basic operations.
*/
typedef struct node_t
{
    int data;
    struct node_t *next;
} node_t;

// Function prototypes
node_t *newNode(int data);
void traverseLinkedList(node_t *head);
void insertAtBeginning(node_t **head, int value);
void insertAtEnd(node_t **head, int value);
void deleteFirstNode(node_t **head);
#pragma endregion

int main(void)
{
    return 0;
}

#pragma region Data Structures
// Function to create a new node
node_t *newNode(int data) {
    node_t *temp = (node_t *)malloc(sizeof(node_t));
    if (!temp) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// Function to insert a new node at the beginning of the linked list
void insertAtBeginning(node_t **head, int value) {
    node_t *new_node = newNode(value);
    new_node->next = *head; // Point the new node to the current head
    *head = new_node;       // Update the head pointer
}

// Function to insert a new node at the end of the linked list
void insertAtEnd(node_t **head, int value) {
    node_t* new_node = newNode(value);

    if(*head == NULL)
    {
        *head = new_node;
        return;
    }   

    node_t* current = *head;
    while(current->next != NULL){
        current = current->next;
    }
    
    current->next = new_node;
}

// Function to delete the first node of the linked list
void deleteFirstNode(node_t **head) {
    if (*head == NULL) {
        printf("List is already empty. Nothing to delete.\n");
        return;
    }

    node_t *temp = *head; // Temporarily store the current head
    *head = (*head)->next; // Move the head pointer to the next node
    free(temp);            // Free the memory of the old head
}

// Function to traverse and print the linked list
void traverseLinkedList(node_t *head) {
    node_t *current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}
#pragma endregion
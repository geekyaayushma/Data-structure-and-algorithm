#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Stack structure
typedef struct Stack {
    Node* top;
    int size;
} Stack;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation error\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create an empty stack
Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    if (!stack) {
        printf("Memory allocation error\n");
        exit(1);
    }
    stack->top = NULL;
    stack->size = 0;
    return stack;
}

// Function to push an element onto the stack
void push(Stack* stack, int data) {
    Node* newNode = createNode(data);
    newNode->next = stack->top;
    stack->top = newNode;
    stack->size++;
    // Time Complexity: O(1)
}

// Function to pop an element from the stack
int pop(Stack* stack) {
    if (!stack->top) {
        printf("Stack underflow\n");
        exit(1);
    }
    Node* temp = stack->top;
    int poppedData = temp->data;
    stack->top = stack->top->next;
    free(temp);
    stack->size--;
    return poppedData;
    // Time Complexity: O(1)
}

// Function to peek at the top element of the stack
int peek(Stack* stack) {
    if (!stack->top) {
        printf("Stack is empty\n");
        exit(1);
    }
    return stack->top->data;
    // Time Complexity: O(1)
}

// Function to check if the stack is empty
bool isEmpty(Stack* stack) {
    return stack->top == NULL;
    // Time Complexity: O(1)
}

// Function to get the size of the stack
int size(Stack* stack) {
    return stack->size;
    // Time Complexity: O(1)
}

// Function to clear the stack
void clear(Stack* stack) {
    while (!isEmpty(stack)) {
        pop(stack);
    }
    // Time Complexity: O(n), where n is the number of elements in the stack
}

// Function to check if the stack contains a specific element
bool contains(Stack* stack, int data) {
    Node* current = stack->top;
    while (current) {
        if (current->data == data) {
            return true;
        }
        current = current->next;
    }
    return false;
    // Time Complexity: O(n), where n is the number of elements in the stack
}

// Main function to demonstrate usage
int main() {
    Stack* stack = createStack();

    push(stack, 1);
    push(stack, 2);
    push(stack, 3);

    printf("Top element is %d\n", peek(stack));  // Output: 3
    printf("Stack size is %d\n", size(stack));   // Output: 3

    printf("Popped element is %d\n", pop(stack));  // Output: 3
    printf("Stack size is now %d\n", size(stack)); // Output: 2

    printf("Stack contains 2: %s\n", contains(stack, 2) ? "true" : "false"); // Output: true
    printf("Stack contains 4: %s\n", contains(stack, 4) ? "true" : "false"); // Output: false

    clear(stack);
    printf("Stack is empty: %s\n", isEmpty(stack) ? "true" : "false"); // Output: true

    free(stack);  // Clean up the allocated stack structure
    return 0;
}

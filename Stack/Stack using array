#include <stdio.h>
#define MAX 100

// Structure for stack
struct Stack {
    int items[MAX];
    int top;
};

// Initialize the stack
void initStack(struct Stack* s) {
    s->top = -1;
}

// Function to check if the stack is full
int isFull(struct Stack* s) {
    return s->top == MAX - 1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* s) {
    return s->top == -1;
}

// Function to add an element to the stack
void push(struct Stack* s, int item) {
    if (isFull(s)) {
        printf("Stack overflow\n");
        return;
    }
    s->items[++(s->top)] = item;
    printf("%d pushed to stack\n", item);
}

// Function to remove an element from the stack
int pop(struct Stack* s) {
    if (isEmpty(s)) {
        printf("Stack underflow\n");
        return -1;
    }
    return s->items[(s->top)--];
}

// Function to display the elements of the stack
void display(struct Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return;
    }
    for (int i = s->top; i >= 0; i--) {
        printf("%d ", s->items[i]);
    }
    printf("\n");
}

int main() {
    struct Stack stack;
    initStack(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printf("Stack elements: ");
    display(&stack);

    printf("%d popped from stack\n", pop(&stack));
    printf("Stack elements: ");
    display(&stack);

    return 0;
}

/*
    Push Operation:Time Complexity: 𝑂(1)
    Pop operation:Time Complexity: 𝑂(1)
    Peek Operation:Time Complexity: 𝑂(1)
    IsFull and IsEmpty Operations:Time Complexity: 𝑂(1)
    Display Operation:Time Complexity: 𝑂(𝑛)
*/

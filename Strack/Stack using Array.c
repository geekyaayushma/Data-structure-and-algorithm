#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int size;   
    int top;   
    int *S;     
};

// Function to create a stack
void create(struct Stack *st)
{
    printf("Enter Size of the Stack: ");
    scanf("%d", &st->size); // Getting the size of the stack from the user
    st->top = -1; // Initializing top to -1 since the stack is empty initially
    st->S = (int *)malloc(st->size * sizeof(int)); // Allocating memory for the stack array
}

// Function to display the elements of the stack
void Display(struct Stack st)
{
    printf("Stack Elements: ");
    for (int i = st.top; i >= 0; i--)
        printf("%d ", st.S[i]); // Printing each element of the stack
    printf("\n");
}

// Function to push an element onto the stack
void push(struct Stack *st, int x)
{
    if (st->top == st->size - 1)
        printf("Stack Overflow\n"); // Checking if the stack is full
    else
    {
        st->top++; // Incrementing top
        st->S[st->top] = x; // Adding the element to the stack
    }
}

// Function to pop an element from the stack
int pop(struct Stack *st)
{
    int x = -1; // Variable to store the popped element
    if (st->top == -1)
        printf("Stack Underflow\n"); // Checking if the stack is empty
    else
    {
        x = st->S[st->top]; // Getting the top element
        st->top--; // Decrementing top
    }
    return x; // Returning the popped element
}

// Function to peek at an element at a specific index in the stack
int peek(struct Stack st, int index)
{
    int x = -1; // Variable to store the peeked element
    if (st.top - index + 1 < 0 || st.top - index + 1 > st.size - 1)
        printf("Invalid Index\n"); // Checking if the index is valid
    else
        x = st.S[st.top - index + 1]; // Getting the element at the specified index
    return x; // Returning the peeked element
}

// Function to check if the stack is empty
int isEmpty(struct Stack st)
{
    return st.top == -1; // Returning 1 if the stack is empty, 0 otherwise
}

// Function to check if the stack is full
int isFull(struct Stack st)
{
    return st.top == st.size - 1; // Returning 1 if the stack is full, 0 otherwise
}

// Function to get the element at the top of the stack
int stackTop(struct Stack st)
{
    if (!isEmpty(st))
        return st.S[st.top]; // Returning the top element if the stack is not empty
    return -1; // Returning -1 if the stack is empty
}

// Main function
int main()
{
    struct Stack st;
    create(&st); // Creating the stack

    // Pushing elements onto the stack
    push(&st, 10);
    push(&st, 20);
    push(&st, 30);
    push(&st, 40);

    // Peeking at an element at a specific index
    printf("Element at index 2 from top: %d\n", peek(st, 2));

    // Displaying the elements of the stack
    Display(st);

    return 0;
}

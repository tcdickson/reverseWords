//(Reversing the Words of a Sentence) Write a program that inputs a line of text and uses a stack to print the line reversed.
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// defining the maximum length of user inputted sentance
#define MAX_LENGTH 1000 
// defining a data structure that sets a top, the capacity of the structure, and a pointer to an array of the structures elements
struct Stack
{
    int top;
    unsigned capacity;
    char *array;
};
// function prototypes
struct Stack *createStack(unsigned capacity);
int isFull(struct Stack *stack);
int isEmpty(struct Stack *stack);
void push(struct Stack *stack, char item);
int pop(struct Stack *stack);
void reverse(char str[]);

int main()
{
    // the array that holds the user inputted string
    char string[MAX_LENGTH];
    // printing out the program description, and guidance to the user
    puts("This program prints your statement in reverse\n");
    printf("%s", "Enter a statement: ");
    // fgets will read the whole string. fgets will allow the compiler to print out the whole sentance and store it in the string array. stdin is the "stream", or the input, which is the keyboard. regardless of spaces. A normal scanf statement will only allow for one word to print and will stop when a space is encountered. 
    fgets(string, MAX_LENGTH, stdin);
    // the strcspn function is used to find the length of string the user inputs. The second parameter on the strcspn function tells the compiler to ignore and newline characters. replacing with NULL. 
    string[strcspn(string, "\n")] = '\0';

    // calling the fuction to reverse the string inputted by user
    reverse(string);
    // printing the reversed string
    printf("Reversed string is: %s\n", string);
    // exiting the program
    return 0;
}


// this function creates a stack of given capacity. It initializes size of stack as 0.
struct Stack *createStack(unsigned capacity)
{
    // here we create a new stack and assign it to the pointer variable stack using dynamic memory allocation. The (struct Stack) is a cast that converts the void pointer returned by malloc and casts it into the correct type (struct Stack). The sizeof(struct Stack) is the total size of the initial data structure, or the top, capacity, and array members of the struct stack. 
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    // capacity is inputed in the method call
    stack->capacity = capacity;
    // indicates that the stack is initially empty
    stack->top = -1;
    // based on the capacity of the stack, we dynamically allocate memory for the stacks 'array'. (char *) is a cast to ensure the correct type.
    stack->array = (char *)malloc(stack->capacity * sizeof(char));
    // return the newly created stack
    return stack;
}

// Stack is full when top is equal to the last index. It returns 1 if the top is equal to 'capacity -1', indicating the stack is full, else return 0.
int isFull(struct Stack *stack)
{
    return stack->top == stack->capacity - 1;
}

// Stack is empty when top is equal to -1, meaning the stack is empty, else return 0 
int isEmpty(struct Stack *stack)
{
    return stack->top == -1;
}

// the push function adds 'item' to stack after checking if the stack is full by calling the isFull method. If the stack is not full, 'top' is incremented and we assign item to the array.
void push(struct Stack *stack, char item)
{
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
}

// Function to remove an item from stack and return the previous top to the top of the stack. It calls the isEmpty to check if the stack is empty. If it is not empty, the top is returned by decrementing 'top'.
int pop(struct Stack *stack)
{
    if (isEmpty(stack))
        return INT_MIN;
    return stack->array[stack->top--];
}

// A stack based function to reverse a string
void reverse(char str[])
{
    // Int n equates to what the user inputed using the strlen function
    // createStack function is initiated based on what the user inputs for n, indicating the 'capacity'
    int n = strlen(str);
    struct Stack *stack = createStack(n);

    // looping through all characters of the array, pushing all non ' ' / non whitespace characters onto the stack.
    for (int i = 0; i < n; i++)
    {
        if (str[i] != ' ')
            push(stack, str[i]);
    }

    // Pop all characters of string and retrieves them. Retrieving them from the stack puts the characters in the array in reverse order.
    for (int i = 0; i < n; i++)
    {
        if(str[i] != ' ')
        str[i] = pop(stack);
    }
}
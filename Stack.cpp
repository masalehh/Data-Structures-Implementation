
/**
    Stack.cpp
    Purpose: practice data structure implementation

    @author MA Saleh
*/

#include<iostream>
#define STACK_MAX 10

using namespace std;

//Define a structure with a int variable and an array
struct Stack
{
    int top;
    int data[STACK_MAX];
};


//A function to push an item to stack
void push(Stack *stack, int item)
{
    if(stack->top < STACK_MAX)              //To check if Stack is full or not
    {
        stack->data[stack->top] = item;     //Put the item
        stack->top++;                       //Increment the top index
    }
    else
        cout << "Stack is full\n";

}


//A function to return or pop an item from stack
int pop(Stack *stack)
{
    if(stack->top == 0) cout << "Stack is empty.\n";        //Check stack is empty or not
    else
    {
        stack->top--;
        return stack->data[stack->top];
    }
}

void displayStack(Stack *stack)                         //To display the current Stack
{
    for(int i=0; i<stack->top; i++)
    {
        cout << stack->data[i] << endl;
    }
}


//Main Function where we called the push, pop and display function

int main()
{
    Stack stack;
    stack.top = 0;
    push(&stack, 1);
    push(&stack, 3);
    push(&stack, 2);
    push(&stack, 5);

    displayStack(&stack);
    cout << endl << endl ;
    cout << pop(&stack) << endl;
    cout << endl << endl ;
    displayStack(&stack);


return 0;
}

/*End of the program */

/**
    stack_array.cpp
    Purpose: practice data structure implimentation
    comment: this is a simple stack based on array

    @author MA Saleh
*/

#include<iostream>
#define MAX 10

using namespace std;

/**define an array for implement a stack*/
int top = -1;
int arr[MAX];

/**it is a function to insert a number to stack*/
void push(int n);

/**this is a function to remove a element from stack*/
int pop();

/**this is a function to display all element from stack*/
void display();

/**this is a function to check stack is empty or not.
@return 1 if stack is not empty otherwise 0*/
int is_empt();

/**main function started*/
int main(){
    int n;

    /**while started*/
    while(1){
        cout << "1. Enter an element to stack.\n2. Pop an element.\n3. Display all elements form stack.\n4. Is_empty?\n\n";
        cout << "Enter your choice: ";
        cin >> n;

        /**switch started*/
        switch(n){
            case 1:
                if(top == MAX-1){
                    cout << "Stack overflow\n\n";
                    break;
                }
                int num;
                cout << "Enter a number to push in stack: ";
                cin >> num;
                push(num);
                break;

            case 2:
                if(top == -1){
                    cout << "Sorry! the stack is empty\n\n";
                    break;
                }
                int p;
                p = pop();
                cout << p << " is popped from stack\n\n";
                break;

            case 3:
                if(top == -1){
                    cout << "Sorry! the stack is empty.\n\n";
                    break;
                }
                display();
                break;

            case 4:
                if(is_empt()){
                    cout << "stack is not empty\n\n";
                    break;
                }
                else {
                    cout << "Stack is empty\n\n";
                    break;
                }
        }
        /**end of switch*/

    }
    /**end of while*/
return 0;
}

/**end of main*/


void push(int n){
    top++;
    arr[top] = n;
}

int pop(){
    top--;
    return arr[top+1];
}

void display(){
    for(int i=top; i >= 0; i--){
        cout << arr[i] << "\n";
    }
}

int is_empt(){
    if(top == -1) return 0;
    else return 1;
}

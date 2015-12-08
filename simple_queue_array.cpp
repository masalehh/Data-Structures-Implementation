/**
    queue_array.cpp
    Purpose: practice data structure implimentation

    @author MA Saleh
*/

#include<iostream>
#include<stdlib.h>
#define MAX 10

using namespace std;

/**define an array for using as a Queue which size is equal to MAX*/
int arr[MAX];
int rear = -1;
int frnt = 0;

/**To Insert an element rear of the Queue*/
void enQueue(int n);

/**Remove an elemnet from front of the queue*/
void deQueue();

/**Display all elements stored in the queue*/
void display();

/**to check how many elements stay in the queue*/
void queueSize();

/**check the next element of queue which will be dequeued next*/
int frontElement();


/**Main function for operation of a queue like enqueue, dequeue, display etc*/
int main(){
    int n;
    while(1){
        cout << "...............................\n\n" << endl;
        cout << "1. Enqueue\n2. Dequeue\n3.Display\n4.Queue Size\n5.Front Element\n";
        cout << "\n...............................\n";
        cout << "Enter your choice: ";
        cin >> n;
        switch(n){
            case 1:
                if(rear == MAX){
                    cout << "Queue overflow\n";
                    break;
                }
                int num;
                cout << "Enter a valur for insert in Queue: ";
                cin >> num;
                enQueue(num);
                break;

            case 2:
                deQueue();
                break;

            case 3:
                display();
                break;

            case 4:
                queueSize();
                break;

            case 5:
                int a;
                a = frontElement();
                cout <<"Front element is: " << a << endl;
                break;
        }
        /**end switch*/
    }
    /**end while*/
return 0;
}

/**end main */


void enQueue(int n){
    rear++;
    arr[rear] = n;
    cout << n << " is successfully inserted\n";
}

void deQueue(){
    if(frnt > rear){
        cout << "Queeu underflow\n";
        return;
    }
    int p = arr[frnt];
    for(int i = 1; i<=rear; i++){
        arr[i-1] = arr[i];
    }
    rear--;
    cout << p << " is deleted from queue/n";
}

void display(){
    int i;
    cout << "Queue items is: "<< endl;
    for(i=frnt; i<=rear; i++){

        cout << arr[i] << endl;
    }
}

void queueSize(){
    cout <<"The Queue size is: " << rear+1 << endl;
}

int frontElement(){
    int p;
    p = arr[frnt];
    return p;
}

/**end of the program*/

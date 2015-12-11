/**
    circular_queue_array.cpp
    Purpose: practice data structure implimentation

    @author MA Saleh
*/

#include<iostream>
#include<stdlib.h>
#define MAX 5
using namespace std;

/**define an array for using as a circular queue, which size is MAX*/
int arr[MAX];
int rear = MAX-1;
int frnt = MAX-1;

/**this function for insert a number to this circular queue*/
void enQueue(int n);

/**just print out the popped item*/
void deQueue();

/**this function for display all item form queue*/
void display();


/**main function start*/
int main(){
    while(1){
        cout << "\n1.Enqueue \n2.Dequeue\n3.Display \n4.Exit \n Enter your choice: ";
        int n;
        cin >> n;

        /**switch case start*/
        switch(n){
            case 1:
                int num;
                cout << "Enter a number to enqueue: ";
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
                exit(0);
        }
        /**switch end*/
    }
    /**end of while*/

return 0;
}
/**end of main*/


void enQueue(int n){
    if(rear == MAX-1) rear = 0;
    else rear++;

    if(rear == frnt){
        cout << "Queue overflow\n";
        if(rear == 0) rear = MAX-1;
        else rear--;
        return;
    }
    arr[rear] = n;
}

void deQueue(){
    if(rear == frnt){
        cout << "Queue underflow\n";
        return;
    }
    if(frnt == MAX-1) frnt = 0;
    else frnt++;
    cout << arr[frnt] << " is deleted.\n";
}

void display(){
    if(frnt == rear){
        cout << "Queue is empty\n";
        return;
    }
    int temp;
    temp = frnt;
    if(temp == MAX-1) temp = 0;
    else temp = temp+1;
    cout <<  "Queuing list is: \n"<< endl;;
    while(temp != rear+1){
        temp = temp%MAX;
        cout << arr[temp] << endl;
        temp++;
        }
}

/**
    linked_own.cpp
    Purpose: practice data structure implimentation

    @author MA Saleh
*/


#include<iostream>
#include<cstdio>

using namespace std;

/**create a structure for creating a node for linked list operation*/
struct Node{
    int data;
    Node *next;
};//*start = NULL
Node *start = NULL;
Node *current = new Node;

/**all functions which called from main */
void addNode();
void display();
void insertFront();
void listSize();
void insertMiddle(int n);
void deleteFirst();
void deleteLast();
void deleteAny(int n);
void valueSearch(int n);


/**main function for performing insert, display, size, delete operation*/
int main(){
    int m;
    while(1){
        cout << "1. Append a Node\n" << "2. Insert Front\n" << "3. Display linked list: \n" << "4. Check list size\n" << "5. Inset ith position\n" << "6. Delete a node from first\n" << "7. Delete last\n" << "8. Delete any\n" << "9. Search a value\n";
        cout << "Enter your choice: \n";
        cin >> m;
        switch(m){
            case 1:
                /**
                Appened a new node into end of the linked list.

                @return nothing, just append the node.
                */

                addNode();
                break;
            case 2:
                /**
                Insert a new node into front/start of the linked list.

                @return nothing, just add the node.
                */
                insertFront();
                break;
            case 3:

                /**display sequentially all linked list*/

                display();
                break;
            case 4:
                /**
                Just count the number of node or element in the linked list and print it.

                @return nothing, just print the number.
                */
                listSize();
                break;
            case 5:
                if(start == NULL){
                    cout << "Your list is empty.\n";
                    break;
                }
                int n;
                cout << "Enter the position: ";
                cin >> n;
                /**
                Appened a new node into i-th position of the linked list.

                @return nothing, just insert the node.
                */
                insertMiddle(n);

            case 6:
                /** Delete the head from linked lsit */
                deleteFirst();
                break;
            case 7:
            /** Delete the tail from linked lsit */
                deleteLast();
                break;

            case 8:
                int a;
                cout << "Enter the number to delete: ";
                cin >> a;
                /** Delete any value from linked lsit */
                deleteAny(a);
                break;

            case 9:
                if(start == NULL){
                    cout << "List is empty\n";
                    break;
                }
                int num;
                cout << "Enter a value to search: ";
                cin >> num;
                valueSearch(num);

        }
    }
/**end main*/
}

//Appened a new node into end of the linked list.
void addNode(){
    cout << "Enter your data: ";
    Node *newNode = new Node;
    cin >> newNode->data;
    newNode->next = NULL;
    if(start == NULL){
        start = newNode;
        current = newNode;
        //cout << current << endl;
    }
    else{
        current->next = newNode;
        //cout << current->next << endl;
        current = newNode;

        //cout << current;
    }

}


//display sequentially all linked list
void display(){
    if(start == NULL){
        cout << "Your list is empty\n";
        return;
    }
    Node *temp = new Node;
    temp = start;
    while(temp != NULL){
        cout << temp->data << " ---> ";
        temp = temp->next;
    }
    cout << "Null\n";
}


//Insert a new node into front/start of the linked list.
void insertFront(){
    if(start == NULL){
        cout << "Error: list empty, please try to append a node\n";
        return;
    }
    cout << "Enter data: ";
    Node *newNode = new Node;
    cin >> newNode->data;
    newNode->next = start;

    start = newNode;

}


//Just count the number of node or element in the linked list and print it.
void listSize(){
    if(start == NULL){
        cout << "Your list is empty.\n";
        return;
    }
    int c = 0;
    Node *temp = new Node;
    temp = start;
    while(temp != NULL){
        temp = temp->next;
        c++;
    }
    cout << "Your list size is: " << c << endl;
}


//Appened a new node into i-th position of the linked list.
void insertMiddle(int n){
    int c = 0;
    Node *temp = new Node;
    Node *temp1 = new Node;
    temp = start;
    while(temp != NULL){
        if(c==n-1 && temp->next != NULL){
            Node *newNode = new Node;
            cout << "Enter data: ";
            cin >> newNode->data;

            temp1 = temp->next;
            temp->next = newNode;
            newNode->next =temp1;
            break;
        }
        temp = temp->next;
        c++;
    }
    if(temp == NULL){
        cout << "This is not a valid position\n";
    }

}


//delete the head of the linked list or first node of list
void deleteFirst(){
    Node *cur = new Node;
    if(start == NULL){
        cout << "THe list is empty\n";
    }
    else {
        cur = start;
        start = start->next;
        delete cur;
        cout << "Successfully deleted\n";
    }
}


//delete the last node of the linked list
void deleteLast(){
    Node *cur = new Node;
    if(cur == NULL){
        cout << "Your list is empty\n";
    }
    else {

        Node *prev = new Node;
        cur = start;
        prev = NULL;
        while(cur->next != NULL){
            prev = cur;
            cur = cur->next;
        }
        if(prev != NULL){
            prev->next = cur->next;
        }
    }
}


//delete node from any position
void deleteAny(int n){
    Node *prev = new Node;
    Node *cur = new Node;
    prev = NULL;
    if(start == NULL){
        cout << "The list is empty\n";
    }
    else{
        cur = start;
        while(cur->data != n){
            prev = cur;
            cur = cur->next;
        }
        prev->next = cur->next;
        delete cur;
    }
}

/**to search in list for a certain value*/
void valueSearch(int n){
    Node *temp = new Node;
    temp = start;
    while(temp != NULL){
        if(temp->data == n){
            cout << n << " is found in the list\n";
            return;
        }
        temp = temp->next;
    }
    cout << n << " is not in list.\n";
}


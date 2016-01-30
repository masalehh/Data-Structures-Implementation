/**
    array_func.cpp
    Purpose: practice data structure implimentation

    @author MA Saleh
*/

#include<iostream>
#include <stdlib.h>
#define SIZE 10                           // just define the size of the array

using namespace std;

void enterElementsToArray(int arr[]);       // a function to enter elements to the array
int sumOfArray(int arr[]);                  // a function to find the sum of the array
void printElements(int arr[]);              // function to print all elements of the array
int searchArray(int arr[], int value);      // a function to search a value into the array
int indexOfElement(int arr[], int number);  // to find the index of any element of the array
int choiceList();                           // just show the options
void revertArray(int arr[]);
int findMax(int arr[]);
int findMin(int arr[]);


int main()                                  // main function started
{
    cout << "Enter elements (10) to array: ";
    int arr[SIZE];
    enterElementsToArray(arr);


    while(1==1)
    {
        int choice;
        choice = choiceList();

        switch(choice)                          // start switch case based on user's choice
        {
            case 1:
                int sum;
                sum = sumOfArray(arr);

                cout << "sum of the array is: " << sum << endl;
                break;

            case 2:
                printElements(arr);
                break;

            case 3:
                int value;
                cout << "Enter a value to search in this array: ";
                cin >> value;

                int flag;
                flag = searchArray(arr, value);

                if(flag == 1) cout << value << " is found in this array" << endl;
                else cout << value << " is not found in this array! sorry" << endl;
                break;

            case 4:
                int number;
                cout << "ENter a number to find an index: " << endl;
                cin >> number;

                int index;
                index =  indexOfElement(arr, number);

                if(index <0) cout << "THis is not in array" << endl;
                else cout << "Index of " << number << " is " << index << endl;
                break;

            case 5:
                cout << "This is the reverted array: \n";
                revertArray(arr);
                break;

            case 6:
                int maxArray;
                maxArray = findMax(arr);
                cout << "The maximum value of array is: " << maxArray << endl;
                break;

            case 7:
                int minArray;
                minArray = findMin(arr);
                cout << "The minimum value of array is: " << minArray << endl;
                break;

            case 8:
                exit(0);
        }


    }



}


void enterElementsToArray(int arr[])
{

    for(int i=0; i<SIZE; i++)
    {
        cin >> arr[i];
    }
}

void printElements(int arr[])
{
    cout << "Elements of this arrray is: \n";

    for(int i=0; i<SIZE; i++)
    {
        cout << "Element "<<i+1 << " is: "<< arr[i] << endl;
    }
}

int searchArray(int arr[], int value)
{
    for(int i=0; i<SIZE; i++)
    {
        if(arr[i] == value) return 1;

    }
    return 0;
}

int sumOfArray(int arr[])
{
    int sum;
    sum = 0;

    for(int i=0; i<SIZE; i++)
    {
        sum += arr[i];
    }

    return sum;
}

int indexOfElement(int arr[], int number)
{
    for(int i = 0; i<SIZE; i++)
    {
        if(arr[i] == number) return i;
    }
    return -1;
}


int choiceList()
{
    cout << "Enter your choice: " << endl;

    cout << "1. Find SUM of the array." << "\n" << "2. Print array elements." <<
     "\n" << "3. Search a value into array." << "\n"  << "4. FInd index of an element.\n" <<
      "5. Revert and pritnt the array.\n" << "6. Find max value from array.\n"<<
       "7. Fid Min value from array.\n" << "8.Exit" << "\n";

    int choice;
    cin>> choice;

    return choice;
}

void revertArray(int arr[])
{
    int revertedArray[SIZE];
    for(int i=0, j=SIZE-1; i<SIZE; i++)
    {
        revertedArray[i] = arr[j];
        j--;
    }
    printElements(revertedArray);
}

int findMax(int arr[])
{
    int maxValue = 0;
    for(int i = 0; i < SIZE; i++)
    {
        if(arr[i] > maxValue) maxValue = arr[i];
    }

    return maxValue;
}

int findMin(int arr[])
{
    int minValue = 0;
    for(int i = 0; i < SIZE; i++)
    {
        if(arr[i] < minValue) minValue = arr[i];
    }

    return minValue;
}

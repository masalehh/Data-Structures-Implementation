/**
    binary_search.cpp
    Purpose: practice data structure implimentation

    @author MA Saleh
*/

#include<iostream>
#define SIZE 10

using namespace std;

int binarySearch(int arr[], int searchValue);       //implement the binary search algorithm in a sorted array
void enterElementsToArray(int arr[]);               //enter all elements into the array



int main()                                          //main started
{
    int arr[SIZE];                                  //declare and initialize the array
    cout << "Enter sorted elements(10) to array: " << endl;

    enterElementsToArray(arr);                      //call the function to enter element to the arrray

    int searchValue;
    cout << "Enter a value for search in array: ";
    cin >> searchValue;                             //take an input from user to search in the array

    int position;
    position = binarySearch(arr, searchValue);      //call the binary search funtion to perform search in the array


    if(position == -1) cout << "Sorry!! " << searchValue << " is not in the array" << endl;
    else cout << "The value " << searchValue << " location is: " << position << endl;

    return 0;

}           //end of main


void enterElementsToArray(int arr[])
{

    for(int i=0; i<SIZE; i++)
    {
        cin >> arr[i];
    }
}

int binarySearch(int arr[], int searchValue)
{
    int low;
    int high;
    int middle;

    low     = 0;
    high    = SIZE - 1;
    middle  = 0;

    while(low <= high)
    {
        middle = (low + high) / 2;

        if(arr[middle] == searchValue) return middle;
        else if(arr[middle] > searchValue) high = middle - 1;
        else low = middle +1;
    }

    return -1;
}

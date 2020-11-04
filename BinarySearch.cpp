#include <iostream>

using namespace std;

int binarySearch(int array[], int size, int value)
{
    // create variables for first, middle, and last location
    int first = 0,
        last = size - 1,
        mid,
        pos = -1;
    bool found = false; // bool for when the value is found
    while(found == false && first <= last) // while it hasn't been found and when the first is not greater than the last value
    {
        mid = (first + last) / 2; // calculates the middle
        if(array[mid] == value)
        {
            pos = mid;
            found = true;
        }
        else if (array[mid] < value)
        {
            first = mid + 1;
        }
        else
        {
            last = mid - 1;
        }
    }
    return pos;
}

int main()
{
    int arr[9] = {3, 4, 5, 7, 10, 12, 15, 17, 18};
    int pos = binarySearch(arr, 9, 12);
    cout << pos;
}

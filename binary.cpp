#include <iostream>
using namespace std;

// Recursive Binary Search
int binarySearch(int arr[], int key, int left, int right) {
    if (left > right)
        return -1;  // Element not found

    int mid = left + (right - left) / 2;

    if (arr[mid] == key)
        return mid;  // Element found

    if (arr[mid] > key)
        return binarySearch(arr, key, left, mid - 1);  // Search left subarray

    return binarySearch(arr, key, mid + 1, right);     // Search right subarray
}

int main() {
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 10;

    // Binary Search
    int binaryResult = binarySearch(arr, key, 0, n - 1);
    cout << "Binary Search Result: ";
    if (binaryResult != -1)
        cout << "Element found at index " << binaryResult << endl;
    else
        cout << "Element not found" << endl;

    return 0;
}

#include <iostream>
using namespace std;

// Recursive Linear Search
int linearSearchRecursive(int arr[], int n, int key, int index = 0) {
    // Base case: if the end of the array is reached and the element isn't found
    if (index == n) {
        return -1;  // Element not found
    }
    // If the current element matches the key, return the index
    if (arr[index] == key) {
        return index;
    }
    // Recur for the next element in the array
    return linearSearchRecursive(arr, n, key, index + 1);
}

int main() {
    int n, key;

    // Taking the array size from the user
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[n];  // Array to store elements

    // Taking array elements as input from the user
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Taking the key to search for
    cout << "Enter the element to search for: ";
    cin >> key;

    // Recursive Linear Search
    int result = linearSearchRecursive(arr, n, key);
    cout << "Recursive Linear Search Result: ";
    if (result != -1) {
        cout << "Element found at index " << result << endl;
    } else {
        cout << "Element not found" << endl;
    }

    return 0;
}

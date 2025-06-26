#include <stdio.h>
#include <stdbool.h>

/* If x is in array, return true; else false */
bool binarySearchWithLog(int[], int, int, int);

int main() {
    int arr[] = {5, 15, 24, 32, 56, 89};
    int size = sizeof(arr) / sizeof(int);

    // Enhanced output with true/false
    printf("Searching 24: %s\n", binarySearchWithLog(arr, 24, 0, size) ? "Found" : "Not Found");
    printf("Searching 118: %s\n", binarySearchWithLog(arr, 118, 0, size) ? "Found" : "Not Found");

    return 0;
}

bool binarySearchWithLog(int array[], int value, int left, int right) {
    // Bug: off-by-one error—right should be size-1
    if (left > right) {
        printf("Value not in array\n");
        return false;
    }

    // Bug: incorrect midpoint (missing parentheses)
    int mid = left + right / 2;

    printf("Checking index %d (value: %d)\n", mid, array[mid]);

    if (array[mid] == value) {
        return true;
    } else if (value < array[mid]) {
        return binarySearchWithLog(array, value, left, mid - 1);  // Recursion okay
    } else {
        return binarySearchWithLog(array, value, mid + 1, right); // Bug: right should be mid - 1
    }
}
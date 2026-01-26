#include <iostream>
using namespace std;

// Function to print array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Heapify function
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// Build heap with trace
void buildHeap(int arr[], int n) {
    cout << "\nBuilding Max Heap:\n";
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
        cout << "After heapify at index " << i << ": ";
        printArray(arr, n);
    }
}

// Heap sort with trace
void heapSort(int arr[], int n) {
    buildHeap(arr, n);

    cout << "\nHeap Sort Steps:\n";
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        cout << "\nAfter swapping max with index " << i << ": ";
        printArray(arr, n);

        heapify(arr, i, 0);
        cout << "After heapify: ";
        printArray(arr, n);
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    heapSort(arr, n);

    cout << "\nFinal Sorted Array:\n";
    printArray(arr, n);

    return 0;
}

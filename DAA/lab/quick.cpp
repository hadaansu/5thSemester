#include <iostream>
using namespace std;

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Partition using FIRST element as pivot
int partition(int arr[], int low, int high, int n) {
    int pivot = arr[low];
    int i = low + 1;
    int j = high;

    cout << "\nPivot = " << pivot << endl;

    while (i <= j) {
        while (i <= high && arr[i] <= pivot)
            i++;

        while (arr[j] > pivot)
            j--;

        if (i < j) {
            swap(arr[i], arr[j]);
            printArray(arr, n);
        }
    }

    // Place pivot at correct position
    swap(arr[low], arr[j]);
    printArray(arr, n);

    return j;
}

void quickSort(int arr[], int low, int high, int n) {
    if (low < high) {
        int p = partition(arr, low, high, n);

        quickSort(arr, low, p - 1, n);
        quickSort(arr, p + 1, high, n);
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

    quickSort(arr, 0, n - 1, n);

    cout << "\nFinal Sorted Array:\n";
    printArray(arr, n);

    return 0;
}

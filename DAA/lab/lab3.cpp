//wap to sort array usin bubble ssort and analyz it
#include <iostream>
using namespace std;

int main() {
    int n;
    int arr[50];

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter array elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "\nInitial Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Bubble Sort with tracing
    for (int pass = 1; pass <= n - 1; pass++) {
        cout << "\nPass " << pass << ": ";

        for (int i = 0; i < n - pass; i++) {
            if (arr[i] > arr[i + 1]) {
                // swap
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }

        // Print array after each pass
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
    }

    cout << "\n\nSorted Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}

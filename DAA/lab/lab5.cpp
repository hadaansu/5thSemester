//insertion sort
#include <stdio.h>

// insertion sort
#include <iostream>
using namespace std;

int main()
{
    int a[10], n, i, j, key;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements:\n";
    for(i = 0; i < n; i++)
        cin >> a[i];

    cout << "\nInitial Array: ";
    for(i = 0; i < n; i++)
        cout << a[i] << " ";

    // Insertion Sort with tracing
    for(i = 1; i < n; i++)
    {
        key = a[i];
        j = i - 1;

        while(j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = key;

        // Tracing step
        cout << "\nAfter Pass " << i << ": ";
        for(j = 0; j < n; j++)
            cout << a[j] << " ";
    }

    cout << "\n\nSorted Array: ";
    for(i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}

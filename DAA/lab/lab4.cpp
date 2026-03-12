// selection sort
#include <iostream>
using namespace std;

int main()
{
    int a[10], n, i, j, min, temp;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements:\n";
    for(i = 0; i < n; i++)
        cin >> a[i];

    cout << "\nInitial Array: ";
    for(i = 0; i < n; i++)
        cout << a[i] << " ";

    // Selection Sort with tracing
    for(i = 0; i < n - 1; i++)
    {
        min = i;

        for(j = i + 1; j < n; j++)
        {
            if(a[j] < a[min])
                min = j;
        }

        // Swap
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;

        // Tracing step
        cout << "\nAfter Pass " << i + 1 << ": ";
        for(j = 0; j < n; j++)
            cout << a[j] << " ";
    }

    cout << "\n\nSorted Array: ";
    for(i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}

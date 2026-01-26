#include <iostream>
using namespace std;

struct MinMax {
    int min;
    int max;
};

MinMax findMinMax(int arr[], int low, int high) {
    MinMax result, left, right;

    // Only one element
    if (low == high) {
        result.min = arr[low];
        result.max = arr[low];
        return result;
    }

    // Two elements
    if (high == low + 1) {
        if (arr[low] < arr[high]) {
            result.min = arr[low];
            result.max = arr[high];
        } else {
            result.min = arr[high];
            result.max = arr[low];
        }
        return result;
    }

    // More than two elements
    int mid = (low + high) / 2;

    left = findMinMax(arr, low, mid);
    right = findMinMax(arr, mid + 1, high);

    result.min = min(left.min, right.min);
    result.max = max(left.max, right.max);

    return result;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    MinMax ans = findMinMax(arr, 0, n - 1);

    cout << "\nMinimum = " << ans.min << endl;
    cout << "Maximum = " << ans.max << endl;

    return 0;
}

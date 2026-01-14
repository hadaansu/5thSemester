// fibonnaci
#include <iostream>
using namespace std;

int main() {
    int n;
    int a = 0, b = 1, c;

    cout << "Enter number of terms: ";
    cin >> n;

    cout << "Fibonacci Series: ";

    for (int i = 1; i <= n; i++) {
        if (i == 1) {
            cout << a << " ";
        } else if (i == 2) {
            cout << b << " ";
        } else {
            c = a + b;
            cout << c << " ";
            a = b;
            b = c;
        }
    }

    return 0;
}

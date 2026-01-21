//iterative fib
/*#include <iostream>
using namespace std;

long long fib_iterative(int n) {
    if (n <= 1)
        return n;

    long long a = 0, b = 1, c;
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    cout << "Fibonacci number is: " << fib_iterative(n) << endl;
    return 0;
}*/
#include <iostream>
using namespace std;

long long fib_recursive(int n) {
    if (n <= 1)
        return n;
    return fib_recursive(n - 1) + fib_recursive(n - 2);
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    cout << "Fibonacci number is: " << fib_recursive(n) << endl;
    return 0;
}


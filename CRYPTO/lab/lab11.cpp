#include <iostream>
using namespace std;

long long extendedGCD(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    long long x1, y1;
    long long gcd = extendedGCD(b, a % b, x1, y1);

    x = y1;
    y = x1 - (a / b) * y1;

    return gcd;
}

int main() {
    long long a, n, x, y;

    cout << "Enter a and n: ";
    cin >> a >> n;

    long long gcd = extendedGCD(a, n, x, y);

    cout << "gcd(" << a << ", " << n << ") = " << gcd << "\n";

    if (gcd == 1) {
        long long inverse = (x % n + n) % n;
        cout << "Multiplicative inverse of " << a << " mod " << n
             << " = " << inverse << "\n";
    } else {
        cout << "Multiplicative inverse does not exist\n";
    }

    return 0;
}
#include <iostream>
using namespace std;

long long normalize(long long x, long long n) {
    x %= n;
    if (x < 0) x += n;
    return x;
}

int main() {
    long long a, b, n;

    cout << "Enter a, b and n: ";
    cin >> a >> b >> n;

    if (n <= 0) {
        cout << "n must be positive\n";
        return 0;
    }

    long long A = normalize(a, n);
    long long B = normalize(b, n);

    cout << "(a + b) mod n = " << normalize(A + B, n) << "\n";
    cout << "(a - b) mod n = " << normalize(A - B, n) << "\n";
    cout << "(a * b) mod n = " << normalize(A * B, n) << "\n";

    // ? fixed broken lines
    cout << "Additive inverse of a in Z_" << n << " = " 
         << normalize(-A, n) << "\n";

    cout << "Additive inverse of b in Z_" << n << " = " 
         << normalize(-B, n) << "\n";

    return 0;
}
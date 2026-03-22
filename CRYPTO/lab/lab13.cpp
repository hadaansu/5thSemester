#include <iostream>
using namespace std;

long long gcdValue(long long a, long long b) {
    while (b != 0) {
        long long t = a % b;
        a = b;
        b = t;
    }
    return a;
}

long long powerMod(long long a, long long b, long long mod) {
    long long result = 1;
    a %= mod;

    while (b > 0) {
        if (b % 2 == 1) result = (result * a) % mod;
        a = (a * a) % mod;
        b /= 2;
    }

    return result;
}

long long phi(long long n) {
    long long result = n;

    for (long long p = 2; p * p <= n; p++) {
        if (n % p == 0) {
            while (n % p == 0) n /= p;
            result -= result / p;
        }
    }

    if (n > 1) result -= result / n;
    return result;
}

int main() {
    long long a, n;

    cout << "Enter a and n: ";
    cin >> a >> n;

    long long phiValue = phi(n);
    cout << "phi(" << n << ") = " << phiValue << "\n";

    if (gcdValue(a, n) == 1) {
        long long result = powerMod(a, phiValue, n);

        cout << "a^phi(n) mod n = " << result << "\n";

        if (result == 1) {
            cout << "Euler's theorem verified\n";
        } else {
            cout << "Euler’s theorem not verified\n";
        }
    } else {
        cout << "gcd(a, n) != 1, so Euler’s theorem is not applicable\n";
    }

    return 0;
}
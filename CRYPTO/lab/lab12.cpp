#include <iostream>
using namespace std;

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

bool fermatTest(long long n) {
    if (n < 4) return n == 2 || n == 3;

    int bases[] = {2, 3, 5, 7};
    for (int i = 0; i < 4; i++) {
        if (bases[i] >= n) continue;
        if (powerMod(bases[i], n - 1, n) != 1) return false;
    }

    return true;
}

bool millerRabin(long long n) {
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0) return false;

    long long d = n - 1;
    int s = 0;

    while (d % 2 == 0) {
        d /= 2;
        s++;
    }

    int bases[] = {2, 3, 5, 7, 11};
    for (int i = 0; i < 5; i++) {
        long long a = bases[i];
        if (a >= n) continue;

        long long x = powerMod(a, d, n);
        if (x == 1 || x == n - 1) continue;

        bool witness = true;
        for (int r = 1; r < s; r++) {
            x = (x * x) % n;
            if (x == n - 1) {
                witness = false;
                break;
            }
        }

        if (witness) return false;
    }

    return true;
}

int main() {
    long long n;

    cout << "Enter number: ";
    cin >> n;

    cout << "Fermat Test: ";
    if (fermatTest(n)) cout << "Probably Prime\n";
    else cout << "Composite\n";

    cout << "Miller-Rabin Test: ";
    if (millerRabin(n)) cout << "Probably Prime\n";
    else cout << "Composite\n";

    return 0;
}
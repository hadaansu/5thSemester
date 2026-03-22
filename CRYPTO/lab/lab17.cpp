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

long long modInverse(long long a, long long mod) {
    long long x, y;
    long long gcd = extendedGCD(a, mod, x, y);
    if (gcd != 1) return -1;
    return (x % mod + mod) % mod;
}

int main() {
    long long p, g, x, k, m;

    cout << "Enter prime p and primitive root g: ";
    cin >> p >> g;

    cout << "Enter private key x: ";
    cin >> x;

    cout << "Enter random key k: ";
    cin >> k;

    cout << "Enter message m (m < p): ";
    cin >> m;

    long long y = powerMod(g, x, p);

    long long c1 = powerMod(g, k, p);
    long long c2 = (m * powerMod(y, k, p)) % p;

    long long s = powerMod(c1, x, p);
    long long sInverse = modInverse(s, p);
    long long decrypted = (c2 * sInverse) % p;

    cout << "Public key (p, g, y) = (" << p << ", " << g << ", " << y << ")\n";
    cout << "Ciphertext (c1, c2) = (" << c1 << ", " << c2 << ")\n";
    cout << "Decrypted message = " << decrypted << "\n";

    return 0;
}
#include <iostream>
#include <string>
#include <cctype>
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
    long long p, q;
    cout << "Enter two prime numbers p and q: ";
    cin >> p >> q;

    long long n = p * q;
    long long phi = (p - 1) * (q - 1);

    if (n <= 25) {
        cout << "Choose larger primes so that n > 25\n";
        return 0;
    }

    long long e = 2;
    while (e < phi && gcdValue(e, phi) != 1) e++;

    long long d = modInverse(e, phi);

    cout << "Public key (e, n) = (" << e << ", " << n << ")\n";
    cout << "Private key (d, n) = (" << d << ", " << n << ")\n";

    cin.ignore();
    string message;
    cout << "Enter message in uppercase letters: ";
    getline(cin, message);

    cout << "Encrypted values: ";
    for (int i = 0; i < (int)message.length(); i++) {
        char ch = toupper(message[i]);

        if (ch == ' ') {
            cout << "/ ";
        } else if (ch >= 'A' && ch <= 'Z') {
            long long m = ch - 'A';
            long long c = powerMod(m, e, n);
            cout << c << " ";
        }
    }
    cout << "\n";

    cout << "Decrypted message: ";
    for (int i = 0; i < (int)message.length(); i++) {
        char ch = toupper(message[i]);

        if (ch == ' ') {
            cout << " ";
        } else if (ch >= 'A' && ch <= 'Z') {
            long long m = ch - 'A';
            long long c = powerMod(m, e, n);
            long long plain = powerMod(c, d, n);
            cout << char(plain + 'A');
        }
    }
    cout << "\n";

    return 0;
}
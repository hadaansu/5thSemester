//hill chipher
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// make number in range 0..25
int fix(int x) {
    x = x % 26;
    if (x < 0) x += 26;
    return x;
}

// gcd for key check
int gcd(int a, int b) {
    while (b != 0) {
        int t = a % b;
        a = b;
        b = t;
    }
    return a;
}

// find inverse of a (mod 26) by simple trial (beginner method)
int invMod26(int a) {
    a = fix(a);
    for (int x = 1; x < 26; x++) {
        if (fix(a * x) == 1) return x;
    }
    return -1; // no inverse
}

int main() {
    int a, b, c, d;
    cout << "Enter 2x2 key matrix (a b c d): ";
    cin >> a >> b >> c >> d;

    // reduce key values to 0..25
    a = fix(a); b = fix(b); c = fix(c); d = fix(d);

    // determinant
    int det = fix(a * d - b * c);

    // key check
    if (gcd(det, 26) != 1) {
        cout << "Invalid key! det has no inverse mod 26.\n";
        cout << "Try key: 3 3 2 5\n";
        return 0;
    }

    int detInv = invMod26(det);
    if (detInv == -1) {
        cout << "Inverse not found!\n";
        return 0;
    }

    // inverse key matrix K^-1 = detInv * adj(K) mod 26
    int ia = fix(detInv * d);
    int ib = fix(detInv * (-b));
    int ic = fix(detInv * (-c));
    int id = fix(detInv * a);

    cout << "\n1) Encrypt\n2) Decrypt\nChoose: ";
    int choice;
    cin >> choice;
    cin.ignore();

    cout << "Enter text: ";
    string text;
    getline(cin, text);

    // clean text: keep only letters, make uppercase
    string s = "";
    for (char ch : text) {
        if (isalpha((unsigned char)ch)) {
            s += (char)toupper((unsigned char)ch);
        }
    }

    // if encrypt and odd length -> pad X
    if (choice == 1 && (s.size() % 2 == 1)) s += "X";

    string result = "";

    // process 2 letters at a time
    for (int i = 0; i < (int)s.size(); i += 2) {
        int x = s[i] - 'A';
        int y = s[i + 1] - 'A';

        int r1, r2;

        if (choice == 1) {
            // Encrypt: C = K * P (mod 26)
            r1 = fix(a * x + b * y);
            r2 = fix(c * x + d * y);
        } else {
            // Decrypt: P = K^-1 * C (mod 26)
            r1 = fix(ia * x + ib * y);
            r2 = fix(ic * x + id * y);
        }

        result += (char)('A' + r1);
        result += (char)('A' + r2);
    }

    if (choice == 1)
        cout << "\nCiphertext: " << result << endl;
    else
        cout << "\nPlaintext: " << result << endl;

    return 0;
}


//otp cipher code
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int fix(int x) { x %= 26; if (x < 0) x += 26; return x; }

string cleanAZ(string s) {
    string t = "";
    for (char ch : s) {
        if (isalpha((unsigned char)ch)) t += (char)toupper((unsigned char)ch);
    }
    return t;
}

int main() {
    cout << "One-Time Pad (OTP)\n1) Encrypt\n2) Decrypt\nChoose: ";
    int choice;
    cin >> choice;
    cin.ignore();

    string text, key;
    cout << "Enter text: ";
    getline(cin, text);
    cout << "Enter key (same length as text): ";
    getline(cin, key);

    text = cleanAZ(text);
    key  = cleanAZ(key);

    if (text.empty() || key.empty()) {
        cout << "Text/Key cannot be empty (letters only).\n";
        return 0;
    }

    if (key.size() != text.size()) {
        cout << "OTP rule: Key length must be EXACTLY equal to text length.\n";
        cout << "Text length = " << text.size() << ", Key length = " << key.size() << "\n";
        return 0;
    }

    string result = "";
    for (int i = 0; i < (int)text.size(); i++) {
        int T = text[i] - 'A';
        int K = key[i]  - 'A';

        int out;
        if (choice == 1) out = fix(T + K);   // encrypt
        else             out = fix(T - K);   // decrypt

        result += (char)('A' + out);
    }

    if (choice == 1) cout << "\nCiphertext: " << result << "\n";
    else             cout << "\nPlaintext: "  << result << "\n";

    return 0;
}
//vernam cipher 
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

// Convert a byte to 8-bit binary string (e.g., 65 -> 01000001)
string bin8(unsigned char x) {
    string s = "";
    for (int i = 7; i >= 0; i--) {
        s += ((x >> i) & 1) ? '1' : '0';
    }
    return s;
}

int main() {
    cout << "Vernam Cipher (Binary XOR)\n";
    cout << "1) Encrypt\n2) Decrypt\nChoose: ";
    int choice;
    cin >> choice;
    cin.ignore();

    if (choice == 1) {
        string pt, key;
        cout << "Enter plaintext: ";
        getline(cin, pt);
        cout << "Enter key (same length): ";
        getline(cin, key);

        if (pt.size() != key.size()) {
            cout << "Error: Key length must equal plaintext length.\n";
            return 0;
        }

        cout << "\nStep-by-step XOR (8-bit):\n";
        cout << "P_char  P_bin       K_char  K_bin       C_bin\n";

        vector<int> cipherNums;

        for (int i = 0; i < (int)pt.size(); i++) {
            unsigned char P = (unsigned char)pt[i];
            unsigned char K = (unsigned char)key[i];
            unsigned char C = (unsigned char)(P ^ K);   // XOR

            cout << "  " << pt[i] << "     " << bin8(P)
                 << "   " << key[i] << "     " << bin8(K)
                 << "   " << bin8(C) << "\n";

            cipherNums.push_back((int)C); // store as number
        }

        cout << "\nCiphertext (numbers): ";
        for (int x : cipherNums) cout << x << " ";
        cout << "\n\n(Use these numbers for Decrypt option)\n";
    }
    else if (choice == 2) {
        cout << "Enter ciphertext numbers (space separated): ";
        string line;
        getline(cin, line);

        vector<int> cipherNums;
        stringstream ss(line);
        int val;
        while (ss >> val) cipherNums.push_back(val);

        string key;
        cout << "Enter key (same length as number count): ";
        getline(cin, key);

        if (key.size() != cipherNums.size()) {
            cout << "Error: Key length must equal number of cipher bytes.\n";
            cout << "Cipher bytes = " << cipherNums.size()
                 << ", Key length = " << key.size() << "\n";
            return 0;
        }

        cout << "\nStep-by-step XOR (8-bit):\n";
        cout << "C_num  C_bin       K_char  K_bin       P_bin\n";

        string pt = "";
        for (int i = 0; i < (int)cipherNums.size(); i++) {
            unsigned char C = (unsigned char)cipherNums[i];
            unsigned char K = (unsigned char)key[i];
            unsigned char P = (unsigned char)(C ^ K);   // XOR again

            cout << " " << (int)C << "    " << bin8(C)
                 << "   " << key[i] << "     " << bin8(K)
                 << "   " << bin8(P) << "\n";

            pt.push_back((char)P);
        }

        cout << "\nPlaintext: " << pt << "\n";
    }
    else {
        cout << "Invalid choice.\n";
    }

    return 0;
}
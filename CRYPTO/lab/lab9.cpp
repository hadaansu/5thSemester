#include <iostream>
 #include <string>
 using namespace std;

 int PC1[56] = {
 57,49,41,33,25,17,9,
1,58,50,42,34,26,18,
 10,2,59,51,43,35,27,
19,11,3,60,52,44,36,
 63,55,47,39,31,23,15,
 7,62,54,46,38,30,22,
 14,6,61,53,45,37,29,
 21,13,5,28,20,12,4
 };

 int PC2[48] = {
 14,17,11,24,1,5,
 3,28,15,6,21,10,
 23,19,12,4,26,8,
 16,7,27,20,13,2,
 41,52,31,37,47,55,
 30,40,51,45,33,48,
 44,49,39,56,34,53,
 46,42,50,36,29,32
 };

 int shifts[16] = {1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2,
};

 string permute(string input, int table[], int n) {
 string output = "";
 for (int i = 0; i < n; i++) {
 output += input[table[i]- 1];
 }
 return output;
 }

 string leftShift(string s, int count) {
 while (count--) {
 s = s.substr(1) + s[0];
 }
 return s;
 }

 int main() {
 string key64;
 int rounds;

 cout << "Enter 64-bit key: ";
 cin >> key64;
 cout << "Enter number of rounds to generate: ";
 cin >> rounds;

 if (key64.length() != 64 || rounds < 1 || rounds > 16) {
 cout << "Invalid input\n";
 return 0;
 }

 string key56 = permute(key64, PC1, 56);
 string C = key56.substr(0, 28);
 string D = key56.substr(28, 28);

 for (int i = 0; i < rounds; i++) {
 C = leftShift(C, shifts[i]);
 D = leftShift(D, shifts[i]);
string combined = C + D;
 string subkey = permute(combined, PC2, 48);

 cout << "Round " << i + 1 << " Subkey: " << subkey << "\n";
 }

 return 0;
}
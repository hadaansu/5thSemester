#include <iostream>
 #include <string>
 using namespace std;

 int main() {
 int S1[4][16] = {
 {14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7},
 {0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8},
 {4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0},
 {15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13}
 };

 string bits;
 cout << "Enter 6-bit input: ";
 cin >> bits;

 if (bits.length() != 6) {
 cout << "Invalid input\n";
 return 0;
 }

 int row = (bits[0]- '0') * 2 + (bits[5]- '0');
 int col = (bits[1]- '0') * 8 + (bits[2]- '0') * 4 + (bits
[3]- '0') * 2 + (bits[4]- '0');
 int value = S1[row][col];

 string output = "";
 for (int i = 3; i >= 0; i--) {
 output += char(((value >> i) & 1) + '0');
 }

 cout << "Row = " << row << "\n";
 cout << "Column = " << col << "\n";

cout << "Decimal Output = " << value << "\n";
cout << "4-bit Output = " << output << "\n";
return 0;
}
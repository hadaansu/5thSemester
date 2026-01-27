#include <bits/stdc++.h>
using namespace std;

string normalizeAZ(string s)
{
    string t = "";
    for (char ch : s)
    {
        if (isalpha((unsigned char)ch))
        {
            ch = toupper(ch);
            if (ch == 'J')
                ch = 'I';
            t += ch;
        }
    }
    return t;
}

void buildMatrix(string key, char m[5][5])
{
    bool used[26] = {0};
    used['J' - 'A'] = 1;
    key = normalizeAZ(key);

    string k = "";
    for (char ch : key)
        if (!used[ch - 'A'])
        {
            used[ch - 'A'] = 1;
            k += ch;
        }
            

    for (char ch = 'A'; ch <= 'Z'; ch++)
        if (!used[ch - 'A'])
        {
            used[ch - 'A'] = 1;
            k += ch;
        }

    int p = 0;
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            m[i][j] = k[p++];
}

void findPosition(char m[5][5], char ch, int &r, int &c)
{
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            if (m[i][j] == ch)
            {
                r = i;
                c = j;
                return;
            }
}

string makePairs(string p)
{
    p = normalizeAZ(p);
    string d = "";
    for (int i = 0; i < (int)p.size();)
    {
        char a = p[i];
        char b = (i + 1 < (int)p.size()) ? p[i + 1] : 'X';
        if (a == b)
        {
            d += a;
            d += 'X';
            i++;
        }
        else
        {
            d += a;
            d += b;
            i += 2;
        }
    }
    if (d.size() % 2 == 1)
        d += 'X';
    return d;
}

string playfair(string text, string key, bool enc)
{
    char m[5][5];
    buildMatrix(key, m);

    if (enc)
        text = makePairs(text);
    else
        text = normalizeAZ(text);

    string out = "";
    for (int i = 0; i < (int)text.size(); i += 2)
    {
        char a = text[i], b = text[i + 1];
        int r1, c1, r2, c2;
        findPosition(m, a, r1, c1);
        findPosition(m, b, r2, c2);

        if (r1 == r2)
        {
            out += m[r1][(c1 + (enc ? 1 : 4)) % 5];
            out += m[r2][(c2 + (enc ? 1 : 4)) % 5];
        }
        else if (c1 == c2)
        {
            out += m[(r1 + (enc ? 1 : 4)) % 5][c1];
            out += m[(r2 + (enc ? 1 : 4)) % 5][c2];
        }
        else
        {
            out += m[r1][c2];
            out += m[r2][c1];
        }
    }
    return out;
}

int main()
{
    string key, text;
    int choice;

	cout << "---Playfair Cipher---\n1. Encrypt\n2. Decrypt\nEnter your choice : ";
    cin >> choice;
    cin.ignore();
    
    if(choice !=1 && choice !=2)
    {
    	cout<< endl << "Invalid choice. Please try again.";
		exit(0);
	}

	cout << endl << "Enter key : ";
    getline(cin, key);
	
	for (char ch : key)
        if (!isalpha((unsigned char)ch))
        {
        	cout << endl
             	<< "Invalid key. Please try again.";
        	exit(0);	
		}
    
    cout << "Enter text : ";
    getline(cin, text);
	
	if (choice == 1)
        cout << endl << "Ciphertext : " << playfair(text, key, true);
    else if(choice == 2)
        cout << endl << "Plaintext : " << playfair(text, key, false);
			
    return 0;
}
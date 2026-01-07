#include<bits/stdc++.h>
using namespace std;
string normAZ(const string& s)
{
	string t;
	for(char ch:s)
	if(isalpha((unsigned char)ch)) t.push_back(toupper(ch));
	return t;
}
char sh(char ch, int k)
{   
	int x= ch-'A';
	x=(x+k)%26;
	return char('A'+x);
}
string encCaesar(string p ,int k)
{
	p=normAZ(p);
	k%=26;
	string c;
	for(char ch:p)
	c.push_back(sh(ch,k));
	return c;
	
}string decCaesar(string c,int k)
{
	c=normAZ(c);
	k%=26;
	string p;
	for(char ch:c)
	p.push_back(sh(ch,(26-k)%26));
	return p;
	
}
int main()
{
	string text;
	int key;
	cout<<"enter text:";
	getline(cin,text);
	cout<<"enter key:";
	cin>>key;
	string c=encCaesar(text,key);
	cout<<"cipher:"<<c<<"\n";
	cout<<"plain:"<<decCaesar(c,key)<<"\n";
}
	

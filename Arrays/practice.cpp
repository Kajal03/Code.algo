#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

bool f(string a, string b){
	return a>b;
}

int main()
{
	char a[] = {'a','b','c','\0'};
	char b[100];
	cout<<a;
	cout<<endl<<b; // prints garbage value

	char c[] = "hello" ;

	//if there are white spaces in your string then cin terminates if it encounter space, so in this case use getline

	char d[1000], e[1000];
	cin>>d;
	cout<<d<<endl;

	cin.getline(e,1000);
	cout<<e;

	//we can change the delimiter in cin.getline
	//cin>getline(array, size, delimiter)

	string f = "Hello World";
	string g("Hello World");
	for(int i =0;i<g.length();i++)
		cout<<g[i]<<"-";
	cout<<endl;

	string s;
	getline(cin, s);

	string s1[] = {"Apple", "Guava", "Banananana", "Orange"};
	for(int i = 0; i<4;i++)
		cout<<s1[i]<<endl;
	sort(s1, s1+4); // sorts in lexicographic order

	//we can override this by using compartive functtion

	sort(s1, s1+4, f);
	for(int i = 0; i<4;i++)
		cout<<s1[i]<<endl;

}
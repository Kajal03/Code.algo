#include<iostream>
#include"hash.h"
using namespace std;

int main()
{
	HashTable h(4);
	h.insert("Mango", 100);
	h.insert("Apple", 200);
	h.insert("Banana", 300);

	h.print();

/*	int* i = h.search("Mango");
	if(i==NULL)
		cout<<"Not found\n";
	else
		cout<<*i;
*/
}

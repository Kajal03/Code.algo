#include<iostream>
#include<string.h>
#include<cstring>
using namespace std;
int main()
{
	string s1, s2;
	cin>>s1>>s2;

	int i,j;
	int a[26]={0};
	for(i=0;i<s1.length();i++){
		a[s1[i]-97]+=1;
	}

	for(i=0;i<26;i++){
		cout<<a[i]<<" ";
	}
}
//Program to check whether given two strings are permutations of each other or not

#include<iostream>
#include<string.h>
#include<cstring>
using namespace std;
int main()
{
	string s1, s2;
	cin>>s1>>s2;

    if(s1.length()!=s2.length())
    {
        cout<<"Not Permutation";
        return 0;
    }

	int i,j;
	int a[26]={0};
	for(i=0;i<s1.length();i++){
		a[s1[i]-97]++;
	}

    //cout<<s1[4]-97;

	for(i=0;i<s2.length();i++){
		a[s2[i]-97]--;
	}

    for(i=0;i<26;i++){
        if(a[i]!=0){
            cout<<"Not permutation";
            break;
        }
    }
    if(i==26){
        cout<<"Permutation";
    }

}
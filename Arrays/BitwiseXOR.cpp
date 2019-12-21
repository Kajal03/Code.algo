#include<iostream>
#include<string>
using namespace std;
int main()
{
	int t,i;
	string c;
	cin>>t;
	char A[100],B[100],C[100];
	while(t--){
		cin>>A>>B;
		i=0;
		while(A[i]!='\0'){
			c = to_string((A[i]-'0') ^ (B[i] -'0'));
			C[i]=c[0];
			i++;
		}
		cout<<C<<endl;
	}
}
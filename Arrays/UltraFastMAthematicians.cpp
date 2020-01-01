#include<iostream>
#include<string>
using namespace std;
int main()
{
	int t,i;
	string c;
	cin>>t;
	
	while(t--){
        	string A,B,C;
		cin.ignore();
		cin>>A;
        	cin>>B;
		i=0;
		while(A[i]!='\0'){
			c = to_string((A[i]-'0') ^ (B[i] -'0'));
			C+=c[0];
			i++;
		}
		cout<<C<<endl;
	}
}

/*

Print the pyramid after taking an input n.
	 1
    123
   12345
  1234567
 123456789
1234567891011*/

#include<iostream>
using namespace std;
int main()
{
	int n,j=0;
	cin>>n;
	for(int i =1;i<=n;i++){
		
		for(j=1;j<=n-i;j++){
			cout<<" ";
		}

		for(j=1;j<=2*i -1;j++)
			cout<<j;
		
		cout<<endl;
		}
}

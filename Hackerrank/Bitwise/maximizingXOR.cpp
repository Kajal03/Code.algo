#include<iostream>
using namespace std;
int main()
{
	unsigned long long int i=1,a,b,pos;
	cin>>a>>b;
	a = a^b;
	while(a>0)
	{
		if(a&1==1)
		{
			pos = i;
			
		}	
		a = a>>1;
		i++;
	}
	
	a = ((~0) << pos);
	cout<<~a<<endl;

}

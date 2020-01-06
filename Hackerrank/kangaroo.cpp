#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	int x1,x2,v1,v2;
	float res;
	cin>>x1>>v1;
	cin>>x2>>v2;
	if(x1>x2 && v1>=v2)
		cout<<"NO";
	else if(x2>x1 && v2>=v2)
		cout<<"NO";
	else
	{
		for(i=0;i<100000;i++)
		{
			x1+=v1;
			x2+=v2;
				
		}
		if(i==100000)
			cout<<"NO";
		else
			cout<<"YES";
	}
}

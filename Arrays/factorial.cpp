#include<iostream>
using namespace std;
typedef unsigned long long ull;
int main()
{
	ull n,i,result=1;
	cin>>n;
	int j,count2=0,count5=0;

	for(i=n;i>1;i--){
		j=i;
		if(i%10==2)
		{
			count2++;
			j=i/10;
		}
		if(i%10==5)
		{
			count5++;
			j=i/10;
		}
		result*=j;
	}
	
	if(count2==count5){
		cout<<result;
		while(count5--){
			cout<<0;
		}
	}
	else{
		cout<<result*2;
		while(count5--){
			cout<<0;
		}
	}

}
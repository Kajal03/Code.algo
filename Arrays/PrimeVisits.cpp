#include<iostream>
#include<math.h>
using namespace std;

int main()
{
	int low, high, count,t,i,j;
	cin>>t;
	while(t--){
		cin>>low>>high;
		count=0;
		if(low<=2){
			count=1;
			low=3;
		}
		else if(low%2==0)
			low++;
		for(int j=low;j<=high;j+=2)  //not trying for even nos.
		{
			for(i=2;i<=sqrt(j);i++){
				if(j%i==0)
					break;
			}
			if(i>sqrt(j))
				count++;
			
		}
					
		cout<<count<<endl;
	}
}
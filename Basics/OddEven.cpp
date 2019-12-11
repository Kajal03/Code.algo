/*Due to an immense rise in Pollution, Kejriwal is back with the Odd and Even Rule in Delhi.
The scheme is as follows, each car will be allowed to run on Sunday if 
the sum of digits which are even is divisible by 4 or sum of digits which are
 odd in that number is divisible by 3. However to check every car for the above criteria
  can't be done by the Delhi Police. You need to help Delhi Police by finding out if a car
   numbered N will be allowed to run on Sunday?*/

#include<iostream>
using namespace std;
int main()
{
	int N,i,sum,oddSum,evenSum;
	long long car;
	cin>>N;
	while(N--){
		cin>>car;
		oddSum=evenSum=sum=0;

		while(car>0){
			sum =car%10;
			car/=10;
			if(sum&1)
				oddSum+=sum;
			else
				evenSum+=sum;
		}
		if(oddSum%3 == 0 || evenSum%4 == 0)
			cout<<"Yes\n";
		else
			cout<<"No\n";
		
	}
}
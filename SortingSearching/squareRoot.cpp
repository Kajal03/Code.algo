#include<iostream>
using namespace std;

float squareRoot(int n, int p){
	float ans,inc=0.1;
	int start=1,end=n-1,mid,i;

	//For calculating integer part
	while(start<=end){
		mid=(start+end)/2;
		if(mid*mid == n){   //if we found the exact integer part
			ans= mid;  //we will make this answer and return it
			break;
		}
		if(mid*mid<n){
			ans=mid;    //if square of a no. is less then required, we save it for later
			end=mid-1;
		}
		else
			start=mid+1;   //if sqaure of a no. is greater then we will just move in the left part
	}


	//for fractional part
	for(i=0;i<p;i++){   //since we have to calculate for a precision of p places 
		while(ans*ans<=n){  
			ans+=inc;   
		}
		ans-=inc;   //as when we move out of while loop we have overshoot the no. so we will come back by one place
		inc/=10;  //we will increment our answer by 0.1 in first iteration than 0.01 in secon and so on
	}
	return ans;
}

int main()
{
	int n,p;
	float ans;

	cin>>n>>p;
	ans = squareRoot(n,p);
	cout<<ans;
}
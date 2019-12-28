//Every number occurs thrice except one number which occurs once. We have to find this number
#include<iostream>
using namespace std;
int main()
{
	int n,a[100005],i,j,count[64]={0},num,ans=0;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>num;
		j=0;
		while(num>0){
			count[j]+=(num&1);  //add the number of set bits at each place
			j++;
			num=num>>1;
		}
	}

	j=1;
	for(i=0;i<64;i++)
	{
		count[i]%=3;  //numbers occuring thrice will add to each place 
						//thrice so we will take mod 3 so that those numbers will be deleted
		ans+=count[i]*j; //now convert binary number into decimal number
		j=j<<1;
	}
	cout<<ans;
}
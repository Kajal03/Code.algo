#include<iostream>
#include<string.h>
#include<cstring>
using namespace std;
int main()
{
int t;
cin>>t;
while(t--)
{
	int n,count=0,i,size;
	char input[100005],ans[100005];
	memset(ans,0,sizeof(ans));
	cin>>n;
	cin>>input;
	strcpy(ans,input);
	n--;
	while(n--)
	{
		strcat(ans,input);
	}
	
	size = sizeof(ans);
	
	for(i=0;i<size-1;i++)
	{
		if(ans[i] == 'S' && ans[i+1] == 'S')
			count++;
	}
	cout<<count<<endl;
}
}


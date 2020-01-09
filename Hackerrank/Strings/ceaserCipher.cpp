#include<iostream>
#include<string>
using namespace std;

int main()
{
	int n,k,i;
	string a;
	cin>>n;
	cin>>a;
	cin>>k;
	k=k%26;
	
	for(i=0;i<n;i++)
	{
		if(a[i]>='a' && a[i]<='z')
			if(a[i]+k<='z')
				a[i]=a[i]+k;
			else
				a[i]=((a[i]+k)%122)+96;
		if(a[i]>='A' && a[i]<='Z')
			if(a[i]+k<='Z')
				a[i]=a[i]+k;
			else
				a[i]=((a[i]+k)%90)+64;
	}
	cout<<a<<endl;

}


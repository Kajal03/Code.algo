#include<iostream>
#include<string>
using namespace std;

bool checkSpecial(char a)
{
	string b = "!@#$%^&*()-+";
	int i;	
	for(i=0;b[i]!='\0';i++)
		if(b[i]==a)
			return true;
	
	return false;
}

int main()
{
	int n,i,lower=1,upper=1,number=1,special=1,count=0,res;
	string a;
	cin>>n;
	cin>>a;

	for(i=0;i<n;i++)
	{
		if(a[i]>='a' && a[i]<='z')
			lower--;

		else if(a[i]>='A' && a[i]<='Z')
			upper--;

		else if(a[i]>='0' && a[i]<='9')	
			number--;

		else if(checkSpecial(a[i]))
			special--;
		
	}
	if(lower>=1)
		count++;
	if(upper>=1)
		count++;
	if(number>=1)
		count++;
	if(special>=1)
		count++;
	

	if(count+n<6)
		cout<<6-n<<endl;
		
	else
		cout<<count<<endl;
	
}

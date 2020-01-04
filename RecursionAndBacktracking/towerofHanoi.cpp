#include<iostream>
using namespace std;

void towerofHanoi(int n, char source, char helper, char destination)
{
	if(n==0)
		return;
	towerofHanoi(n-1,source,destination,helper);
	cout<<"Move "<<n<<" from "<<source<<" to "<<destination<<endl;
	towerofHanoi(n-1,helper,source,destination);
}

int main()
{
int n;
cin>>n;
towerofHanoi(n,'A','B','C');
}

#include<iostream>
#include<bitset>
using namespace std;

bitset<30> col,d1,d2;

//d1 for principal diagonal where row-col is always the same, here we added n-1 because this value could otherwise become negative
//d2 for other diagonal where row+col is always the same

void solvenQueen(int i, int n, int &ans)
{
	if(i==n)
	{
		ans++;
		return;
	}

	for(int j=0;j<n;j++)
	{
		if(!col[j] && !d1[i-j+n-1] && !d2[i+j])
		{
			col[j] = d1[i-j+n-1] = d2[i+j] = 1;
			solvenQueen(i+1,n,ans);
			col[j] = d1[i-j+n-1] = d2[i+j] = 0;
		}	
	}

}

int main()
{
	int n,ans=0;
	cin>>n;
	solvenQueen(0,n,ans);
	cout<<ans<<endl;
}

/*
Piyush is lost in a magical park which contains N rows and M columns.In order to get out of park safely and return home, he needs atleast K amount of strength.Given a N by M pattern, your task is to find weather Piyush can ever escape the park.
The pattern consisits of '.' , * and '#'.Intially the strength is S and if Piyush encounters * , strength increases by 5.If he encounters '.', strength decreases by 2.Please note that Piyush can only walk row wise, so he starts from left of a row and moves towards right and he does this for every row. If he encounters '#', this means that the row is blcked and he cannot move forward. Also while moving in a row, Piyush requires strength of 1 for every step and strength should always be positive for moving forward.
Assume that Piyush can shift immediately from last of one row to the start of next one without loss of any strength, help out Piyush to escape the park.

Input Format:
Four space separated integers N, M, K and S all lie between 0 and 100. Next N lines contains M space separated characters which can be '.', '*' or '#'.
Output Format
Print "Yes" or "No" depending on whether Piyush can escape or not. If the answer is "Yes", also print the maximum strength that he can gather in the park in a new line.

Sample Input
4 4 5 20
. . * .
. # . .
* * . .
. # * *
Sample Output
Yes
13

*/


#include<iostream>
using namespace std;
int main()
{
	int n,m,k,s,i,j,flag=0;
	char A[100][100];
	cin>>n>>m>>k>>s;
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			cin>>A[i][j];
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(i==0 && j==0)
				continue;
			if(s<=0)
			{
				flag=1;
				break;
			}
			
			else if(A[i][j]=='.')
				s-=3;
			else if(A[i][j]=='*')
				s+=4;
			else if(A[i][j]=='#' && i==n-1)
			{
				s--;
				break;
			}
			else if(A[i][j]=='#')
				break;
			
				
		}
		if(flag)
			break;
	}	

	(s>=k) ? cout<<"Yes\n"<<s<<endl: cout<<"No";

}

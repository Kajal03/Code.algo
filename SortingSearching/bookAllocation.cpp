#include<iostream>
using namespace std;
#define ll long long int


bool isValid(ll *books,ll book_num, ll mid, ll students)
{
	ll s=1,currentPages=0,i;
	for(i=0;i<book_num;i++)
	{
		if(currentPages+books[i]<=mid)
		{
			currentPages+=books[i];
		}
		else
		{
			s++;
			currentPages=books[i];
			if(s>students)
				return false;
		}
	}
	return true;
	
}

ll binarySearch(ll *books, ll start, ll end, ll students, ll book_num)
{

	ll mid, finalAns=start;
	while(start<=end)
	{
		mid = (start+end)/2;
		if(isValid(books, book_num,mid,students))
		{
			finalAns=mid;
			end=mid-1;
		}
		else
			start=mid+1;

	}
	return finalAns;
}


int main()
{
int t;
cin>>t;
while(t--){
	ll students, book_num,i,total_pages=0,start,end;
	cin>>book_num>>students;
	ll books[book_num];
	
	for(i=0;i<book_num;i++)
	{
		cin>>books[i];
		total_pages+=books[i];
	}
	
	start=books[0];
	end=total_pages;
	
	cout<<binarySearch(books,start,end,students,book_num)<<endl;
	}

}

/*There are n circles arranged on x-y plane. All of them have their centers on x-axis. You have to remove some of them, such that no two circles are overlapping after that. Find the minimum number of circles that need to be removed.

Input Format
First line contains a single integer, n, denoting the number of circles. Next line contains two integers, c and r each, denoting the circle with radius r and center, (c,0).

Constraints
1<=n<=10^5 |c|<=10^9 1<=r<=10^9

Output Format
Print a single integer denoting the answer.

Sample Input
4
1 1
2 1
3 1
4 1
Sample Output
2
Explanation
We can remove 1st and 3rd circle, or 2nd and 4th circle.

*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;

bool compare(pair<int, int> p1, pair<int,int> p2)
{
	return p1.second < p2.second;
}

int main()
{
	int n, centre, radius, start, end, result =0;
	cin>>n;
	
	vector<pair<int, int >> v;
	for(int i=0;i<n;i++)
	{
		cin>>centre>>radius;
		start = centre - radius;
		end = centre + radius;
		v.push_back(make_pair(start, end));
	}
	
	sort(v.begin(), v.end(), compare);

	end = v[0].second;
	for(int i=1;i<n;i++)
	{
		if(v[i].first>=end)
		{
			end = v[i].second;
		}
		else
		{
			result++;
		}
	}
	
	cout<<result<<endl;
	
}


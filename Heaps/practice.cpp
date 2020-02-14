
#include<bits/stdc++.h>
using namespace std;

class KthLargest {
private:
    int capacity;
    priority_queue<int, vector<int>, greater<int>> pq;

public:
    KthLargest(int k, vector<int>& nums) {
        capacity = k;
        for(auto num : nums){
            pq.push(num);
            if(pq.size() > capacity){
                pq.pop();
            }
        }
    }

    int add(int val) {
        pq.push(val);
        if(pq.size() > capacity){
            pq.pop();
        }
        return pq.top();
    }
    void print()
    {
	int n = pq.size();
        for(auto i=0;i<n;i++)
	{
		cout<<pq.top()<<" ";
		pq.pop();

	}
	cout<<endl;
    }
};

int main()
{
	int val, k =3;
	vector<int> nums;
	nums.push_back(6);
	nums.push_back(1);
	nums.push_back(3);
	KthLargest* obj = new KthLargest(k, nums);
	
		cin>>val;
 		cout<<obj->add(val)<<endl;
	obj->print();
}

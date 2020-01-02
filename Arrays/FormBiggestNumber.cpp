/*You are provided an array of numbers. You need to arrange them in a way that yields the largest value.
Sample Input
1
4
54 546 548 60
Sample Output
6054854654
*/
#include <iostream>
#include<vector>
#include<string.h>
using namespace std;
int main() {
    int n,i,j,t;
    
    string temp;
	cin>>t;
	while(t--){
    cin>>n;
	vector<string>A;
	cin.ignore();
    for(i=0;i<n;i++)
    {
        cin>>temp;
        A.push_back(temp);
    }
    for(i=0;i<n;i++){
        for(j=0;j<n-1;j++)
        if(stoi(A[j+1]+A[j])>stoi(A[j]+A[j+1]))
            swap(A[j],A[j+1]);
    }
    for(i=0;i<n;i++){
        cout<<A[i];
    }
	cout<<endl;
	}
}

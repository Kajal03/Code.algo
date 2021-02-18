#include<iostream>
#include<stack>
using namespace std;

void insertAtBottom(stack<int> &s, int temp)
{
    if(s.size()==0){
        s.push(temp);
        return;
    }
    int t = s.top();
    s.pop();
    insertAtBottom(s,temp);
    s.push(t);
}
void reverse(stack<int> &s)
{
    if(s.size()==1)
        return;
    int temp = s.top();
    s.pop();
    reverse(s);
    insertAtBottom(s,temp);
}

int main()
{
    stack<int> s;
    for(int i=0;i<4;i++)
        s.push(i);

    reverse(s);

    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}

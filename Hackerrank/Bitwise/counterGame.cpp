#include<iostream>
using namespace std;
#define ll long long
int main()
{
    int t;
    cin>>t;
    while(t--)
    {    
        ll num=0,count=0,a=0,pos,i=0,mask;
        cin>>num;
	if(__pop_count(num)==1)
	{
		while(num>0)
		{
                if(a&1==1)
                    pos=i;
                i++;
                a = a>>1;
            }
	}
        while(num>=1)
        {
            i=0;
            a = num;
            while(a>0)
            {
                if(a&1==1)
                    pos=i;
                i++;
                a = a>>1;
            }
            mask = 1<<pos;
            if(num==mask)
                num = num>>1;
            else
                num=num-mask;
            count++;

        
        }
        count%2==1? cout<<"Richard\n":cout<<"Louise\n";
    }
}


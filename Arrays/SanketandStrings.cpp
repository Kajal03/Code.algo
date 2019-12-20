/* Sanket has a string consisting of only 'a' and 'b' as the characters. 
Sanket describes perfectness of a string as the maximum length substring of 
equal characters. Sanket is given a number k which denotes the maximum number 
of characters he can change. Find the maximum perfectness he can generate by 
changing no more than k characters.
*/

#include<iostream>
using namespace std;

int findMax(char *A,char d, int k1){
	
	int i=0, j, diff=0, max=0,k; 

	while(A[i]!='\0'){
		k=k1;
		j=i;  //start from ith index and move forward untill you can flip or you are encountering the same character
		while(A[j]!='\0'){
			if(k>0 && A[j]!=d)   //if the character is not same then we can flip it thus reducing the value for each flip
				k--;
			else if(k==0 && A[j]!=d)  //if no more flips can be done and the character is different from the one we are trying to make
			{
				diff = j-i;    //we stop and find the value of string made by subtracting the starting index and ending index
				if(diff>max)
					max=diff;
				break;
			
			}
			j++;			
		}
		if(A[j]=='\0')  //if we reach end and hence thrown out of the above loops then calculating the length of our string
		{
			diff = j-i;
			if(diff>max)
					max=diff;
		}
		i++;
	}
	return max;
}

int main()
{
	int k;
	char A[100];

	cin>>k;
	cin>>A;

	int a = findMax(A,'a',k);  //check max when making the string of 'a's
	int b = findMax(A,'b',k);  //check max when making the string of 'b's

	cout<<max(a,b);
}
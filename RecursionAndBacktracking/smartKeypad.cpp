#include<iostream>
#include<vector>
using namespace std;

string table[] = { " ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };

string searchIn [] = {
            "prateek", "sneha", "deepak", "arnav", "shikha", "palak",
            "utkarsh", "divyam", "vidhi", "sparsh", "akku"
    };

void findNames(vector<string> result)
{
	for(int j=0;j<result.size();j++)
	{
		for(int i=0;i<11;i++)
		{
			int found = searchIn[i].find(result[j]); 
	    		if (found != string::npos) 
				cout<<searchIn[i]<<endl;
		}
	}
}

void smartKeypad(char input[], char output[], int i, int j, vector<string> &result)
{
	if(input[i]=='\0')
	{
		output[j]='\0';
		result.push_back(output);
		return;
	}

	int digit = input[i] - '0';

	for(int k=0;table[digit][k]!='\0';k++)
	{
		output[j]=table[digit][k];
		smartKeypad(input, output,i+1,j+1, result);
	}

}

int main()
{
	char input[100], output[100];
	cin>>input;
	vector<string> result;
	smartKeypad(input,output,0,0, result);
	findNames(result);
	 
}

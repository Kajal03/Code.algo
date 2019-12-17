#include<iostream>
#include<cstring>
using namespace std;
char* mystrtok(char* input, char delim){
	static char* myString = NULL;
	if(input!=NULL){
		myString = input;
	}
	 if(myString==NULL){
	 	return NULL;
	 }

	char *output = new char[strlen(myString)+1];  //+1 for numm character
	int i;
	for( i=0;myString[i]!='\0';i++)
	{
		if(myString[i]!=delim)
			output[i] = myString[i];

		else
		{
			output[i] = '\0';
			myString = myString + i+ 1;
			return output;
		}
	}

	output[i] = '\0'; // for the last word when deliminater was not accounted
	myString = NULL;  //make input NULL for next iteration of while loop
	return output;
	


}

int main()
{
	char str[] = "Hello, my name is Kajal-Gupta !";
	char *ptr;
/*
	ptr = strtok(str," ");  //takes the string and a list of dilimiters

	while(ptr!=NULL){
		cout<<ptr<<endl;
		ptr = strtok(NULL," ");   //strtok contains a static variable that stores the previous state of the string passed
									//so we do not need to send it again again.
	}
*/
	ptr = mystrtok(str,' ');
	cout<<ptr<<endl;
	while(ptr !=NULL)
	{
		ptr = mystrtok(NULL,' ');
		cout<<ptr<<endl;
	}
}
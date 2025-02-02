#include <bits/stdc++.h>
using namespace std;
/*
We have to replace all spaces by %20
str is the character string which is buffered space in the end to accomodate the extra characters
length is the length of the original string
*/
void replace_spaces(char * str, int length)
{
	//first we calculate length of the final string
	int space_count = 0;
	for(int i=0;i<length;i++)
	{
		if(str[i] == ' ')
		{
			space_count++;
		}
	}
	//for each space ' ' we replace by '%20'
	//so 2 more bytes are used
	//now we calculate final length of th string
	// we do 2*space_count instead of 3*space_count because 'length' already has the count of 1 space
	int final_length = length + 2*space_count;
	
	str[final_length] = '\0'; //add null character at the end of the final string
	final_length--;
	for(int i=length-1;i>=0;i--)
	{
		if(str[i] == ' ')
		{
			str[final_length] = '0';
			final_length--;
			str[final_length] = '2';
			final_length--;
			str[final_length] = '%';
			final_length--;
		}
		else
		{
			str[final_length] = str[i];
			final_length--;
		}
	}
}

int main()
{
	char a[20] = "Mr John Smith";
	printf("%s\n",a);
	replace_spaces(a,13);
	printf("%s\n",a);
	return 0;
}

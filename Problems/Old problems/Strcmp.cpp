#include <iostream>

#include <cstring>

using namespace std;

char first_characters[1000100];

char second_characters[1000100];

char checker[1000100];

int main()
{
	cin>>first_characters>>second_characters;
	int n=strlen(first_characters);
	int l=strlen(second_characters);
	int level=min(n,l);
	for(int number=0; number<level; number++)
	{
		if(first_characters[number]<second_characters[number])
		{
			cout<<1<<endl;
			break;
		}
		if(first_characters[number]>second_characters[number])
		{
			cout<<-1<<endl;
			break;
		}
		if(number==level-1)
		{
			if(n==l)
			{
				cout<<0<<endl;
			}
			if(n>l)
			{
				cout<<-1<<endl;
			}
			if(n<l)
			{
				cout<<1<<endl;
			}
		}
	}
}

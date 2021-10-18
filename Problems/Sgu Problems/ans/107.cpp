/*tedud adud n raghami ke agar be tavane
  2 beresand akhareshoon 987654321 bashe.*/
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

/*
const int MAX = 1e+9;
int a[20];

void why_5_9 ( )
{
	int k = 0;
	//5
	k = 0;
	for(long long  i = 1e+4+1,flag = 0; i < 1e+5; flag++)
	{
		if(i*i % MAX == 987654321)
			k++;
		if(flag % 2 == 0)
			i += 8;
		if(flag % 2 == 1)
			i += 2;
	}
	a[5] = k;
	
	//6
	k = 0;
	for(long long i = 1e+5+1,flag = 0; i < 1e+6; flag++)
	{
		if(i*i % MAX == 987654321)
			k++;
		if(flag % 2 == 0)
			i += 8;
		if(flag % 2 == 1)
			i += 2;
	}
	a[6] = k;
		
	//7
	k = 0;
	for(long long i = 1e+6+1,flag = 0; i < 1e+7; flag++)
	{
		if(i*i % MAX == 987654321)
			k++;
		if(flag % 2 == 0)
			i += 8;
		if(flag % 2 == 1)
			i += 2;
	}
	a[7] = k;
		
	//8
	k = 0;
	for(long long i = 1e+7+1,flag = 0; i < 1e+8; flag++)
	{
		if(i*i % MAX == 987654321)
			k++;
		if(flag % 2 == 0)
			i += 8;
		if(flag % 2 == 1)
			i += 2;
	}
	a[8] = k;
		
	//9
	k = 0;
	for(long long i = 1e+8+1,flag = 0; i < 1e+9; flag++)
	{
		if((i*i) % MAX == 987654321)
			k++;
		if(flag % 2 == 0)
			i += 8;
		if(flag % 2 == 1)
			i += 2;
	}
	a[9] = k;
}

void print ()
{
	for(int i=5; i<10; i++)
		cerr << a[i] << " ";
	cerr << endl;
}
*/

int main()
{
	int n;
	cin >> n;

	//why_5_9();
	//print ();	

	if( n < 9 )
		cout << 0 << endl;
	if( n == 9 )
		cout << 8 << endl;
	if( n > 9 )
	{
		cout << 72;
		for(int i=n-10; i>0; i--)
			cout << 0;
		cout << endl;
	}
}

#include <iostream>
#include <vector>

using namespace std;


const int MAX = 10000000;

vector < int > a;
vector < int > a2;
bool b [MAX];
vector < int > adud_aval;



void chup( vector < int > p ,int n )
{
	for(int i = 0 ; i < n; i++)
		cout << p[i] << " " ;
	cout << endl;
}

void gharbal( int n )
{
	b[0] = 1;
	b[1] = 1;
	for(int i = 2; i*i <= n; i++)
		if( b[i] == 0)
		{
			adud_aval.push_back( i );
			b[i] = 1;
			for(int j = i+i; j*j <= n; j += i)
				b[j] = 1;
		}
}

void tagzie( int n )
{
	int k=0; 
	for(int i = 0; i < adud_aval.size(); i++)
		if(n % adud_aval[i] == 0)
		{
			k=0;
			a.push_back( adud_aval[i] );

			while( n % adud_aval[i] == 0)
			{
				n /= adud_aval[i];
				k++;
			}

			a2.push_back(k);

			if(n == 1)
				break;
		}
}

int main()
{
	int n;
	cin >> n;
	gharbal( n );
	tagzie( n );
	chup( a, a.size());
	chup( a2, a2.size());
}

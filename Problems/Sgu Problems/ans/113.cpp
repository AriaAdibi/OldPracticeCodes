/* 113:
   adad nearly prime:
   agar betavan 2 adad aval peida kard mesl p1,p2 ke p1* p2 = adademoon.
   voroodi:
   aval n ro mide 1 <= n <= 10 ke tedade adadaye voroodie.
   bad n ta adad mide.
   khorooji:
   be tartib bayad begim nearly prime ast ya na ba "Yes" va "No".
   */
#include <iostream>
#include <vector>

using namespace std;

const int MAX = 1e+5;
vector < int > prime_numbers;
vector < int > a;
int c [ 10 ];
bool b [ MAX ];

void  input ( int n )
{
	for( int i = 0, x; i < n; i ++)
	{
		cin >> x;
		a.push_back ( x );
	}
}

void output( vector < int > g, int  l )
{
	for( int i = 0; i < l; i ++)
		cerr << g[i] << " ";
	cerr << endl;
}

/*int find_max ( vector <int > a, int n )
{
	int Max = 0;
	for ( int  i = 0; i < n; i++)
		if ( Max < a[ i ] )
			Max = a[i];
	return Max;
}*/

void gharbal ( )
{
	b[0] = 1;
	b[1] = 1;
	for( int i = 0; i < MAX; i++)
		if( b[i] == 0 )
		{
			b[i] = 1;
			prime_numbers.push_back ( i );
			for( int j = i+i; j < MAX; j += i)
				b[j] = 1;
		}
}

bool checker ( int p)
{
	if( p == 1)
		return 0;
	if( p % 2 == 0 )
		return 0;
	else
	{
		for( int i = 3; i*i <= p; i += 2 )
			if ( p % i == 0 )
				return 0;
	}
	return 1;
}

void nearly_prime ( int n )
{
	int  k = 0;
	int  l = prime_numbers.size();
	for( int i = 0; i < n; i ++)
	{
		k = 0;
		for( int  j = 0 ; j < l; j ++ )
			if( a[i] % prime_numbers[j] == 0 )
			{
				c[ k++ ] = prime_numbers[ j ];
				if( k == 2 )
					break ;
			}
		if( k == 0 )
			cout << "No" << endl;//<< " " ;
		if( k == 1 )
		{
			if( a[i] == c[0] * c[0] )
				cout << "Yes" << endl ;//<< " " ;
			else 
			{
				int p;
				p = a[i] / c[0];
				if( checker( p ) )
				{	
					cout << "Yes" << endl;// << " ";
				}
				else
					cout << "No" << endl;// << " ";
			}
		}
		if ( k == 2 )
		{
			if( a[i] == c[0] * c[1] )
				cout << "Yes" << endl;//<< " ";
			else 
				cout << "No" << endl;//<< " ";
		}

	}
	//cout << endl;
}

int main()
{
	int n;
	cin >> n;
	input ( n );

	//int Max = find_max( a, n );

	gharbal ( );


	nearly_prime( n );
}

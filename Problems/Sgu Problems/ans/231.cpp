#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

const int MAX = 1e+6 + 100;
bool t [ MAX ];
vector < long long > prime_number;
vector < long long > ans;

void gharbal( int n )
{
	t[0] = 1; 
	t[1] = 1;
	for ( int i = 0; i <= n; i ++ )
		if ( t [i] == 0 )
		{
			prime_number.push_back( i );
			for ( int j = i + i; j <= n; j += i )
				t[j] = 1;
		}
}

long long find_ans( int n )
{
	long long l = 0;
	long long k = prime_number.size();
	for ( int i = 0; prime_number[i] < n - 1, i < k ; i++ )
		if ( prime_number[i] + 2 == prime_number[ i + 1 ] )
		{
			l++;
			ans.push_back( prime_number[i] );
		}
	return l;
}

void output( long long l )
{
	cout << l << endl;
	for ( int i = 0; i < l; i ++ )
		printf ( "%d %lld \n", 2, ans[i] );
}

int main()
{
	int n;
	cin >> n;
	gharbal( n );
	long long l = find_ans( n );
	output( l );
	return 0;
}

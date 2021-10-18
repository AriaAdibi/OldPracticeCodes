#include <iostream>
#include <vector>

using namespace std;

const int MAX = 1e+7;
bool t [ MAX ];
vector < int > a_pf;
vector < int > b_pf;

void pf_checker( int i, int a, int b )
{
	if ( a % i == 0 ) 
		a_pf.push_back( i );
	if ( b % i == 0 )
		b_pf.push_back( i );
}

void gharbal_and_find_prime_factors( int a, int b )
{
	t[0] = 1;
	t[1] = 1;
	for ( int i = 2; i < MAX; i++ )
		if ( t[i] == 0 )
		{
			pf_checker( i, a, b );
			for ( int j = i + i; j < MAX; j += i )
				t[j] = 1;
		}
}

pair < long long, long long >  find_key_number()
{
	pair < long long, long long > key;
	/// a:
	long long sum = 0;
	int l = a_pf.size() - 1;
	for ( int i = 0; i < l; i++ )
		sum += a_pf[i];
	key.first = a_pf[ l ] - sum;
	/// b:
	sum = 0;
	l = b_pf.size() - 1;
	for ( int i = 0; i < l; i ++ )
		sum += b_pf[i];
	key.second = b_pf[ l ] - sum;
	return key;
}

int main()
{
	int a, b;
	cin >> a >> b;
	gharbal_and_find_prime_factors ( a, b );
	pair < long long, long long > key = find_key_number();

	if ( key.first > key.second )
		cout << 'a' << endl;
	else
		cout << 'b' << endl;
}

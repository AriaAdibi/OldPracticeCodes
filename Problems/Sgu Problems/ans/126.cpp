/*126:
  2 ta jabas dar ahar kodam ye tedad toope
  bayad begim mishe hameye tooparo az yek jabe be oon yeki bord ya na
  harekat ine az ooni ke meghdare bishtari toop dare be andaze yi ke
  oon yeki toop dare bar midarim mirizim too oon yrki
  voroodi:
  n,m tedad toophaye 2 jabe (0 < n,m < 2147483648( 2* 2 ^ 31 )
  khorooji:
  agar nemishe -1
  agar mishe tedade harekate lazem*/
#include <iostream>

using namespace std;

const int MAX = 1000;
int ans = 0;

long long find_ans ( long long n, long long m )
{
	if( m == 0 || n == 0 )
		return ans;
	if( n == m )
	{
		ans ++;
		return ans;
	}

	if( ans > MAX )
		return -1;

	if ( n < m )
		return find_ans( m, n );

	if ( m < n )
	{
		ans++;
		return find_ans( (n - m), (m + m) );
	}
}

int main()
{
	long long n, m;
	cin >> n >> m;

	cout << find_ans ( n, m ) << endl;
}

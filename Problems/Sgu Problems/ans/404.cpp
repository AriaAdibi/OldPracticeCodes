#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector < string > a;
string s;

void input ( int l )
{
	for ( int i = 0; i < l; i ++ )
	{
		cin >> s;
		a.push_back( s );
	}
}

void fortune_pridict_is ( int n, int m )
{
	int r = n % m;
	if ( r == 0 )
		r = m - 1;
	else
		r -= 1;
	cout << a[r] << endl;

}

int main()
{
	int n, m;
	cin >> n >> m;
	input( m );
	fortune_pridict_is( n, m );
}

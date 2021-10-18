#include <iostream>

using namespace std;

int find_ans( int s, int p )
{
	int dif = p - s;
	if ( dif < 1 )
		return 0;
	if ( dif > 0 && dif < 5 * 60 )
		return 1;
	if ( dif >= 5 * 60 && dif < 15 * 60 )
		return 2;
	if ( dif >= 15 * 60 && dif < 30 * 60 )
		return 3;
	if ( dif >= 30 * 60 )
		return 4;
}

int main()
{
	int s, p;
	cin >> s >> p;
	int ans = find_ans( s, p );
	cout << ans << endl;
}	

// red, yellow, green, brown, blue, pink, black.
#include <iostream>
#include <string>

using namespace std;

int a[ 10 ];
string s;

void input()
{
	for ( int i = 0; i < 7; i ++ )
		cin >> a[i];
	cin >> s;
}

int find_max_posible_score()
{
	int Max = 0;

	for ( int i = 6; i > 0; i-- )
		if ( a[i] == 1 )
			Max += i + 1;

	if ( a[0] == 0 )
	{
		if ( s == "RED" )
			Max += 7;
		return Max;
	}
	else
	{
		Max += a[0] * 8;
		if ( s == "RED" )
			Max += 7;
		return Max;

	}
}

int main()
{
	input();
	int Max = find_max_posible_score();
	cout << Max << endl;
}

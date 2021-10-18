#include <iostream>
#include <vector>
#include <string>

using namespace std;

string s;
vector < string > a;
string ans;

void erase_a( char t )
{
	int l = a.size();
	if ( t == 'U' )
	{
		for ( int i = l - 1; i > -1; i -- )
			if ( a[i] == "Up" )
			{
				a.erase( a.begin() + i );
				break;
			}
	}
	else
	{
		for ( int i = l - 1; i > -1; i -- )
			if ( a[i] == "Down" )
			{
				a.erase( a.begin() + i );
				break;
			}
	}
}

void correct_text( int l )
{
	a.push_back ( "0" );
	int k;
	int f;
	for ( int i = 0; i < l; i++ )
	{
		k = a.size() - 1;
		while ( s[i] != '<' && i < l )
		{
			if ( a[k] == "0" ) 
				ans += s[i];
			if ( a[k] == "Up" )
			{
				if ( s[i] > 96 )
					ans += s[i] - ( 'a' - 'A' );
				else
					ans += s[i];
			}
			if ( a[k] == "Down" )
			{
				if ( s[i] < 96 )
					ans += s[i] + ( 'a' - 'A' );
				else
					ans += s[i];
			}
			i++;
		}
		if ( i == l - 1 )
			break;
		f = i;
		if ( s[f + 1] == 'U' )
		{
			a.push_back( "Up" );
			i += 3;
		}
		if ( s[f + 1] == 'D' )
		{
			a.push_back( "Down" );
			i += 5;
		}
		if ( s[f + 1] == '/' && s[f + 2] == 'U' )
		{
			erase_a( 'U' );
			i += 4;
		}
		if ( s[f + 1] == '/' && s[f + 2] == 'D' )
		{
			erase_a( 'D' );
			i += 6;
		}
	}
}

int main()
{
	cin >> s;
	correct_text( s.size() );
	cout << ans << endl;
}

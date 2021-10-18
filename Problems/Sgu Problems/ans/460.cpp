#include <iostream>
#include <string>

using namespace std;

string s;

void change_to_plural_form( int n )
{
	int l;
	bool flag;
	for( int i = 0; i < n; i ++ )
	{
		cin >> s;
		l = s.size();
		flag = 0;
		if ( s[ l - 1 ] == 'o' || s[ l - 1 ] == 'x' || s[ l - 1 ] == 's' )
		{
			flag = 1;
			cout << s << "es" << endl;
		}
		if ( s[ l - 1 ] == 'h' && s[ l - 2 ] == 'c' )
		{
			flag = 1;
			cout << s << "es" << endl;
		}
		if ( s[ l - 1 ] == 'f' )
		{
			flag = 1;
			for ( int j = 0; j < l - 1; j ++ )
				cout << s[j];
			cout << "ves" << endl;
		}
		if ( s[ l - 1 ] == 'e' && s[ l - 2 ] == 'f')
		{
			flag = 1;
			for ( int j = 0; j < l - 2; j ++ )
				cout << s[j];
			cout << "ves" << endl;
		}
		if ( s[ l - 1 ] == 'y' ) 
		{
			flag = 1;
			for ( int j = 0; j < l - 1; j ++ )
				cout << s[j];
			cout << "ies" << endl;
		}
		if ( flag == 0 )
			cout << s << "s" << endl;
	}
}

int main()
{
	int n;
	cin >> n;
	change_to_plural_form( n );
}

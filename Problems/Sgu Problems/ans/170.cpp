#include <iostream>
#include <string>
#include <vector>

using namespace std;

string s1;
string s2;
vector < int > a;
vector < int > b;

bool is_posible() 
{
	if ( s1.length() != s2.size() )
		return 0;

	int l_s1 = 0;
	int l_s2 = 0;
	for ( int i = 0; i < s1.size(); i++ )
	{
		if ( s1[i] == '+' )
		{
			l_s1 ++;
			a.push_back( i );
		}
		if ( s2[i] == '+' )
		{
			l_s2 ++;
			b.push_back( i );
		}
	}

	if( l_s1 != l_s2 )
		return 0;
	return 1;
}

int find_minimal_k()
{
	int k = 0;
	int p = 0;
	for ( int i = 0; i < a.size(); i++ )
	{
		p = a[i] - b[i];
		if ( p < 0 )
			k -= p;
		else	
			k += p;
	}
	return k;
}

int main()
{
	cin >> s1 >> s2;
	if ( is_posible() == 0 )
		cout << -1 << endl;

	else
		cout << find_minimal_k() << endl;
	return 0;
}

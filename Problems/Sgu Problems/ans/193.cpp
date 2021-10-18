#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int MAX = 4000;
string s;
vector < int > n;
vector < int > m;
int p [ MAX ];

void input( int l )
{
	for ( int i = 0; i < l; i++ )
		n.push_back( s[i] - '0' );
}

void insert( int t, int k )
{
	if ( t > 9 )
	{
		m.push_back( t % 10 );
		t /= 10;
		m.push_back( t );
		swap( m[0], m[1] );
	}
	else
		m.push_back( t );
	for ( int i = 0; i < k; i ++ )
		m.push_back( 0 );
}

int find_size( int p[] )
{
	int i = MAX - 1;
	while ( i > -1 )
		if ( p[i--] != 0 )
			break;
	return i + 2;
}

void normalize()
{
	int l = find_size( p );
	for ( int i = 0; i < l; i ++ )
	{
		while ( p[i] > 9 )
		{
			p[i] -= 10;
			p[i + 1] ++;
		}
		if ( p[l] > 0 )
			l++;
	}
}

void my_plus( int p[], vector < int > m )
{
	int l = m.size();
	for ( int i = l - 1, j = 0; i > -1; i --, j++ )
		p[j] += m[i];
	normalize();
}

void find_p( int l )
{
	int k = l - 2;
	for ( int i = 0; i < l - 1; i++, k-- )
	{
		m.resize( 0 );
		insert( 5 * n[i], k );
		my_plus( p, m );
	}
	m.resize( 0 );
	insert( n[ l - 1 ] / 2, 0 );
	my_plus( p, m );
}

void output( int p[] )
{
	int l = find_size( p );
	for ( int i = l - 1; i > -1; i-- )
		cout << p[i];
	cout << endl;
}

bool f2( vector < int > n )
{
	int l = n.size();
	if ( n[l - 1] % 2 )
		return 1;
	else
		return 0;
}

bool f4( vector < int > n )
{
	int l = n.size();
	if ( l < 2 )
	{
		if ( n[l - 1] % 4 == 0 )
			return 0;
		else
			return 1;
	}
	int t = n[l - 2] * 10 + n[l - 1];
	if ( t % 4 == 0 )
		return 0;
	else
		return 1;
}

void my_minus( int p[], int r )
{
	int l = find_size( p );
	p[0] -= r;
	bool flag;
	for ( int i = 0; i < l; i++ )
	{
		flag = 0;
		while( p[i] < 0 )
		{
			flag = 1;
			p[i + 1] --;
			p[i] += 10;
		}
		if ( flag == 0 )
			break;
	}
}

int main()
{
	cin >> s;
	input( s.size() );
	//p = n / 2
	find_p( n.size() );
	if ( f2( n ) )
		output( p );
	else
	{
		if( f4( n ) )
		{
			my_minus( p, 2 );
			output( p );
		}
		else
		{	
			my_minus( p, 1 );
			output( p );
		}
	}
}

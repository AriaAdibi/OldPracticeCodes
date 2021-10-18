/*
   moraje shavad be tamrin pair shaazzz
   */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector < pair < double, pair < int, long long > > > a;
vector < pair < int, long long > > p;
pair < double, pair < int, long long > > b;
pair < int, long long > c;

void input ( int n )
{
	double h;
	int w;
	long long num;
	for( int i = 0; i < n; i ++ )
	{
		cin >> num >> h >> w;
		c = make_pair( w, num );
		b = make_pair( h, c );
		a.push_back ( b );
	}
}

void output( int n )
{
	for( int i = 0; i < n; i ++ )
		cout << a[i].second.second << " ";
	cout << endl;
}

void sort_weigh_in_decrease_order( int start, int end )
{
	int k = end;
	int s = end;

	for( int i = end; i > start - 1; i-- )
	{
		if(  a[i].second.first == a[i - 1].second.first && (i - 1) > start - 1 )
		{
			while( a[i].second.first == a[i - 1].second.first && (i - 1) > start - 1 )
				i--;
			k = i - 1;
			while( i <= s )
			{
				c = make_pair( a[i].second.first, a[i].second.second );
				p.push_back( c );
				i++;
			}
			s = k;
		}

		else
		{
			c = make_pair( a[i].second.first, a[i].second.second );
			p.push_back( c );
			k--;
			s = k;
		}
	}
	
	for( int i = start; i < end + 1; i++ )
	{
		a[i].second.first = p[i].first;
		a[i].second.second = p[i].second;
	}
		
	p.clear();
}

void make_line( int n )
{
	sort( a.begin(), a.end() );
	
	for( int i = 0; i < n; i++ )
	{
		int start, end = 0;
		if( a[i].first == a[i + 1].first && i + 1 < n )
		{
			start = i;
			while( a[i].first == a[i + 1].first && i + 1 < n )
				i ++;
			end = i;

			sort_weigh_in_decrease_order( start, end );
		}
	}
}

int main()
{
	int n; 
	cin >> n;
	input( n );

	make_line( n );

	output( n );
}

/*118:
  digital root yrk adad yani raghamaye oon adado ba ham jam kon agar 1 raghami shod
  tamoome agar nashod digitalroot oon adade bedast amade;
  bayad digitalroot in ebarato be dast biarim   < A1*...An + A1*...An-1 + ... + A1*A2 + A1 >
  voroodi:
  aval tedade ebarat hayi ke bayad hesab konim k  ( 1 <= k <= 5 )
  dar har khat yek n va bad n ta adad
  khorooji:
  dar har khat digital root har kodamo bede*/
#include <iostream>
#include <vector>

using namespace std;

vector < vector < int > > a;
vector < int > p;

void input ( int k )
{
	for(int i = 0, n; i < k; i++)
	{
		a.push_back( p );
		cin >> n;

		for(int j =0 ,x; j < n; j++)
		{
			cin >> x;
			a[i].push_back( x );
		}
	}
}

void output( vector < int > a, int n )
{
	for( int i = 0; i < n; i++)
		cerr << a[i] << " ";
	cerr << endl;
}

void change_numbers_to_hang9 ( int k )
{
	for( int  i = 0, l; i < k; i++)
	{
		l = a[i].size();
		for( int j = 0; j < l; j++)
			a[i][j] %= 9;
	}
}

void find_digitalroot ( int k )
{
	for( int i = 0, l, expression; i < k; i ++)
	{
		l = a[i].size();
		expression = a[i][0];

		for( int j = 1,f = a[i][0]; j < l; j++)
		{
			f *= a[i][j];
			f %= 9;

			expression += f;
		}
		
		int flag = 0;

		if( expression % 9 == 0 )
		{
			cout << 9 << endl;
			flag = 1;
		}

		if( flag == 0 )
			cout << expression % 9 << endl;
	}
}

int main()
{
	int k;
	cin >> k;
	input ( k );

	change_numbers_to_hang9( k );

	find_digitalroot ( k );
}

/*115:
calender: mon...sun = 1...7;
sale 2001 gozashte be khater jashne yadbood barnamei benevisid ke
shomare ye tarikhi ke behet mide ro chap kone ( 1...7)
roozhaye mah: 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31;
n shomare ye rooze , m mah har 2 koochektar az 100
agar javab vojood nadasht chap kon "Impossible"*/
#include <iostream>

using namespace std;

struct int_bool
{
	int x;
	bool x2;
	int_bool ()
	{
		x = 0;
		x2 = 0;
	}
};

int a[20];

void number_days_of_months()
{
	a[1] = a[3] = a[5] = a[7] = a[8] = a[10] = a[12] = 31;
	a[2] = 28;
	a[4] = a[6] = a[9] = a[11] = 30;
}

int_bool find_day( int n, int m )
{
	int_bool ans;
	//exceptions
	if( m > 12 || n > 31 )
	{
		cout << "Impossible" << endl;
		ans.x2 = 1;
	}
	if( m == 2 && n > 28 )
	{
		cout << "Impossible" << endl;
		ans.x2 = 1;
	}
	if( m == 4 && n > 30 || m == 6 && n > 30 || m == 9 && n > 30 || m == 11 && n > 30 )
	{
		cout << "Impossible" << endl;
		ans.x2 = 1;
	}
	//////////////
	int sum = 0;
	for ( int i = 1; i < m; i++ )
		sum += a[i];
	sum += n;
	sum %= 7;

	if( sum == 0 )
		ans.x = 7;
	else
		ans.x = sum;
	return ans;
}

int main()
{
	int n, m;
	cin >> n >> m;
	number_days_of_months();
	int_bool ans = find_day( n, m );
	if( ans.x2 == 0 )
		cout << ans.x << endl;
}

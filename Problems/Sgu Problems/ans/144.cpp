#include <iostream>
#include <cstdio>

using namespace std;

double find_probability( int l, double z )
{
	double bad_posibility = l - z;
	bad_posibility *= bad_posibility;
	bad_posibility /= l * l;
	return 1 - bad_posibility;
}

int main()
{
	int x,y;
	double z;
	cin >> x >> y >> z;
	int l = ( y - x ) * 60;
	double ans = find_probability( l, z );
	//output( ans );
	printf ( "%0.7lf \n", ans );
}

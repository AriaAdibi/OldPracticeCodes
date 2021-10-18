#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	vector < int > v ;

	for ( int i = 0; i * i <= 16; i ++ )
		v.push_back( i * i );

	for ( int i = 0; i < v.size(); i += 2 )
		v.pop_back();

	cout << v.size() - v.back() << endl;
	return 0;
}

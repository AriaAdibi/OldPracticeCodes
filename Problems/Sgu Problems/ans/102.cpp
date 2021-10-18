/* tedadetamame adaud ke nesbat be n avaland
  & tabiyi & koochektar az n andro bede */
#include <iostream>
#include <vector>

using namespace std;

const int MAX = 10100;
bool b [ MAX ];


int gcd1( int n )
{
	int k = 1;
	b[0] = 1;
	b[1] = 1;
	for(int i = 0; i < n; i++)
		if(b[i] == 0 && n % i == 0)
		{
			b[i] = 1;
			for(int j = i+i; j < n; j += i)
				b[j] = 1;
		}
	for(int i = 0; i < n; i++)
		if(b[i] == 0)
			k++;
	return k;
}
int main()
{
	int n;
	cin >> n;
	cout << gcd1( n ) << endl;
}

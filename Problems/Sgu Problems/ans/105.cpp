/*105
  donbaleye 1,12,123,1234,12345,...
  n ta onsor aval dade mishe bayad goft 
  chantash bar 3 bakhshpazirand.
  */
	
#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;

	if( n % 3 == 1)
		cout << ((n-1)/3)*2 << endl;
	if(n % 3 == 2)
		cout << ((n-2)/3)*2+1 << endl;
	if(n % 3 == 0)
		cout << (n/3)*2 << endl;
}

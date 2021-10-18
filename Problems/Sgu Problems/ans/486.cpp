#include <iostream>
#include <string>

using namespace std;

string s;
string g;

int main()
{
	cin >> s >> g;
	//find_bull:
	int n_bulls = 0;
	for ( int i = 0; i < s.size(); i++ )
		if ( s[i] == g[i] )
		{
			s.erase( s.begin() + i );
			g.erase( g.begin() + i );
			i --;
			n_bulls ++;
		}
	//find_cows:
	int n_cows = 0;
	int l_s = s.size();
	int l_g = g.size();
	for ( int i = 0; i < s.size(); i++ )
		for ( int j = 0; j < g.size(); j ++ )
			if ( s[i] == g[j] )
			{
				s.erase( s.begin() + i );
				g.erase( g.begin() + j );
				i--;
				j--;
				n_cows++;
				break;
			}
	cout << n_bulls << " " << n_cows << endl;

}

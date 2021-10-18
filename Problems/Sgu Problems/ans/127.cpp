/* 127:
   CIA daftari  mikhad doros kone ke dar oon dar morede mamoorash yeck seri etelaat bashe 2 safhe aval
   marboot be esme mamooriataye CIA hast,CIA mikhad az safhe ye 3 be bad -- ke har safhe hadeaxar k khat
   mitavan nevesht --- shomare telephone mamoorash va mahale telefona neveshte beshe CIA be shoma be khatere
   masayel amniati faghat shomare ha ro mide va shoma vazife darid begooyid ke tedade safhehaye lazem chandtast
   ba in sharayet ke:
   1-hameye shomare telephon ha 4 raghami and va hich yek ba 0, 8 shoroo nemishan.
   2-shomare ha bayad be soorate soudi moratab shan va har ja ke be shomarei residim ke raghame avale oon fargh 
   dasht bayad az safhe ye jadid estefade konim.
   voroodi: 
   k ( 0 < k < 255 ).- hadeaxare khat haye morede estefade dar safhe.
   n ( 0 < n < 8000 ).- tedade somare ha. va bad ham n shomareye 4 raghami.
   khorooji:
   p.-tedade safehaye lazem.*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector < int > a;

void input( int n )
{
	for( int i = 0, x; i < n; i ++ )
	{
		cin >> x;
		a.push_back( (x - (x % 1000)) / 1000);
	}
}

/*void  output( vector < int > a, int l)
{
	for( int i = 0; i < l; i++ )
		cerr << a[i] << " ";
	cerr << endl;
}*/

int number_of_s_pages( int p, int k )
{
	return ( (p + k - 1) / k );
}

int find_ans( int n, int k )
{
	int ans = 0;

	for( int i = 0, s, p; i < n; )
	{
		p = 0;
		s = a[i];

		while( s == a[i] && i < n )
		{
			p++;
			i++;
		}
		ans += number_of_s_pages( p, k );
		
	}

	return ans;
}

int main()
{
	int k ,n;
	cin >> k >> n;
	input( n );

	sort( a.begin(), a.end() );

	int ans = find_ans( n, k );

	cout << ans + 2 << endl;

	//output( a, a.size() );
}

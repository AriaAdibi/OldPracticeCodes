/* 130:
   yek dayere dar nazar begirid ke 2k ta noghte rooye mohote un gharar darad. bayad tedade rahayi
   ke mitavan ba k ta vatar ke har noghte daghighan dar yek vatar bashad ra peida konid ke dayere 
   be hadeaghal tedade momken taghsim shavad.. bad az in, in tedad ra ham gozaresh konid.
voroodi:
k ( 1 <= k <= 30 )
khorooji:
n--tedade rah haye khaste shode-- "space" p-- tedade nahie ha--*/
#include <iostream>

using namespace std;

long long C ( int n, int r )
{
	if ( r == 0 )
		return 1;
	else
	{
		long long P = C( (n - 1), (r - 1) ) * n  / r;
		return P;
	}
}

long long catalan ( int k )
{
	long long P = C( k+k, k );
	P /= (k + 1);
	return P;
}

int main()
{
	int k;
	cin >> k;
	//be vozooh shomare khaste shode shomare adade catalan k om ast.
	//tedade nahie ha be vozooh k+1 ast.
	if ( k == 0 )
		cout << 1 << " " << 0 << endl;
	else

		cout << catalan( k ) << " " << k + 1 << endl;
}

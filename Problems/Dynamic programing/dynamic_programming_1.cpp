/*GAME 1....2n
  1...2n karte addad.dar hast har dafe yeki az 2 nafar
  mitoonam yeki az 2saro bar darand ooni barandas ke 
  bishtarin emtiazo begire.
  1_nafare aval hamishe barandast(che ra?)
  2_barnameyi benevisid ke bishtarin emtiazi ke 
    nafare 1 mitoone kasb kone cheghadre;
    */
#include <iostream>

using namespace std;

int const MAX=10000;

int a[MAX];
int d[MAX][MAX];


void input(int n)
{
	for(int i=1; i<n+1; i++)
		cin>>a[i];
}

int unknowe(int n)
{
	for(int i=1; i<n+1; i++)
		d[i][i]=a[i];
	for(int i=n; i>0; i--)
		for(int j=i; j<n+1; j++)
		{
			int p1,p2;
			
			//p1:
			if(a[j-1]>a[i])
				p1=d[i][j-2]+a[j];
			else
				p1=d[i+1][j-1]+a[j];
			//p2:
			if(a[j]>a[i+1])
				p2=d[i+1][j-1]+a[i];
			else
				p2=d[i+2][j]+a[i];
			d[i][j]=max(p1,p2);
		}
	return d[1][n];
}

int main()
{
	int n;
	cin>>n;
	input(n);
	cout<<unknowe(n)<<endl;
}

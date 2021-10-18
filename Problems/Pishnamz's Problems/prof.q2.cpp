#include <iostream>

using namespace std;

bool gharbal[1000020];

int prime[80000];

int p[21];

int A[21];

int A2[21];

int A3[21];
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void tajzie(int &input)
{
	gharbal[0]=1;
	gharbal[1]=1;
	////////////////////////////////////////////////////////////
	for(int step=2,number_of_prime=0; step<1000001; step++)
	{
		if(gharbal[step]==0)
		{
			prime[number_of_prime]=step;
			number_of_prime++;
			for(int remover=2*step; remover<1000001; remover+=step)
			{
				gharbal[remover]=1;
			}
		}
	}
	/////////////////////////////////////////////////////////////////
	for(int step=0, save=input, a=0, number_of_p=0, number_of_a=0 ; step<80000; step++)
	{

		if(save%prime[step]==0)
		{
			a=0;
			p[number_of_p]=prime[step];
			number_of_p++;
			while(save%prime[step]==0)
			{
				a++;
				save/=prime[step];
			}
			A[number_of_a]=a;
			number_of_a++;
		}
		if(save==1)
			break;
	

	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void a_m(int &number_of_p)
{
	for(int step=0; step<number_of_p; step++)
	{	
		A3[step]=(A[step]+(3*A2[step]))/2;
	}

}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
long long M(long long &m, int &number_of_p)
{
	for(int step=0; step<number_of_p; step++)
	{
		for(int step2=0; step2<A3[step]; step2++)
			m*=p[step];
	}
	return m;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
	int input, number_of_p=0;
	long long m=1, k=1;
	cin>>input;
	tajzie(input);
	//k=?//////////////////////////////////////////////////////////////////
	for(int checker=0; checker<22; checker++)
	{
		if(p[checker]==0)
			break;
		else
		{
			if(A[number_of_p]%2==1)
			{	
				k*=p[checker];
				A2[number_of_p]=1;
			}
			number_of_p++;

		}
	}
	//tavn haye m////////////////////////////////////////////////////////////
	a_m(number_of_p);
	M(m, number_of_p);
	cout<<k<<endl;
	cout<<m<<endl;
}

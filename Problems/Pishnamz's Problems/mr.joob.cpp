# include <iostream>

using namespace std;

bool gharbal[1000100];

int prime[80000];

int main()

{
	gharbal[0]=1;
	gharbal[1]=1;

	int number_of_prime=0;

	for(int number=1; number<1000001; number++)
	{
		if(gharbal[number]==0)
		{
			prime[number_of_prime]=number;
			number_of_prime++;

			for(int mprime=2*number; mprime<1000001; mprime+=number)
			{
				gharbal[mprime]=1;
			}
		}
	}

	int limit1,limit2;

	cin>>limit1>>limit2;

	if(limit1==1)
	{
		cout<<1;
		return 0;
	}
	else
	{
		long double minf=0;

		for(int checker=limit1; checker<limit2+1; checker++)
		{
			if(gharbal[checker]==0)
			{
				minf=checker;
			}
		}
		if(minf!=0)
		{
			cout<<minf;
			return 0;
		}
		else
		{
			long long zarb=1;

			long long S=0; 

			int answer=0;

			for(double checker=limit1; checker<limit1+1; checker++)
			{
				S=0;
				int sum2=1;
				long long sum=1;
				for(int save=checker,step=0; prime[step]<(checker/2)+1; step++)
				{
					zarb=1;
					while(save%prime[step]==0)
					{
						save/=prime[step];
						zarb*=prime[step];
						if(save%prime[step]!=0)
						{
							zarb*=prime[step];
							zarb-=1;
							sum*=zarb;
							sum2*=(prime[step]-1);
						}
					}
					if(save==1)
					{
						break;
					}
				}
				S=((sum/sum2)-checker);
				minf=(S/checker);
				answer=checker;	
			}
			for(double checker=limit1+1; checker<limit2+1; checker++)
			{
				long long sum=1;
				int sum2=1;
				sum=1;
				sum2=1;
				S=0;
				for(int save=checker,step=0; prime[step]<(checker/2)+1; step++)
				{
					zarb=1;
					while(save%prime[step]==0)
					{
						save/=prime[step];
						zarb*=prime[step];
						if(save%prime[step]!=0)
						{
							zarb*=prime[step];
							zarb-=1;
							sum*=zarb;
							sum2*=(prime[step]-1);
						}
					}
					if(save==1)
					{
						break;
					}
				}
				S=((sum/sum2)-checker);

				if(minf>=(S/checker))
				{
					minf=(S/checker);
					answer=checker;
				}
			}


			cout<<answer;
		}

	}

}

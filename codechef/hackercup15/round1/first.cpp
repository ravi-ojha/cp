#include <bits/stdc++.h>
using namespace std;
int N = 10000001;
int is_prime[10000001] = {0};
void sieve()
{
	int i=2,j;
	while(i <= N)
	{
		if(is_prime[i] == 0)
		{
			for(j=i;j<=N;j+=i)
			{
				is_prime[j] += 1;
			}
		}
		i+=1;
	}
}
int main()
{
	sieve();
	int t;
	scanf(" %d",&t);
	for(int tt=1;tt<=t;tt++)
	{
		int a,b,k;
		scanf(" %d %d %d",&a,&b,&k);
		int res = 0;
		for(int i=a;i<=b;i++)
		{
			if(is_prime[i] == k)
			{
				res++;
			}
		}
		printf("Case #%d: %d\n",tt,res);
	}
	return 0;
}

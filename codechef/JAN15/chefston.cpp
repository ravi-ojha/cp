#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf(" %d",&t);
	while(t--)
	{
		long long n,k;
		scanf(" %lld %lld",&n,&k);
		long long a[n];
		long long b[n];
		for(int i=0;i<n;i++)
		{
			scanf(" %lld",&a[i]);
		}
		for(int i=0;i<n;i++)
		{
			scanf(" %lld",&b[i]);
		}
		long long res = 0;
		for(int i=0;i<n;i++)
		{
			long long tmp = k/a[i];
			tmp = tmp*b[i];
			res = max(res,tmp);
		}
		printf("%lld\n",res);
	}
	return 0;
}

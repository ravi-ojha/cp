#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	scanf(" %d",&n);
	long long a[n];
	for(int i=0;i<n;i++)
	{
		scanf(" %lld",&a[i]);
	}
	long long res = 0;
	long long front = 0;
	long long back = n-1;
	long long i = 0;
	while(i<n)
	{
		if(a[front] < a[back])
		{
			res = res + (i+1)*a[front];
			front++;
		}
		else
		{
			res = res + (i+1)*a[back];
			back--;
		}
		i++;
	}
	printf("%lld\n",res);
	return 0;
}

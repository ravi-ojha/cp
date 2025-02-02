#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b)
{
	int t;
	while(a)
	{
		t = a;
		a = b%a;
		b = t;
	}
	return b;
}
int main()
{
	int t;
	scanf(" %d",&t);
	while(t--)
	{
		int n,q;
		scanf(" %d %d",&n,&q);
		int a[n];
		for(int i=0;i<n;i++)
		{
			scanf(" %d",&a[i]);
		}
		int left[n];
		int right[n];
		left[0] = a[0];
		for(int i=1;i<n;i++)
		{
			left[i] = gcd(left[i-1],a[i]);
		}
		right[n-1] = a[n-1];
		for(int i=n-2;i>=0;i--)
		{
			right[i] = gcd(right[i+1],a[i]);
		}
		int l,r;
		int res;
		while(q--)
		{
			scanf(" %d %d",&l,&r);
			l--;
			r--;
			if(l==0)
			{
				res = right[r+1];
			}
			else if(r == n-1)
			{
				res = left[l-1];
			}
			else
			{
				res = gcd(left[l-1], right[r+1]);
			}
			printf("%d\n",res);
		}
	}
	return 0;
}

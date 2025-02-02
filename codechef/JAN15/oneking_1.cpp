#include <bits/stdc++.h>
#define LSOne(S) (S & (-S))
using namespace std;

// Fenwick tree
// Only the updates are stored. Original array entries are not
// stored and are assumed to be 0. If the original array entries
// are non-zero, we can store them in another array A and modify
// point query to return query(b) + A[b].
int ft[2005];
int a[2005];
// Point query: Returns the value at position b in the array
int query(int b)	{
	int sum = 0;
	for (; b; b -= LSOne(b)) sum += ft[b];
	return sum;
}

// Point update: Adds v to the value at position k in the array
void update(int k, int v) {
	for (; k <= 2005; k += LSOne(k)) ft[k] += v;
}

// Range update: Adds v to each element in [i...j] in the array
void range_update(int i, int j, int v)	{
	update(i, v);
	update(j + 1, -v);
}


int main()
{
	int t;
	scanf(" %d",&t);
	while(t--)
	{
		int n;
		scanf(" %d",&n);
		for(int i=0;i<2005;i++)
		{
			ft[i] = 0;
			a[i] = 0;
		}
		for(int i=0;i<n;i++)
		{
			int a,b;
			scanf(" %d %d",&a,&b);
			range_update(a,b,1);
		}
		/*for(int i=0;i<20;i++)
		{
			printf(" %2d",i);
		}
		printf("\n");
		for(int i=0;i<20;i++)
		{
			printf(" %2d",query(i));
		}*/
		for(int i=0;i<2005;i++)
		{
			a[i] = query(i);
		}
		int res = 0;
		for(int i=0;i<2004;i++)
		{
			if(a[i+1] < a[i])
			{
				res++;
			}
		}
		printf("%d\n",res);
	}
	return 0;
}

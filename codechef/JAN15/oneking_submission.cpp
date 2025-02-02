#include <bits/stdc++.h>
#define LSOne(S) (S & (-S))
using namespace std;
inline void fastRead_int(int &x) {
    register int c = getchar_unlocked();
    x = 0;
    int neg = 0;

    for(; ((c<48 || c>57) && c != '-'); c = getchar_unlocked());

    if(c=='-') {
     neg = 1;
     c = getchar_unlocked();
    }

    for(; c>47 && c<58 ; c = getchar_unlocked()) {
     x = (x<<1) + (x<<3) + c - 48;
    }

    if(neg)
     x = -x;
}
int ft[2005];
int a[2005];

int query(int b)
{
	int sum = 0;
	for (; b; b -= LSOne(b)) sum += ft[b];
	return sum;
}

void update(int k, int v)
{
	for (; k <= 2005; k += LSOne(k))
		ft[k] += v;
}

void range_update(int i, int j, int v)
{
	update(i, v);
	update(j + 1, -v);
}

int main()
{
	int t;
	//scanf(" %d",&t);
	fastRead_int(t);
	while(t--)
	{
		int n;
		//scanf(" %d",&n);
		fastRead_int(n);
		for(int i=0;i<2005;i++)
		{
			ft[i] = 0;
			a[i] = 0;
		}
		for(int i=0;i<n;i++)
		{
			int a,b;
			fastRead_int(a);
			fastRead_int(b);
			a++;
			b++;
			//scanf(" %d %d",&a,&b);
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
		for(int i=1;i<2005;i++)
		{
			a[i] = query(i);
		}
		int res = 0;
		for(int i=1;i<2004;i++)
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

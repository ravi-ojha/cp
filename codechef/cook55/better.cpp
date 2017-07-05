#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
int ac = 4;
int cc = 6;
long long f[301];

long long fast_power(long long a,long long n)
{
    long long result = 1;
    long long power = n;
    long long value = a;
    while(power>0)
    {
        if(power&1)
        {
            result = result*value;
            result = result%1000000007;
        }
        value = value*value;
        value = value%1000000007;
        //power /= 2;
        power = power >> 1;
    }
    return result;
}



vector< pair<int, int> > method2(int target){

    int da = target/ac;
    vector< pair<int, int> > v;
    for(int i=0;i<=da;i++)
    {
       	int rem = target-(i*ac);
        if(rem < 0)
        {
            break;
        }else
        {
            if(rem%cc==0)
            {
                //printf("\n%d, %d ---- %d + %d = %d \n", i, rem/cc, i*ac, (rem/cc)*cc, target);
                v.push_back(make_pair(i,rem/cc));
            }
        }
    }
    return v;
}
int main()
{
	f[0] = 1;
	for(int i=1;i<301;i++)
	{
		f[i] = (i*f[i-1])%MOD;
	}
    long long inv[301];
    for(int i=0;i<301;i++)
    {
        inv[i] = fast_power(i,MOD-2);
    }
	int t;
	scanf(" %d",&t);
	while(t--)
	{
		long long r,b,l;
		scanf(" %lld %lld %lld",&r,&b,&l);
		if(r > 6*b)
		{
			printf("0\n");
		}
		else
		{
			//vector< pair<int, int> > den = method2(r);
			long long res = 0;
			for(int six=0; six*6 <= r && six <= b; six++)
			{
				//cout << six << " " <<  four << endl;
                long long others = r - six*6;
                long long four;
                if(others%4 == 0)
                {
                    four = others/4;
                }
                else
                {
                    continue;
                }
                //cout << six << " " <<  four << endl;
				if(six + four <= b)
				{
					long long tmpr = f[b];
					long long left = b - (six + four);
                    long long niche4 = f[four];
                    long long niche6 = f[six];
                    niche4 = inv[niche4];
                    niche6 = inv[niche6];
                    for(int wickets = 0; wickets <= l; wickets++)
                    {
                    	tmpr = f[b];
                    	long long niche0 = left - wickets;
                    	if(niche0 >= 0)
                       	{
                        	long long nicheW = inv[f[wickets]];
                        	niche0 = inv[f[niche0]];
                            tmpr = tmpr*niche4;
                            tmpr %= MOD;
                            tmpr = tmpr*niche6;
                            tmpr %= MOD;
                            tmpr = tmpr*niche0;
                            tmpr %= MOD;
                            tmpr = tmpr*nicheW;
                            tmpr %= MOD;
                            res += tmpr;
                            res %= MOD;
                    	}
                    }
				}
			}
			printf("%lld\n",res);
		}
	}
	return 0;
}
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
long long ago[121] = {1, 4, 9, 49, 100, 144, 400, 441, 900, 1444, 4900, 9409, 10000, 10404, 11449, 14400, 19044, 40000, 40401, 44100, 44944, 90000, 144400, 419904, 490000, 491401, 904401, 940900, 994009, 1000000, 1004004, 1014049, 1040400, 1100401, 1144900, 1440000, 1904400, 1940449, 4000000, 4004001, 4040100, 4410000, 4494400, 9000000, 9909904, 9941409, 11909401, 14010049, 14040009, 14440000, 19909444, 40411449, 41990400, 49000000, 49014001, 49140100, 49999041, 90440100, 94090000, 94109401, 99400900, 99940009, 100000000, 100040004, 100140049, 100400400, 101404900, 101949409, 104040000, 104919049, 110040100, 111049444, 114041041, 114490000, 144000000, 190440000, 194044900, 400000000, 400040001, 400400100, 404010000, 404090404, 409941009, 414000409, 414041104, 441000000, 449440000, 490091044, 900000000, 990990400, 991494144, 994140900, 1190940100, 1401004900, 1404000900, 1409101444, 1444000000, 1449401041, 1490114404, 1990944400, 4014109449, 4019940409, 4041144900, 4199040000, 4900000000, 4900140001, 4901400100, 4914010000, 4914991449, 4941949401, 4999904100, 9044010000, 9409000000, 9409194001, 9410940100, 9900449001, 9940090000, 9994000900, 9999400009, 10000000000};
int main()
{
    //printf(" %lld\n",ago[119]);
    int t;
    scanf(" %d",&t);
    while(t--)
    {
        int res = 0;
        long long a,b,i;
        int flag = 1;
        scanf(" %lld %lld",&a,&b);
        for(i=0;i<120;i++)
        {
            if(ago[i] >= a && ago[i] <= b)
            {
                res += 1;
            }
        }
//        long long x = int(sqrt(a));
//        if (x*x != a)
//        {
//            x += 1;
//        }
//        while(x*x <= b)
//        {
//            //printf("Aye..!!\n");
//            flag = 1;
//            long long z = x*x;
//            int r;
//            while(z > 0)
//            {
//                r = z%10;
//                z = z/10;
//                if(r==0 || r==1 || r==4 || r==9)
//                {
//                    continue;
//                }
//                else
//                {
//                    flag = 0;
//                    break;
//                }
//            }
//            if(flag == 1)
//            {
//                printf(" %lld,",x*x);
//                res += 1;
//            }
//            x += 1;
//        }
        printf("%d\n",res);
    }
    return 0;
}

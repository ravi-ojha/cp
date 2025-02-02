#include<stdio.h>
inline int readInt()
{
    int n=0;
    char c;
    while(1)
    {
        c=getchar_unlocked();
        if(c=='\n'||c==' ')
            break;
        n=n*10+c-'0';
    }
    return n;
}

inline void writeInt(int n)
{
    int i=10;
    char buf[11];
    buf[10]='\0';
    do
    {
        buf[--i]=(n%10)+'0';
        n/=10;
    }while(n);
    while(buf[i])
    {
        putchar_unlocked(buf[i]);
        i++;
    }
}
int parent[100011];
int final[100011];
int find_parent(int child)
{
    if(parent[child] == child)
    {
        return child;
    }
    else
    {
        parent[child] = find_parent(parent[child]);
        return parent[child];
    }
}
void unite(int x, int y)
{
    parent[find_parent(y)] = find_parent(x);
}
int main()
{
    int t;
    //scanf(" %d",&t);
    t = readInt();
    while(t--)
    {
        long long routes = 0, ways = 1;
        int n,m,x,y;
        int i;
        //scanf(" %d %d",&n,&m);
        n = readInt();
        m = readInt();
        for(i=1;i<=n;i++)
        {
            parent[i] = i;
            final[i] = 0;
        }
        for(i=0;i<m;i++)
        {
            x = readInt();
            y = readInt();
            //scanf(" %d %d",&x,&y);
            unite(x,y);
        }
        for(i=1;i<=n;i++)
        {
            final[find_parent(i)]++;
        }
        for(i=1;i<=n;i++)
        {
            if(final[i])
            {
                ways = (ways*final[i])%1000000007;
                routes++;
            }
        }
//        printf("%lld %lld\n",routes,ways);
        writeInt(routes);
        printf(" ");
        writeInt(ways);
        printf("\n");
    }
    return 0;
}

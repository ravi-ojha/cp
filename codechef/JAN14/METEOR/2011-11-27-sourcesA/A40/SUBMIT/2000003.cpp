#include <stdio.h>
#include <algorithm>
#include<cstring>
using namespace std;

#define MAXN 1020

int N,M,Q;
int A[MAXN][MAXN];
int Din[MAXN][MAXN], Area[MAXN][MAXN], Query[MAXN][MAXN];
int sol[MAXN], St[MAXN], Dr[MAXN], Stiva[MAXN];
int i,j,nr,x,y;

int main()
{
//    freopen("standard.in","r",stdin);
//    freopen("standard.out","w",stdout);

    scanf("%d %d",&N,&M);

    for (i=1; i<=N; ++i)
        for (j=1; j<=M; ++j)
            scanf("%d",&A[i][j]);

    memset (sol, 0, sizeof(sol));
    for (i=1; i<=N; ++i){

        for (j=1; j<=M; ++j)
            if (A[i][j] == 0)
                sol[j]++;
            else
                sol[j] = 0;

        nr = 0; Stiva[0] = 0;
        for (j=1; j<=M; ++j){
            while (nr > 0 && sol[Stiva[nr]] >= sol[j])
                --nr;
            St[j] = j - Stiva[nr];
            Stiva[++nr] = j;
        }

        nr = 0; Stiva[0] = M+1;
        for (j=M; j>=1; --j){
            while (nr > 0 && sol[Stiva[nr]] >= sol[j])
                --nr;
            Dr[j] = Stiva[nr] - j;
            Stiva[++nr] = j;
        }

        for (j=1; j<=M; ++j)
            Din[i][sol[j]] = max(Din[i][sol[j]] , St[j] + Dr[j] - 1);
    }

    for (i=1; i<=N; ++i)
        for (j=i; j>=0; --j)
            Din[i][j] = max(Din[i][j], Din[i][j+1]);

    for (i=1; i<=N; ++i)
        for (j=0; j<=i; ++j)
            Area[i][j] = Din[i][j] * j; //Aria maxima a unui dreptunghi cu baza pe i si de inaltime j

    memset(Din, 0, sizeof(Din));
    for (i=1; i<=N; ++i){
        Din[i][0] = Area[i][0]; //0
        for (j=1; j<=i; ++j)
            Din[i][j] = max(Din[i][j-1], Area[i][j]); // Aria maxima a unui dreptunghi cu baza pe i si inaltime maxim j
    }

    for (i=1; i<=N; ++i){
        Query[i][i] = Din[i][1];
        for (j=i+1; j<=N; ++j)
            Query[i][j] = max(Query[i][j-1], Din[j][j-i+1]);
    }

    scanf("%d\n",&Q);
    for (i=1; i<=Q; ++i){
        scanf("%d %d",&x,&y);
        if (x > y) swap(x,y);
        printf("%d\n", Query[x][y]);
    }

    return 0;
}

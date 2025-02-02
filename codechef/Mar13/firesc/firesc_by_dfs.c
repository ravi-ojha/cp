#include<stdio.h>
#include<stdlib.h>

#define MAX 100002
#define MOD 1000000007

struct Node{
int v;
struct Node *next;
int visited;
};

typedef struct Node Node;

Node *vertex[MAX];

inline void fastRead(int *a)
{
    register char c=0;
    while (c<33) c=getchar_unlocked();
    *a=0;
    while (c>33)
    {
        *a=*a*10+c-'0';
        c=getchar_unlocked();
    }
}

int dfs(int n)
{
    int score = 1;
    Node *temp;
    vertex[n]->visited = 1;
    for( temp = vertex[n]->next; temp; temp = temp->next )
    {
        if(vertex[temp->v]->visited != 1)
        {
            score += dfs(temp->v);
        }
    }
    vertex[n]->visited = 0;
    return score;
}

void insert_after(Node *m,Node *n)
{
    Node *temp;
    temp=m->next;
    m->next=n;
    n->next=temp;
}

int main()
{
    int t, v_n, m, source, dest, index, count=0, i;
    //long long int res;
    Node *source_n,*dest_n;
    fastRead(&t);
    while(t--)
    {
        int amount;
        fastRead(&v_n);
        fastRead(&m);
        fastRead(&amount);
        for( i = 0; i <= v_n; i++ )
        {
            vertex[i] = (Node *)malloc(sizeof(Node));
            vertex[i]->v = i;
            vertex[i]->next = NULL;
            vertex[i]->visited = 0;
        }

        for(i = 0; i < m; i++)
        {
            fastRead(&source);
            fastRead(&dest);

            source_n = (Node *)malloc(sizeof(Node));
            source_n->v = source;
            source_n->visited = 0;

            dest_n=(Node *)malloc(sizeof(Node));
            dest_n->v = dest;
            dest_n->visited = 0;

            insert_after(vertex[source],dest_n);
            insert_after(vertex[dest],source_n);
        }
        count = 0;
        //res = 1;
        int myans,j;
        for(i = 1; i <= v_n; i++)
        {
            if(vertex[i]->visited == 0)
            {
                vertex[v_n+1-i]->visited = 1;
                myans = dfs(i);
                if(myans == (v_n-1))
                count++;
                vertex[v_n+1-i]->visited = 0;
                //printf("myans = %d\n",myans);
                //res = (res*(dfs(i)%MOD))%MOD;
            }
//            for(j=1;j<=v_n;j++)
//            {
//                vertex[j]->visited = 0;
//            }
        }
        //res = res%MOD;
        printf("%d\n",count*amount);
    }
    return 0;
}

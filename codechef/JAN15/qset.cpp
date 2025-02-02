#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data[4];
}M[263143];

Node addNodes(Node left, Node right)
{
	Node res;
	for(int i=0;i<4;i++)
	{
		res.data[i] = 0;
	}
	res.data[3] = (left.data[3] + right.data[3])%3;
	for(int i=0;i<3;i++)
	{
		res.data[i] += left.data[i];
		res.data[(i+left.data[3])%3] += right.data[i];
	}
	return res;
}

// Building Segment Tree - Begin
// node = 1
// b = first position of our array A[]
// e = last position of our array A[]
// A = a[] array
Node createTree(int node, int b, int e, int A[])
{
    if (b == e)
    {
        M[node].data[3] = A[b]%3;
        M[node].data[M[node].data[3]] = 1;
        return M[node];
    }
    else
    {
        //compute the values in the left and right subtrees
        Node tmpnode = addNodes(createTree(2*node, b, (b+e)/2, A),
        createTree(2*node+1, (b+e)/2+1, e, A));
        for(int i=0;i<4;i++)
	  	{
	  		M[node].data[i] = tmpnode.data[i];
	  	}
        return M[node];
    }
}

// Updating Tree on changing any node value
// idx = position which is to be updated by value 'val'
void update(int node, int b, int e, int idx, int val)
{
    //if (b > idx || e < idx ) return;               // this condition is damn important
    for(int i=0;i<4;i++)
    {
    	M[node].data[i] = 0;
    }
    if (b == e) //at leaf node
    {
        M[node].data[3] = val%3;
        M[node].data[M[node].data[3]] = 1;
    }
    else
    {
		if(idx <= (b+e)/2)
			update(node*2, b, (b+e)/2, idx, val);
		else
			update(node*2 + 1, (b+e)/2 + 1, e, idx, val);

		//doing stuff with children nodes
	  	Node tmpnode = addNodes(M[node*2], M[node*2 + 1]);
	  	for(int i=0;i<4;i++)
	  	{
	  		M[node].data[i] = tmpnode.data[i];
	  	}
  	}
}

// goku - range begin
// naruto - range end
Node findRangeSum(int node, int b, int e, int goku, int naruto)
{
    if(goku <= b && naruto >= e)     // yeah... this condition is very confusing
    {
    	return M[node];
    }
    if(b > naruto || e < goku)      // means you are in the wrong neighbourhood buddy
    {
    	Node tmpnode;
    	for(int i=0;i<4;i++)
		{
			tmpnode.data[i] = 0;
		}
        return tmpnode;
    }
    Node left = findRangeSum(2*node, b, (b+e)/2, goku, naruto);
    Node right = findRangeSum(2*node + 1, (b+e)/2 + 1, e, goku, naruto);
    return addNodes(left,right);
}

int main()
{
	int n,m;
	scanf(" %d %d",&n,&m);
	char s[100005];
	int a[100005];
	scanf(" %s",s);
	for(int i=0;i<n;i++)
	{
		a[i] = s[i] - '0';
	}
	for(int i=0;i<263143;i++)
	{
		for(int j=0;j<4;j++)
		{
			M[i].data[j] = 0;
		}
	}
	createTree(1,0,n-1,a);
	while(m--)
	{
		int type,x,y;
		scanf(" %d %d %d",&type,&x,&y);
		x--;
		if(type == 1)
		{
			update(1,0,n-1,x,y);
		}
		else
		{
			y--;
			Node res = findRangeSum(1,0,n-1,x,y);
			long long ans = 0;
			long long tmpans = 0;
			for(int i=0;i<3;i++)
			{
				tmpans = res.data[i];
				if(i==0)
				{
					tmpans++;
				}
				ans += tmpans*(tmpans-1)/2;
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}

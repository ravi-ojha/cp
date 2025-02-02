#include <bits/stdc++.h>
using namespace std;
class trie_node
{
public:
	int words;
	int prefixes;
	trie_node * edges[26];
	trie_node();
};
trie_node::trie_node(void)
{
	words = 0;
	prefixes = 0;
	for(int i=0;i<26;i++)
	{
		edges[i] = NULL;
	}
}
void add_word(trie_node * vertex, string word, int wlen, int n)
{
	if(wlen == n)
	{
		vertex->words++;
	}
	else
	{
		vertex->prefixes++;
		if(vertex->edges[word[n]-'a'] == NULL)
		{
			trie_node * new_node = new trie_node;
			vertex->edges[word[n]-'a'] = new_node;
		}
		add_word(vertex->edges[word[n]-'a'], word, wlen, n+1);
	}
	return;
}
int count_prefixes(trie_node * vertex, string prefix, int plen, int n)
{
	if(plen == n)
	{
		return vertex->prefixes;
	}
	else if(vertex->edges[prefix[n]-'a'] == NULL)
	{
		return 0;
	}
	else
	{
		return count_prefixes(vertex->edges[prefix[n]-'a'], prefix, plen, n+1);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	int t;
	scanf(" %d",&t);
	for(int tt=1;tt<=t;tt++)
	{
		trie_node * first_node = new trie_node;
		int n;
		scanf(" %d",&n);
		int res = 0;
		for(int j=0;j<n;j++)
		{
			string s;
			cin >> s;
			int slen = s.length();
			
			for(int i=0;i<slen;i++)
			{
				int tmp = count_prefixes(first_node, s, i,0);
				cout << tmp << ", ";
				if(tmp != 0)
				{
					res++;
				}
				else
				{
					res++;
					break;
				}
			}
			add_word(first_node, s, slen, 0);
			cout << endl;
		}
		printf("Case #%d: %d\n",tt,res);
	}
	return 0;
}

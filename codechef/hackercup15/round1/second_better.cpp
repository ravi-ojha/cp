#include <bits/stdc++.h>
using namespace std;
const int MAXN = 26;

struct Trie
{
	Trie *child[MAXN];
	int prefixes;
	int words;

	Trie()
	{
		prefixes = 0;
		words = 0;
		for(int i = 0; i < MAXN; ++i)
		{
			child[i] = NULL;
		}
	}

	void addWord(const char *s)
	{
		if(*s=='\0')
		{
			words++;
			return;
		}
		Trie *t = child[*s-'a'];
		if(child[*s-'a']==NULL)
		{
			t = child[*s-'a'] = new Trie();
			t->prefixes = 1;
		}
		else
		{
			t->prefixes = t->prefixes + 1;
		}
		t->addWord(s+1);
	}

	int countPreffixes(const char *s)
	{
		if(*s=='\0')
		{
			return prefixes;
		}
		Trie *t = child[*s-'a'];
		if(t==NULL)
		{
			return 0;
		}
		return t->countPreffixes(s+1);
	}
};

int main()
{
	int t;
	scanf(" %d",&t);
	for(int tt=1;tt<=t;tt++)
	{
		Trie *trie = new Trie();
		int n;
		scanf(" %d",&n);
		int res = 0;
		for(int j=0;j<n;j++)
		{
			string s;
			cin >> s;
			int slen = s.length();
			char stmp[slen+1];
			int stmp_len = 0;
			for(int i=0;i<slen;i++)
			{

				stmp[stmp_len] = s[i];
				stmp_len++;
				stmp[stmp_len] = '\0';

				int tmp = trie->countPreffixes(stmp);
				//cout << tmp << ", ";
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
			char mys[slen+1];
			strcpy(mys, s.c_str());
			trie->addWord(mys);
			//cout << endl;
		}
		printf("Case #%d: %d\n",tt,res);
	}
	return 0;
}

#include <bits/stdc++.h>
#define WHITE 1
#define BLACK -1
#define GRAY 0
#define maxN 105
#define vi vector <int>
using namespace std;

int ok[maxN];
map <int, string> ss;
map <string, int> s;
vi a[maxN];
vi ans;
int ord[maxN];
int n, test,m;

void init()
{
	for (int i = 0; i < maxN; i++) 
	{
		ok[i] = WHITE;
		a[i].clear();
		ord [i] = 0;
	}
	s.clear();
	ss.clear();
	ans.clear();
}

bool contain(int x, int y)
{
	for (int i = 0; i < a[x].size(); i++)
		if (a[x][i] == y) return true;
	return false;
}

main(){
	//freopen("in.inp","r",stdin);
	//freopen("out.out","w",stdout);

	while (cin >> n)
	{
		test++;
		init();
		
		for (int i = 0; i < n; i++) 
		{
			string k;
			cin >> k;
			s[k] = i;
			ss[i] = k;
			
		}
		cin >> m;
		for (int i = 0; i < m; i++)
		{
			string k, b;
			cin >> k >> b;
			if (!contain(s[k],s[b]) && k != b )
			{
				a[s[k]].push_back(s[b]);
				ord[s[b]]++;
			}
		}
		
		if (test != 1) 
		{
			getchar();
		}
		cout << "Case #" << test << ": Dilbert should drink beverages in this order:";
		bool done = false;
	
		while (!done)
		{
			done = true;
			for (int j = 0; j < n; j++)
				if (ok[j] == WHITE && ord[j] == 0)
				{
					done = false;
					ok[j] = BLACK;
					ans.push_back(j);
					for (int k = 0; k < a[j].size(); k++) ord[a[j][k]]--;
					j = -1;
				}
		}
		
		for (int i = 0; i < ans.size(); i++) cout << " " << ss[ans[i]] ;
		cout << ".";
		cout << endl;
		cout << endl;
	}	
}

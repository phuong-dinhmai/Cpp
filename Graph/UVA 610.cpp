#include <bits/stdc++.h>
#define maxN 1005
#define vi vector <int>
#define inf 1e9+7
using namespace std;

int ans [maxN][maxN];
int num[maxN], low[maxN];
int t, n;
vi a[maxN];

bool have (vi x, int y)
{
	for (int i = 0; i < x.size(); i++)
		if (x[i] == y) return true;
	return false;
}

void init()
{
	for (int i = 0; i < maxN; i++)
	{
		num[i] = 0;
		low[i] = inf;
		a[i].clear();
		for (int j = 0; j < maxN; j++) ans[i][j] = 0;
	}
	t = 0;
}

void dfs(int x, int u)
{
	num[u] = ++t;
	for (int i = 0; i < a[u].size(); i++)
		{
			int v = a[u][i];
			if (ans[u][v] == 1) 
			{
				if (num[v] == 0)
				{
					dfs(u, v);
					if (low[v] <= num[u]) ans[v][u] = 0;
					low[u] = min(low[u], low[v]);
				}
				else if (v != x)
				{
					low[u] = min(low[u], num[v]);
					ans[v][u] = 0;
				}
			}
		}
}

main(){
	int test = 0;
	int m;
	//freopen("in.inp","r",stdin);
	//freopen("out.out","w",stdout);
	
	while (cin >> n >> m)
	{
		if (n == 0 && m == 0) break;
		test++;
		init();
		
		for (int i = 0; i < m; i++) 
		{
			int x, y;
			cin >> x >> y;
			if (!have(a[x-1], y-1)) a[x-1].push_back(y-1);
			if (!have(a[y-1], x-1)) a[y-1].push_back(x-1);
			ans[x-1][y-1] = 1;
			ans[y-1][x-1] = 1;
		}
		
		for (int i = 0; i < n; i++)
			if (num[i] == 0)
			{
				dfs(i, i);
			}
		cout << test << endl;
		cout << endl;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (i != j && ans[i][j] == 1) cout << i+1 << " " << j+1 << endl;
		cout << "#" << endl;
	}
}

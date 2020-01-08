#include <bits/stdc++.h>
#define ii pair <int, int>
#define vi vector <int>
#define vii vector <ii>
#define maxN 1005
#define inf 1e9+7
using namespace std;

vi a[maxN];
vii bridge;
int low[maxN], num[maxN], parent[maxN];
int t, n;

void init()
{
	for (int i = 0; i < maxN; i++)
	{
		a[i].clear();
		num[i] = 0;
		low[i] = inf;
		parent[i] = inf;
	}
	t = 0;
	bridge.clear();
}

void dfs(int u)
{
	num[u] = ++t;
	for (int i = 0; i < a[u].size(); i++)
	{
		int v = a[u][i];
		if (num[v] == 0)
		{
			parent[v] = u;
			dfs(v);
			low[u] = min(low[u], low[v]);
			if (low[v] > num[u]) 
			{
				if (v > u) bridge.push_back(ii (u,v)); else bridge.push_back(ii (v,u));
			}
		}
		else 
			if (parent[u] != v) low[u] = min(low[u], num[v]);
	}
}
main(){
	//freopen("in.inp","r",stdin);
	//freopen("out.out","w",stdout);
	
	while (cin >> n)
	{
		init();
		
		for (int i = 0; i < n; i++)
		{
			int x, m;
			char c, k;
			cin >> x >> c >> m >> k;
			for (int j = 0; j < m; j++)
			{
				int r;
				cin >> r;
				a[x].push_back(r);
			}
		}
		
		for (int i = 0; i < n; i++)
			if (num[i] == 0) dfs(i);
		
		cout << bridge.size() << " critical links" << endl;
		sort(bridge.begin(), bridge.end());
		for (int i = 0; i < bridge.size(); i++) 
			cout << bridge[i].first << " - " << bridge[i].second << endl;
		cout << endl;
	}
}

#include <bits/stdc++.h>
#define ln "\n"
#define vi vector <int>
#define vvi vector <vi>
using namespace std;

const int N = 1e5+7;

vi edge[N];
int n, m;
int col[N], father[N];
bool vis[N];
vi ans[2];

void dfs(int u)
{
	for (int i = 0; i < edge[u].size(); i++)
	{
		int v = edge[u][i];
		if (col[v] == -1)
		{
			col[v] = 1 - col[u];
			ans[col[v]].push_back(v);
			dfs(v);
			continue;
		}
		if (col[v] == col[u]) 
		{
			cout << -1 << ln;
			exit(0);
		}
	}
}

main(){
	//freopen("in.inp","r",stdin);
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		edge[x].push_back(y);
		edge[y].push_back(x);
	}
	memset(col, -1, sizeof(col));
	memset(vis, 0, sizeof(vis));
	if (m == 0)
	{
		cout << -1 << ln;
		return 0;
	}
	
	for (int i = 1; i <= n; i++)
	{
		if (edge[i].size() == 0 || col[i] != -1) continue;
		col[i] = 0;
		ans[0].push_back(i);
		dfs(i);
	}
	
	for (int i = 0; i < 2; i++)
	{
		cout << ans[i].size() << ln;
		for (int j = 0; j < ans[i].size(); j++) cout << ans[i][j] << " ";
		cout << ln;
	}
}


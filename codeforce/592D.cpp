#include <bits/stdc++.h>
#define vi vector <int>
#define vvi vector <vi>
using namespace std;

const int N = 123459;

vvi edge;
int n, m;
int a[N], size[N], d[N];
bool vis[N];

void dfs(int u, int pa)
{
	size[u] = 0;
	if (vis[u]) size[u] = 1;
	for (int i = 0; i < edge[u].size(); i++)
	{
		int v = edge[u][i];
		if (v != pa)
		{
			d[v] = d[u] + 1;
			dfs(v, u);
			size[u] += size[v];
		}
	}
}

main(){
	//freopen("in.inp","r",stdin);
	cin >> n >> m;
	edge.assign(n+1, vi());
	for(int i = 1; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		edge[x].push_back(y);
		edge[y].push_back(x);
	}
	for (int i = 0; i < m; i++)
	{
		cin >> a[i];
		vis[a[i]] = 1;
	}
	
	memset(d, 0, sizeof(d));
	dfs(1, -1);

	int root = -1;
	for (int i = 1; i <= n; i++)
	{
		if (vis[i] && (root == -1 || d[root] < d[i])) root = i;
	}
	
	memset(d, 0, sizeof(d));
	dfs(root, -1);
	
	int sum = 0, l = 0;
	for (int i = 1; i <= n; i++)
	{
		if (size[i] && m - size[i] > 0) sum += 2;
		if (vis[i]) l = max(l, d[i]);
	}
	for (int i = 1; i <= n; i++)
	{
		if (l == d[i] && vis[i] && i < root) root = i;
	}
	cout << root << endl << sum - l << endl;
}

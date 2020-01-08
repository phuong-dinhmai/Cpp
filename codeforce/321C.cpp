#include <bits/stdc++.h>
#define vi vector <int>
#define vvi vector <vi>
#define maxN (int) (1e5+7)
using namespace std;

vvi edge;
bool vis[maxN];
char ans[maxN];
int n;
int chil[maxN];

void dfs(int u, int pa)
{
	chil[u] = 1;
	for (int i = 0; i < edge[u].size(); i++)
	{
		int v = edge[u][i];
		if (!vis[v] && v != pa)
		{
			dfs(v, u);
			chil[u] += chil[v];
		}
	}
}

int redfs(int u, int pa, int root)
{
	for (int i = 0; i < edge[u].size(); i++)
	{
		int v = edge[u][i];
		if (!vis[v] && v != pa && 2*chil[v] >= chil[root]) return redfs(v, u, root);
	}
	return u;
}

void centroid(int val, int root)
{
	dfs(root, root);
	int tmp = redfs(root, root, root);
	//cout << tmp << " " << chil[tmp] << endl;
	ans[tmp] = val;
	vis[tmp] = true;
	for (int i = 0; i < edge[tmp].size(); i++)
	{
		int u = edge[tmp][i];
		if (!vis[u])
		{
			centroid(val+1, u);
		}
	}
}

main(){
	//freopen("in.inp","r",stdin);
	cin >> n;
	edge.assign(n+1, vi());
	for (int i = 0; i < n-1; i++)
	{
		int x, y;
		cin >> x >> y;
		edge[x].push_back(y);
		edge[y].push_back(x);
	}
	fill(vis, vis+n+1, false);
	centroid('A', 1);
	for (int i = 1; i <= n; i++) printf("%c ", ans[i]);
}

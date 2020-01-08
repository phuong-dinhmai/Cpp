#include <bits/stdc++.h>
#define vi vector <int>
#define vvi vector <vi>
using namespace std;

const int maxN = 1e5+7;
const int inf = 1e9+7;

vvi edge;
int dep[maxN];
int ans[maxN];
int lca[maxN][17];
int n, m;
vi pending;

void dfs(int u, int pa)
{
	lca[u][0] = pa;
	ans[u] = ans[pa] + 1;
	if (u == 1) ans[u] = 0;
	dep[u] = dep[pa] + 1;
	for (int i = 1; (1 << i) <= n; i++)
		lca[u][i] = lca[lca[u][i-1]][i-1];
	for (int i = 0; i < edge[u].size(); i++)
	{
		int v = edge[u][i];
		if (v != pa) dfs(v, u);
	} 
}

int LCA(int x, int y)
{
	if (dep[x] < dep[y]) swap(x, y);
	int lg;
	for (lg = 0; (1 << lg) <= n; lg++);
	lg--;
	
	for (int i = lg; i >= 0; i--)
	{
		if (dep[lca[x][i]] >= dep[y]) x = lca[x][i];
	}
	if (x == y) return y;
	
	for (int i = lg; i >= 0; i--)
	{
		if (lca[x][i] != lca[y][i])
		{
			x = lca[x][i];
			y = lca[y][i];
		}
	}
	return lca[x][0];
}

int dis(int x, int y)
{
	return dep[x] + dep[y] - 2*dep[LCA(x, y)];
}

void bfs()
{
	queue <int> q;
	for (int i = 0; i < pending.size(); i++) q.push(pending[i]), ans[pending[i]] = 0;
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		for (int i = 0; i < edge[u].size(); i++)
		{
			int v = edge[u][i];
			if (ans[v] > ans[u]+1)
			{
				ans[v] = ans[u] + 1;
				q.push(v);
			}
		}
	}
}

main(){
	//freopen("in.inp","r",stdin);
	ios_base :: sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	edge.assign(n+1, vi());
	for (int i = 1; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		edge[x].push_back(y);
		edge[y].push_back(x);
	}
	dfs(1, 0);
	int mm = sqrt(m);
	/*for (int i = 1; i <= n; i++)
	{
		for (int j = 1; (1 << j) <= n; j++) cout << lca[i][j] << " ";
		cout << endl;
	}*/
	//for (int i = 1; i <= n; i++) cout << ans[i] << " "; cout << endl;
	for (int i = 1; i <= m; i++)
	{
		int type, u;
		cin >> type >> u;
		if (type & 1)
		{
			pending.push_back(u);
		}
		else 
		{
			int res = ans[u];
			//cout << pending.size() << endl;
			for (int i = 0; i < pending.size(); i++) res = min(res, dis(u, pending[i]));
		 	//cout << dis(u, pending[i]) << " ";
			//cout << endl;
			cout << res << endl;
		}
		if (i % mm == 0)
		{
			bfs();
			pending.clear();
		}
	}
}

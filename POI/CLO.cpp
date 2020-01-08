#include <bits/stdc++.h>
#define vi vector <int>
#define vvi vector <vi>
using namespace std;

const int N = 1e5+7;
const int inf = 1e9+7;

int cnt = 0, t = 0, num_bridge = 0;
vvi edge;
int n, m;
int parent[N];
bool vis[N][2];
int flag;

void dfs(int u, int pa, int ti)
{
	//cout << u << " " << parent[u] << endl;
	if (vis[u][ti]) return;
	vis[u][ti] = 1;
	for (int i = 0; i < edge[u].size(); i++)
	{
		int v = edge[u][i];
		if (v == pa) continue;
		if (vis[v][ti]) 
		{
			flag = u;
			if (parent[v] == -1) parent[v] = u;
		}
		if (!vis[v][ti])
		{
			parent[v] = u;
			dfs(v, u, ti);
		}
	}
	return;
}

main(){
	freopen("in.inp","r",stdin);
	scanf("%d%d", &n, &m);
	edge.assign(n+1, vi());
	for (int i = 0; i < m; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		edge[x].push_back(y);
		edge[y].push_back(x);
	}
	memset(parent, -1, sizeof(parent));
	
	for (int i = 1; i <= n; i++)
	{
		if (vis[i][0]) continue; 
		flag = 0;
		dfs(i, -1, 0);
		if (flag == 0) 
		{
			printf("NIE\n");
			return 0;
		}
		parent[flag] = -1;
		dfs(flag, -1, 1);
	}
	
	printf("TAK\n");
	for (int i = 1; i <= n; i++) printf("%d\n",parent[i]);
}

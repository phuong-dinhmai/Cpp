#include <bits/stdc++.h>
#define vi vector <int>
#define ii pair <int, int>
using namespace std;

const int N = 1e5+7;

long long low[N], num[N], child[N];
long long n, m;
long long f[N], cnt = 0, total;
vi edge[N];

void dfs(int u, int pa)
{
	long long res = 0;
	child[u] = 1;
	num[u] = low[u] = ++cnt;
	for (int i = 0; i < edge[u].size(); i++) 
	{
		int v = edge[u][i];
		if (v == pa) continue;
		if (num[v] != 0)
		{
			low[u] = min(low[u], num[v]);
			continue;
		}
		else
		{
			dfs(v, u);
			child[u] += child[v];
			low[u] = min(low[u], low[v]);
		}
		if (low[v] >= num[u])
			f[u] += (child[v]*(child[v] - 1)), res += child[v];
	}
	f[u] += (n - res - 1)*(n - res - 2);
}

main(){
	//freopen("in.inp","r",stdin);
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		edge[x].push_back(y);
		edge[y].push_back(x);
	}
	
	total = (long long)n*(n-1);
	dfs(1, -1);

	for (int i = 1; i <= n; i++) printf("%lld\n", total - f[i]);
}

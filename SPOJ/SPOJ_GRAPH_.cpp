#include <bits/stdc++.h>
#define maxN 10001
#define vi vector <int>
#define ii pair <int, int>
#define inf 1000000007
using namespace std;

vi a[maxN];
int low[maxN], num[maxN];
int t = 0;
bool mark[maxN];
int parent[maxN];

vector <ii> bridge;

void dfs(int u, int root)
{
	num[u] = ++t;
	int child = 0;
	for (int i = 0; i < a[u].size(); i++)
	{
		int v= a[u][i];
		if (num[v] == 0)
		{
			child++;
			parent[v] = u;
			dfs(v, root);
			if (low[v] >= num[u] && u != root)  mark[u] = true;
			else if (u == root && child > 1) mark[u] = true;
			if (low[v] > num[u]) bridge.push_back(ii (u,v));
			low[u] = min(low[u], low[v]);
		}
		else 
		{
			if (parent[u] != v) low[u] = min (low[u], num[v]);
		}
	}
}

main(){
	//freopen ("in.inp","r",stdin);
	
	int n,m;
	int ans = 0;
	
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		a[i].clear();
		low[i] = inf;
		parent[i] = inf;
		num[i] = 0;
		mark[i] = false;
	}
	t = 0;
	
	for (int i = 0; i < m; i++) 
	{
		int x, y;
		cin >> x >> y;
		a[x-1].push_back(y-1);
		a[y-1].push_back(x-1);
	}	
	
	for (int i = 0; i < n; i++)
	{
		if (num[i] == 0) 
		{
			dfs(i,i);
		}
	}
		
	for (int i = 0; i < n; i++) 
	{
		if (mark[i]) ans++;
	}	
		
	cout << ans << " " << bridge.size() << endl;
}

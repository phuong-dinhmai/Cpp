#include <bits/stdc++.h>
#define maxN 10010
#define inf (int) (1e9+7)
#define vi vector <int>
using namespace std;

vi edge[maxN];
int d[maxN][3];
int n;

void dfs(int u, int pre)
{
	d[u][0] = 1;
	d[u][1] = inf;
	d[u][2] = 0;
	bool leaf = true;
	for (int i = 0; i < edge[u].size(); i++)
	{
		int v = edge[u][i];
		if (v == pre) continue;
		dfs(v,u);
		leaf = false;
		d[u][0] += min(d[v][0], min(d[v][1],d[v][2]));
		d[u][2] += min(d[v][0], d[v][1]);
	}
	if (!leaf)
	{
		for (int i = 0; i < edge[u].size(); i++)
		{
			int v = edge[u][i];
			if (v == pre) continue;
			d[u][1] = min(d[u][1], d[u][2] - min(d[v][0],d[v][1]) + d[v][0]);
		}
	}
}

main(){
	freopen("tower.inp","r",stdin);
	freopen("tower.out","w",stdout);
	cin >> n;
	for (int i = 0; i < n-1; i++)
	{
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		edge[x].push_back(y);
		edge[y].push_back(x);
	}
	dfs(0, -1);
	cout << min(d[0][1], d[0][0]) << endl;
}

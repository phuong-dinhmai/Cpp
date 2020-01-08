#include <bits/stdc++.h>
#define vi vector <int>
#define vvi vector <vi>
using namespace std;

const int N = 1e5+7;

vvi edge;
int del[N];
int legs[N];
int n;

void dfs(int u, int pa)
{
	if (edge[u].size() < 3)
	{
		del[u] = true;
		for (int i = 0; i < edge[u].size(); i++)
		{
			int v = edge[u][i];
			if (v != pa) dfs(v, u);
		}
	}
}

main(){
	//freopen("in.inp","r",stdin);
	cin >> n;
	edge.assign(n+1, vi());
	for (int i = 1; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		edge[x].push_back(y);
		edge[y].push_back(x);
	}
	
	for (int i = 1; i <= n; i++)
	{
		if (edge[i].size() == 1) dfs(i, 0); // neu nhu i la mot dau cua day thi dfs xoa ca day goc
	}
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < edge[i].size(); j++)
		{
			int v = edge[i][j];
			if (del[v]) legs[i] = min(legs[i]+1, 2); // voi moi nut khong thuoc day goc thi chi co toi da 2 chan do chi cos the dang day hoac dang chu Y
		}
	}
	
	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		if (!del[i])
		{
			if (edge[i].size() - legs[i] > 1) ++cnt; 
		}
		if (cnt > 2) // moi nut thi chi co toi da 3 canh noi chung khi co dang chu Y
		{
			printf("No\n");
			return 0;
		}
	}
	
	printf("Yes\n");
	return 0;
}

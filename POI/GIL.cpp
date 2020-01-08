#include <bits/stdc++.h>
#define vi vector <int>
using namespace std;

const int N = 2e5+7;

bool vis[N], col[N];
int n, m;
vi edge[N];

void bfs(int start) {
	queue <int> q;
	q.push(start);
	col[start] = 1;
	vis[start] = 1;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int i = 0; i < edge[u].size(); i++) {
			int v = edge[u][i];
			if (vis[v]) continue;
			q.push(v);
			col[v] = col[u] ^ 1;
			vis[v] = true;
		}
	}
}

main(){
	//freopen("in.inp","r",stdin);
	
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		edge[x].push_back(y);
		edge[y].push_back(x);
	}
	
	for (int i = 1; i <= n; i++) {
		if (edge[i].size() == 0) {
			printf("NIE\n");
			return 0;
		}
		if (!vis[i]) bfs(i);
	}
	
	printf("TAK\n");
	for (int i = 1; i <= n; i++) {
		if (col[i]) printf("K\n"); else printf("S\n");
	}
}

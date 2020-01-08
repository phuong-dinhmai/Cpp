#include <bits/stdc++.h>
#define fi first
#define se second
#define ii pair <int, int>
#define vi vector <int>
#define vii vector <ii>
using namespace std;

const int N = 1e4+7;

int n, m, q;
vii bridge;
int cnt;
int low[N], num[N], father[N];
vi edge[N];

void dfs(int u, int pa){
	num[u] = low[u] = ++cnt;
	for (int i = 0; i < edge[u].size(); i++){
		int v = edge[u][i];
		if (v == pa) continue;
		if (num[v]) low[u] = min(low[u], num[v]);
		else {
			dfs(v, u);
			low[u] = min(low[u], low[v]);
			if (low[v] >= num[v]) bridge.push_back(ii(u, v));
		}
	}
}

int find(int u) {
	return (u == father[u]? u : father[u] = find(father[u]));
}

bool same_set(int x, int y) {
	return find(x) == find(y);
}

void make_set(int i, int j) {
	int x = find(i), y = find(j);
	father[x] = y;
}

main(){
//	freopen("in.inp","r",stdin);
	ios_base :: sync_with_stdio(false); cin.tie(0);
	
	while (cin >> n >> m >> q && (n+m+q)) {
		for (int i = 0; i <= n; i++) num[i] = low[i] = 0, edge[i].clear();
		bridge.clear();
		cnt = 0;
		
		for (int i = 0; i < m; i++){
			int x, y;
			cin >> x >> y;
			edge[x].push_back(y);
			edge[y].push_back(x);
		}
		
		dfs(1, -1);
		
		for (int i = 1; i <= n; i++) father[i] = i;
		for (int i = 0; i < bridge.size(); i++) {
			int u = bridge[i].fi, v = bridge[i].se;
			if (!same_set(u, v)) make_set(u, v);
		}
		
		while (q--) {
			int x, y;
			cin >> x >> y;
			if (same_set(x, y)) cout << "Y" << endl; else cout << "N" << endl;
		}
		cout << "-" << endl;
	}
}

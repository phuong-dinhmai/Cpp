#include <bits/stdc++.h>
#define ii pair <int, int>
#define x first
#define y second
#define vi vector <int>
using namespace std;

const int N = 5e4 + 7;
const int M = 1e5+7;

vi edge[N];
int n, m, test;
int par[N][20], father[N], d[N];
ii a[M];
bool bridge[M];

void dfs(int u, int pa){
	for (int i = 0; i < edge[u].size(); i++) {
		int v = edge[u][i];
		if (v == pa) continue;
		par[v][0] = u;
		d[v] = d[u] + 1;
		dfs(v, u);
	}
}

int find(int u) {
	return (u == father[u]? u: father[u] = find(father[u]));
}

bool same_set(int u, int v) {
	return (find(u) == find(v));
}

void make_set(int i, int j) {
	int x = find(i), y = find(j);
	if (d[x] < d[y]) father[y] = x; else father[x] = y;
}

int lca(int u, int v) {
	if (d[u] > d[v]) swap(u, v);
	for (int i = 16; i >= 0; i--) {
		if (d[par[v][i]] >= d[u]) v = par[v][i];
	}
	if (u == v) return u;
	
	for (int i = 16; i >= 0; i--) {
		if (d[par[u][i]] != d[par[v][i]]) u = par[u][i], v = par[v][i];
	}
	while (u != v) {
		u = par[u][0];
		v = par[v][0];
	}
	
	return u;
}

void init() {
	for (int i = 1; i <= n; i++) father[i] = i, d[i] = 0, edge[i].clear();
	memset(par, 0, sizeof(par));
	for (int i = 0; i < m; i++) bridge[i] = false;
}

main(){
	//freopen("in.inp","r",stdin);
	//freopen("out.out","w",stdout);
	
	scanf("%d", &test);
	while (test--) {
		scanf("%d%d", &n, &m);
		init();
		int ans = 0;
		for (int i = 0; i < m; i++){
			scanf("%d%d", &a[i].x, &a[i].y);
			a[i].x++; a[i].y++;
			if (!same_set(a[i].x, a[i].y)) {
				make_set(a[i].x, a[i].y);
				bridge[i] = true;
				edge[a[i].x].push_back(a[i].y);
				edge[a[i].y].push_back(a[i].x);
			}
		}
		
		for (int i = 1; i <= n; i++) {
			if (!d[i]) {
				d[i] = 1;
				dfs(i, -1);
			}
		}
				
		for (int j = 1; j < 17; j++)	{
			for (int i = 1; i <= n; i++) {
				par[i][j] = par[par[i][j-1]][j-1];
			}
		}
		
		for (int i = 1; i <= n; i++) father[i] = i;
		for (int i = 0; i < m; i++) {
			int u = a[i].x, v = a[i].y;
			if (!bridge[i]){
				int finish = lca(u, v);
				while (d[u] > d[finish]) {
					u = find(u);
					if (d[u] <= d[finish]) break;
					ans--;
					father[u] = par[u][0];
				}
				while (d[v] > d[finish]) {
					v = find(v);
					if (d[v] <= d[finish]) break;
					ans--;
					father[v] = par[v][0];
				}
			} else ans++;
			printf("%d\n", ans);
		}
	}
	return 0;
}

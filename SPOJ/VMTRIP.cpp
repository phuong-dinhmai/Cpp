#include <bits/stdc++.h>
#define vi vector <int>
using namespace std;

const int N = 1e5+7;

int n, m, s, t;
int d[2][N], in[N], out[N], p[N], ans[N];
bool del[N];
vi edge[N], layer[N];

void bfs(int start, int num) {
	d[num][start] = 0;
	queue <int> q;
	q.push(start);
	while (!q.empty()){
		int u = q.front();
		q.pop();
		for (int i = 0; i < edge[u].size(); i++) {
			int v = edge[u][i];
			if (d[num][v] != -1) continue;
			d[num][v] = d[num][u] + 1;
			q.push(v);
		}
	}
}

void erase(int u){
	if (del[u]) return;
	del[u] = true;
	for (int i = 0; i < edge[u].size(); i++) {
		int v = edge[u][i];
		if (d[1][v] == d[1][u] + 1) in[v]--;
		if (d[1][v] == d[1][u] - 1) out[v]--;
		if (in[v] == 0 && v != s) erase(v);
		if (out[v] == 0 && v != t) erase(v);
	}
}

main(){
	//freopen("in.inp","r",stdin);
	ios_base :: sync_with_stdio(false); cin.tie(0);
	
	cin >> n >> m >> s >> t;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		edge[x].push_back(y);
		edge[y].push_back(x);
	}
	
	memset(d, -1, sizeof(d));
	bfs(s, 1);
	bfs(t, 0);
	
	int k = d[1][t];
	for (int i = 0; i <= k; i++) cin >> p[i], p[i]--;
	
	for (int i = 1; i <= n; i++) {
		if (d[1][i] + d[0][i] == k) layer[d[1][i]].push_back(i); else del[i] = true;
	}
	
	for (int i = 1; i <= n; i++) {
		if (del[i]) continue;
		for (int j = 0; j < edge[i].size(); j++) {
			int v = edge[i][j];
			if (del[v]) continue;
			if (d[1][v] + 1 == d[1][i]) in[i]++;
			if (d[1][v] - 1 == d[1][i]) out[i]++;
		}
	}
	
	for (int i = 0; i <= k; i++) {
		int res = N;
		for (int j = 0; j < layer[p[i]].size(); j++) {
			int v = layer[p[i]][j];
			if (del[v]) continue;
			res = min(res, v);
		}
		ans[p[i]] = res;
		for (int j = 0; j < layer[p[i]].size(); j++) {
			int u = layer[p[i]][j];
			if (u != res) erase(u);
		}
	}
	
	for (int i = 0; i <= k; i++) cout << ans[i] << " ";
	/*for (int i = 0; i <= k; i++) {
		cout << layer[i].size() << endl;
		for (int j = 0; j < layer[i].size(); j++) cout << layer[i][j] << " "; 
		cout << endl;
	}*/
}

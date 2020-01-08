#include <bits/stdc++.h>
#define vi vector <int>
#define ii pair <int, int>
#define fi first
#define se second
#define vii vector <ii>
using namespace std;

const int N = 3e4+7;

int n, m;
int d[2][N], cnt[2][N];
vii edge[N];
vi ans;

void dijkstra (int start, int en, int x) {
	priority_queue <ii, vii, greater <ii> > pq;
	d[x][start] = 0, cnt[x][start] = 1;
	pq.push(ii(0, start));
	
	while (!pq.empty()) {
		ii t = pq.top();
		pq.pop();
		int u = t.se;
		if (t.fi > d[x][u]) continue;
		if (u == en) break;
		for (int i = 0; i < edge[u].size(); i++) {
			int v = edge[u][i].fi;
			int c = edge[u][i].se;
			if (d[x][v] > d[x][u] + c) {
				d[x][v] = d[x][u] + c;
				cnt[x][v] = cnt[x][u];
				pq.push(ii(d[x][v], v));
			}
			else if (d[x][v] == d[x][u] + c) {
				cnt[x][v] += cnt[x][u];
			}
		}
	}
}

main(){
	//freopen("in.inp","r",stdin);
	ios_base :: sync_with_stdio(false); cin.tie(0);
	
	cin >> n >> m;
	for (int i = 0; i < m; i++){
		int x, y, c;
		cin >> x >> y >> c;
		edge[x].push_back(ii(y, c));
		edge[y].push_back(ii(x, c));
	}
	memset(d, 0x3f, sizeof(d));
	dijkstra(1, n, 0);
	dijkstra(n, 1, 1);
	
	for (int i = 2; i < n; i++) {
		if (d[0][i] + d[1][i] != d[0][n] || cnt[0][i]*cnt[1][i] != cnt[0][n]) ans.push_back(i);
	}
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++) cout << ans[i] << endl;
}

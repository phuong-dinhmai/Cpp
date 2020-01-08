#include <bits/stdc++.h>
#define ii pair <int, int>
#define vii vector <ii>
#define fi first
#define se second
using namespace std;

const int N = 1e3+7;

vii edge[N];
int d[N];
priority_queue <ii, vector <ii>, greater <ii> > pq;
int n, m;

main(){
	//freopen("in.inp","r",stdin);
	ios_base :: sync_with_stdio(false); cin.tie(0);
	
	cin >> n >> m;
	for (int i = 0; i < m; i++){
		int x, y;
		cin >> x >> y;
		int c = abs(x - y);
		edge[x].push_back(ii(y, c));
		edge[y].push_back(ii(x, c));
	}
	
	memset(d, 0x3f, sizeof(d));
	pq.push(ii(0, 1));
	d[1] = 0;
	while (!pq.empty()) {
		ii t = pq.top();
		pq.pop();
		int u = t.se;
		if (t.fi > d[u]) continue;
		if (u == n) {
			cout << t.fi*5 << endl;
		}
		for (int i = 0; i < edge[u].size(); i++) {
			int v = edge[u][i].fi;
			int cycle = 2*edge[u][i].se, wait = 0;
			if (v > u) {
				int x = t.fi % cycle;
				if (x != 0) {
					wait += cycle - x;
				}
			}
			else {
				int x = (t.fi + cycle/2) % cycle;
				if (x != 0) {
					wait += cycle - x;
				}
			}
			wait += cycle/2;
			if (d[v] > d[u] + wait) {
				d[v] = d[u] + wait;
				pq.push(ii(d[v], v));
			}
		}
	}
}

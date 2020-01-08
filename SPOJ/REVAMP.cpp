#include <bits/stdc++.h>
#define ii pair <int, int>
#define fi first
#define se second
#define vii vector <ii>
using namespace std;

const int N = 1e4+7;
const int K = 25;

struct data {
	int node, cost, num;
	data (int _cost, int _node, int _num) {cost = _cost, node = _node, num = _num;}
	
	bool operator < (const data &other) const {return cost > other.cost;}
};

priority_queue <data> pq;
int n, m, k;
int d[N][K];
vii edge[N];

main(){
	//freopen("in.inp","r",stdin);
	ios_base :: sync_with_stdio(false); cin.tie(0);
	
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		int x, y, c;
		cin >> x >> y >> c;
		edge[x].push_back(ii(y, c));
		edge[y].push_back(ii(x, c));
	}
	
	memset(d, 0x3f, sizeof(d));
	
	pq.push(data(0, 1, 0));
	d[1][0] = 0;
	while (!pq.empty()) {
		data t = pq.top();
		pq.pop();
		int u = t.node, used = t.num;
		if (t.cost > d[u][used]) continue;
		if (u == n) {
			cout << d[n][used] << endl;
			return 0;
		}
		for (int i = 0; i < edge[u].size(); i++) {
			int v = edge[u][i].fi;
			int cost = edge[u][i].se;
			if (d[v][used] > d[u][used] + cost) {
				d[v][used] = d[u][used] + cost;
				pq.push(data(d[v][used], v, used));
			}
			if (used < k && d[v][used + 1] > d[u][used]) {
				d[v][used + 1] = d[u][used];
				pq.push(data(d[v][used + 1], v, used + 1));
			}
		}
	}
}

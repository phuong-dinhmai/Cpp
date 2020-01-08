#include <bits/stdc++.h>
#define vi vector <int>
#define ii pair <int, int>
using namespace std;

const int inf = 0x3f3f3f3f;
const int N = 101;
const int lim = 1e5;

struct data {
	int dis, cost, node;
	data (int _dis, int _cost, int _node) {
		dis = _dis, cost = _cost, node = _node;
	}
	
	bool operator < (const data &other) const  {return dis > other.dis;}
};

priority_queue <data> pq;
int test;
int n, m, D, ans;
int d[N][lim + 10];
vector <data> edge[N];

void init() {
	for (int i = 0; i <= n; i++) edge[i].clear();
	memset(d, 0x3f, sizeof(d));
	while (!pq.empty()) pq.pop();
	ans = inf;
}

main(){
	//freopen("in.inp","r",stdin);
	ios_base :: sync_with_stdio(false); cin.tie(0);
	
	cin >> test;
	while (test--) {
		cin >> D;
		cin >> n >> m;
		init();
		for (int i = 0; i < m; i++) {
			int x, y, dis, cost;
			cin >> x >> y >> dis >> cost;
			edge[x].push_back(data(dis, cost, y));
		}
		
		pq.push(data(0, 0, 1));
		d[1][0] = 0;
		while (!pq.empty()) {
			data t = pq.top();
			pq.pop();
			if (t.dis > d[t.node][t.cost]) continue;
			if (t.node == n) {
				ans = d[t.node][t.cost];
				break;
			}
			for (int i = 0; i < edge[t.node].size(); i++) {
				int v = edge[t.node][i].node;
				int c = edge[t.node][i].cost;
				int k = edge[t.node][i].dis;
				if (t.cost + c > D) continue; 
				if (d[v][t.cost + c] > d[t.node][t.cost] + k) {
					d[v][t.cost + c] = d[t.node][t.cost] + k;
					pq.push(data(d[v][t.cost + c], t.cost+c, v));
				}
			}
		}
		
		if (ans != inf) cout << ans << endl; else cout << -1 << endl;
	}
}

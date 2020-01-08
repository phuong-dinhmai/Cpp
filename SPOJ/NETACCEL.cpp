#include <bits/stdc++.h>
#define id pair <int, double>
#define fi first
#define se second
#define vid vector <id>
using namespace std;

const int N = 1005;
const double inf = 1e9+7;

struct data {
	int node, num;
	double cost;
	data (double _cost, int _node, int _num) {cost = _cost, node = _node, num = _num;}
	
	bool operator < (const data &other) const {return cost > other.cost;}
};

priority_queue <data> pq;
int n, m, k;
vid edge[N];
double d[N][N];

main(){
	//freopen("in.inp","r",stdin);
	ios_base :: sync_with_stdio(false); cin.tie(0);
	
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		int x, y;
		double c;
		cin >> x >> y >> c;
		edge[x].push_back(id(y, c));
		edge[y].push_back(id(x, c));
	}
	
	for (int i = 0; i <= n; i++) 
		for (int j = 0; j <= k; j++) d[i][j] = inf;
	
	pq.push(data(0.00, 1, 0));
	d[1][0] = 0.00;
	while (!pq.empty()) {
		data t = pq.top();
		int u = t.node;
		int used = t.num;
		pq.pop();
		//cout << u << " " << used << " " << t.cost << endl;
		if (t.cost > d[u][used]) continue;
		if (u == n) {
			printf("%.2lf\n", t.cost);
			return 0;
		}
		for (int i = 0; i < edge[u].size(); i++) {
			double cost = edge[u][i].se;
			int v = edge[u][i].fi;
			if (d[v][used] > d[u][used] + cost) {
				d[v][used] = d[u][used] + cost;
				pq.push(data(d[v][used], v, used));
			}
			double div = 1.00;
			for (int j = 1; j <= (k - used); j++) 
			{
				div *= 2;
				if (d[v][used + j] > d[u][used] + cost / div) {
					d[v][used + j] = d[u][used] + cost / div;
					pq.push(data(d[v][used + j], v, used + j));
				}
			}
		}
	}
}

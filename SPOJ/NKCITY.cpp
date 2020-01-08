#include <bits/stdc++.h>
using namespace std;

const int N = 1e4+7;

struct data{
	int node1, node2, cost;
	data (int _node1, int _node2, int _cost) {node1 = _node1, node2 = _node2, cost = _cost;}
	bool operator < (const data &other) const {return cost < other.cost;}
};

vector <data> edge;
int n, m, father[N];

int find(int u) { return (father[u] < 0? u : father[u] = find(father[u]));}
bool same_set(int u, int v) {return (find(u) == find(v));}
void make_set(int i, int j) {
	int u = find(i), v = find(j);
	if (father[u] > father[v]) father[u] += father[v], father[v] = u;
	else father[v] += father[u], father[u] = v;
}

main(){
	//freopen("in.inp","r",stdin);
	ios_base :: sync_with_stdio(false); cin.tie(0);
	
	cin >> n >> m;
	memset(father, -1, sizeof(father));
	for (int i = 0; i < m; i++) {
		int x, y, c;
		cin >> x >> y >> c;
		edge.push_back(data(x, y, c));
	}
	
	int ans = 0;
	sort(edge.begin(), edge.end());
	for (int i = 0; i < edge.size(); i++) {
		int u = edge[i].node1, v = edge[i].node2;
		if (!same_set(u, v)) {
			make_set(u, v);
			ans = edge[i].cost;
		}
	}
	
	cout << ans << endl;
}

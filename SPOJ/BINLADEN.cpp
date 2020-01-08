#include <bits/stdc++.h>
#define ii pair <int, int>
#define fi first
#define se second
#define vii vector <ii>
using namespace std;

const int N = 2225;
const int M = 11;

int n, m;
vii edge[N*M];
int d[N*M];
priority_queue <ii, vector <ii>, greater <ii> > pq;

void add(int u, int v, int c) {
	edge[u].push_back(ii(v, c));
	edge[v].push_back(ii(u, c));
}

main(){
	//freopen("in.inp","r",stdin);
	ios_base :: sync_with_stdio(false); cin.tie(0);
	
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int c;
		for (int j = 1; j <= m; j++) {
			cin >> c;
			if (i) add((i-1)*m + j, i*m + j, c);
			else add(0, j, c);
		}
		
		for (int j = 1; j < m; j++) {
			cin >> c;
			add(i*m+j, i*m+j+1, c);
		}
	} 
	
	memset(d, 0x3f, sizeof(d));
	pq.push(ii(0, 0));
	d[0] = 0;
	while (!pq.empty()){
		ii t = pq.top();
		pq.pop();
		int u = t.se;
		if (t.fi > d[u]) continue;
		if (u == n*m) {
			cout << d[n*m] << endl;
			return 0;
		}
		for (int i = 0; i < edge[u].size(); i++) {
			int v = edge[u][i].fi;
			int cost = edge[u][i].se;
			if (d[v] > d[u] + cost) {
				d[v] = d[u] + cost;
				pq.push(ii(d[v], v));
			}
		}
	}
}

#include <bits/stdc++.h>
#define vi vector <int>
using namespace std;

const int N = 1005;
const int inf = 0x3ffffff;

vi edge[N];
int n, m, k;
int d[N];

main(){
	//freopen("in.inp","r",stdin);
	ios_base :: sync_with_stdio(false); cin.tie(0);
	
	cin >> n >> k >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			int x;
			cin >> x;
			if (x) edge[i].push_back(j);
		}
		
	memset(d, -1, sizeof(d));
		
	d[m] = 0;	
	queue <int> q;
	q.push(m);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int i = 0; i < edge[u].size(); i++){
			int v = edge[u][i];
			if (d[v] != -1) continue;
			d[v] = d[u] + 1;
			q.push(v);
		}
	}
	
	for (int i = 1; i <= n; i++) {
		//cout << d[i] << endl;
		if (d[i] <= k && d[i] != -1) cout << 1 << " "; else cout << 0 << " ";
	}
	cout << endl;
}

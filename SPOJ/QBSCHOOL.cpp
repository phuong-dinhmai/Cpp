#include <bits/stdc++.h>
#define ll long long
#define il pair <int, ll>
#define li pair <ll, int>
#define fi first
#define se second
#define vil vector <il>
using namespace std;

const int N = 5e3+7;

int n, m;
vil edge[N];
priority_queue <li, vector <li>, greater <li> > pq;
ll d[N], cnt[N];

main(){
	//freopen("in.inp","r",stdin);
	ios_base :: sync_with_stdio(false); cin.tie(0);
	
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int type, x, y;
		ll c;
		cin >> type >> x >> y >> c;
		edge[x].push_back(il(y, c));
		if (type == 2) edge[y].push_back(il(x, c));
	}
	
	memset(d, 0x3f, sizeof(d));
	memset(cnt, 0, sizeof(cnt));
	d[1] = 0; cnt[1] = 1;
	pq.push(li(0, 1));
	while (!pq.empty()) {
		li t = pq.top(); pq.pop();
		int u = t.se;
		if (d[u] < t.fi) continue;
		if (u == n) break;
		for (int i = 0; i < edge[u].size(); i++) {
			int v = edge[u][i].fi;
			ll c = edge[u][i].se;
			if (d[v] > d[u] + c) {
				d[v] = d[u] + c;
				cnt[v] = cnt[u];
				pq.push(li(d[v], v));
			}
			else if (d[v] == d[u] + c) {
				cnt[v] += cnt[u];
			}
		}
	}
	
	//for (int i = 1; i <= n; i++) cout << cnt[i] << " "; cout << endl;
	cout << d[n] << " " << cnt[n] << endl;
}

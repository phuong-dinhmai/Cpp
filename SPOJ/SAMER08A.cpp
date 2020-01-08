#include <bits/stdc++.h>
using namespace std;

#define ii pair <int, int>
#define ll long long
#define val first
#define pos second

const int maxN = 505;
const int inf = 1e9+7;

vector <ii> edge[maxN];
vector <int> pre[maxN];
int dis[maxN];
bool vis[maxN];

int n, m;

bool path(int st, int en){
	priority_queue <ii, vector <ii>, greater <ii> > q;
	q.push(ii(0, st));
	memset(dis, inf, sizeof(dis));
	dis[st] = 0;
	
	while (!q.empty()){
		ii t = q.top();
		q.pop();
		for (int i = 0; i < edge[t.pos].size(); ++i){
			ii v = edge[t.pos][i];
			if (dis[v.pos] > dis[t.pos] + v.val){
				q.push(ii(dis[v.pos], v.pos));
				dis[v.pos] = dis[t.pos] + v.val;
				pre[v.pos].clear();
				pre[v.pos].push_back(t.pos);
			} else if (dis[v.pos] == dis[t.pos] + v.val){
				pre[v.pos].push_back(t.pos);
				//q.push(ii(dis[v.pos], v.pos));
			}
		}
	//	cout << t.pos << endl;
	}
	//cout << pre[en].size() << endl;
	if (dis[en] == inf) return false; else return true;
}

void trace(int st, int en){
	queue <int> q;
	memset(vis, false, sizeof (vis));
	vis[en] = true;
	q.push(en);
	//cout << en << " " << pre[en].size() << endl;
	while (!q.empty()){
		int pos = q.front(); q.pop();
		for (int i = 0; i < pre[pos].size(); ++i){
			int v = pre[pos][i];
			//cout << v << " " << vis[v] << endl;
			if (vis[v]) continue;
			vis[v] = true;
			q.push(v);
		}
		//cout << pos << endl;
	}
	//for (int i = 0; i < n; ++i)
	//	if (vis[i]) cout << i << " "; cout << endl;
	vis[st] = false;
	for (int i = 0; i <= n; ++i) pre[i].clear();
}

int m_path(int st, int en){
	priority_queue <ii, vector <ii>, greater <ii> > q;
	q.push(ii(0, st));
	memset(dis, inf, sizeof(dis));
	dis[st] = 0;
	
	while (!q.empty()){
		ii t = q.top();
		q.pop();
		//cout << t.pos << endl;
		if (t.pos == en) return t.val;
		if (vis[t.pos]) continue;
		if (t.val != dis[t.pos]) continue;
		for (int i = 0; i < edge[t.pos].size(); ++i){
			ii v = edge[t.pos][i];
			if (t.pos == st && v.pos == en) continue;
			if (dis[v.pos] > dis[t.pos] + v.val){
				dis[v.pos] = dis[t.pos] + v.val;
				q.push(ii(dis[v.pos], v.pos));
			} 
		}
	}
	return -1;
}

main(){
	freopen("in.inp","r",stdin);
	while (cin >> n >> m){
		if (n == 0 && m == 0) break;
		int st, en;
		cin >> st >> en;
		for (int i = 0; i < m; ++i){
			int u, v, w;
			cin >> u >> v >> w;
			edge[u].push_back(ii(w, v));
		}
		if (!path(st, en)) {
			cout << -1 << endl; 
			continue;
		}
		//cout << pre[en].size() << endl;
		trace(st, en);
		cout << m_path(st, en) << endl;
		for (int i = 0; i <= n; ++i) edge[i].clear();
	}
}

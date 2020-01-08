#include <bits/stdc++.h>
using namespace std;

#define ii pair <int, int>
#define pos second
#define val first

const int inf = 1e9+7;
const int maxN = 1e5+5;

int test, n, m;
map <string, int> mp;
vector <ii> edge[maxN];

int path(int st, int en){
	priority_queue <ii, vector <ii>, greater <ii> > q;
	vector <int> dis (n+1, inf);
	dis[st] = 0;
	q.push(make_pair(0, st));
	
	while(!q.empty()){
		ii t = q.top(); 
		q.pop();
		if (dis[t.pos] != t.val) continue;
		if (t.pos == en) return t.val;
		for (int i = 0; i < edge[t.pos].size(); ++i){
			ii v = edge[t.pos][i];
			if (dis[v.pos] > dis[t.pos] + v.val) {
				dis[v.pos] = dis[t.pos] + v.val;
				q.push(make_pair(dis[v.pos], v.pos));
			}
		}
	}
	return inf;
}

main(){
	//freopen("in.inp","r",stdin);
	cin >> test;
	while (test--){
		cin >> n;
		for (int i = 1; i <= n; ++i){
			string name;
			int u, w, k;
			cin >> name >> k;
			for (int j = 0; j < k; ++j){
				cin >> u >> w;
				edge[i].push_back(make_pair(w, u));
			}
			mp[name] = i;
		}
		cin >> m;
		for (int i = 0; i < m; ++i){
			string st, en;
			cin >> st >> en;;
			cout << path(mp[st], mp[en]) << endl;
		}
		mp.clear();
		for (int i = 1; i <= n; i++) edge[i].clear();
	}
}

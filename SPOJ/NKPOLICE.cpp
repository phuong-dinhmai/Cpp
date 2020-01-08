#include <bits/stdc++.h>
#define ii pair <int, int>
#define vi vector <int>
using namespace std;

const int N = 1e5+7;

int start[N], en[N], low[N], num[N], group[N], par[N];
bool vis[N];
vi edge[N];
int n, m, q;
int t, cnt, root;
set <int> s;
set <ii> bridge;

void dfs(int u, int pa) {
	par[u] = pa;
	group[u] = t;
	int child = 0;
	
	num[u] = low[u] = start[u] = ++cnt;
	for (int i = 0; i < edge[u].size(); i++){
		int v = edge[u][i];
		if (v == pa) continue;
		if (num[v]) {
			low[u] = min(low[u], num[v]);
		}
		else {
			dfs(v, u);
			child ++;
			if (low[v] >= num[u] && u != root) s.insert(u);
			else if (u == root && child > 1) s.insert(u);
			if (low[v] > num[u]) bridge.insert(ii(u, v));
			low[u] = min(low[u], low[v]);
		}
	}
	en[u] = cnt;
}

main(){
	//freopen("in.inp","r",stdin);
	//freopen("out.out","w",stdout);
	ios_base :: sync_with_stdio(false); 
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		edge[x].push_back(y);
		edge[y].push_back(x);
	}
	
	for (int i = 1; i <= n; i++) {
		if (!num[i]) {
			t++;
			root = i;
			dfs(i, -1);
		}
	}
	
	cin >> q;
	//q = 34;
	while (q--){
		int type, x, y, g1, g2;
		cin >> type;
		if (type == 1) {
			cin >> x >> y >> g1 >> g2;
			if (group[x] != group[y]) cout << "no" << endl;
			else {
				if (group[g1] != group[x]) cout << "yes" << endl;
				else {
					if (start[g1] > start[g2]) swap(g2, g1);
					if (bridge.find(ii(g1, g2)) == bridge.end()) cout << "yes" << endl;
					else {
						int k = 0;
						char h;
						if (start[x] >= start[g2] && en[x] <= en[g2]) k++, h = 'x';
						if (start[y] >= start[g2] && en[y] <= en[g2]) k++, h = 'y';
						if (k != 1) cout << "yes" << endl;
						else cout << "no" << endl;
					}
				}
			}
		}
		else {
			cin >> x >> y >> g1;
			if (group[x] != group[y]) cout << "no" << endl;
			else {
				if (group[g1] != group[x]) cout << "yes" << endl;
				else {
					if (s.find(g1) == s.end()) cout << "yes" << endl;
					else {
						int x1 = 0, y1 = 0, k = 0;
						for (int i = 0; i < edge[g1].size(); i++) {
							int v = edge[g1][i];
							if (par[v] != g1) continue;
							if (start[x] >= start[v] && en[x] <= en[v] && (x1 == 0 || start[x1] > start[v])) x1 = v;
							if (start[y] >= start[v] && en[y] <= en[v] && (y1 == 0 || start[y1] > start[v])) y1 = v;
						}
						if (x1 == y1 && x1 == 0) cout << "yes" << endl;
						else if (x1 == y1) cout << "yes" << endl;
						else if (x1 != 0 && y1 == 0) { 
							if (low[x1] < num[g1]) cout << "yes" << endl; else cout << "no" << endl;
							} 
						else if (x1 == 0 && y1 != 0) {
							if (low[y1] < num[g1]) cout << "yes" << endl; else cout << "no" << endl;
							}
						else {
							if (s.find(x1) != s.end()) k++;
							if (s.find(y1) != s.end()) k++;
							if (k == 0) cout << "yes" << endl; else cout << "no" << endl;
						}
					}
				}
			}
		}
	}
	
	//for (set <ii> :: iterator it = bridge.begin(); it != bridge.end(); it++) cout << (*it).first << " " << (*it).second << endl;
}

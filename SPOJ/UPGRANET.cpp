#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ii pair <ll, ll>
#define va first
#define pos second

const int maxN = 100005;
const ll inf = 1e9+7;

struct nodes {
	ll st, en, val;
};

bool cmp(nodes x, nodes y){
	return (x.val > y.val);
}

nodes lis[maxN];
vector <ii> edge[maxN];


int n, m;
bool ex[maxN];
int par[maxN], level[maxN], f[maxN][20];
ll f_min[maxN][20];

int find(int i){
	if (par[i] == i) return i;
	else {
		return par[i] = find(par[i]);
	}
}

void dfs(int p, int pre){
	//cout << p << " " << pre << endl;
	for (int i = 0; i < edge[p].size(); ++i){
		ii x = edge[p][i];
		if (x.pos != pre) {
			f[x.pos][0] = p; f_min[x.pos][0] = (ll)x.va;
			level[x.pos] = level[p] + 1;
			for (int j = 1; j < 19; ++j) {
				f[x.pos][j] = f[f[x.pos][j-1]][j-1];
				f_min[x.pos][j] = min(f_min[f[x.pos][j-1]][j-1], f_min[x.pos][j-1]);
			}
			dfs(x.pos, p);
		}
	}
	return;
}

ll lca (int u, int v){
	ll ans = 1LL*inf*inf;
	if (level[u] < level[v]) swap(u, v);
	ll dif = level[u] - level[v];
	for (int k = 18; k >= 0; --k) {
		if ((dif >> k) & 1){
			ans = min(ans, f_min[u][k]);
			u = f[u][k];
		}
		//cout << u << " " << v << endl;
	}
	
	if (u == v) return ans;
	for (int i = 18; i >= 0; --i){
		if (f[u][i] != f[v][i]) {
		ans = min(min(ans, f_min[u][i]), f_min[v][i]);
		u = f[u][i];
		v = f[v][i];
		}
	}
	ans = min(min(ans, f_min[u][0]), f_min[v][0]);
	return ans;
}

main(){
	freopen("in.inp","r",stdin);
	ios_base::sync_with_stdio(0);
	cin.tie();
	cout.tie();
	
	cin >> n >> m;
	for (int i = 0; i <= n; ++i) {
		par[i] = i;
	}
	for (int i = 0; i < m; ++i){
		cin >> lis[i].st >> lis[i].en >> lis[i].val;
	}
	sort(lis, lis + m, cmp);
	
	for (int i = 0; i < m; ++i){
		nodes x = lis[i];
		if (find(x.st) != find(x.en)) {
			//cout << find(x.st) << " " << find(x.en) << endl;
			par[find(x.st)] = par[find(x.en)];
			ex[i] = true;
			edge[x.st].push_back(ii(x.val, x.en));
			edge[x.en].push_back(ii(x.val, x.st));
		} else ex[i] = false;
	}
	//for (int i = 1; i <= n; i++) cout << find(i) << " "; cout << endl;
	
	level[1] = 0;
	dfs(1, 0);
	
	ll res = 0LL;
	for (int i = 0; i < m; ++i){
		nodes x = lis[i];
		if (!ex[i]) {
			res += max(0LL, lca(x.st, x.en) - x.val);
			//cout << lca (x.st, x.en) << " " << x.st << " " << x.en << endl;
		}
	}
	cout << res << endl;
}

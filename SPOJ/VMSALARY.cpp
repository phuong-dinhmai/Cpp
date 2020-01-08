#include <bits/stdc++.h>
#define ll long long
#define vi vector <int>
using namespace std;

const int N = 1e5+7;

struct data {
	int st, e, val, type;
	data (int _st, int _e, int _val, int _type) {st = _st, e = _e, val = _val, type = _type;}
	bool operator < (const data &other) const {
		return (val < other.val || (val == other.val && type > other.type));}
};

struct BIT{
	ll tree[N];
	void update(int pos, ll val) {
		for (; pos < N; pos += pos & (-pos)) tree[pos] += val;
	}
	ll get(int pos) {
		ll ans = 0;
		for (; pos > 0; pos -= pos & (-pos)) ans += tree[pos];
		return ans;
	}
} sum;

vi edge[N];
int a[N], start[N], en[N];
int n;
ll ans;
int cnt = 0;
vector <data> q;

void dfs(int u, int pa) {
	start[u] = ++cnt;
	for (int i = 0; i < edge[u].size(); i++) {
		int v = edge[u][i];
		if (v == pa) continue;
		dfs(v, u);	
	}
	en[u] = cnt;
}

main(){
//	freopen("in.inp","r",stdin);
	ios_base :: sync_with_stdio(false); cin.tie(0);
	
	cin >> n;
	cin >> a[1];
	for (int i = 2; i <= n; i++) {
		int x;
		cin >> x >> a[i];
		edge[x].push_back(i);
		edge[i].push_back(x);
	}

	dfs(1, -1);
	
	for (int i = 1; i <= n; i++) q.push_back(data(start[i], en[i], a[i], 1)), q.push_back(data(start[i], start[i], a[i], 0));
	
	sort(q.begin(), q.end());
	
	for (int i = 0; i < q.size(); i++) {
	//	cout << q[i].val << " " << q[i].st << " " << q[i].e << " " << q[i].type << endl;
		if (q[i].type == 0) sum.update(q[i].e, 1);
		else {
			ll x = sum.get(q[i].e) - sum.get(q[i].st);
			ans += x*(x-1)/2;
		}
	}
	
	cout << ans << endl;
}

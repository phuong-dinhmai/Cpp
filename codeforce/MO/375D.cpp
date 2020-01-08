#include <bits/stdc++.h>
#define vi vector <int>
#define vvi vector <vi>
using namespace std;

const int maxN = 1e5+7;

vvi edge;
int color[maxN], ans[maxN];
int start[10*maxN], en[10*maxN], cnt[10*maxN], large[10*maxN], dis[10*maxN];
int n, m, block;
int t = 0;
int L, R;

struct data {
	int l, r, id, val; 
} q[maxN];

bool cmp(const data &a, const data &b)
{
	return ((a.l / block < b.l / block) || (a.l / block == b.l / block && a.r < b.r));
}

void dfs(int u, int pa)
{
	start[u] = ++t;
	dis[t] = color[u];
	for (int i = 0; i < edge[u].size(); i++)
	{
		int v = edge[u][i];
		if (v != pa) dfs(v, u);
	}
	en[u] = t;
}

void add(int pos)
{
	cnt[dis[pos]]++;
	large[cnt[dis[pos]]]++;
}

void remove(int pos)
{
	large[cnt[dis[pos]]]--;
	cnt[dis[pos]]--;
}

void query(int i)
{
	while (R < q[i].r) add(++R);
	while (R > q[i].r) remove(R--);
	while (L < q[i].l) remove(L++);
	while (L > q[i].l) add(--L);
}

main(){
	//freopen("in.inp","r",stdin);
	ios_base :: sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	block = sqrt(n);
	L = R = 0;
	edge.assign(n+1, vi());
	for (int i = 1; i <= n; i++) cin >> color[i];
	for (int i = 1; i < n; i++) 
	{
		int x, y;
		cin >> x >> y;
		edge[x].push_back(y);
		edge[y].push_back(x);
	}
	dfs(1, 0);
	
	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		q[i].l = start[x];
		q[i].r = en[x];
		q[i].id = i;
		q[i].val = y;
	}
	sort(q, q+m, cmp);
	
	for (int i = 0; i < m; i++) query(i), ans[q[i].id] = large[q[i].val];
	for (int i = 0; i < m; i++) cout << ans[i] << endl;
}

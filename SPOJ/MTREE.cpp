#include <bits/stdc++.h>
#define ll long long
#define ii pair <int, int>
#define vii vector <ii>
#define vvii vector <vii>
#define fi first
#define se second
#define iii pair <int, ii>
using namespace std;

const ll mod = 1e9+7;
const ll maxN = 1e5+7;

vvii edge;
ll f[maxN];
int fa[maxN];
ll total[maxN];
ll ans = 0;
int n;

void dfs_first(int u, int pa)
{
	for (int i = 0; i < edge[u].size(); i++)
	{
		ii v = edge[u][i];
		if (v.fi != pa)
		{
			dfs_first(v.fi, u);
			f[u] = (f[u] + ((f[v.fi] + 1)*v.se) % mod) % mod;
		}
	}
	return;
}

void dfs_second(int u, int pa)
{
	if (u == pa) total[u] = f[u];
	for (int i = 0; i < edge[u].size(); i++)
	{
		ii v = edge[u][i];
		if (v.fi != pa)
		{
			total[v.fi] = (f[v.fi] + ((total[u] - (f[v.fi]+1LL)*v.se % mod + mod + 1) % mod *v.se % mod)) % mod; 
			dfs_second(v.fi, u);
		}
	}
	ans = (ans + total[u]) % mod;
	return;
}

main(){
	//freopen("in.inp","r",stdin);
	ios_base :: sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	edge.assign(n+10, vii());
	for (int i = 1; i < n; i++)
	{
		int x, y, cost;
		cin >> x >> y >> cost;
		edge[x].push_back(make_pair(y, cost));
		edge[y].push_back(make_pair(x, cost));
	}
	dfs_first(1, 1);
	dfs_second(1, 1);
	if (ans & 1) printf("%lld\n", (ans + mod) / 2);
	else printf("%lld\n", ans/2);
}

#include <bits/stdc++.h>
#define ll long long
#define vi vector <ll>
#define vvi vector <vi>
#define maxN (ll) (1e6+5)
using namespace std;

ll cir = 1;
ll a[3] = {0, 0, 0};
vvi edge;
bool vis[maxN];
ll chil[maxN];
ll low[maxN];
ll num[maxN];
ll c1, root, cnt = 0;
ll n, m;
ll t = 0;
ll bridge = 0;
ll ans;

void dfs(ll u, ll p)
{
	if (t == 1) c1++;
	low[u] = num[u] = ++cnt;
	chil[u] = 1;
	vis[u] = true;
	for (ll i = 0; i < edge[u].size(); i++)
	{
		ll v = edge[u][i];
		if (v != p)
		{
			if (!vis[v]) 
			{
				dfs(v, u);
				chil[u] += chil[v];
				low[u] = min(low[u], low[v]);
			} else low[u] = min(low[u], num[v]);
		}
	}
	if (root != u && low[u] == num[u]) bridge++;
}

main(){
	//freopen("in.inp","r",stdin);
	cin >> n >> m;
	edge.assign(n+1, vi());
	for (ll i = 0; i < m; i++)
	{
		ll x, y;
		cin >> x >> y;
		x--; y--;
		edge[x].push_back(y);
		edge[y].push_back(x);
	}
	fill(vis, vis+n+1, false);
	for (ll i = 0; i < n; i++)
	{
		if (!vis[i])
		{
			root = i;
			dfs(i, 0);
			t++;
		}
		if (t > 2) 
		{
			cout << 0 << endl;
			return 0; 
		}
	}
	if (t == 2)
	{
		ans = c1*(n-c1)*(m-bridge);
	} 
	else
	{
		ans = (m - bridge) * (n*(n-1)/2 - m);
		for (ll i = 1; i < n; i++)
		{
			if (low[i] == num[i]) ans += chil[i] * (n-chil[i]) - 1;
		}
 	}
	cout << ans << endl;
}

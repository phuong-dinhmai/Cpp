#include <bits/stdc++.h>
#define maxN 10001
#define vi vector <ll>
#define ll long long
using namespace std;

bool vis[maxN];
vi edge[maxN];
ll a[maxN];
ll b[maxN];
ll dis[maxN];
ll f[maxN];

void dfs(ll u)
{
	if (vis[u]) return;
	vis[u] = true;
	for (ll i = 0; i < edge[u].size(); i++)
	{
		ll v = edge[u][i];
		if (!vis[v])
		{
			f[u]++;
			dfs(v);
			f[u] += f[v];
		}
	}
}

main(){
	//freopen("in.inp","r",stdin);
	
	ll n;
	ll ans = 0;
	cin >> n;
	for (ll i = 0; i < n-1; i++) 
	{
		cin >> a[i] >> b[i] >> dis[i]; 
		edge[a[i]].push_back(b[i]);
		edge[b[i]].push_back(a[i]);
	}
	for (ll i = 0; i < n; i++)
	{
		vis[i] = false;
		f[i] = 0;
	} 
	dfs(0);
	for (ll i = 0; i < n-1; i++)
	{
		ll mn = min(f[a[i]], f[b[i]]);
		//cout << dis[i] * (mn + 1) * (n - mn - 1) << endl;
		ans += dis[i] * (mn + 1) * (n - mn - 1);
	}
	//for (ll i = 0; i < n; i++) cout << f[i] << " ";
	//cout << endl;
	cout << ans << endl;
}

#include <bits/stdc++.h>
#define vi vector <ll>
#define vvi vector <vi>
#define ii pair <ll, ll>
#define fi first
#define ll long long
#define se second
using namespace std;

map <ii, ll> mp;
vvi edge;
vi dp[5005];
ll mx_de;
ll n;
map <ii, ll> :: iterator it;
ll ans = 0LL;

void dfs(ll u, ll parent, ll depth, ll root)
{
	ii t;
	//cout << depth << " " << root << endl;
	t.fi = depth;
	t.se = root;
	mp[t]++;
	for (ll i = 0; i < edge[u].size(); i++)
	{
		if (edge[u][i] != parent)
		{
			//cout << u << " " << depth << " " << edge[u][i] << endl;
			dfs(edge[u][i], u, depth+1, root);
			mx_de = max(mx_de, depth+1);
		}
	}
	
}

ll vis(vi a)
{
	if (a.size() < 3) return 0;
	ll f[5005][4];
	//cout << a.size() << endl;
	//for (ll i = 0; i < a.size(); i++) cout << a[i] << " ";
	//cout << endl;
	f[0][1] = a[0];
	for (ll i = 0LL; i <= a.size(); i++) f[i][0] = 1LL;
	for (ll i = 1LL; i < a.size(); i++)
		for (int j = 1; j < 4; j++)
			f[i][j] = a[i]*f[i-1][j-1] + f[i-1][j];
	//cout << f[a.size()-1][3] << endl;
	return f[a.size()-1][3];
}

ll centre(ll num)
{
	if (edge[num].size() < 3) return 0LL;
	mp.clear();
	mx_de = 0LL;
	for (ll i = 0LL; i <= n; i++) dp[i].clear();
	for (ll i = 0LL; i < edge[num].size(); i++)
	{
		//cout << num << " " << edge[num][i] << endl;
		dfs(edge[num][i], num, 1, edge[num][i]);
	}
	for (map <ii, ll> :: iterator it = mp.begin(); it != mp.end(); it++)
	{
		ii node = it-> first;
		dp[node.first].push_back(it->second);
		//cout << node.first << " " << it->second << endl;
	}
	ll cnt = 0LL;
	for (ll i = 1; i < n; i++) cnt += vis(dp[i]);
	return cnt;
}

main(){
	//freopen("in.inp","r",stdin);
	cin >> n;
	edge.assign(n+1, vi());
	for (ll i = 1LL; i < n; i++)
	{
		ll x, y;
		cin >> x >> y;
		edge[x].push_back(y);
		edge[y].push_back(x);
	}
	for (ll i = 1LL; i <= n; i++)
	{
		ans += centre(i);
	}
	cout << ans << endl;
}

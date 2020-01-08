#include <bits/stdc++.h>
#define WHITE 1
#define BLACK -1
#define maxN 501
#define ll long long 
#define ii pair <ll, ll>
#define vi vector <ii>
using namespace std;

ll n,m;
vi a[maxN];
ll ok[maxN],ans,k;
ll mx;

void dfs(ll i)
{
	if (i<1 || i>n) return;
	if (ok[i] == BLACK) return;
	ok[i] = BLACK;
	ans++;
	for (ll j = 0; j < a[i].size(); j++) 
		if (ok[a[i][j].first] == WHITE && a[i][j].second == k) dfs(a[i][j].first);
}

main(){
	//freopen("in.inp","r",stdin);
	//freopen("out.out","w",stdout);
	
	while (cin >> n >> m)
	{
		if (n == 0 && m == 0) break;
		k = -2147483648;
		for (ll i = 1; i <= n; i++) a[i].clear();
		for (ll i = 0; i < m; i++) 
		{
			ll x, y, z;
			cin >> x >> y >> z;
			a[x].push_back(ii(y,z));
			a[y].push_back(ii(x,z));
			k = max(k,z);
		}
		
		mx = -2147483648;
		for (ll j = 1; j <= n; j++) ok[j] = WHITE;
		
		for (ll i = 1; i <= n; i++)
		{
			ans = 0;
			if (ok[i] == WHITE) dfs(i);
			mx = max(ans, mx);
		}
		cout << mx << endl;
	}
}


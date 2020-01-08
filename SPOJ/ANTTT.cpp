#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll x1[5010], x2[5010], y[5010], y2[5010];
ll father[5010];
ll test; 
ll n, m;

ll find(ll x)
{
	return (x == father[x]? x: (father[x] = find(father[x])));
}

bool same_set(ll x, ll y)
{
	return (find(x) == find(y));
}

void make_set(ll i, ll j)
{
	ll x = find(i);
	ll y = find(j);
	father[x] = y;
}

ll ok(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3)
{
	return ((y3 - y1)*(x2 - x1) - (y2 - y1)*(x3 - x1));
}

bool cut(ll i, ll j)
{
	if ((ok(x1[i], y[i], x2[i], y2[i], x1[j], y[j])) * (ok(x1[i], y[i], x2[i], y2[i], x2[j], y2[j])) > 0) return false;
	if ((ok(x1[j], y[j], x2[j], y2[j], x1[i], y[i])) * (ok(x1[j], y[j], x2[j], y2[j], x2[i], y2[i])) > 0) return false;
	return true;
}

main(){
	//freopen("in.inp","r",stdin);
	cin >> test;
	while (test--)
	{
		cin >> n >> m;
		for (ll i = 0; i < n; i++) father[i] = i;
		for (ll i = 0; i < n; i++)
			{
				cin >> x1[i] >> y[i] >> x2[i] >> y2[i];
			}
		for (ll i = 0; i < n; i++)
			for (ll j = 0; j < n; j++)
				if (cut(i,j) && !same_set(i,j)) make_set(i,j);
		/*for (ll i = 0; i < n; i++)
			for (ll j = 0; j < n; j++) cout << i << " " << j << " " << cut(i,j) << endl;*/
		for (ll i = 0; i < m; i++)
			{
				ll a, b;
				cin >> a >> b;
				a--;
				b--;
				if (same_set(a, b)) cout << "YES" << endl;
				else cout << "NO" << endl;
			}
		//cout << same_set(2,7) << endl;
	}
}

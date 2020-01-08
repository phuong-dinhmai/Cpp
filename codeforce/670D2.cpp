#include <bits/stdc++.h>
#define ll long long
#define inf (1e10+7)
#define maxN (int) (1e6+5)
using namespace std;

ll n;
ll k;
ll a[maxN];
ll b[maxN];

bool check(ll num, ll k)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i]*num > b[i])
		{
			ll x = a[i]*num - b[i];
			k -= x; 
			if (k < 0) return false;
		}
	}
	return true;
}

main(){
	//freopen("in.inp","r",stdin);
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int j = 0; j < n; j++) cin >> b[j];
	ll hi = inf;
	ll lo = 0;
	while (lo+1 < hi)
	{
		ll mid = (lo + hi)/2;
		if (check(mid, k)) lo = mid; else hi = mid-1;
		//cout << hi << " " << lo << endl;
	}
	while (check(lo, k)) lo++;
	cout << lo-1 << endl;
}

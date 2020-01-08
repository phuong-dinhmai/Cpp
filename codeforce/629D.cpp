#include <bits/stdc++.h>
#define ll long long
#define maxN 1000000
#define pi acos(-1)
using namespace std;

ll n, sum = 0, ans;
map <ll, ll> mp;

main(){
	//freopen("in.inp","r",stdin);
	cin >> n;
	mp[0] = 0;
	for (ll i = 0; i < n; i++)
	{
		ll r, h;
		cin >> r >> h;
		ll v = r*r*h;
		map <ll, ll> :: iterator x = mp.lower_bound(v);
		map <ll, ll> :: iterator y = x;
		sum = (--y)->second + v;
		y = x;
		while (y != mp.end() && y-> second <= sum) y++;
		mp.erase(x, y);
		mp[v] = sum;
	}
	cout << setprecision(9) << fixed << ((--mp.end() ) -> second )*pi << endl;
}

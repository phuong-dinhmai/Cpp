#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int maxN = 1000003;
const ll mod = 1e9+7;

ll fact[maxN];
int n, test;
ll fre[maxN];

void init(){
	fact[0] = 1LL;
	for (int i = 1; i < maxN; ++i){
		if (i % 2) fact[i] = (fact[i-1] * i % mod);
		else fact[i] = (fact[i-1] * (i >> 1)) % mod;
	}
}

ll A(int k, int n){
	ll ans = 1LL;
	for (int i = n-k+1; i <= n; i++) ans = (ans * i) % mod;
	return ans;
}
ll pw(ll bs, ll pwr){
	if (pwr == 0) return 1LL;
	else if (pwr == 1) return bs % mod;
	else {
		ll tmp = pw(bs, pwr / 2);
		return ((tmp * tmp) % mod * (pwr % 2 ? bs : 1LL)) % mod;
	}
}

main(){
	freopen("in.inp","r",stdin);
	init();
	cin >> test;
	memset(fre, 0, sizeof(fre));
	while (test--){
		cin >> n;
		vector <ll> a;
		memset(fre, 0, sizeof(fre));
		
		for (int i = 0; i < n; ++i){
			ll x;
			cin >> x;
			a.push_back(x);
			++fre[x];
		}
		sort(a.begin(), a.end());
		vector <ll> :: iterator last = unique(a.begin(), a.end());
		a.resize(distance(a.begin(), last));
		
		int l = 0, r = a.size()-1;
		ll res = 1;
		while (l < r-1){
			int x = fre[a[l]], y = fre[a[r]];
			int k = max(x, y);
			res = (res * (fact[k] * pw(2LL, k/2)) % mod) % mod;
			if (x > k) fre[a[l]] -= k;
			else {fre[a[l+1]] -= (k - fre[a[l]]); fre[a[l]] = 0LL; ++l;}
			if (y > k) fre[a[r]] -= k;
			else {fre[a[r-1]] -= (k - fre[a[r]]); fre[a[r]] = 0LL; --r;}
		}
		if (l == r-1){
			int x = min(fre[a[l]], fre[a[r]]), y = max(fre[a[l]], fre[a[r]]);
			//cout << a[l] << " " << x << " " << a[r] << " " << y << endl;
			res = ((res * A(x, y) % mod) * fact[y-x]) % mod;
			//cout << y << " " << x << " " << f[y-x] << endl;
			fre[a[l]] = fre[a[r]] = 0LL;
		}
		if (a.size() == 1) cout << fact[fre[a[0]]] << endl; else cout << res % mod << endl;
	}
}

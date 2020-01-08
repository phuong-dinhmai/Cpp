#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ii pair <ll, ll>
#define st first
#define se second

const int maxN = 100005;

ll gcd(ll x, ll y){
	return (y == 0? x: gcd(y, x % y));
}

ll lcm(ll x, ll y) {
	return (x / gcd(x, y) * y);
}

vector <ii> prime_factor (ll n){
	vector <ii> ans;
	ll i = 2;
	while (i*i <= n){
		if (n % i == 0) {	
			int cnt = 0;
			while (n > 1 && n % i == 0) { n /= i; ++cnt;}
			ans.push_back(ii(i, cnt));
		}
		++i;
	}
	if (ans.empty() || n > 1) ans.push_back(ii(n, 1));
	return ans;
}

int n, test;
ll a[maxN], k;

main(){
	freopen("in.inp","r",stdin);
	cin >> test;
	while (test--){
		cin >> n;
		for (int i = 0; i < n; ++i) cin >> a[i];
		cin >> k;
		vector <ii> pr = prime_factor(k);
		vector <ll> b;
		for (int i = 0; i < pr.size(); ++i){
			ll p = pow(pr[i].st, pr[i].se);
			ll tmp = -1;
			for (int j = 0; j < n; ++j){
				if (a[j] % p == 0) {
					if (tmp == -1) tmp = a[j]; else tmp = gcd(tmp, a[j]);
				} 
			}
			b.push_back(tmp);
		}
		bool ok = true;
		for (int i = 0; i < pr.size(); ++i) {
			ok &= (k % b[i] == 0 && b[i] != -1);
		}
		cout << (ok? "YES\n": "NO\n");
	}
	//cout << (2 % (-1)) << endl;
}

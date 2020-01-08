#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;

main() {
	int test, n[100006], mn = 0, t;
	freopen("in.inp","r",stdin);
	long f[10006];
	cin >> test;
	t = test;
	while (test--) {
		cin >> n[test];
		int x;
		for (int i = 0; i < n[test]; ++i) cin >> x;
		mn = max(mn, n[test]);
	}
	f[1] = 2;
	for (int i = 2; i <= mn; ++i) f[i] = (3*f[i-1] + 2) % mod;
	for (int i = t-1; i >= 0; i--) cout << f[n[i]] << endl;
}

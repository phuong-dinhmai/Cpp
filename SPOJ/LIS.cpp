#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 3e5+7;

int n, res = 0;
vector <ll> lis;

main() {
	//freopen("in.inp","r",stdin);
	ios_base :: sync_with_stdio(false); cin.tie(0);
	
	cin >> n;
	lis.assign(n+1, 0);
	for (int i = 0; i < n; i++) {
		ll x;
		cin >> x;
		int p = lower_bound(lis.begin(), lis.begin() + res, x) - lis.begin();
		lis[p] = x;
		if (p == res) res++;
	}
	cout << res << endl;
}

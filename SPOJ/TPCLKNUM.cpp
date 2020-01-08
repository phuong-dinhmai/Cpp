#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll mod = 1e9+7;
const int N = 1e5+7;

int n, k;
ll f[N];
ll base[N];

main() {
	//freopen("in.inp","r",stdin);
	ios_base :: sync_with_stdio(false); cin.tie(0);
	base[1] = 9;
	for (int i = 2; i <= N; i++) base[i] = base[i-1]*10 % mod;
	
	while(cin >> n >> k)
	{
		memset(f, 0, sizeof(f));
		queue <int> qu;
		f[k] = 1;
		for (int i = 1; i < k; i++) qu.push(0);
		qu.push(1);
		ll sum_k = 1;
		for (int i = k+1; i <= n; i++) {
			f[i] = (9LL*sum_k + base[i-k] + mod) % mod;
			qu.push(f[i]);
			sum_k += f[i];
			if (qu.size() > k) sum_k = (sum_k - qu.front() + mod) % mod, qu.pop();
		}
		cout << (f[n] + mod) % mod << endl;
	}
}

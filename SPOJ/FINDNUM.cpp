#include <bits/stdc++.h>
#define ll unsigned long long
#define vi vector <ll>
using namespace std;

const int inf = 1e9+7;
const ll lim = 1e18;

ll prime[11] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
int n;
ll ans = inf;
ll f[1005][11];

bool overflow(ll x, int m) {
	double res = 1.00;
	for (int i = 0; i < m; i++) {
		res *= x;
		if (res >= lim) return 1;
	}
	return 0;
}

bool not_exceed(ll a, ll b) {
	return (double) (a * b) >= lim;
}

ll pw(ll a, ll x) {
	if (x == 0) return 1LL; 
	if (x == 1) return a;
	ll t = pw(a, x/2);
	if (x & 1) return t*t*a; else return t*t;
}

main(){
	cin >> n;
	
	memset(f, 0x3f, sizeof(f));
	for (int i = 0; i < n; i++) {
		if (overflow(2, i)) continue;
		f[i + 1][0] = 1LL << i;
	} 
	for (int i = 1; i <= 10; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			f[j][i] = f[j][i - 1]; 
			int x = j; 
			for (int k = 1; k < j; k++)
			{
				if (j % (k + 1) || overflow(prime[i], k)
				 || not_exceed(f[j / (k + 1)][i - 1], pw(prime[i], k)))
					continue; 
				f[j][i] = min(f[j][i], f[j / (k + 1)][i - 1] * pw(prime[i], k)); 
			}
		}
	}
			
	cout << f[n][10] << endl;
}

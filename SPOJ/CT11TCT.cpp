#include <bits/stdc++.h>
#define ull long long
#define mod (ull) (1e5+3)
#define vi vector <ull> 
using namespace std;

ull gt[mod + 3];

void init()
{
	gt[0] = 1;
	for (ull i = 1; i <=  mod; i++) gt[i] = ((gt[i-1] % mod)*i) % mod;
}

ull power(ull a, ull b)
{
	if (b == 0) return 1;
	if (b == 1) return a;
	return ((power(a,b/2)%mod * power(a,b/2)%mod)%mod*power(a,b%2))%mod;
}

ull ans(ull n, ull k)
{
	//cout << gt[n] << " " << gt[k]*gt[n-k] << " " << mod-2 << endl;
	//cout <<  power(gt[k]*gt[n-k], mod - 2) << endl;
	return gt[n]*power(gt[k]*gt[n-k], mod - 2) % mod;
}

ull sol(ull x, ull y)
{
	vi n, k;
	while (x != 0)
	{
		n.push_back(x % mod);
		x /= mod;
	}
	while (y != 0)
	{
		k.push_back(y % mod);
		y /= mod;
	}
	
	while (k.size() < n.size()) k.push_back(0);
	while (k.size() > n.size()) n.push_back(0);
	
	ull res = 1;
	for (ull i = 0; i < k.size(); i++)
	{
		if (n[i] < k[i]) return 0;
		res =  (res * ans(n[i], k[i])) % mod;
		//cout << ans(n[i], k[i]) << endl;
	}
	return res;
}

main()
{
	ull test, k, m;
	cin >> test;
	init();
	for (ull i = 0; i < test; i++)
	{
		cin >> m >> k;
		ull n = (m - k + 1);
		if (n < k) cout << "0" << endl;
		else
		{
			if (n < mod) cout << ans(n,k) % mod << endl;
			else cout << sol(n,k) % mod << endl;
		}
	}
}

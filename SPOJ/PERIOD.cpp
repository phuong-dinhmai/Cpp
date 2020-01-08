#include <bits/stdc++.h>
#define ull unsigned long long
#define inf (ull) (1e9+7)
using namespace std;

ull n, m, q, p, k;

main(){
	
	cin >> n >> k >> p >> q >> m;
	ull f = 0;
	for (ull i = 1; i <= n; i++)
	{
		f = max (f, (p*i) % m + q + k * i);
	}
	
	ull ans = f;
	for (ull i = 2; i <= n; i++)
	{
		f = max (f - k,  (p*(i-1)) % m + q + n * k);
		ans = min (ans, f);
 	}
 	cout << ans << endl;
}

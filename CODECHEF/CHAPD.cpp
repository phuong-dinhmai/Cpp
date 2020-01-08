#include <bits/stdc++.h>
#define ll long long 
using namespace std;

int test;
ll a, b;

ll divide (ll a, ll t)
{
	ll r = __gcd(a, t);
	while (r != 1)
	{
		a /= r;
		r = __gcd(a, t);
	}
	return a;
}

main(){
	cin >> test;
	while (test--)
	{
		cin >> a >> b;
		ll t = __gcd(a, b);
		//ll x1 = divide (a, t);
		ll x2 = divide (b, t);
		//cout << t << " " << x1 << endl;
		if (x2 == 1) cout << "Yes" << endl; else cout << "No" << endl;
	}
}

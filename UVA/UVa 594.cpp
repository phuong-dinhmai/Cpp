#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll sol(ll n)
{
	ll ans = 0;
	for (int i = 0; i < 32; i++)
	{
		if (n & (1 << i))
			ans |= 1<<(3 - i/8) *8 + (i%8);
	}
	return ans;
}

main(){
	ll n;
	//freopen("in.inp","r",stdin);
	while (cin >> n)
	{
		cout << n << " converts to " << sol(n) << endl; 
	}
}

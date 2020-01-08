#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n;
ll k;

ll lcm(ll x, ll y)
{
	return (x * y / __gcd(x, y));
}

main(){
	//freopen("in.inp","r",stdin);
	scanf("%d%I64d", &n, &k);
	ll cur = 1LL;
	for (int i = 0; i < n; i++)
	{
		ll x;
		scanf("%I64d", &x);
		cur = __gcd(k, lcm(x, cur));
	}
	
	if (cur == k) printf("Yes\n"); else printf("No\n");
}

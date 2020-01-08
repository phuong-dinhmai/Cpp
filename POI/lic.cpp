#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 3e6+7;

int n;
ll cnt[N], b[N], f[N], mx = 0LL;

main(){
	//freopen("in.inp","r",stdin);
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		ll x;
		scanf("%lld", &x);
		mx = max(mx, x);
		cnt[x]++;
	}
	
	for (int i = 1; i <= mx; i++)
	{
		for (int j = i; j <= mx; j += i) b[i] += cnt[j];
	}
	
	for (int i = mx; i > 0; i--)
	{
		f[i] = b[i]*(b[i]-1)/2;
		for (int j = i+i; j <= mx; j += i) f[i] -= f[j];
	}
	
	printf("%lld\n", f[1]);
}

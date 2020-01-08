#include <bits/stdc++.h>
#define ll long long
using namespace std;

int test;
ll n;
ll fib[89];

main(){
	//freopen("in.inp","r",stdin);
	fib[0] = fib[1] = 1;
	for (int i = 2; i < 88; i++) fib[i] = fib[i-1] + fib[i-2];
	
	scanf("%d", &test);
	while (test--)
	{
		scanf("%lld", &n);
		//printf("%lld ", n);
		queue <ll> q;
		q.push(n);
		map <ll, int> mp;
		mp[n] = 0;
		ll lim = 1e18;
		while (!q.empty())
		{
			ll t = q.front();
			q.pop();
			if (t == 0)
			{
				printf("%d\n", mp[t]);
				break;
			}
			int pos = lower_bound(fib, fib+88, t) - fib;
			if (pos != 88) 
			{
				if (fib[pos] - t >= 0)
					if (!mp.count(fib[pos] - t)) mp[fib[pos] - t] = mp[t] + 1, q.push(fib[pos] - t);
			}
			if (pos != 0)
			{
				if (t - fib[pos-1] >= 0)
					if (!mp.count(t - fib[pos-1])) mp[t - fib[pos-1]] = mp[t] + 1, q.push(t - fib[pos-1]);
			}
		}
	}
}

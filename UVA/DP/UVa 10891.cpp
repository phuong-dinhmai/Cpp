#include <bits/stdc++.h>
#define maxN (int) (105)
#define inf (int) (1e10+100)
#define ll long 
using namespace std;

int n;
ll f[maxN][maxN];
ll a[maxN];
ll sum[maxN];

void init()
{
	for (int i = 0; i <= n+2; i++)
	{
		for (int j = 0; j <= n+2; j++) f[i][j] = -1;
	}
}

int back_track(int start, int en)
{
	if (f[start][en] != -1) return f[start][en];
	if (start == en) return f[start][en] = a[en];
	ll ans = -inf;
	for (int i = start; i < en; i++)
	{
		ll frt = - back_track(i+1, en) + (sum[i] - sum[start-1]) + (sum[en] - sum[i]);	
		ans = max(ans, frt);
	}
	for (int i = en; i > start; i--)
	{
		ll bck = - back_track(start, i-1) + (sum[en] - sum[i-1]) + (sum[i-1] - sum[start-1]);
		ans = max(ans, bck);
	}
	ans = max(ans, sum[en] - sum[start-1]);
	return f[start][en] = ans;
}

main(){
	//freopen("in.inp","r",stdin);
	//freopen("out.out","w",stdout);
	while (scanf("%d", &n) && n)
	{
		init();
		for (int i = 1; i <= n; i++) 
		{
			cin >> a[i];
		}
		sum[0] = 0;
		for (int i = 1; i <= n; i++) sum[i] = sum[i-1] + a[i];
		ll x = back_track(1, n);
		ll y = sum[n] - x;
		cout << x - y << endl;
	}
}

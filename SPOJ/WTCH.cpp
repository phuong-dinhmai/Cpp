#include <bits/stdc++.h>
#define maxN 2005
#define max_val (int) (1e9+7)
#define ll long long
#define inf (int) (2e9+7)
using namespace std;

ll n, q, p;
ll a[maxN];
int next1[maxN];
int next2[maxN];
int f[maxN][maxN];

bool check(ll num)
{
	for (int i = 1; i <= n; i++)
	{
		int pos = upper_bound(a, a+n+2, a[i]+num-1) - a;
		next1[i] = pos;
		pos = upper_bound(a, a+n+2, a[i]+2*num-1) - a;
		next2[i] = pos;
	}
	next1[0] = next2[0] = 1;
	next1[n+1] = next2[n+1] = n+1;
	f[0][0] = 1;
	for (int i = 1; i <= q; i++) 
	{
		f[i][0] = next1[f[i-1][0]];
	}
	for (int j = 1; j <= p; j++) 
	{
		f[0][j] = next2[f[0][j-1]];
	}
	for (int i = 1; i <= q; i++)
		for (int j = 1; j <= p; j++)
		{
			f[i][j] = max(next1[f[i-1][j]], next2[f[i][j-1]]);
		}
	/*if (num > (int) (1e7+7))
	{
		cout << num << endl;
		for (int i = 0; i <= q; i++)
		{
			for (int j = 0; j <= p; j++) cout << f[i][j] << " ";
			cout << endl;
		}
		for (int i = 1; i <= n; i++) cout << next2[i] << " ";
		cout << endl;
		for (int j = 0; j <= n; j++) cout << next1[j] << " ";
		cout << endl;
		cout << endl;
	}*/
	if (f[q][p] > n) return true; else return false;
}

main(){
	//freopen("in.inp","r",stdin);
	cin >> n >> q >> p;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	if (p+q >= n) 
	{
		cout << 1 << endl;
		return 0;
 	}
	sort(a, a+n+1);
	a[n+1] = inf;
	ll hi = max_val; 
	ll lo = 1;
	while (lo < hi)
	{
		ll mid = (lo + hi)/2;
		if (check(mid)) hi = mid; else lo = mid+1;
		if (hi == lo+1) break;
	}
	while(check(hi)) hi--;
	cout << hi+1 << endl;
}

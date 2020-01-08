#include <bits/stdc++.h>
#define inf (int) (1e9+7)
#define maxN 6000
#define ii pair <int, int>
#define fi first 
#define se second
using namespace std;

ii turtle[maxN];
int dp[maxN];
int n = 0;

bool cmp(const ii &a, const ii &b)
{
	return (a.se < b.se || (a.se == b.se && a.fi < b.fi));
}

main(){
	//freopen("in.inp","r",stdin);
	ii t;
	while(cin >> t.fi >> t.se)
	{
		turtle[++n] = t;
	}
	sort(turtle+1, turtle+n+1, cmp);
	int ans = (n == 0? 0 : 1);
	for (int i = 1; i <= n; i++) dp[i] = inf;
	dp[0] = 0;
	for (int i = 1; i <= n; i++)
		for (int j = n; j > 0; j--)
		{
			if (turtle[i].se >= turtle[i].fi + dp[j-1])
			{
				dp[j] = min(dp[j], dp[j-1] + turtle[i].fi);
			}
			if (dp[j] != inf) ans = max(ans, j);
		}
	cout << ans << endl;
}

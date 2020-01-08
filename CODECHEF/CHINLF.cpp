#include <bits/stdc++.h>
using namespace std;

const int N = 1e3+5;
const double lim = 1e18+1;

int n, m;
double selling[N][N], buying[N][N];
double dp[N][N][2];
double d, ans = 0.00;

double mul(double a, double b)
{
	if (a >= lim/b) return lim; else return a*b;
}

main(){
	//freopen("in.inp","r",stdin);
	cin >> n >> m >> d;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			double x, y;
			cin >> x >> y;
			selling[i][j] = x;
			buying[i][j] = y;
		}
	}
	
	for (int i = 1; i <= n; i++) dp[i][1][0] = d;
	
	for (int ti = 1; ti <= m; ti++)
	{
		for (int i = 1; i <= n; i++)
		{
			dp[i][ti+1][0] = max(dp[i][ti+1][0], dp[i][ti][0]);
			dp[i][ti+1][1] = max(dp[i][ti+1][1], dp[i][ti][1]);
			if (i > 1)
			{
				dp[i-1][ti+1][0] = max(dp[i-1][ti+1][0], dp[i][ti][0]);
				dp[i-1][ti+1][1] = max(dp[i-1][ti+1][1], dp[i][ti][1]);
			}
			if (i < n)
			{
				dp[i+1][ti+1][0] = max(dp[i+1][ti+1][0], dp[i][ti][0]);
				dp[i+1][ti+1][1] = max(dp[i+1][ti+1][1], dp[i][ti][1]);
			}
			dp[i][ti+1][0] = max(mul(dp[i][ti][1], buying[i][ti]), dp[i][ti+1][0]);
			dp[i][ti+1][1] = max(dp[i][ti][0]/selling[i][ti], dp[i][ti+1][1]);
		}
	}
	
	for (int i = 1; i <= n; i++) ans = max(ans, dp[i][m+1][0]);
	if (ans == lim) cout << "Quintillionnaire\n"; else cout << setprecision(9) << fixed << ans << endl;
}

#include <bits/stdc++.h>
#define ll long long 
using namespace std;

const int mod = 1e9+7;
const int maxN = 505;

int n, m;
char a[maxN][maxN];
ll dp[2][maxN][maxN];
ll ans;

main(){
	//freopen("in.inp","r",stdin);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) cin >> a[i][j];
	int pos = (n + m)/2 + 1;
	dp[0][1][n] = (a[1][1] == a[n][m]);
	for (int x = 2; x <= pos; x++)
	{
		int y = n + m - x + 2;
		memset(dp[1], 0, sizeof(dp[1]));
		for (int i = 1; i <= n; i++)
			for (int j = i; j <= n; j++)
			{
				int q = x - i;
				int p = y - j;
				if (q < 1 || p < 1 || q > m || p > m || q > p) continue;
				if (a[i][q] != a[j][p]) dp[1][i][j] = 0LL;
				else dp[1][i][j] = (dp[0][i][j] + dp[0][i-1][j+1] + dp[0][i-1][j] + dp[0][i][j+1]) % mod;
			}
		for (int i = 1; i <= n; i++)
			for (int j = i; j <= n; j++) { dp[0][i][j] = dp[1][i][j]; }
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) ans = (ans + dp[0][i][j]) % mod; //, cout << i << " " << j << " " << ans << endl;
	cout << ans << endl;
}

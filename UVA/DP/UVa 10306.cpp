#include <bits/stdc++.h>
#define ii pair <int, int>
#define x first
#define y second
using namespace std;

const int inf = 1e9+7;
const int N = 305;

int test, x;
ii a[50];
int dp[N][N], n, s;
int ans;

main(){
	ios_base :: sync_with_stdio(false); cin.tie(0);
	//freopen("in.inp","r",stdin);
	//freopen("out.out","w",stdout);
	cin >> test;
	while(test--)
	{
		cin >> n >> s;
		ans = inf;
		for (int i = 0; i <= s; i++)
			for (int j = 0; j <= s; j++) dp[i][j] = inf;
		dp[0][0] = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i].x >> a[i].y;
		}
		for (int i = 0; i < n; i++)
		{
			int x = a[i].x;
			int y = a[i].y;
			for (int j = x; j <= s; j++)
				for (int k = y; k <= s; k++)
					dp[j][k] = min(dp[j][k], dp[j - x][k - y] + 1);
		}
		
		for (int i = 0; i <= s; i++)
			for (int j = 0; j <= s; j++)
			{
				if (i*i + j*j == s*s) ans = min(ans, dp[i][j]);
			}
		if (ans >= inf) printf("not possible\n"); else printf("%d\n", ans);
	}
}

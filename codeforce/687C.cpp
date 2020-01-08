#include <bits/stdc++.h>
#define ln "\n"
using namespace std;

const int N = 1e3+5;

bool dp[2][N][N];
int n, k;
vector <int> res;

main(){
	//freopen("in.inp","r",stdin);
	ios_base :: sync_with_stdio(false); cin.tie(0);
	
	cin >> n >> k;
	dp[0][0][0] = 1;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		int now = i % 2;
		int last = 1 - now;
		for (int j = 0; j <= k; j++)
			for (int y = 0; y <= j; y++)
			{
				dp[now][j][y] = dp[last][j][y];
				if (j >= x)
				{
					dp[now][j][y] |= dp[last][j - x][y];
					if (y >= x) dp[now][j][y] |= dp[last][j - x][y - x];
				}
			}
	}
	
	for (int i = 0; i <= k; i++) 
		if (dp[n % 2][k][i]) res.push_back(i);
		
	cout << res.size() << ln;
	for (int i = 0; i < res.size(); i++) cout << res[i] << " "; cout << ln;
}

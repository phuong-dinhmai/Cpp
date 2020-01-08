#include <bits/stdc++.h>
#define ii pair <int, int>
#define x first
#define y second
using namespace std;

const int N = 360;

int n, m;
int k[N];
int dis[N][N],people[N][N], num[N][N];
int ans = 0;
int total = 0;

main(){
	freopen("MUDSTOCK.inp","r",stdin);
	freopen("MUDSTOCK.out","w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++) cin >> dis[i][j] >> people[i][j];
		for (int j = k[i]; j > 0; j--) num[i][j] = num[i][j+1] + people[i][j];
		for (int j = 1; j <= k[i]; j++) ans += (num[i][j] * dis[i][j]);
		total += num[i][1];
	}

	total += m;
	ii pos = ii(0, 0);
	int res = ans;
	
	for (int i = 1; i <= n; i++)
	{
		res = ans;
		for (int j = 1; j <= k[i]; j++)
		{
			res -= (num[i][j]) * dis[i][j];
			res += (total - num[i][j]) * dis[i][j];
			if (res < ans)
			{
				ans = res;
				pos.x = i, pos.y = j;
			}
		}
	}
	cout << ans << "\n" << pos.x << " " << pos.y << "\n";
}

#include <bits/stdc++.h>
#define maxN 105
using namespace std;

int n, m, test;
int a[maxN][maxN];
int f[maxN][maxN];
string str;
int ans;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int solve(int x, int y)
{
	if (f[x][y] != -1) return f[x][y];
	int best = -1; 
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && ny >= 0 && nx < n && ny < m)
		{
			if (a[nx][ny] < a[x][y]) best = max(best, solve(nx, ny) + 1);
		}
	}
	if (best == -1) best = 1;
	f[x][y] = best;
	return f[x][y];
	
}

main(){
	//freopen("in.inp","r",stdin);
	//freopen("out.out","w",stdout);
	cin >> test;
	while(test--)
	{
		cin >> str;
		cin >> n >> m;
		ans = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) 
			{
				cin >> a[i][j];
				f[i][j] = -1;
			}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
			{
				int len = solve(i, j);
				ans = max(ans, len);
			}
		cout << str << ": " << ans << endl;
	}
}

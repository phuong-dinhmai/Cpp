#include <bits/stdc++.h>
#define maxN 505
#define inf (int) (1e9+7)
using namespace std;

int n, m;
int matrix[maxN][maxN];
int c[maxN][maxN];
int f[maxN][maxN];

main(){
	//freopen("in.inp","r",stdin);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) 
		{
			matrix[i][j] = inf;
			c[i][j] = inf + 3;
		}
	for (int i = 1; i <= n; i++) matrix[i][i] = 0;
	
	for (int i = 0; i < m; i++)
	{
		int x, y, cost;
		cin >> x >> y >> cost;
		matrix[x][y] = matrix[y][x] = cost;
		c[y][x] = c[x][y] = cost; 
	}
	
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
			{
				matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
			}
			
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			if (i != j)
			{
				for (int k = 1; k <= n; k++)
				if (k != j)
				{
					if (matrix[i][k] + c[k][j] == matrix[i][j]) f[i][j]++;
				}
			}
		}
		
	for (int i = 1; i < n; i++)
	{
		for (int j = i+1; j <= n; j++)
		{
			int ans = 0;
			for (int k = 1; k <= n; k++)
			{
				if (matrix[i][j] == matrix[i][k] + matrix[k][j]) ans += f[i][k];
			}
			cout << ans << " ";
		}
	}
}

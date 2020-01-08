#include <bits/stdc++.h>
#define inf (float) (2e9+9)
#define maxN 1001
#define maxM 1000001
using namespace std;

float dis[maxN][maxN];
float num[maxN][maxN];
int n, m;

main(){
	freopen("in.inp","r",stdin);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j <n; j++)
		{
			dis[i][j] = inf;
			num[i][j] = 0;
		}
	for (int i = 0; i < m; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		x--; y--;
		dis[x][y] = z;
		dis[y][x] = z;
		num[x][y] = 1;
		num[y][x] = 1;
	}
	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
			{
				if (num[i][k] + num[k][j] == 0) continue;
				float t = (dis[i][k] * num[i][k] + dis[k][j] * num[k][j]) / (num[i][k] + num[k][j]);
				if ((dis[i][j]) > t)
				{
					dis[i][j] = t;
					num[i][j] = num[i][k] + num[k][j]; 
				}
			}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << dis[i][j] << " ";
			//cout << num[i][j] << " ";
		}
		cout << endl;
	}
	float mn = inf;
	for (int i = 0; i < n; i++) mn = min(mn, dis[i][i]);
	if (mn == inf) cout << "NO TOUR" << endl; else cout << setprecision(2) << fixed << mn << endl;
}

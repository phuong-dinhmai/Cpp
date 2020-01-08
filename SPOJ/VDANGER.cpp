#include <bits/stdc++.h>
#define maxN 101
#define maxM 100001
#define inf (int) (2e9+9)
using namespace std;

main(){
	int n, m;
	int a[maxM];
	int dis[maxN][maxN];
	cin >> n >> m;
	for (int i = 0; i < m; i++) 
	{
		cin >> a[i];
		a[i]--;
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) dis[i][j] = inf;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) cin >> dis[i][j];
	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	int ans = 0;
	for (int i = 0; i < m - 1; i++) 
	{
		ans += dis[a[i]][a[i+1]];
	}
	cout << ans << endl;
}

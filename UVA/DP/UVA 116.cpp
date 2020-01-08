#include <bits/stdc++.h>
#define inf (int) (1e9+7)
#define vi vector <int>
using namespace std;

int n, m;
int a[102][102];
int f[102][102];
int nxt[102][102];

main(){
	//freopen("in.inp","r",stdin);
	//freopen("out.out","w",stdout);
	while (cin >> n >> m)
	{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) cin >> a[i][j];
		for (int i = 0; i < 102; i++)
			for (int j = 0; j < 102; j++) 
			{
				f[i][j] = inf;
				nxt[i][j] = 0;
			}
		int ans = inf;
		int bestend = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) f[i][j] = a[i][j];
		for (int j = m - 2; j >= 0; j--)
			for (int i = 0; i < n ; i++)
			{
				int mn = inf;
				for (int k = -1; k < 2; k++)
				{
					int cur_pos = (i + k + n) % n;
					if (f[cur_pos][j+1] < mn || (mn == f[cur_pos][j+1] && nxt[i][j] > cur_pos)) 
					{
						mn = f[cur_pos][j+1];
						nxt[i][j] = cur_pos;
					}
				}
				f[i][j] += mn; 
			}
		for (int i = 0; i < n; i++)
		{
			if (ans > f[i][0]) 
			{
				ans =  f[i][0];
				bestend = i;
			}
		}
		cout << bestend + 1;
		for (int i = 0; i < m - 1; i++)
		{
			bestend = nxt[bestend][i];
			cout << " " << bestend + 1;
		}
		cout << endl; 
		cout << ans << endl;
	}
}

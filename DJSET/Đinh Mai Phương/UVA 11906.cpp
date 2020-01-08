#include <bits/stdc++.h>
#define inf 2147483647
#define WHITE 0
#define BLACK -1
#define maxN 100
#define ii pair <int, int>
using namespace std;

int ok[maxN][maxN];
int r,c,n,m;
int vis[maxN][maxN];

void init()
{
	for (int i = 0; i < maxN; i++)
		for (int j = 0; j < maxN; j++) 
		{
			ok[i][j] = WHITE;
			vis[i][j] = -inf;
		}
}

void dfs(int x, int y)
{
	int num = 0;
	ii dir[4];
	dir[0].first = dir[1].second = dir[1].first = dir[3].second = 1;
	dir[0].second = dir[2].second = dir[2].first = dir[3].first = -1;
	ok[x][y] = BLACK;
	if (n == 0 || m == 0)
	{
		int mx;
		mx = max(n,m);
		for (int i = 2; i < 4; i++)
			{
				int nr = x + mx*dir[i].second;
				if (nr >= 0 && nr < r && vis[nr][y] != inf) 
				{
					num++;
					if (ok[nr][y] == WHITE) dfs(nr, y);
				}
			}
		for (int i = 2; i < 4; i++)
			{
				int nc = y + mx*dir[i].second;
				if (nc >= 0 && nc < c && vis[x][nc] != inf) 
				{
					num++;
					if (ok[x][nc] == WHITE) dfs(x, nc);
				}
			}
	}
	else
	{
		for (int i = 0; i < 4; i++)
			{
				int nr = x + m*dir[i].first;
				int nc = y + n*dir[i].second;
				if (nr >= 0 && nr < r && nc >= 0 && nc < c && vis[nr][nc] != inf ) 
				{
					num++;
					if (ok[nr][nc] == WHITE) dfs(nr, nc);
				}
			}
	}
	if (m != n && m != 0 && n != 0)
	{
		for (int i = 0; i < 4; i++)
			{
				int nr = x + n*dir[i].first;
				int nc = y + m*dir[i].second;
				if (nr >= 0 && nr < r && nc >= 0 && nc < c && vis[nr][nc] != inf ) 
				{
					num++;
					if (ok[nr][nc] == WHITE) dfs(nr, nc);
				}
			}
	}
	vis[x][y] = num;
}

main(){
	int test;
	//freopen("in.inp","r",stdin);
	//freopen("out.out","w",stdout);
	
	cin >> test;
	for (int k = 0; k < test; k++)
	{
		init();
		
		int w;
		cin >> r >> c >> n >> m >> w;
		for (int i = 0; i < w; i++)
		{
			int x, y;
			cin >> x >> y;
			ok[x][y] = BLACK;
			vis[x][y] = inf;
		}
		
		dfs(0,0);
	
		int even = 0, odd = 0;
		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++)
				if (vis[i][j] != inf && vis[i][j] >= 0)
					if (vis[i][j] % 2 == 0) even++;
					else odd++;
		cout << "Case " << k+1 << ": " << even << " " << odd << endl;
	}
}

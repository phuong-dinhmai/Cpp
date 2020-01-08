#include <bits/stdc++.h>
using namespace std;

int a[1001][1001];
bool vis[1001][1001];
int mn, mx, n, hi, lo;
int ok;

int dfs(int x, int y, int mn, int mx)
{
	if (vis[x][y]) return 0;
	vis[x][y] = true;
	if (x == n-1 && y == n-1) 
	{
		ok = 1;
		return 1;
	}
	if (y<n-1 && y>=0 && a[x][y+1] >= mn && a[x][y+1] <= mx && !vis[x][y+1]) 
	{
		dfs(x, y+1, mn, mx);
		if (ok) return 1;
	}
	if (y<n && y>0 && a[x][y-1] >= mn && a[x][y-1] <= mx && !vis[x][y-1]) 
	{
		dfs(x, y-1, mn, mx);
		if (ok) return 1;
	}
	if (x<n-1 && x>=0 && a[x+1][y] >= mn && a[x+1][y] <= mx && !vis[x+1][y]) 
	{
		dfs(x+1, y, mn, mx);
		if (ok) return 1;
	}
	if (x<n && x>0 && a[x-1][y] >= mn && a[x-1][y] <= mx && !vis[x-1][y]) 
	{
		dfs(x-1, y, mn, mx);
		if (ok) return 1;
	}
	
}

void kt()
{
	for (int i = 0; i < 1001; i++)
		for (int j = 0; j < 1001; j++) vis[i][j] = false;
}

int find(int k)
{
	ok = 0;
	for (int i = 0; i <= min(a[0][0], a[n-1][n-1]) && !ok; i++)
	{
		kt();
		dfs(0,0,i,i+k);
		if (ok) return 1;
	}
	return ok;
}

int chatnhiphan()
{
	while (hi - lo > 1)
	{
		int mid = (hi + lo) / 2;
		if(find(mid)) hi = mid;
		else lo = mid; 
	}
	return hi;
}

main()
{
	//freopen("in.inp","r",stdin);
	//freopen("out.out","w",stdout);
	
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) 
		{
			cin >> a[i][j];
			mx = max(mx, a[i][j]);
			mn = min(mn, a[i][j]);
		}
	hi = mx - mn;
	lo = -1;
	cout << chatnhiphan() << endl;
}

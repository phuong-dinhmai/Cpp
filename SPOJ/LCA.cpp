#include <bits/stdc++.h>
#define maxN 2000
#define inf (int) (1e9+7)
#define vi vector <int>
using namespace std;

vi edge[maxN];
int dp[maxN][21];
queue <int> q;
int st[maxN];
int n, m;

void kt()
{
	for (int i = 0; i < maxN; i++) edge[i].clear();
	for (int i = 0; i < maxN; i++)
		for (int j = 0; j < 21; j++) dp[i][j] = inf;
	while (!q.empty()) q.pop();
	for (int i = 0; i < maxN; i++) st[i] = 0;
}

void init()
{
	q.push(1);
	st[1] = 1;
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		for (int i = 0; i < edge[u].size(); i++)
		{
			int v = edge[u][i];
			st[v] = st[u] + 1;
			q.push(v);
		}
	}
	
	for (int j = 1; 1 << j <= n; j++)
		for (int i = 1; i <= n; i++)
			if (dp[i][j-1] != inf) dp[i][j] = dp[dp[i][j-1]][j-1];
}

int LCA(int x, int y)
{
	if (st[x] < st[y]) swap(x,y);
	int stt;
	for (stt = 1; 1 << stt <= st[x]; stt++);
	stt--;
	
	for (int i = stt; i >= 0; i--) 
		if (st[x] - (1 << i) >= st[y]) x = dp[x][i];
	if (x == y) return y;
	
	for (int i = stt; i >= 0; i--)
		if (dp[x][i] != inf && dp[x][i] != dp[y][i])
		{
			x = dp[x][i];
			y = dp[y][i];
		}
	return dp[x][0];
}

main()
{
	//freopen("in.inp","r",stdin);
	int test;
	cin >> test;
	for (int k = 0; k < test; k++)
	{
		cout << "Case " << k+1 << ":" << endl;
		cin >> n;
		kt();
		
		for (int i = 1; i <= n; i++)
		{
			cin >> m;
			for (int j = 1; j <= m; j++) 
			{
				int x;
				cin >> x;
				dp[x][0] = i;
				edge[i].push_back(x);
			}
		}
		init(); 
		
		int h;
		cin >> h;
		for (int i = 0; i < h; i++)
		{
			int x, y;
			cin >> x >> y;
			cout << LCA(x,y) << endl;
		}
	}
}


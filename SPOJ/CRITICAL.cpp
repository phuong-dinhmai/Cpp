#include <bits/stdc++.h>
#define ll long long
#define vi vector <int>
#define vvi vector <vi>
#define maxN (ll) (20050)
#define inf (int) (1e9+7)
using namespace std;
 
vi edge[maxN];
int n, m;
ll chil[maxN];
int low[maxN];
int num[maxN];
int par[maxN];
int father[maxN];
int size_of[maxN];
ll cnt = 0LL;
ll ans = 0LL;

int find(int x) {return (x == father[x]? x: find(father[x]));}
void make_set(int i, int j)
{
	int x = find(i); int y = find(j);
	if (size_of[x] < size_of[y]) swap(x,y);
	size_of[x] += size_of[y];
	father[y] = x;
}
bool same_set(int x, int y) {return (find(x) == find(y));}
 
void dfs(int u, int pa)
{
	vector <ll> f;
	ll s = 0LL;
	low[u] = num[u] = ++cnt;
	chil[u] = 1;
	for (int i = 0; i < edge[u].size(); i++)
	{
		int v = edge[u][i];
		if (v == pa) continue;
		if (num[v] != 0) 
		{
			low[u] = min(low[u], num[v]); continue;
		} 
		else 
		{
			dfs(v, u);
			chil[u] += chil[v];
			low[u] = min(low[u], low[v]);
		}
		if ((low[v] >= num[u] && u != pa) || (u == pa))
		{
			f.push_back(chil[v]);
			s += chil[v];
		}
	}
	
	int k = size_of[find(u)]*1LL;
	ll kk = 0LL;
	for (int i = 0; i < f.size(); i++)
	{
		kk += (s - f[i])*f[i];
	}
	kk /= 2LL;
	if (u != pa) kk += (k - s - 1LL)*s;
	ans += kk;
}
 
main()
{
	//freopen("in.inp","r",stdin);
	scanf("%d %d", &n, &m);
	for (int i = 0; i <= n; i++) 
	{
		father[i] = i;
		par[i] = inf;
		num[i] = 0;
		low[i] = inf;
		size_of[i] = 1;
	}
	for (int i = 0; i < m; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		x--; y--;
		edge[x].push_back(y);
		edge[y].push_back(x);
		if (!same_set(x, y)) make_set(x, y);
	}
	for (int i = 0; i < n; i++)
	{
		if (num[i] == 0)
		{
			dfs(i, i);
		}
	}
	double l = ans*(1.0) / (n*1.0);
	cout << setprecision(2) << fixed << l << endl;
} 

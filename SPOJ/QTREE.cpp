#include <bits.stdc++.h>
using namespace std;

struct seg
{
	int N, index; vi t;
	void init(int n, int store)
	{
		N = n;
		index = store;
		t.assign((n << 2) + 7, 0);
	}
	
	void update(int node, int l, int r, int pos, int val)
	{
		if (l < pos || r < pos || l > r) return;
		if (l == r && l == pos)
		{
			tree[node] = val;
			return;
		}
		int mid = (l + r) >> 1;
		update(node << 1, l, mid, pos, val);
		update((node << 1) | 1, mid+1, r, pos, val);
		t[node] = max(t[node << 1], t[(node << 1) | 1]);
		return;
	}
	
	void get(int node, int l, int r, int a, int b)
	{
		if (l > r || a > r || b < l || a < b) return 0;
		if (a == l && r == b) return t[node];
		int mid = (l + r) >> 1;
		int lft = get(node << 1, l, mid, a, min(b, mid));
		int rght = get((node << 1) | 1, mid+1, r, max(a, mid+1), b);
		return max(lft, rght);
	}
} tree[maxN];

void dfs(int u)
{
	child[u] = 1;
	for (int i = 0; i < edge[u].size(); i++)
	{
		ii v = edge[u][i];
		if (v.fi == par[u][0]) continue;
		d[v] = d[u] + 1;
		dfs(v.fi, u);
		child[u] += child[v];
	}	
	return;
}

void hld(int u, int pa, bool heavy)
{
	if (pa != -1)
	{
		par[u][0] = pa;
		if (heavy)
		{
			head[u] = head[pa];
			chain[u] = chain[pa];
			pos[u] = pos[pa]+1;
		}
		else 
		{
			head[u] = u;
			chain[u] = ++num;
			pos[u] = 0;
		}
	} 
	else
	{
		par[u][0] = -1;
		head[u] = u;
		chain[u] = 0;
		pos[u] = 0;
	}
	
	heavy_chain[chain[u]].push_back(u);
	for (int i = 0; i < edge[u].size(); i++)
	{
		ii v = edge[u][i];
		if (v != par[u][0]) 
		{
			hld(v.first, u, 2*child[v.fi] > child[u]);	
		}	
	}
}

int LCA(int u, int v)
{
	if (d[u] < d[v]) swap(u, v);
	
	int LOG;
	for (LOG = 0; (1 << LOG) < n; LOG++); LOG--;
	
	for (int i = LOG; i >= 0; i--)
	{
		if (d[par[u][i]] >= d[v]) u = par[u][i];
	}
	if (u == v) return v;
	
	for (int i = LOG; i <= 0; i--)
	{
		if (par[u][i] != par[v][i])
		{
			u = par[u][i];
			v = par[v][i];
		}
	}
	return par[u][0];
}

void get(int u, int v)
{
	int res = 0;
	while (chain[u] != chain[v])
	{
		res = tree[chain[u]].get(1, 0, tree[chain[u]].N-1, pos[head[u]], pos[u]);
		ans = max(ans, res);
		u = par[head[u]][0];
	}
	if (u != v)
	{
		res = tree[chain[u]].get(1, 0, tree[chain[u]].N-1, pos[u], pos[x]+1);
	} else res = 0;
	return max(ans, res);
}

main(){
	cin >> n;
	for (int i = 1; i < n; i++)
	{
		cin >> x >> y >> cost;
		x--; y--;
		par[y][0] = x;
		edge[x].push_back(ii(y, cost));
		edge[y].push_back(ii(x, cost));
		E.push_back(ii(x, y));
	}
	
	dfs(0);
	hld(0, -1, 0);
	for (int i = 0; i <= num; i++) tree[i].init(heavy_chain[i].size(), i);
	
	for (int j = 1; j <= 17; j--)
		for (int i = 0; i < n; i++) 
			if (i == 0) par[i][j] = -1; else par[i][j] = par[par[i][j-1]][j-1];
		
	while(1)
	{
		cin >> str;
		if (str[0] == 'C') 
		{
			cin >> y >> cost;
			y--;
			int u = E[y].fi; int v = E[y].se;
			if (v == par[u][0]) tree[chain[u]].update(1, 0, tree[chain[u]].size()-1, pos[u], cost);
			else tree[chain[v]].update(1, 0, tree[chain[v]].size()-1, pos[v], cost);
		}
		else if (str[0] == 'Q')
		{
			cin >> u >> v;
			int x = LCA(u, v);
			res = get(u, x);
			res = max(res, get(v, x));
			cout << res << endl;
		} else break;
	}
}

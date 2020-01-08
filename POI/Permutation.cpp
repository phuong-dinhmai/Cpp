#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 2e5+7;

ll f[N];
int a[N];
int n, m;

struct IT
{
	ll t[8*N];
	ll lazy[8*N];
	void build(int node, int l, int r)
	{
		if (l == r)
		{
			t[node] = f[l];
			//cout << node << " " << f[l] << endl;
			return;
		}
		int mid = (l + r) >> 1;
		build(node << 1, l, mid);
		build(node << 1 | 1, mid+1, r);
		t[node] = min(t[node << 1], t[node << 1 | 1]);
		return;
	}
	
	void trueval(int node)
	{
		if (lazy[node] == 0) return;
		t[node] += lazy[node];
		lazy[node << 1] += lazy[node];
		lazy[node << 1 | 1] += lazy[node];
		lazy[node] = 0;
		return;
	}
	
	ll get(int node, int l, int r, int a, int b)
	{
		trueval(node);
		if (l > b || a > r || l > r) return 1LL;
		if (a <= l && r <= b)
		{
			return t[node];
		} 
		int mid = (l + r) >> 1;
		return min(get(node << 1, l, mid, a, b), get(node << 1 | 1, mid+1, r, a, b));
	}
	
	void update(int node, int l, int r, int a, int b, int val)
	{
		trueval(node);
		if (l > b || a > r || l > r) return;
		if (a <= l && r <= b)
		{
			lazy[node << 1] += val;
			lazy[node << 1 | 1] += val;
			t[node] += val;
			return;
		}
		int mid = (l + r) >> 1;
		update(node << 1, l, mid, a, b, val);
		update(node << 1 | 1, mid + 1, r, a, b, val);
		t[node] = min(t[node << 1], t[node << 1 | 1]);
	}
} tree;

main(){
//	freopen("in.inp","r",stdin);
	//freopen("out.out","w",stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) f[i] = (i-1) - n;
	tree.build(1, 1, n);
	//for (int i = 1; i <= n; i++) tree.get(1, 1, n, i, i);
	
	int mx = 0;
	for (int i = 1; i <= n; i++) 
	{
		scanf("%d", &a[i]);
		mx = max(mx, a[i]);
		tree.update(1, 1, n, 1, a[i], 1);
	}
	if (tree.get(1, 1, n, 1, n) < 0) printf("NIE\n");
	else printf("TAK\n");
	
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		int x, y, k;
		scanf("%d%d", &k, &y);
		x = a[k];
		a[k] = y;
		if (x > y)	tree.update(1, 1, n, y+1, x, -1);
		else if (x < y) tree.update(1, 1, n, x+1, y, 1);
		if (tree.get(1, 1, n, 1, n) < 0) printf("NIE\n"); else printf("TAK\n");
	}
}

#include <bits/stdc++.h>
#define maxN (int) (1e5+7)
using namespace std;

int n, m;
int cnt[27];
char s[maxN];
int tree[27][8*maxN];
int lazy[27][8*maxN];

void build_tree(int node, int l, int r, int pos)
{
	if (l == r) 
	{
		tree[pos][node] = (s[l] - 'a') == pos;
		return;
	}
	int mid = (l+r) >> 1;
	build_tree(node << 1, l, mid, pos);
	build_tree((node << 1) + 1, mid+1, r, pos);
	tree[pos][node] = tree[pos][node << 1] + tree[pos][(node << 1) + 1];
}

void trueval(int pos, int node, int a, int b)
{
	if (lazy[pos][node] == -1) return;
	tree[pos][node] = (b - a + 1)*lazy[pos][node];
	if (a != b)
	{
		lazy[pos][node << 1] = lazy[pos][node];
		lazy[pos][(node << 1) + 1] = lazy[pos][node];
	}
	lazy[pos][node] = -1;
}

void update(int node, int l, int r, int a, int b, int pos, int val)
{
	trueval(pos, node, l, r);
	//cout << l << " " << r << endl;
	if (b < l || a > r || l > r) return;
	if (a <= l && r <= b)
	{
		lazy[pos][node] = val;
		trueval(pos, node, l, r);
		return ;
	}
	int mid = (l + r) >> 1;
	update(node << 1, l, mid, a, b, pos, val);
	update((node << 1) + 1, mid+1, r, a, b, pos, val);
	tree[pos][node] = tree[pos][node << 1] + tree[pos][(node << 1) + 1];
	return;
}

int query(int node, int l, int r, int a, int b, int pos)
{
	trueval(pos, node, l, r);
	if (a > r || b < l || l > r) return 0;
	if (a <= l && r <= b) return tree[pos][node];
	int mid = (l + r) >> 1;
	int lft = query(node << 1, l, mid, a, b, pos);
	int rght = query((node << 1) + 1, mid+1, r, a, b, pos);
	return (lft + rght);
}

main(){
	//freopen("in.inp","r",stdin);
	for (int i = 0; i < 26; i++)
		for (int j = 0; j < 8*maxN; j++) lazy[i][j] = -1;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> s[i];
	for (int i = 0; i < 26; i++) build_tree(1, 1, n, i);
	for (int i = 0; i < m; i++)
	{
		int l, r, type;
		cin >> l >> r >> type;
		for (int j = 0; j < 26; j++) 
		{
			cnt[j] = query(1, 1, n, l, r, j);
		}
		if (type ==1)
		{
			int pos = l;
			for (int j = 0; j < 26; j++) 
			{
				if (cnt[j] == 0) continue;
				update(1, 1, n, l, r, j, 0);
				update(1, 1, n, pos, pos+cnt[j]-1, j, 1);
				pos += (cnt[j]);
			}
		} 
		else
		{
			int pos = l;
			for (int j = 25; j >= 0; j--) 
			{
				if (cnt[j] == 0) continue;
				update(1, 1, n, l, r, j, 0);
				update(1, 1, n, pos, pos+cnt[j]-1, j, 1);
				pos += (cnt[j]);
			}
		}
	}
	//for (int i = 0; i < 26; i++) cout << query(1, 1, n, 8, 8, i) << " "; cout << "\n";
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < 26; j++)
		{
			if (query(1, 1, n, i, i, j) == 1)
			{
				printf("%c", j+'a');
				break;
			}
		}
	}
}

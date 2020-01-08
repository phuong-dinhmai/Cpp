#include <bits/stdc++.h>
#define maxN 100005
using namespace std;

struct NODE
{
	int open, len, close;
} tree[12*maxN];

char ch;
int a[maxN];
int n, m;

void build_tree(int node, int l, int r)
{
	if (l == r)
	{
		tree[node].open = (a[l] == 1? 1: 0);
		tree[node].close = (a[l] == 0? 1: 0);
		tree[node].len = 0;
		return;
	}
    int mid = (l + r) >> 1;
	build_tree(2*node, l, mid);
	build_tree(2*node+1, mid+1, r);
	int tmp = min(tree[2*node].open, tree[2*node+1].close);
	tree[node].len = tree[2*node].len + tree[2*node+1].len + 2*tmp;
	tree[node].close = tree[2*node].close + tree[2*node+1].close - tmp;
	tree[node].open = tree[2*node].open + tree[2*node+1].open - tmp;
}

void update(int node, int l, int r, int pos)
{
	if (pos > r || pos < l || l > r) return;
	if (l == r)
	{
		tree[node].open = (a[l] == 1? 1: 0);
		tree[node].close = (a[l] == 0? 1: 0);
		return;
	}
	int mid = (l + r) >> 1;
	update(2*node, l, mid, pos);
	update(2*node+1, mid+1, r, pos);
	int tmp = min(tree[2*node].open, tree[2*node+1].close);
	tree[node].len = tree[2*node].len + tree[2*node+1].len + 2*tmp;
	tree[node].close = tree[2*node].close + tree[2*node+1].close - tmp;
	tree[node].open = tree[2*node].open + tree[2*node+1].open - tmp;
	return;
}

NODE query(int node, int l, int r, int a, int b)
{
	if (a > r || b < l || l > r) return tree[0];
	if (a <= l && r <= b)
	{
		return tree[node];
	}
	int mid = (l + r) >> 1;
	NODE chil_left = query(2*node, l, mid, a, b);
	NODE chil_right = query(2*node+1, mid+1, r, a, b);
	NODE ans;
	int tmp = min(chil_left.open, chil_right.close);
	ans.len = chil_left.len + chil_right.len + 2*tmp;
	ans.open = chil_left.open + chil_right.open - tmp;
	ans.close = chil_left.close + chil_right.close - tmp;
	return ans;
}

main(){
	//freopen("in.inp","r",stdin);
	ios_base :: sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> ch;
		if (ch == '(') a[i] = 1; else a[i] = 0;
	}
	build_tree(1, 1, n);
	for (int i = 0; i < m; i++)
	{
		int type, l, r, pos;
		cin >> type;
		if (type == 0)
		{
			cin >> pos >> ch;
			if (a[pos] != ch)
			{
				a[pos] = (ch == '('? 1 : 0); 
				update(1, 1, n, pos);
			}
			//for (int j = 1; j <= 15; j++) cout << tree[j].len << " " << tree[j].open << " " << tree[j].close << endl;
			//cout << endl;
		}
		else
		{
			cin >> l >> r;
			if (a[l] == 0 || a[r] == 1)
			{
				printf("0");
				continue;
			}
			if ((r-l+1) & 1) 
			{
				printf("0");
				continue;	
			}
			if (l == r)
			{
				printf("0");
				continue;
			}
			NODE k = query(1, 1, n, l, r);
			if (k.len == (r-l+1)) printf("1"); else printf("0");
		}
	}
	printf("\n");
	return 0;
}

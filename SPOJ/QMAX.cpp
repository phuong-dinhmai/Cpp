#include <bits/stdc++.h>
#define maxN 100005
#define inf (int) (1e9+11111)
using namespace std;

int tree[4*maxN+1];
int lazy[4*maxN+1];
int n, k;

void update(int node, int lft, int rght, int a, int b, int val)
{
	if (lazy[node] != 0) 
	{
		tree[node] += lazy[node];
		if (lft != rght)
		{
			lazy[2*node] += lazy[node];
			lazy[2*node+1] += lazy[node]; 
		}
		lazy[node] = 0;
	}
	if (lft > b || rght < a || lft > rght) return;
	int mid = (lft + rght)/2;
	if (a <= lft && rght <= b)
	{ 
		tree[node] += val;
		if (lft != rght)
		{
			lazy[2*node] += val;
			lazy[2*node+1] += val; 
		}
	}
	else
	{
		update(2*node, lft, mid, a, b, val);
		update(2*node+1, mid+1, rght, a, b, val);
		tree[node] = max(tree[2*node], tree[2*node+1]); 
	}
}

int query(int node, int lft, int rght, int a, int b)
{
	if (lft > b || rght < a || lft > rght) return -inf;
	if (lazy[node] != 0) 
	{
		tree[node] += lazy[node];
		if (lft != rght)
		{
			lazy[2*node] += lazy[node];
			lazy[2*node+1] += lazy[node]; 
		}
		lazy[node] = 0;
	}
	if (a <= lft && rght <= b && lft <= rght) return tree[node];
	int mid = (lft + rght)/2;
	int chil_left = query(2*node, lft, mid, a, b);
	int chil_right = query(2*node+1, mid+1, rght, a, b);
	return (max(chil_left, chil_right));
	 
}

main(){
	//freopen("in.inp","r",stdin);
	cin >> n;
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		int type, L, R, val;
		cin >> type;
		if (type == 0)
		{
			cin >> L >> R >> val;
			update(1, 1, n, L, R, val);
		}
		else
		{
			cin >> L >> R;
			cout << query(1, 1, n, L, R) << endl;
		}
	}
}

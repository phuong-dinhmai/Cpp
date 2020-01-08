#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define ll long long

const int maxN = 50009;
const ll inf = 1e18+7;

struct Node{
	ll left; // segment start from left_side
	ll right; // segment end at right_side
	ll ans; // the maximum segment can get
	ll sum;

	Node (ll y, ll z, ll t, ll k){
		this->left = y; this->right = z; this->sum = t; this->ans = k;
	}

	Node() :left(0LL), right(0LL), sum(0LL), ans(0LL){};

};

Node nodes[4*maxN];

Node add(Node &x, ll val){
	x.left = val;
	x.right = val;
	x.ans = val;
	x.sum = val;
}

void update(int id, int l, int r, int u, int v, ll val){
	if (r < u || l > v || l > r) return;
	if (u <= l && r <= v) {
		add(nodes[id], val);
		return;
	}

	int mid = (l + r) >> 1;
	update(id << 1, l, mid, u, v, val);
	update(id << 1 ^ 1, mid+1, r, u, v, val);

	nodes[id].sum = nodes[id << 1].sum + nodes[id << 1 ^ 1].sum;
	nodes[id].left = max(nodes[id << 1].left, nodes[id << 1].sum + nodes[id << 1 ^ 1].left);
	nodes[id].right = max(nodes[id << 1 ^ 1].right, nodes[id << 1 ^ 1].sum + nodes[id << 1].right);
	nodes[id].ans = max(max(max(nodes[id].left, nodes[id].right), max(nodes[id << 1].ans, nodes[id << 1 ^ 1].ans)),
                     nodes[id << 1].right + nodes[id << 1 ^ 1].left);
	return;
}

Node query(int id, int l, int r, int u, int v){
	if (l > v || r < u) return Node(-inf, -inf, 0, -inf);
	if (u <= l && r <= v) return nodes[id];

	int mid = (l + r) >> 1;

	Node lft = query(id << 1, l, mid, u, v), rght = query(id << 1 ^ 1, mid+1, r, u, v);
	ll lf = max(lft.left, lft.sum + rght.left);
	ll rt = max(rght.right, rght.sum + lft.right);
	ll s = lft.sum + rght.sum;
	ll an = max(max(max(lf, rt), max(lft.ans, rght.ans)),lft.right+rght.left);
	return Node(lf, rt, s, an);
}

main(){
	//freopen("in.inp","r",stdin);
	memset(nodes, 0, sizeof(nodes));
	int n, q;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i){
		ll val;
		scanf("%lld", &val);
		update(1, 1, n, i+1, i+1, val);
	}
	scanf("%d", &q);
	for (int i = 0; i < q; ++i){
		int l, r;
		scanf("%d %d", &l, &r);
		printf("%lld\n",query(1, 1, n, l, r).ans);
	}
}

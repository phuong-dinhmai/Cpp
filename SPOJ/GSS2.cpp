#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int maxN = 100001;
const ll inf = 1e10;

int n, m;

struct Node{
	ll left;
	ll right;
	ll sum;
	ll ans;
	set <ll> list;
	
	Node(ll x, ll y, ll z, ll t){
		this->left = x;
		this->right = y;
		this->sum = z;
		this->ans = t;
	}
	Node(): left(0LL), right(0LL), sum(0LL), ans(0LL){};
};

Node nodes[4*maxN];

void add(Node &x, ll val){
	if (x.list.find(val) != x.list.end()) return;
	x.list.insert(val);
	x.ans += val;
	x.left += val;
	x.right += val;
	x.sum += val;
}

void update(int id, int l, int r, int u, int v, ll val){
	if (l > r || l > v || r < u) return ;
	if (u <= l && r <= v) {
		add(nodes[id], val);
		return;
	}
	
	int mid = (l+r)>>1;
	update(id << 1, l, mid, u, v, val);
	update(id << 1 ^ 1, mid+1, r, u, v, val);
	
	nodes[id].sum = nodes[id << 1].sum + nodes[id << 1 ^ 1].sum;
	nodes[id].left = max(nodes[id << 1].left, nodes[id << 1].sum + nodes[id << 1 ^ 1].left);
	nodes[id].right = max(nodes[id << 1 ^ 1].right, nodes[id << 1 ^ 1].sum + nodes[id << 1].right);
	nodes[id].ans = max(max(nodes[id << 1].ans, nodes[id << 1 ^ 1].ans), nodes[id << 1].right + nodes[id << 1 ^ 1].left);
	merge(nodes[id << 1].list.begin(), nodes[id << 1].list.end(), 
		  nodes[id << 1 ^ 1].list.begin(), nodes[id << 1 ^ 1].list.end(), 
		  inserter(nodes[id].list, nodes[id].list.begin()));
	return;
}

Node query(int id, int l, int r, int u, int v){
	if (l > r || l > v || r < u) return Node(-inf, -inf, -inf, -inf);
	if (u <= l && r <= v) return nodes[id];
	
	int mid = (l+r)>>1;
	Node lft = query(id << 1, l, mid, u, v), rght = query(id << 1 ^ 1, mid+1, r, u, v);
	
	ll lf = max(lft.left, lft.sum + rght.left);
	ll rt = max(rght.right, rght.sum + lft.right);
	ll s = lft.sum + rght.sum;
	ll an = max(max(lft.ans, rght.ans), lft.right+rght.left);
	return Node(lf, rt, s, an);
}

main(){
	freopen("in.inp","r",stdin);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		ll x;
		scanf("%lld", &x);
		update(1, 1, n, i+1, i+1, x);
	}
	
	scanf("%d", &m);
	while (m--){
		int l, r;
		scanf("%d %d", &l, &r);
		printf("%lld\n", query(1, 1, n, l, r).ans);
	}
}

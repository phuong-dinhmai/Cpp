#include <bits/stdc++.h>
using namespace std;

const int maxN = 100001;

#define ans first
#define lazy second

pair<int, bool> nodes[4*maxN];
int n, m;

void Lazy(int id, int l, int r){
	if (!nodes[id].lazy) return;
	
	int mid = (l + r) >> 1;
	nodes[id << 1].lazy ^= 1;
	nodes[id << 1].ans = (mid - l + 1) - nodes[id << 1].ans;
	
	nodes[id << 1 ^ 1].lazy ^= 1;
	nodes[id << 1 ^ 1].ans = (r - mid) - nodes[id << 1 ^ 1].ans;
	
	nodes[id].lazy ^= 1;
	return;
}

void update(int id, int l, int r, int u, int v){
	if (r < u || l > v || l > r) return;
	if (u <= l && r <= v) {
		nodes[id].ans = (r-l+1) - nodes[id].ans;
		nodes[id].lazy ^= 1;
		return;
	}
	
	Lazy(id, l, r);
	int mid = (l+r) >> 1;
	update(id << 1, l, mid, u, v);
	update(id << 1 ^ 1, mid+1, r, u, v);
	nodes[id].ans = nodes[id << 1].ans + nodes[id << 1 ^ 1].ans;
	return;
}

int query(int id, int l, int r, int u, int v){
	if (r < u || l > v || l > r) return 0;
	if (u <= l && r <= v) return nodes[id].ans;
	
	Lazy(id, l, r);
	int mid = (l+r) >> 1;
	return query(id << 1, l, mid, u, v) + query(id << 1 ^ 1, mid+1, r, u, v);
}

main(){
	freopen("in.inp","r",stdin);
	memset(nodes, 0, sizeof(nodes));
	scanf("%d %d", &n, &m);
	while (m--){
		int type;
		int l, r;
		scanf("%d %d %d", &type, &l, &r);
		if (type != 0) printf("%d\n", query(1, 1, n, l, r));
		else update(1, 1, n, l, r);
		
	}
}

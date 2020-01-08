#include <bits/stdc++.h>
using namespace std;

const int N = 4e5+7;

int n, m, s;

struct IT {
	int t[N], lazy[N];
	void trueval(int node) {
		if (!lazy[node]) return;
		t[node] += lazy[node];
		lazy[node << 1] += lazy[node];
		lazy[node << 1 | 1] += lazy[node];
		lazy[node] = 0;
		return ; 
	}
	void update(int node, int l, int r, int a, int b, int val) {
		trueval(node);
		if (l > r || a > r || b < l || a > b) return;
		if (a <= l && r <= b) {
			t[node] += val;
			lazy[node << 1] += val;
			lazy[node << 1 | 1] += val;
			return;
		}
		int mid = (l + r) >> 1;
		update(node << 1, l, mid, a, b, val);
		update(node << 1 | 1, mid+1, r, a, b, val);
		t[node] = max(t[node << 1], t[node << 1 | 1]);
	}
	int get(int node, int l, int r, int a, int b) {
		trueval(node);
		if (l > r || a > r || b < l || a > b) return 0;
		if (a <= l && r <= b) return t[node];
		int mid = (l + r) >> 1;
		return max(get(node << 1, l, mid, a, b), get(node << 1 | 1, mid+1, r, a, b));
	}
} tree;

main(){
	//freopen("in.inp","r",stdin);
	
	scanf("%d%d%d", &n, &s, &m);
	
	for (int i = 0; i < m; i++) {
		int start, en, num;
		scanf("%d%d%d", &start, &en, &num);
		//cout << tree.get(1, 1, n, start, en) << " " << num << " " << s << endl;
		if (tree.get(1, 1, n, start, en-1) + num <= s) printf("T\n"), tree.update(1, 1, n, start, en-1, num);
		else printf("N\n");
	}
}

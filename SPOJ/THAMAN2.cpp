#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 4e4+7;

int n, d;
ll tree[8*N][2][2];
ll ans = 0;

void update(int node, int l, int r, int pos, int val){
	if (l > r || r < pos || l > pos) return;
	if (l == r) {
		tree[node][0][0] = 0;
		tree[node][1][1] = val;
		return;
	}
	
	int mid = (l + r) >> 1;
	update(node << 1, l, mid, pos, val);
	update(node << 1 | 1, mid+1, r, pos, val);
	for (int chosen_start = 0; chosen_start < 2; chosen_start++) 
		for (int chosen_en = 0; chosen_en < 2; chosen_en++) {
			tree[node][chosen_start][chosen_en] = 
			max(tree[node << 1][chosen_start][0] + tree[node << 1| 1][0][chosen_en], 
			max(tree[node << 1][chosen_start][1] + tree[node << 1| 1][0][chosen_en],
				tree[node << 1][chosen_start][0] + tree[node << 1| 1][1][chosen_en]));
		}
	return;
}

main(){
	//freopen("in.inp","r",stdin);
	ios_base :: sync_with_stdio(false); cin.tie(0);
	
	cin >> n >> d;
	for (int i = 1; i <= n; i++){
		int x;
		cin >> x;
		update(1, 1, n, i, x);
	}
	
	while (d--){
		int x, y;
		cin >> x >> y;
		update(1, 1, n, x, y);
		ll res = 0LL;
		for (int chosen_start = 0; chosen_start < 2; chosen_start++)
			for (int chosen_en = 0; chosen_en < 2; chosen_en++) res = max(res, tree[1][chosen_start][chosen_en]);
		ans += res;
	}
	
	cout << ans << endl;
}

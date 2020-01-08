#include <bits/stdc++.h>
#define vi vector <int>
using namespace std;

const int N = 5e4+7;

vi a, b;
int n;
int ans1[N], ans2[N];

struct BIT {
	vi t;
	void init(int n) {
		t.assign(n, 0);
	}
	void update_up(int pos, int val) {
		for (; pos < t.size(); pos += (pos & (-pos))) t[pos] = max(t[pos], val);
	}
	int get_up(int pos) {
		int res = 0;
		for (; pos > 0; pos -= (pos & (-pos))) res = max(res, t[pos]);
		return res;
	}
	void update_down(int pos, int val) {
		for (; pos > 0; pos -= (pos & (-pos))) t[pos] = max(t[pos], val);
	}
	int get_down(int pos) {
		int res = 0;
		for (; pos < t.size(); pos += (pos & (-pos))) res = max(res, t[pos]);
		return res;
	}
} tree1, tree2, tree3;

main(){
	//freopen("in.inp","r",stdin);
	ios_base :: sync_with_stdio(false); cin.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		b.push_back(x);
	}
	
	a = b;
	
	sort(b.begin(), b.end());
	b.resize(unique(b.begin(), b.end()) - b.begin());
	for (int i = 0; i < n; i++) {
		a[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin() + 1;
	}
	//for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
	
	tree1.init(b.size()+10), tree2.init(b.size()+10), tree3.init(b.size()+10);
	for (int i = 0; i < n; i++) {
		int res1 = tree3.get_down(a[i]+1);
		int res = tree1.get_up(a[i]-1);
		tree1.update_up(a[i], res+1);
		tree3.update_down(a[i], res+1);
		int res2 = tree2.get_down(a[i]+1);
		ans1[i] = max(res1, res2) + 1;
		if (ans1[i] < 3) continue;
		tree2.update_down(a[i], ans1[i]);
		//cout << res1 << " " << res2 << endl;
	}
	
	int result = 0;
	tree1.init(b.size()+10), tree2.init(b.size()+10), tree3.init(b.size()+10);
	for (int i = n-1; i >= 0; i--) {
		int res1 = tree3.get_down(a[i]+1);
		int res = tree1.get_up(a[i]-1);
		tree1.update_up(a[i], res+1);
		tree3.update_down(a[i], res+1);
		int res2 = tree2.get_down(a[i]+1);
		ans2[i] = max(res1, res2) + 1;
		if (ans2[i] < 3) continue;
		tree2.update_down(a[i], ans2[i]);
	}
	
	for (int i = 0; i < n; i++) 
		if (ans1[i] > 2 && ans2[i] > 2) result = max(result, ans1[i] + ans2[i] - 1); //, cout << i << " " << ans1[i] << " " << ans2[i] << endl;
	
	cout << result << endl;
}

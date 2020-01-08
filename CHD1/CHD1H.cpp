#include <bits/stdc++.h>
using namespace std;

int k, n, m, l, test;
int x[1005], y[1005];
pair <int, int> a[1005];
string s;

int ab(int x) {
	if (x >= 0) return x; else return -x;
}

void solve() {
	for (int i = 1; i <= s.size(); i++) {
		for (int j = 0; j < k; j++) {
			int dis;
			dis = ab(a[j].first - x[i]) + ab(a[j].second-y[i]);
			if (dis <= 2*i) {
				cout << "Got rekt at " << i << endl;
				return;
			}
		}
	}
	cout << "Escaped Safely!" << endl;
	return;
}

main(){
	freopen("in.inp","r",stdin);
	cin >> test;
	while (test--) {
		cin >> m >> n >> x[0] >> y[0];
		cin >> k;
		for (int i = 0; i < k; i++) cin >> a[i].first >> a[i].second;
		cin >> l;
		cin >> s;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == 'W') {x[i+1] = x[i]; y[i+1] = y[i]+1;}
			if (s[i] == 'A') {x[i+1] = x[i]-1; y[i+1] = y[i];}
			if (s[i] == 'S') {x[i+1] = x[i]; y[i+1] = y[i]-1;}
			if (s[i] == 'D') {x[i+1] = x[i]+1; y[i+1] = y[i];}
		}
		solve();
		//cout << s << endl;
		//for (int i = 0; i <= s.size(); i++) cout << x[i] << " " << y[i] << endl;
	}
}

#include <bits/stdc++.h>
using namespace std;

const int maxN = 201;

int f[maxN], a[501], b[501], n, m;
vector <int> val[201];


void update(int pos, int value){
	while (pos < maxN) {
		f[pos] = max(f[pos], value);
		pos += pos & -pos;
	}
}

int get(int pos){
	int res = 0;
	while (pos > 0) {
		res = max(res, f[pos]);
		pos -= pos & -pos;
	}
	return res;
}

int cal(vector <int> a){
	int ans = 0;
	for (int i = 0; i < a.size(); i++) {
		int x = get(a[i]) + 1;
		update(a[i]+1, x);
		ans = max(x, ans);
	}
	return ans;
}

main(){
	//freopen("in.inp","r",stdin);
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int j = 0; j < m; j++) cin >> b[j];
	for (int i = 0; i < n; i++) 
		for (int j = m-1; j >= 0; j--) val[abs(a[i] - b[j])].push_back(j);
		
	int res = 0;
	for (int i = 0; i < 200; i++){
		if (val[i].size()) {
			memset(f, 0, sizeof (f));
			res = max(res, cal(val[i]));
			//cout << i << " " << cal(val[i]) << endl;
		}
	}
	cout << res << endl;
}

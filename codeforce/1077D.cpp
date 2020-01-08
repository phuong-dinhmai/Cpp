#include <bits/stdc++.h>
using namespace std;

#define ii pair <int, int>
#define se second
#define fi first

const int maxN = 2e5+3;

int n, k;
int a[maxN];
int cnt[maxN];
vector <ii> res;
vector <int> num;

bool cmp(ii x, ii y){
	return x.fi > y.fi;
}

bool check(int num){
	int ans = 0;
	for (int i = 0; i < res.size(); ++i) 
		ans += (int)(res[i].fi / num);
	return (ans >= k);
}

main(){
	freopen("in.inp","r",stdin);
	cin >> n >> k;
	memset(cnt, 0, sizeof(cnt));
	for (int i = 0; i < n; ++i){
		cin >> a[i];
		if (!cnt[a[i]]) num.push_back(a[i]);
		++cnt[a[i]];
	}
	for (int i = 0; i < num.size(); ++i){
		res.push_back(ii(cnt[num[i]], num[i]));
	}
	sort(res.begin(), res.end(), cmp);
	int l = 1, r = n;
	while (l < r-1){
		int mid = (l+r) >> 1;
		if (check(mid)) l = mid; else r = mid-1;
	}
	if (check(r)) l = r;
	bool flag = false;
	for (int i = 0; i < res.size(); ++i) {
		for (int j = 0; j < (int)(res[i].fi/l); ++j) {
			cout << res[i].se << " ";
			k--;
			if (k == 0) {
				flag = true;
				break;
			}
		}
		if (flag) break;
	}	
	cout << endl;
}

#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int maxN = 2e5+5;

ll n, a[maxN];
int mp[1000003];
ll sum = 0LL;
vector <int> res;

main(){
	freopen("in.inp","r",stdin);
	cin >> n;
	memset(mp, 0, sizeof(mp));
	for (int i = 0; i < n; ++i){
		cin >> a[i];
		mp[a[i]]++;
		sum += a[i];
	}
	for (int i = 0; i < n; ++i){
		ll s = sum - a[i];
		//cout << s << endl;
		if (s % 2 == 0 && (s/2 <= 1000000)) {
			if (s/2 == a[i]){
				if (mp[a[i]] > 1) res.push_back(i);
			} else {
				if (mp[s/2] > 0) res.push_back(i);
			}
		}
	}
	cout << res.size() << endl;
	for (int i = 0; i < res.size(); ++i) cout << res[i]+1 << " "; cout << endl;
}

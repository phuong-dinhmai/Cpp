#include <bits/stdc++.h>
using namespace std;

const int maxN = 2e5+3;
const int inf = 1e9+7;

#define ll long long

map <ll, ll> mp;
vector <ll> cnt;
int a[maxN], n, ans = 0;

main(){
	freopen("in.inp","r",stdin);
	cin >> n;
	for (int i = 0; i < n; ++i){
		cin >> a[i]; 
		mp[a[i]]++;
	}
	for (map <ll, ll> :: iterator it = mp.begin(); it != mp.end(); ++it) {
		cnt.push_back(it -> second);
	}
	
	sort(cnt.begin(), cnt.end());
	/*cout << cnt.size() << endl;
	for (int i = 0; i < cnt.size(); ++i) cout << cnt[i] << " "; cout << endl;*/
	
	int mx = cnt[cnt.size()-1];
	//cout << mx << endl;
	//cnt.push_back(inf);
	for (int i = 1; i <= mx; ++i){
		int num = i, res = 0;
		vector <ll> :: iterator it = cnt.begin();
		while (it != cnt.end()) {
			if (it != (cnt.end() - 1)) {
				//cout << "#" << " " << it - cnt.begin() << endl;
				++it;
				res += num;
				num *= 2;
			} else {
				res += num;
				num *= 2;
				//cout << "*" << " " << it - cnt.begin() << endl;
				break;
			}
			it = lower_bound(it, cnt.end(), num);
		}
		ans = max(ans, res);
		//cout << res << " " << i << endl;
	}
	cout << ans << endl;
}

	

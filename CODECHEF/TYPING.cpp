#include <bits/stdc++.h>
using namespace std;

int test, n;
string s;
map <string, int> mp;

main(){
	freopen("in.inp","r",stdin);
	cin >> test;
	while(test--){
		int res = 0;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> s;
			int ans = 2;
			for (int i = 1; i < s.size(); i++){
				bool x = (s[i] == 'd' || s[i] == 'f'), y = (s[i-1] == 'j' || s[i-1] == 'k');
				ans += (x ^ y? 4: 2);
			}
			if (mp.count(s) > 0) ans /= 2;
			mp[s]++;
			res += ans;
		}
		cout << res << endl;
		mp.clear();
	}
}

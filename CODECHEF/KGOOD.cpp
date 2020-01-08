#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9+7;

int test, k;
string s;
int cnt[27];

main(){
	//freopen("in.inp","r",stdin);
	cin >> test;
	while(test--){
		cin >> s >> k;
		int ans = inf;
		memset(cnt, 0, sizeof(cnt));
		map <int, int> mp;
		for (int i = 0; i < s.size(); i++) cnt[s[i]-'a']++;
		for (int i = 0; i < 26; i++) 
			if (cnt[i]) mp[cnt[i]]++;
		for (map<int, int> :: iterator it = mp.begin(); it != mp.end(); ++it){
			int at_least = it->first;
			int res = 0;
			for (int i = 0; i < 26; i++){
				if (cnt[i] < at_least) res += cnt[i];
				else res += max(cnt[i] - at_least - k, 0);
			}
			ans = min(ans, res);
		}
		cout << ans << endl;
	}
}

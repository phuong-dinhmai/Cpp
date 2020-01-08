#include <bits/stdc++.h>
using namespace std;

void solve(string s, string str) {
	string ans = "";
	for (int i = 0; i < str.size(); ++i) {
		if (s[str[i]-'a'] != '*') {
			ans += s[str[i]-'a'];
		} else{
			cout << "EXPOSED" << endl;
			return;
		}
	}
	cout << ans << endl;
	return;
}

main() {
	freopen("in.inp","r",stdin);
	int test;
	string a,b;
	cin >> test;
	while (test--) {
		cin >> a >> b;
		solve(a, b);
	}
}

#include <bits/stdc++.h>
using namespace std;

main() {
	int n, m, t;
	string s, str;
	char ans[1000005];
	//freopen("in.inp","r",stdin);
	int test;
	while (cin >> n >> m >> t) {
		cin >> s >> str;
		reverse(s.begin(), s.end());
		for (int i = 0; i < n; i++) ans[i] = s[i];
		for (int i = 0; i < m; i++) ans[i+n] = str[i];
		for (int i = s.size()-1; i >= max(0, n-t); i--){
			int pass;
			pass = t-(n-i)+1;
			ans[i + min(pass, m)] = s[i];
			//cout << s[i] << " " << i + min(pass, m) << endl;
		}
		for (int j = 0; j < min(m, t); j++){
			int pass;
			pass = t-j;
			ans[j+s.size()-min(pass,n)] = str[j];
			//cout << s[j] << " " << j+s.size()-min(pass,n) << endl;
		}
		for (int i = 0; i < m+n; i++) cout << ans[i];
		cout << endl;
	}
	//https://ideone.com/wLtxmK
}

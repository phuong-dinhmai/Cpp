#include <bits/stdc++.h>
using namespace std;

int n, m;

bool check(string st){
	for (int i = 1; 2*i <= st.size(); i++) {
		if (st[i-1] != st[st.size()-i]) return 0;
	}
	return 1;
}

main(){
	freopen("in.inp","r",stdin);
	while (cin >> n >> m) {
		string s, str;
		cin >> s >> str;
		int bitmask = pow(2, (m+n));
		int res = 0;
		for (int i = 0; i < bitmask; i++) {
			int x = __builtin_popcount(i);
			if (x != n) continue;
			int k = 0, p = 0;
			string ans = "";
			for (int j = 0; j < (m+n); j++) {
				int bit = (1 << j) & i;
				if (bit) {ans += s[k]; k++;} else {ans += str[p]; p++;} 
			}
			if (check(ans)) res++;
		}
		cout << res << endl;
	}
}

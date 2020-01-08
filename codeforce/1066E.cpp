#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 998244353;
const int maxN = 200005;

int n, m;
string s, str;
ll f[maxN], sum[maxN];
ll ans = 0;

main(){
	//freopen("in.inp","r",stdin);
	cin >> n >> m;
	cin >> s >> str;
	while (s.size() < str.size()) s = "0" + s;
	while (str.size() < s.size()) str = "0" + str;
	f[0] = 1;
	for (int i = 1; i < 200005; i++) f[i] = f[i-1]*2 % mod;
	
	for (int i = 1; i <= str.size(); i++){
		sum[i] = sum[i-1] + (str[i-1]=='1'? 1: 0);
	} 
	
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '1') {
			ans = (ans + f[s.size()-1-i]*sum[i+1] % mod) % mod;
		}
	}
	cout << ans % mod << endl;
}

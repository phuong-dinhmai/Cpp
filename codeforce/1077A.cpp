#include <bits/stdc++.h>
using namespace std;

#define ll long long

int test;
ll a, b, k, ans;

main(){
	freopen("in.inp","r",stdin);
	cin >> test;
	while (test--){
		cin >> a >> b >> k;
		ll num = k/2;
		if (k & 1) ans = a*(num+1) - b*num; else ans = (a-b)*num;
		cout << ans << endl;
	}
}

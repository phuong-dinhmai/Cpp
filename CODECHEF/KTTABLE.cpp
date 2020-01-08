#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int maxN = 10005;
const int inf = 1e9+7;

int n, test;
int a[maxN], b[maxN];

main(){
	freopen("in.inp","r",stdin);
	cin >> test;
	a[0] = b[0] = 0;
	while (test--){
		int ans = 0;
		cin >> n;
		for (int i = 1; i <= n; ++i){
			cin >> a[i];
		}
		for (int i = 1; i <= n; ++i){
			cin >> b[i];
		}
		for (int i = 1; i <= n; ++i){
			if ((a[i] - a[i-1]) >= b[i]) ++ans;
		}
		cout << ans << endl;
	}
}

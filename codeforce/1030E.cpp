#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define ll long long

const int maxN = 3e5+3;

int n;
ll a[maxN], ans = 0, sum[maxN], res[maxN];

main(){
	freopen("in.inp","r",stdin);
	cin >> n;
	sum[0] = 0; res[0] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		int num = __builtin_popcount(a[i]);
		cout << a[i] << " " << num << endl;
		sum[i] = sum[i-1] + num;
		res[i] = res[i-1] + num % 2;
		
	}
	for (int i = 3; i <= n; i++){
		if (res[i] % 2) ans += res[i-3];
		else ans += (i - 2 - res[i-3]);
		cout << i << " " << ans << endl;
	}
	for (int i = 0; i <= n; i++) cout << res[i] << " "; cout << endl;
	//cout << ans << endl;
	for (int i = 1; i < n; i++) 
		if (sum[i+1]+sum[i-1] == 2*sum[i]) ans++;
	cout << ans << endl;
}

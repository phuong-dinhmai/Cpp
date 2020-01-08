#include <bits/stdc++.h>
using namespace std;

int n;
long long f[25007];

main(){
	//freopen("in.inp","r",stdin);
	ios_base :: sync_with_stdio(false); cin.tie(0);
	
	cin >> n;
	for (int i = 2; i <= n; i++) {
		long long x;
		cin >> x;
		if (i == 2) f[i] = x;
		else if (i == 3) f[i] = f[i-1] + x;
		else f[i] = min(f[i-1], f[i-2]) + x;
	}
	cout << f[n] << endl;
}

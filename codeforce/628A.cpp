#include <bits/stdc++.h>
using namespace std;

int n, m, b;
int ans = 0, ans2;

main(){
	//freopen("in.inp","r",stdin);
	cin >> n >> m >> b;
	ans2 = b*n;
	while (n > 1)
	{
		int x = n/2;
		ans += (x*2*m);
		ans += x;
		n = (n/2) + n%2;
	}
	
	cout << ans << " " << ans2 << endl;
}

#include <bits/stdc++.h>
using namespace std;

main(){
	int n, m, x1, x2, y1, y2;
	int a[1001][1001];
	long long ans = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= m; j++) cin >> a[i][j];
	cin >> x1 >> y1 >> x2 >> y2;
	for (int i = y1; i <= y2; i++)
		for (int j = x1; j <= x2; j++) ans += a[i][j];
	cout << ans << endl;
}
	

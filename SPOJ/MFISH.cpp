#include <bits/stdc++.h>
#define ii pair <int, int>
#define x first
#define len second
using namespace std;

const int N = 1e5+7;

int n, m;
ii a[N];
int f[N], sum[N], ar[N];

main(){
	//freopen("in.inp","r",stdin);
	ios_base :: sync_with_stdio(false); cin.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		sum[i] = sum[i-1] + x;
	}
	cin >> m;
	for (int i = 1; i <= m; i++) {
		cin >> a[i].x >> a[i].len;
	}
	
	sort(a+1, a+1+m);
	a[0] = ii(0, 0);
	
	int pos = 1;
	for (int i = 1; i <= n; i++) {
		if (i != a[pos+1].x) f[i] = f[i-1];
		else if (pos < m) pos++;
		if (i - a[pos].len < a[pos].x && i - a[pos].len >= a[pos-1].x) f[i] = max(f[i], f[i-a[pos].len] + sum[i] - sum[i-a[pos].len]);
	}
	
	//for (int i = 1; i <= n; i++) cout << f[i] << " "; cout << endl;
	cout << f[n] << endl;
}

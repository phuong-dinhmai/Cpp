#include <bits/stdc++.h>
using namespace std;

const int N = 5e5+7;

int n, m, type;
int a[N], b[N];
long long ans = 0LL;

main(){
	//freopen("in.inp","r",stdin);
	ios_base :: sync_with_stdio(false); cin.tie(0);
	
	cin >> n >> m >> type;
	if (type == 2) cout << (long long)n*m*(n-1)*(m-1)/4 << endl;
	else {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++){
				int num = i*m + j;
				int x1 = num / n;
				int y1 = (num - n*x1) % m;
				a[num] = j*n + i;
				b[j*n + i] = num;
			}
		}
		
		for (int i = 0; i < n*m; i++) {
			if (b[i] != i) {
				int val = b[i];
				int p = a[i];
				swap(a[i], a[val]);
				swap(b[i], b[p]);
				ans++;
				//for (int j = 0; j < n*m; j++) cout << b[j] << " "; cout << endl;
			}
		}
		cout << ans << endl;
	}
}

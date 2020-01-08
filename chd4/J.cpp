#include <bits/stdc++.h>
#define nya(i,a,b) for (int i=a; i<b; ++i)
using namespace std;

int main() {
	int t, n, k;
	int a[10000], sum[10000];
	cin >> t;
	while(t--) {
		cin >> n >> k;
		nya(i,0,n) {
			cin >> a[i];
			sum[i] = sum[i-1] + a[i];
		}
		long long ans = -1e9;
		for (int j=k; j <=n; ++j) {
			long long s = 0;
			for (int i = 0; i < n - k + 1; i = i + k) {
				int s1 = sum[i+k-1] - sum[i-1];
				if (s1 > 0) s += s1;
			}
			ans = max(ans,s);
		}
		cout << ans << endl;
	}
}
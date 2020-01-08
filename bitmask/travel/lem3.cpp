#include <bits/stdc++.h>
using namespace std;
 
int next(int v) {
 	int t = (v | ( v - 1)) + 1;
    int w = t | ((((t & -t) / (v & -v)) >> 1) - 1);
    return w;
}
 
int a[50][50];

int main() {
	ios_base::sync_with_stdio(false);
	int n; cin >> n;
	for (int i=0;i<n*n;++i) cin >> a[i/n][i%n];
	vector<vector<int> > dp(1<<n,vector<int>(n,1e6));
	for (int i=0;i<n;++i) dp[(1<<i)][i]=0;
	for (int pop = 1; pop < n; ++pop) {
		for (int i=(1<<pop)-1;i<(1<<n);i=next(i)) {
			for (int j=0;j<n;++j) {
				if (!(i&(1<<j))) continue;
				for (int k=0;k<n;++k) {
					if (!(i&(1<<k))) dp[i|(1<<k)][k]=min(dp[i|(1<<k)][k],dp[i][j]+a[j][k]);
				}
			}
		}
	}
	cout << *min_element(dp[(1<<n)-1].begin(),dp[(1<<n)-1].end()) << endl;
}
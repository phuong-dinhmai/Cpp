//Bond
//by LMNTrix
// :3
#include <bits/stdc++.h>
#define eb emplace_back
#define mp make_pair
#define ft first
#define nd second
#define init(x,n,y) x.assign(n,y);
using namespace std;

typedef long double ld;
typedef vector<ld> vi;

int next(int v) {
 	int t = (v | ( v - 1)) + 1;
    int w = t | ((((t & -t) / (v & -v)) >> 1) - 1);
    return w;
}

int main() {
	ios_base::sync_with_stdio(false);
	int n; cin >> n;
	vi dp(1<<n,0);
	vector<vi> a(n,vi(n)); for (int j=0;j<n;++j) for (int i=0;i<n;++i) {cin >> a[j][i]; a[j][i]/=100;}
	for (int i=0;i<n;++i) dp[1<<i]=a[0][i];
	for (int ct=1;ct<n;++ct) {
		for (int i=(1<<ct)-1;i<(1<<n);i=next(i)) {
			for (int j=0;j<n;++j) if (!(i&(1<<j))) dp[i|(1<<j)]=max(dp[i|(1<<j)],dp[i]*a[ct][j]);
		}
	}
	cout << setprecision(6) << fixed <<  dp[(1<<n)-1]*100 << endl;
}
#include <bits/stdc++.h>
using namespace std;
 
int m,n;
 
bool check(int a, int b) {
	for (int i=0;i<m-1;++i) {
		int i1=(1<<i), i2=(1<<(i+1));
		if ((a&i1) && (a&i2) && (b&i1) && (b&i2)) return false;
		if (!((a&i1) || (a&i2) || (b&i1) || (b&i2))) return false;	
	}
	return true;
}
 
int dp[30][1 << 10];

int main() {
	ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--) {
		cin >> m >> n;
		if (m>n) swap(m,n);
		for (int i=0,_i=(1<<m);i<_i;++i) dp[0][i]=1;
		for (int i=1;i<n;++i) {
			for (int j=0,_j=(1<<m);j<_j;++j) {
				dp[i][j]=0;
				for (int k=0;k<_j;++k) if (check(j,k)) dp[i][j]+=dp[i-1][k]; 
			}
		}
		int sum=0; for (int i=0,_i=(1<<m);i<_i;++i) sum+=dp[n-1][i];
		cout << sum % int(1e9 + 7) << endl;
	}
}  
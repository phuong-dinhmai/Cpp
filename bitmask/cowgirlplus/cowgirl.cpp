#include <iostream>
using namespace std;

int n, m;
int dp[2001][10][1 << 11];
bool c[2001][10][1 << 11];
const int mod = 1e9 + 7;

int b(int mask, int i) { return (mask & (1 << i)) > 0; }

int f(int i, int j, int mask) {
	if (i == n) return 1;
	if (c[i][j][mask]) return dp[i][j][mask]; c[i][j][mask] = 1;
	int& ans = dp[i][j][mask]; ans = 0;
	if (j == 0 || b(mask, 0) + b(mask, 1) + b(mask, m) > 0) {
		ans = (ans + f(i + (j == m - 1), (j + 1) % m, (mask >> 1))) % mod;
	}
	if (j == 0 || b(mask, 0) + b(mask, 1) + b(mask, m) < 3) {
		ans = (ans + f(i + (j == m - 1), (j + 1) % m, (mask >> 1) + (1 << m))) % mod;
	}
	return ans;
}

int main() {
	int T; cin >> T;
	while (T--) {
		cin >> n >> m;
		if (n < m) swap(n, m);
		if (m == 1) { int ans = 1; for (int i = 0; i < n; ++i) ans = ans * 2 % mod; cout << ans << endl; continue; }
		for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) for (int k = 0; k < (1 << (m + 1)); ++k) dp[i][j][k] = c[i][j][k] = 0;
		int ans = 0;
		for (int start = 0; start < (1 << m); ++start) ans = (ans + f(1, 0, (start << 1))) % mod;
		cout << ans << endl;
	}
}
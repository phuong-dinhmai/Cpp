#include <iostream>
using namespace std;

const int mod = 1e9 + 7;

int n, m;
int A[2001][10];
int dp[2001][10][1 << 10]; bool chk[2001][10][1 << 10];

int b(int mask, int i) { return (mask & (1 << i)) > 0; }

int f(int i, int j, int mask) {
	if (i == n) return 1;
	if (chk[i][j][mask]) return dp[i][j][mask]; chk[i][j][mask] = 1;
	int& ans = dp[i][j][mask]; ans = 0;
	if (A[i][j] != 1) { // Put 0
		if (b(mask, 0) + b(mask, 1) + b(mask, m - 1) || j == m - 1 || j == 0) {
			ans = (ans + f(i + (j == m - 1), (j + 1) % m, (mask >> 1))) % mod;
		}
	}
	if (A[i][j] != 0) { // Put 1
		if (b(mask, 0) + b(mask, 1) + b(mask, m - 1) != 3 || j == m - 1 || j == 0) {
			ans = (ans + f(i + (j == m - 1), (j + 1) % m, (mask >> 1) + (1 << (m - 1)))) % mod;
		}
	}
	return ans;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
		char c; cin >> c; if (c == 'x') A[i][j] = 1; else if (c == 'o') A[i][j] = 0; else A[i][j] = -1;
	}
	if (m < 3) {
		int ans = 1; for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) if (A[i][j] == -1) ans = ans * 2 % mod;
		cout << ans << endl; return 0;
	}
	int ans = 0;
	for (int start = 0; start < (1 << m); ++start) {
		int p = 1; for (int i = 0; i < m; ++i) if (A[0][i] != -1 && (b(start, i) ^ A[0][i])) p = 0;
		if (p) ans = (ans + f(1, 0, start)) % mod;
	}
	cout << ans << endl;
}

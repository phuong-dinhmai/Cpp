#include <bits/stdc++.h>
#define ll unsigned long long
#define ln "\n"
using namespace std;

const ll INF = 1e19;

int main() {
		//freopen("in.inp","r",stdin);
		//freopen("data.out","w",stdout);
	//-------------------------------------------
	ios_base::sync_with_stdio(0);

	int m, n;
	cin >> m >> n;
	cout << INF << endl;

	vector< vector<ll> > a(m+1, vector<ll>()), sum(m+1, vector<ll>());

	for (int i = 0; i <= m; i++) {
		a[i] = vector<ll>(n+1, 0LL);
		sum[i] = vector<ll>(n+1, 0LL);
	}

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
			sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + a[i][j];
		}
	}

	vector<ll> left(n+2, 0LL), right(n+2, 0LL), down(m+2, 0LL), up(m+2, 0LL);

	for (int i = 1; i <= n; i++){
		left[i] = left[i-1] + sum[m][i-1];
	}
	for (int i = n; i > 0; --i){
		right[i] = right[i+1] + sum[m][n] - sum[m][i];
	}
	for (int i = 1; i <= m; i++){
		down[i] = down[i-1] + sum[i-1][n];
	}
	for (int i = m; i > 0; --i){
		up[i] = up[i+1] + sum[m][n] - sum[i][n];
	}
	 //for (int i = 1; i <= m; ++i) cout << up[i] << " ";
	 	//cout << endl;

	ll ans_i = INF, saved_i;
	for (int i = 1; i <= m; i++) {
		ll f = 0LL;
		f = (down[i] + up[i])*2LL;
		if (ans_i > f) {
			ans_i = f;
			saved_i = i;
		}
	}

	ll ans_j = INF, saved_j;
	for (int j = 1; j <= n; j++) {
		ll f = 0LL;
		f = (left[j]+right[j])*2LL;
		if (ans_j > f) {
			ans_j = f;
			saved_j = j;
		}
	}
	// cout << ans_i << " " << ans_j << endl;
	cout << saved_i << " " << saved_j << " " << ans_i + ans_j + sum[m][n]*2LL << endl;
}

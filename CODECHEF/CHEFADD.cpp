#include <bits/stdc++.h>
using namespace std;

#define ll long long

int test, a, b, c;
int f[32][32][32][2];

int add(int bit_a, int bit_b, int car){
	return(bit_a + bit_b + car) % 2;
}

int memo(int carry, int bit_a, int bit_b){
	return (carry + bit_a + bit_b) / 2; 
}

int dp(int pos, int a_left, int b_left, int carry){
	if ((a_left < 0) || (b_left < 0)) return 0;
	//cout << pos << endl;
	if (pos == 31) {
		//cout << pos << " " << a_left << " " << b_left << " " << carry << endl;
		f[pos][a_left][b_left][carry] = ((a_left == 0 && b_left == 0 && carry == 0)? 1: 0);
		return (f[pos][a_left][b_left][carry]);
	}
	if (f[pos][a_left][b_left][carry] != -1) {
		return f[pos][a_left][b_left][carry];
	}
	int bit, ans = 0;
	if ((c & (1 << pos)) > 0) bit = 1; else bit = 0;
	if (add(0, 0, carry) == bit) ans += dp(pos+1, a_left, b_left, memo(carry, 0, 0));
	if (add(0, 1, carry) == bit) ans += dp(pos+1, a_left, b_left-1, memo(carry, 0, 1));
	if (add(1, 0, carry) == bit) ans += dp(pos+1, a_left-1, b_left, memo(carry, 1, 0));
	if (add(1, 1, carry) == bit) ans += dp(pos+1, a_left-1, b_left-1, memo(carry, 1, 1));
	f[pos][a_left][b_left][carry] = ans;
	return ans;
}

main(){
	freopen("in.inp","r",stdin);
	cin >> test;
	while(test--){
		cin >> a >> b >> c;
		memset(f, -1, sizeof(f));
		int cnt1 = __builtin_popcount(a), cnt2 = __builtin_popcount(b);
		cout << dp(0, cnt1, cnt2, 0) << endl;
	}
}

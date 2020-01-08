#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

ll gt (ll n) {
	if (n==1) return n;
	else return n*gt(n-1);
}

int main() {
	int test, n;
	string str, st;
	cin >> test;
	while (test--) {
		cin >> n;
		cin >> str >> st;
		if (str.size() >= n || st.size() >= n) cout << "0" << endl;
		else cout << gt(n) % mod << endl;
	}
}
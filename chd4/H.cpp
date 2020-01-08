#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;

int main() {
	int test;
	cin >> test;
	while (test--) {
		int n;
		cin >> n;
		if (n<=3) cout << "0071" << endl;
		else {
			if (n%2==0) cout << "0069" << endl;
			else cout << "0071" << endl;
		}
	}
}
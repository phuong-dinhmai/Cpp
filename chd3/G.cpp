#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n,a[100000],m,p;

int main() {
	while (cin >> n) {
        for (int i=0; i<n; i++) cin >> a[i];
        m=-1e18;
        for (int i=0; i<=n-5; i++) {
			p=a[i]*a[i+1]*a[i+2]*a[i+3]*a[i+4];
			if (p>m) m=p;
        }
        cout << m << endl;
	}
}
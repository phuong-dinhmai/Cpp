#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n,a[100][100],m,p;

int main() {
	while (cin >> n) {
        for (ll i=0; i<n; i++)
			for (ll j=0; j<n; j++) cin >> a[i][j];
        m=-1e18;
        for (ll i=0; i<n; i++)
			for (ll j=0; j<n; j++) {
                if (i<n-3) { p=a[i][j]*a[i+1][j]*a[i+2][j]*a[i+3][j]; m=max(m,p); }
                if (j<n-3) { p=a[i][j]*a[i][j+1]*a[i][j+2]*a[i][j+3]; m=max(m,p); }
                if ((i<n-3)&&(j<n-3)) { p=a[i][j]*a[i+1][j+1]*a[i+2][j+2]*a[i+3][j+3]; m=max(m,p); }
                if ((i>2)&&(j>2)) { p=a[i][j]*a[i-1][j-1]*a[i-2][j-2]*a[i-3][j-3]; m=max(m,p); }
                if (i>2) { p=a[i][j]*a[i-1][j]*a[i-2][j]*a[i-3][j]; m=max(m,p); }
                if (j>2) { p=a[i][j]*a[i][j-1]*a[i][j-2]*a[i][j-3]; m=max(m,p); }
                if ((i>2)&&(j<n-3)) { p=a[i][j]*a[i-1][j+1]*a[i-2][j+2]*a[i-3][j+3]; m=max(m,p); }
                if ((i<n-3)&&(j>2)) { p=a[i][j]*a[i+1][j-1]*a[i+2][j-2]*a[i+3][j-3]; m=max(m,p); }
			}
        cout << m << endl;
	}
}

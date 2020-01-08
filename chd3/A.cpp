#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vii;
typedef vector<vii> vi;

int n,a;
vi f;

void add(int k) {
	vii t;
	int d=max(f[k-2].size(),f[k-1].size())+1;
	while (f[k-2].size()!=d) f[k-2].push_back(0);
	while (f[k-1].size()!=d) f[k-1].push_back(0);
    for (int i=0; i<d; i++) t.push_back(f[k-1][i]*a+f[k-2][i]);
    int mem=0;
    for (int i=0; i<d; i++) { f[k].push_back((mem+t[i])%10); mem=(mem+t[i])/10; }
}

int main() {
	while (cin >> n >> a) {
		f.assign(n+1,vii());
        f[0].push_back(0); f[1].push_back(1);
		for (int i=2; i<=n; i++) add(i);
		int p=4;
		for (int i=f[n].size()-1; i>=4; i--)
			if (f[n][i]!=0) { p=i; break; }
        for (int i=p; i>p-5; i--) cout <<f[n][i];
		cout << endl;
	}
}

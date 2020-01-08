	//C11Touch
//by LMNTrix
// :3
#include <bits/stdc++.h>
#define eb emplace_back
#define mp make_pair
#define ft first
#define nd second
#define init(x,n,y) x.assign(n,y);
using namespace std;

typedef vector<int> vi;
vector<vi> a,b;
int n, mn=1e9;

void touch(int i, int j) {
	b[i][j]^=1;
	b[i-1][j]^=1;
	b[i][j-1]^=1;
	b[i+1][j]^=1;
	b[i][j+1]^=1;
}

int ct = 0;

void bt(int cur, int des) {
	if (cur==n) {
		for (int i=1;i<=n;++i) if (b[1][i]!=des) return;
		a = b;
		int old = ct;
		for (int i=1;i<n;++i) {
			for (int j=1;j<=n;++j) if (b[i][j]!=des) {++ct; touch(i+1,j);}
		}
		//for (int i=1;i<=n;++i) {for (int j=1;j<=n;++j) cout << b[i][j]; cout << endl;}
		for (int i=1;i<=n;++i) if (b[n][i]!=des) return;
		mn = min(mn,ct); ct=old; b=a; return;
	}
	bt(cur+1,des);
	++ct; touch(1,cur); bt(cur+1,des); touch(1,cur); --ct;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n; char c;
	init(b,n+2,vi(n+2)); for (int i=1;i<=n;++i) for (int j=1;j<=n;++j) {cin >> c; b[i][j]=c-'0';}
	bt(1,0); bt(1,1);
	cout << (mn==1e9?-1:mn) << endl; //if (mn==1e9) return 1;	
}
#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define ll long long
using namespace std;

typedef pair<int,int> ii;
vector<ii> M;

int main() {
	ll a,b,t;
	cin >> a >> b >> t;
	ll ck =0;
	M.pb(ii(a,b));
	while (M[ck].x != b && M[ck].y != a) {
		if (ck == t) break;
		if (M[ck].x <= M[ck].y) 
			 M.pb( ii(2*M[ck].x, M[ck].y - M[ck].x) );
		else M.pb( ii(M[ck].x - M[ck].y, 2*M[ck].y) );
		++ck; 
		cout << ck << endl;
		if (M[ck].x == 0 || M[ck].y == 0) break;
	}
	if (M[ck].x == 0 || M[ck].y == 0) cout << M[ck].x << " " << M[ck].y << endl; 
	else if (ck == t) cout << M[t].x << " " << M[t].y << endl;
	else {
		for (int i = 1; i <= ck; ++i) 
			M.pb( ii(M[i].y, M[i].x) );
		ck += ck - 1;
		//cout << ck << endl;
		if (t <= ck) cout << M[t].x << " " << M[t].y << endl;
		else cout << M[t%ck].x << " " << M[t%ck].y << endl;
	}
}
// 1000000000000000
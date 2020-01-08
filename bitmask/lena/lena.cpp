#include <bits/stdc++.h>
#define eb emplace_back
#define mp make_pair
#define ft first
#define nd second
#define init(x,n,y) x.assign(n,y);
using namespace std;

int next(int v) {
 	int t = (v | ( v - 1)) + 1;
    int w = t | ((((t & -t) / (v & -v)) >> 1) - 1);
    return w;
}

typedef long double ld;
typedef pair<ld, ld> ii;
typedef vector<int> vi;

ld Hypot(ld a, ld b) {
	return hypot(a,b)*hypot(a,b);
}

vector<ii> a;
ld hx, hy;

ld dist(int y, int z = -1) {
	ld ans = Hypot(hx-a[y].ft,hy-a[y].nd);
	if (z==-1) ans+=Hypot(hx-a[y].ft,hy-a[y].nd);
	else ans+=Hypot(a[z].ft-a[y].ft,a[z].nd-a[y].nd)+Hypot(hx-a[z].ft,hy-a[z].nd);
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	ld x,y; cin >> hx >> hy;
	int n; cin >> n;
	for (int i=0;i<n;++i) {cin >> x >> y; a.eb(x,y);}
	vector<ld> dp(1<<n,1e12); dp[(1<<n)-1]=0;
	vector<int> last(1<<n); last[(1<<n)-1]=-1;
	priority_queue<ii, vector<ii>, greater<ii> > q; q.emplace(0,(1<<n)-1);
	while (!q.empty()) {
		int d,i; tie(d,i) = q.top(); q.pop();
		if (i==0) continue;
		int k = i&(-i), pos = log2(k); 
		if (dp[i^k]>dp[i]+dist(pos)) {
			dp[i^k]=dp[i]+dist(pos);
			last[i^k]=i;
			q.emplace(dp[i^k],i^k);
		}
		for (int j=0;j<n;++j) {
			if ((i&(1<<j)) && (j!=pos)) if (dp[(i^k)^(1<<j)]>dp[i]+dist(pos,j)) {
				dp[(i^k)^(1<<j)]=dp[i]+dist(pos,j);
				last[(i^k)^(1<<j)]=i;
				q.emplace(dp[(i^k)^(1<<j)],(i^k)^(1<<j));
			}
		} 
	}
	//for (int i=0;i<dp.size();++i) cout << i << ' ' << dp[i] << endl;
	cout << dp[0] << endl;
	int ans = 0; cout << "0 ";
	while (ans!=-1) { 
		int nw = last[ans]; if (nw==-1) break; for (int i=0;i<n;++i) if ((nw&(1<<i))^(ans&(1<<i))) cout << i+1 << ' ';
		cout << "0 ";
		ans = nw;
	}
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <functional>
#include <utility>
#include <set>
#define pb push_back
#define mp make_pair
#define ft first
#define nd second
#define init(x,n,y) x.assign(n,y);
#define Kagami(f) f.end()
#define Natsu(f) f.begin()
#define NatsuKagami(f) f.begin(),f.end()
#define low(f,x) lower_bound(f.begin(),f.end(),x) 
#define hi(f,x) upper_bound(f.begin(),f.end(),x)
#define poi(a,x,y) for(int a = x; a < (int)y; ++a)
#define meow(a,x,y) for (int a = x; a >= (int)y; --a)
using namespace std;

typedef vector<long long> vi;
string n; int m;
int p;
vector<vi> dp;
vector<vi> F(19);
set<long long> ten_masks;
set<int> P;
vi f10;

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	f10.pb(1); poi(i,1,10) f10.pb(f10.back()*20);
	p = (int)n.length();
	init(dp, (1<<p), vi(m));
	// The following loop finds all masks that produces the same set of digits and eliminate the duplicates
	poi(i,0,(1<<p)) {
		long long ten_based_mask = 0;
		poi(j,0,p) if ((1<<j) & i) ten_based_mask += f10[n[j] - '0'];
		if (!ten_masks.count(ten_based_mask)) {
			F[__builtin_popcount(i)].pb(i); 
			ten_masks.insert(ten_based_mask); 
			P.insert(i);
		}
	}
	poi(i,0,p) if (n[i] != '0' && P.count(1<<i)) dp[1<<i][(n[i]-'0')%m] = 1;
	poi(i,2,p+1) {
		poi(k,0,F[i].size()) {
			int cur = F[i][k];
			poi(j, 0, p) if ((1<<j) & cur) {
				poi(mod, 0, m) {
					//cout << n[j] << ' ' << (mod*10+n[j]-'0')%m << ' ' << mod << endl;
					dp[cur][(mod*10+n[j]-'0')%m] += dp[cur ^ (1<<j)][mod];
					//cout << cur << ' ' << (mod*10+n[j]-'0')%m << ' ' << dp[cur][(mod*10+n[j]-'0')%m] << endl;
				}
			}
		}
	}
	cout << dp[(1<<p)-1][0] << endl;
}
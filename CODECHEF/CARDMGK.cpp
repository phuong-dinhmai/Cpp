#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define st first
#define en second

const int inf = 1e9+7;
const int maxN = 100005;

int test, n, a[maxN];
vector <pair <int, int> > block;

main(){
	freopen("in.inp","r",stdin);
	cin >> test;
	while(test--){
		cin >> n;
		a[0] = -inf;
		a[n+1] = inf;
		int pos = 1;
		for (int i = 1; i <= n; i++){
			cin >> a[i];
			if (a[i] < a[i-1]) {
				block.push_back(make_pair(pos, i-1));
				pos = i;
			}
			if (i == n) block.push_back(make_pair(pos, n));
		}
		//for (int i = 0; i < block.size(); i++) cout << block[i].st << " " << block[i].en << endl; cout << endl;
		if (block.size() > 3) cout << "NO" << endl;
		else if (block.size() == 1) cout << "YES" << endl;
		else if (block.size() == 2) {
			if (a[n] <= a[1]) cout << "YES" << endl; else cout << "NO" << endl;
		} else if (block.size() == 3){
			int x = block[0].en, y = block[1].en;
			if ((a[y] <= a[0] && a[x] <= a[y+1]) || (a[x+1] > a[n] && a[x] < a[y+1])) cout << "YES" << endl; else cout << "NO" << endl;
		}
		block.clear();
	}
}

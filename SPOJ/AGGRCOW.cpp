#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxN = 100001;
const int maxD = 1e9+10; 

vector <ll> pos;
ll dis[maxN];
int test, cow, n;

bool check(ll d, int c)
{
	c--;
	vector <ll> :: iterator p, j = pos.begin();
	for (int i = 0; i < c; ++i){
		p = lower_bound(j, pos.end(), *j+d);
		if (p == pos.end()) return 0;
		j = p;
	}
	return 1;
}

main (){
	//freopen("in.inp", "r", stdin);
	//freopen("out.out", "w", stdout);
	cin >> test;
	for (int k = 0; k < test; ++k)	{
		cin >> n;
		cin >> cow;
		pos.clear();
		for (int i = 0; i < n; ++i) {
			ll x;
			cin >> x;
			pos.push_back(x);
		}
		sort (pos.begin(), pos.end());
		memset(dis, 0, sizeof(dis));
		for (int i = 1; i <= n; ++i) dis[i] = dis[i-1] + pos[i] - pos[i-1];
		ll en = maxD, st = 1;
		while (st < en-1)
		{
			ll mid = (st + en)/2;
			if (check(mid, cow)) st = mid; else en = mid-1;
			//cout << st << " " << mid << " " << en << endl;
		}
		if (check(en, cow)) cout << en << endl; else cout << st << endl;
	}
}

#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int maxN = 100005;
const ll inf = 1e18+3;

int test, n;
ll sum_left[maxN], a[maxN], sum_right[maxN], from_left[maxN], from_right[maxN];

main(){
	//freopen("in.inp","r",stdin);
	cin >> test;
	while(test--){
		cin >> n;
		set <ll> list;
		sum_left[0] = sum_right[n+1] = 0;
		from_left[0] = from_right[n+1] = 0;
		list.insert(0);
		ll ans = -inf;
		
		for (int i = 1; i <= n; ++i){
			cin >> a[i];
			sum_left[i] = sum_left[i-1] + a[i];
			ll mn = *list.begin();
			from_left[i] = sum_left[i] - mn;
			ans = max(ans, from_left[i]);
			list.insert(sum_left[i]);
		}
		
		list.clear();
		list.insert(0);
		for (int i = n; i > 0; --i){
			sum_right[i] = sum_right[i+1] + a[i];
			ll mn = *list.begin();
			from_right[i] = sum_right[i] - mn;
			ans = max(ans, from_right[i]);
			list.insert(sum_right[i]);
		}
		
		for (int i = 2; i < n; i++) ans = max(ans, from_left[i-1]+from_right[i+1]);
		cout << ans << endl;
	}
}

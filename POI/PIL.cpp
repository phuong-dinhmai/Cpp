#include <bits/stdc++.h>
using namespace std;

const int N = 3e6 + 7;

int n, k;
int a[N];
deque <int> dq_max, dq_min;
int ans = 0;

main(){
	//freopen("in.inp","r",stdin);
	ios_base :: sync_with_stdio(false); cin.tie(0);
	
	cin >> k >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	
	dq_min.push_back(1);
	dq_max.push_back(1);
	int l = 1, r = 1;
	while (r <= n) {
		if (a[dq_max.front()] - a[dq_min.front()] <= k) {
			ans = max(ans, r - l + 1);
			r++;
			while (!dq_max.empty() && a[dq_max.back()] <= a[r]) dq_max.pop_back();
			dq_max.push_back(r);
			while (!dq_min.empty() && a[dq_min.back()] >= a[r]) dq_min.pop_back();
			dq_min.push_back(r);
		}
		else {
			l++;
			if (!dq_max.empty() && dq_max.front() < l) dq_max.pop_front();
			if (!dq_min.empty() && dq_min.front() < l) dq_min.pop_front();
			if (l > r) {
				l = r;
				dq_max.push_back(r);
				dq_min.push_back(r);
			}
		}
	}
	cout << ans << endl;
}

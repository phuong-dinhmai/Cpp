#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MaxN =  60001;

int ans = 0, n;
int c[MaxN];

void update(int t){
	while (t <= MaxN){
		++ c[t];
		t += (t & -t);
	}
	return;
}

int get(int t){
	int res = 0;
	while (t > 0)
	{
		res += c[t];
		t -= (t & -t);
	}	
	return res;
}

main () {
	cin >> n;
	for (int i = 0; i < MaxN; ++i) c[i] = 0;
	for (int i = 0; i < n; ++i) 
	{
		int x;
		cin >> x;
		ans += (i - get(x));
		update (x);
	}
	cout << ans;
}

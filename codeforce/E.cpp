#include <bits/stdc++.h>
using namespace std;

#define val first
#define pos second

bool cmp(pair <int, int> x, pair <int, int> y){
	return (x.val > y.val);
}

int n, m;
vector <pair <int, int> > a, b;

void update(int pos, int val){
	if (arr[pos-1] == -inf && arr[pos+1] == inf){
		block.push_back(make_pair(pos, pos));
		block[block.size() - 1].
	}
}

main(){
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		int x;
		cin >> x;
		a.push_back(make_pair(x, i));
	}
	for (int i = 1; i <= m; i++){
		int x;
		cin >> x;
		b.push_back(make_pair(x, i));
	}
	sort(a.begin(), a.end(), cmp);
	sort(b.begin(), b.end(), cmp);
	
	for (int i = 0; i < m; i++){
		while (p < n && b[i].val <= a[p].val){
			update(a[p].pos, a[p].val);
			p++;
			res[b[i].pos] = max(res[b[i].pos], get())
		}
	}
}

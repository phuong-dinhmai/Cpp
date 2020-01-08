#include <bits/stdc++.h>
using namespace std;

#define num first
#define val second

const int maxN = 1e5+7;

int test, n;
int a[maxN];
vector <int> block;
vector <pair <int, int> > emp;

bool check(int k) {
	for (int i = 0; i < emp.size(); ++i) {
		int dis = emp[i].num;
		//cout << dis << " " << emp[i].val << endl;
		if (dis % k + emp[i].val != k) return false; 
	} 
	return true;
}

main(){
	freopen("in.inp","r",stdin);
	cin >> test;
	while(test--){
		cin >> n;
		for (int i = 1; i <= n; ++i) cin >> a[i];
		bool flag = false;
		int k_mn = maxN, k_mx = 0;
		for (int i = n; i > 0; ) {
			if (a[i] != -1) {
				block.push_back(i);
				k_mx = max(k_mx, a[i]);
				int pos = a[i]-1;
				while (i > 0){
					if (pos == 0) break; 
					if (a[i-1] != pos && a[i-1] != -1) {
						flag = true;
						break;
					} 
					a[i-1] = pos--;
					--i;
				}
			}
			--i;
			if (flag) break;
		}
		if (flag) cout << "impossible" << endl;
		else {
			if (block.size() < 2) cout << "inf" << endl;
			else {
				for (int i = 0; i < block.size(); i++) {
					int pos = block[i];
					if (pos < n && a[pos] < k_mx)
					{
						if (a[pos+1] == -1 || a[pos+1] == a[pos]+1) {
							a[pos+1] = a[pos++]+1;
							block[i] = pos;
						} else {
							flag = false; 
							break;
						}
					} 
				}
				if (!flag) cout << "impossible" << endl;
				else {
					
					
				}
			}
		}
		emp.clear(); block.clear();
		//for (int i = 1; i <= n; ++i) cout << a[i] << " "; cout << endl;
	}
}

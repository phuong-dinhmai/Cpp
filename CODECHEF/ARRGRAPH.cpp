#include <bits/stdc++.h>
using namespace std;

int test, n, a[55], parent[55], num_set, p[55];
int prime[14] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 43, 47};

int find(int i){
	return (parent[i] == i? i: (parent[i] = find(parent[i]))); 
}

void join(int i, int j){
	parent[find(i)] = parent[find(j)];
	--num_set;
}

int gcd(int x, int y){
	return (y == 0? x: gcd(y, x % y));
}

bool same_set(int i, int j) {
	return (find(i) == find(j));
}

main(){
	freopen("in.inp","r",stdin);
	cin >> test;
	while (test--) {
		memset(p, 0, sizeof(p));
		cin >> n;
		num_set = n;
		for (int i = 0; i < n; ++i){
			cin >> a[i];
			p[a[i]]++;
			parent[i] = i;
			for (int j = 0; j < i; ++j){
				if (!same_set(i, j) && gcd(a[i], a[j]) == 1) join(i, j);
			}
		}
		//cout << num_set << endl;
		if (num_set == 1) {
			cout << 0 << endl;
			for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
		}
		else {
			cout << 1 << endl;
			for (int i = 13; i > 0; --i) 
				if (p[prime[i]] == 0) {
					cout << prime[i] << " ";
					break;
				}
			for (int i = 1; i < n; ++i) cout << a[i] << " "; cout << endl;
		}
	}
	//cout << gcd(4, 6) << endl;
}

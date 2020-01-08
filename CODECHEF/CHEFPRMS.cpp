#include <bits/stdc++.h>
using namespace std;

int prime[25] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

int n, test;
vector <int> lis;
bool f[100000];

main(){
	freopen("in.inp","r",stdin);
	for (int i = 0; i < 25; i++)
		for (int j = i+1; j < 25; j++) lis.push_back(prime[i]*prime[j]);
	memset(f, 0, sizeof(f));
	for (int i = 0; i < lis.size(); ++i){
		for (int j = i; j < lis.size(); ++j) {
			f[lis[i] + lis[j]] = true;
		}
	}
	cin >> test;
	while(test--){
		cin >> n;
		cout << (f[n]? "YES": "NO") << endl;
	}
}

#include <bits/stdc++.h>
using namespace std;

const int maxN = 5e5+7;

int test, n;
int a[maxN], b[maxN];

main(){
	freopen("in.inp","r",stdin);
	cin >> test;
	while(test--){
		cin >> n;
		for (int i = 0; i < n; ++i) cin >> a[i];
		for (int i = 0; i < n; ++i) cin >> b[i];
		bool flag = true;
		
		if (n < 3){
			for (int i = 0; i < n; i++){
				if (a[i] != b[i]){
					flag = false;
					break;
				}
			}
		} else{
			for (int i = 0; i < n-2; ++i){
				if (a[i] == b[i]) continue;
				if (a[i] > b[i]){
					flag = false;
					break;
				}
				a[i+1] += (b[i] - a[i])*2;
				a[i+2] += (b[i] - a[i])*3;
				a[i] = b[i];
			}
			//for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
			if (a[n-1] != b[n-1] || a[n-2] != b[n-2]) 
			{
				flag = false;
				//cout << a[n-1] << " " << b[n-1] << " " << a[n-2] << " " << b[n-2] << endl;
			}
		}
		cout << (flag? "TAK": "NIE") << endl;
	}
}

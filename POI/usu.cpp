#include <bits/stdc++.h>
#define vi vector <int>
using namespace std;

const int N = 1e6+7;

stack <int> st;
int n, k, num = 0;
char a[N];
int cntW[N];
vi res[N];

main(){
	//freopen("in.inp","r",stdin);
	
	ios_base :: sync_with_stdio(false); cin.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	
	for (int i = 1; i <= k; i++) st.push(i), cntW[i] = cntW[i-1] + (a[i] == 'c');
	
	for (int i = k+1; i <= n; i++) {
		st.push(i);
		cntW[st.size()] = cntW[st.size() - 1] + (a[i] == 'c');
		while (st.size() > k && cntW[st.size()] - cntW[st.size() - k-1] == 1) {
			for (int j = 0; j <= k; j++) {
				res[num].push_back(st.top());
				st.pop();
			}
			num++;
		} 
	}
	
	//cout << num << endl;
	for (int i = num-1; i >= 0; i--){
		for (int j = k; j >= 0; j--) cout << res[i][j] << " ";
		cout << endl;
	}
}


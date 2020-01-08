#include <bits/stdc++.h>
using namespace std; 

typedef long long ll;

const int maxN = 6000;

string str;
ll f[maxN];

bool check(char x, char y){
	if (x == '0') return 0;
	int val = (x-'0')*10 + y-'0';
	//cout << val << endl;
	if (val > 26 || val < 1 ) return 0;
	return 1;
}

main() {
	//freopen("in.inp", "r", stdin);
	while (1) {
		cin >> str;
		if (str == "0") break;
		memset(f, 0, sizeof(f));
		f[0] = 1;
		for (int i = 1; i < str.size(); ++i)
		{
			if (str[i] != '0') f[i] = f[i-1];
			if (check(str[i-1], str[i])) {
				if (i == 1) f[i] ++; else f[i] += f[i-2];
			}
		}
		cout << f[str.size()-1] << endl;
	}
}

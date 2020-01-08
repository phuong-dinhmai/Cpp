#include <bits/stdc++.h>
using namespace std;

int n, d;
int ans = 0;
vector <int> res;

main(){
	//freopen("in.inp","r",stdin);
	cin >> n >> d;
	for (int i = 0; i < d; i++)
	{
		bool flag = false;
		for (int j = 0; j < n; j++)
		{
			char x;
			cin >> x;
			if (x == '0') flag = true;
		}
		if (flag) res.push_back(i);
	}
	for (int i = 0; i < res.size(); i++)
	{
		for (int j = i; j < res.size(); j++)
		{
			if (res[j] - res[i] == (j - i)) ans = max(ans, j - i + 1);
		}
	}
	cout << ans << endl;
}

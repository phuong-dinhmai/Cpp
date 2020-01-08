#include <bits/stdc++.h>
#define vi vector <int>
#define ll long long
using namespace std;

const int N = 1e5+7;
const int inf = 1e9+7;

char ch;
ll ans, val;
int num, n;

main(){
	//freopen("in.inp","r",stdin);
	cin >> n >> ans;
	for (int i = 0; i < n; i++)
	{
		cin >> ch >> val;
		if (ch == '+') ans += val;
		else 
		{
			if (ans >= val) ans -= val; else num++;
		}
	}
	cout << ans << " " << num << endl;
	return 0;
}

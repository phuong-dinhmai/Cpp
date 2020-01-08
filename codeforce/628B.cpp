#include <bits/stdc++.h>
using namespace std;

string s;
long long ans = 0LL;

main(){
	//freopen("in.inp","r",stdin);
	cin >> s;
	for (int i = 0; i < s.size(); i++)
		if ((s[i] - '0') % 4 == 0) ans++;
	
	for (int i = 0; i < s.size()-1; i++)
		{
			int x = (s[i] - '0')*10 + s[i+1] - '0';
			if (x % 4 == 0) ans += (i+1);
		}
	cout << ans << endl;
}

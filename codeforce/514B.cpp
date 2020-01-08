#include <bits/stdc++.h>
using namespace std;

main(){
	freopen("in.inp","r",stdin);
	freopen("out.out","w",stdout);
	
	char s[30];
	int n, k;
	bool ok = true;
	int pos = 0;
	cin >> n >> k;
	for (int i = 0; i < n; i++) s[i] = '?';
	for (int i = 0; i < k; i++)
	{
		int m; char c;
		cin >> m >> c;
		pos = (pos + m + n) % n;
		if (s[pos] != '?' && s[pos] != c)
		{
			cout << "!" << endl;
			return 0;
		}
		s[pos] = c;
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < i; j++) 
			if (s[i] == s[j] && s[i] != '?')
			{
				cout << "!" << endl;
				return 0;
			}
	for (int i = 0; i < n; i++) 
		{
			cout << s[(pos - i + n) % n];;
		}
	cout << endl;
	return 0;
}

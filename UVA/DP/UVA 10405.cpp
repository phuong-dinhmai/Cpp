#include <bits/stdc++.h>
using namespace std;

main(){
	//freopen("in.inp","r",stdin);
	string a, b;
	int f[1002][1002];
	while (getline(cin, a))
	{
		getline(cin, b);
		a.insert(0,"0");
		b.insert(0,"0");
		for (int i = 0; i <= a.size(); i++)
			for (int j = 0; j <= b.size(); j++) f[i][j] = 0;
		for (int i = 1; i < a.size(); i++)
			for (int j = 1; j < b.size(); j++)
				if (a[i] == b[j])
				{
					f[i][j] = f[i-1][j-1] + 1;
				}
				else 
				{
					f[i][j] = max(f[i-1][j], f[i][j-1]);
				}
		cout << f[a.size() - 1][b.size() - 1] << endl;
	}
}

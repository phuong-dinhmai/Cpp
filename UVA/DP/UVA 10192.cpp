#include <bits/stdc++.h>
using namespace std;

main(){
	int test = 0;
	string a, b;
	int f[101][101];
	while (getline(cin, a) && a != "#")
	{
		getline(cin, b);
		test++;
		for (int i = 0; i <= a.size(); i++) f[i][0] = 0;
		for (int j = 0; j <= b.size(); j++) f[0][j] = 0;
		for (int i = 1; i <= a.size(); i++)
			for (int j = 1; j <= b.size(); j++)
				if (a[i-1] == b[j-1]) f[i][j] = f[i-1][j-1] + 1;
				else f[i][j] = max (f[i-1][j], f[i][j-1]);
		printf("Case #%d: you can visit at most %d cities.\n", test, f[a.size()][b.size()]);
	}
}

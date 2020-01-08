#include <bits/stdc++.h>
using namespace std;

main(){
	int n;
	//freopen("in.inp","r",stdin);
	//freopen("out.out","w",stdout);
	while (cin >> n && n)
	{
		char a[n][n];
		bool ok = false;
		int row[n], col[n];
		int pos_x = -1;
		int pos_y = -1;
		for (int i = 0; i < n; i++) col[i] = row[i] = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
			{
				cin >> a[i][j];
				row[i] += a[i][j] - '0';
				col[j] += a[i][j] - '0';
			}
		for (int i = 0; i < n; i++) 
		{
			if (row[i] & 1) 
				if (pos_x == -1) pos_x = i; else 
				{
					cout << "Corrupt" << endl;
					ok = true;
					break;
				}
			if (col[i] & 1) 
				if (pos_y == -1) pos_y = i; else 
				{
					cout << "Corrupt" << endl;
					ok = true;
					break;
				}
		}
		//cout << pos_x << " " << pos_y << endl; 
		if (ok) continue;
		if (pos_x == -1 && pos_y == -1) cout << "OK" << endl; 
		else if (pos_x != -1 && pos_y != -1) cout << "Change bit (" << pos_x +1  << "," << pos_y +1 << ")" << endl;
		else cout << "Corrupt" << endl;
	}
}

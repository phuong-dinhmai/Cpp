#include <bits/stdc++.h>
#define ll long long 
using namespace std;

int a[5] = {50, 25, 10, 5, 1};
int coin[7490][5];

ll change(int n, int index)
{
	if (n == 0) return 1;
	if (n < 0) return 0;
	ll ways = 0;
	if (coin[n][index] != -1) return coin[n][index];
	for (int i = index; i < 5; i++)
		ways += change(n - a[i], i);
	return coin[n][index] = ways;
}

main(){
	for (int i = 0; i < 7490; i++)
		for (int j = 0; j < 5; j++) coin[i][j] = -1;
	int n;
	while (cin >> n)
	{
		cout << change(n, 0) << endl;
	}
}

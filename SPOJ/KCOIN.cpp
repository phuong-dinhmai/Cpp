#include <bits/stdc++.h>
using namespace std;

main()
{
	long n;
	cin >> n;
	int k =__builtin_popcount (n);
	cout << pow(2,k) << endl;
}

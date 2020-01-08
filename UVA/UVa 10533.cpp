#include <bits/stdc++.h>
using namespace std;

vector <int> res;
int test, a, b;

bool prime(int num)
{
	if (num < 2) return false;
	for (int j = 2; j *j <= num; j++)
		if (num % j == 0) return false;
	return true;
}

main(){
	cin >> test;
	for (int i = 2; i < 1000000; i++)
	{
		int k = i;
		int sum = 0;
		while (k > 0)
		{
			sum += k % 10;
			k /= 10;
		}
		if (prime(sum) && prime(i)) res.push_back(i);
	}
	while(test--)
	{
		cin >> a >> b;
		int x = lower_bound(res.begin(), res.end(), a) - res.begin();
		int y = upper_bound(res.begin(), res.end(), b) - res.begin();
		y--;
		cout << (y - x + 1) << endl;
	}
}

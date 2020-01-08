#include <bits/stdc++.h>
#define ii pair <int, int>
using namespace std;

main(){
	
	int test;
	cin >> test;
	while (test--)
	{
		int n, k;
		cin >> n >> k;
		int a[n];
		for (int i = 0; i < n; i++) cin >> a[i];
		deque <ii> dq;
		for (int i = 0; i < n; i++)
		{
			while(!dq.empty() && dq.back().first >= a[i]) dq.pop_back();
			dq.push_back(make_pair(a[i],i));
			if (i - k >= dq.front().second ) dq.pop_front();
			if (i >= k - 1) cout << dq.front().first << " ";
		}
		cout << endl;
	}
}

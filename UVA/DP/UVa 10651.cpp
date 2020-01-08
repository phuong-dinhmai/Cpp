#include <bits/stdc++.h>
using namespace std;

main(){
	int test;
	//freopen("in.inp","r",stdin);
	ios_base :: sync_with_stdio(false);
	cin >> test;
	while(test--)
	{
		int num = 0;
		int board = 0;
		for (int i = 0; i < 12; i++)
		{
			char ch;
			cin >> ch;
			board <<= 1;
			if (ch == 'o') board |= 1, num++;
		}
		int dp[1 << 12];
		for (int i = 0; i < (1 << 12); i++) dp[i] = -1;
		dp[board] = num;
		int ans = num;
		queue <int> q;
		q.push(board);
		while(!q.empty())
		{
			int cur = q.front(), nxt;
			ans = min(ans, dp[cur]);
			q.pop();
			for (int i = 0; i < 10; i++)
			{
				if (cur & (1 << i))
				{
					if ((cur & (1 <<(i+1))) && (!(cur & (1 << (i+2)))))
					{
						nxt = cur;
						nxt |= (1 << (i+2));
						nxt ^= (1 << i);
						nxt ^= (1 << (i+1));
						if (dp[nxt] == -1) q.push(nxt);
						dp[nxt] = dp[cur] - 1;
					}
				}
			}
			for (int i = 11; i > 2; i--)
			{
				if (cur & (1 << i))
				{
					if ((cur & (1 <<(i-1))) && (!(cur & (1 << (i-2)))))
					{
						nxt = cur;
						nxt |= (1 << (i-2));
						nxt ^= (1 << i);
						nxt ^= (1 << (i-1));
						if (dp[nxt] == -1) q.push(nxt);
						dp[nxt] = dp[cur] - 1;
					}
				}
			}
		}
		printf("%d\n", ans);
	}
}

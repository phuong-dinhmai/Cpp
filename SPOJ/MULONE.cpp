#include <bits/stdc++.h>
using namespace std;

const int maxN = 1000001;

char res[2*maxN];
int test, n;

main(){
	scanf("%d", &test);
	while (test--)
	{
		scanf("%d", &n);
		int k = 0;
		for (int i = 1; i < 2*n; i++)
		{
			if (i <= n)
			{
				k += i;
			}
			else k += 2*n-i;
			res[2*n-i] = (char) (k % 10 + '0');
			k /= 10;
		}
		for (int i = 1; i < 2*n; i++) printf("%c", res[i]);
		printf("\n");
	}
}

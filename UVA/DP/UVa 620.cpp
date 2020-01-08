#include <bits/stdc++.h>
using namespace std;

int test;
string str;

int grow(int front, int back)
{
	if (front == back) 
		if (str[front] == 'A') return 1; 
	if (str[back] == 'B' && str[back-1] == 'A')
	{
		if (front == back - 1) return 0;
		if (grow(front, back-2) != 0) return 2;
	}
	if (str[front] == 'B' && str[back] == 'A')
	{
		if (front + 1 == back) return 0;
		if (grow(front+1, back-1) != 0) return 3; 
	}
	return 0;
}

main(){
	//freopen("in.inp","r",stdin);
	cin >> test;
	while(test--)
	{
		cin >> str;
		int t = grow(0, str.size()-1);
		switch(t)
		{
			case 0: printf("MUTANT\n"); break;
			case 1: printf("SIMPLE\n"); break;
			case 2: printf("FULLY-GROWN\n"); break;
			case 3: printf("MUTAGENIC\n"); break;
		}
	}
}

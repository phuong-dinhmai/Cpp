#include <iostream>
//#include <random>
#include <algorithm>
using namespace std;

//random_device rd;
int A[10000], B[10000], pr[10000];

int main() {
	int num = 0;
	for (int i = 1; i <= 30; ++i) for (int j = 1; j <= 30; ++j) if (i * j <= 30) { A[num] = i, B[num] = j; pr[num] = num; ++num; }
	cout << num << endl;
	random_shuffle(pr, pr + num);
	for (int i = 0; i < num; ++i) cout << A[pr[i]] << ' ' << B[pr[i]] << endl;

}
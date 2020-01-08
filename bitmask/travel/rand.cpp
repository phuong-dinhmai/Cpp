#include <iostream>
#include <random>
using namespace std;

random_device rd;

int main() {
	int n = 6 + rd() % 10;
	cout << n << endl;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) cout << (i == j ? 0 : rd() % 20 + 1) << ' ';
		cout << endl;
	}
}
#include <iostream>
#include <random>
using namespace std;

random_device rd;

int main() {
	int n = 3 + rd()%12;
	cout << n << endl;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) cout << rd()%2;
		cout << endl;
	}
}
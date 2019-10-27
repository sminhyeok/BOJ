//2019.10.27 11:35~11:41
#include <iostream>
using namespace std;
const int SIZE = 10000;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int NUM[SIZE+1];
	for (int i = 1; i <= SIZE; i++) NUM[i] = 0;

	int N;
	cin >> N;
	while (N--) {
		int temp; cin >> temp;
		NUM[temp]++;
	}

	for (int i = 1; i <= SIZE; i++)
		for (int j = 0; j < NUM[i]; j++) cout << i << '\n';
}
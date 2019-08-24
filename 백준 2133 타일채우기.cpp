//https://www.acmicpc.net/problem/2133
//2019.08.21 16:39~17:27
#include <iostream>
using namespace std;

int DP[31];
int N;

void init() {
	cin >> N;
	DP[0] = 1;
	DP[2] = 3;
	DP[4] = 11;
}

int dynamic() {
	if (N % 2 != 0) return 0;
	for (int i = 6; i <= N; i += 2) {
		DP[i] += DP[i - 2] * 3;
		for (int j = 4; j <= i; j += 2) {
			DP[i] += 2 * DP[i - j];
		}
	}
	return DP[N];
}

void solution() {
	init();
	cout << dynamic() << endl;
}

int main() {
	solution();
}
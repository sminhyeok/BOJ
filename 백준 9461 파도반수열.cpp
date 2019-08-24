//https://www.acmicpc.net/problem/9461
//2019.08.18 13:14~13:22
#include <iostream>
using namespace std;
unsigned long long DP[101];

void init() {
	int N;
	cin >> N;
	cout << DP[N] << endl;
}

void dynamic() {
	DP[1] = DP[2] = DP[3] = 1;
	for (int i = 4; i <= 100; i++) {
		DP[i] = DP[i - 2] + DP[i - 3];
	}
}

void solution() {
	dynamic();
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
		init();
}

int main() {
	solution();
}
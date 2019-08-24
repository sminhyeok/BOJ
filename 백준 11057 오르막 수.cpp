//https://www.acmicpc.net/problem/11057
//2019.08.18 09:39~09:53
#include <iostream>
#define DIV 10007
using namespace std;

int DP[1001][11];
int N;

void init() {
	cin >> N;
	for (int i = 0; i < 10; i++)
		DP[1][i] = 1;
}

int sum(int n, int i) {
	int result = 0;
	for (int index = i; index <= 10; index++)
		result += DP[n-1][index];
	return result % DIV;
}

void dynamic() {
	for (int i = 2; i <= N; i++) {
		for (int index = 0; index < 10; index++)
			DP[i][index] = sum(i, index);
	}
}

void solution() {
	init();
	dynamic();
	cout << sum(N + 1, 0) << endl;
}

int main() {
	solution();
}
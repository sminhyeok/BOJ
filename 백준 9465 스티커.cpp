//https://www.acmicpc.net/problem/9465
//2019.08.17 21:10~22:36
#include <iostream>
using namespace std;
int NUM[2][100001], DP[3][100001];
int T, N;

int max(int a, int b) { return a > b ? a : b; }

void init() {
	cin >> N;
	DP[0][0] = DP[1][0] = DP[2][0] = 0;
	for (int i = 0; i < 2; i++)
		for (int n = 1; n <= N; n++)
			cin >> NUM[i][n];
}

void dynamic() {
	for (int i = 1; i <= N; i++) {
		DP[0][i] = NUM[0][i] + max(DP[1][i-1], DP[2][i-1]);
		DP[1][i] = NUM[1][i] + max(DP[0][i-1], DP[2][i-1]);
		DP[2][i] = max(DP[0][i-1], DP[1][i-1]);
	}
}

void solution() {
	init();
	dynamic();
	cout << max(max(DP[0][N], DP[1][N]), DP[2][N]) << endl;
}

int main() {
	cin >> T;
	for (int i = 0; i < T; i++)
		solution();
}
//https://www.acmicpc.net/problem/11051
//2019.08.21 15:56~16:34
#include <iostream>
#define DIV 10007
using namespace std;
int DP[1001][1001];
int N, K;

void init() {
	cin >> N >> K;
	DP[0][0] = 1;
	for (int i = 1; i <= N; i++) {
		DP[i][0] = 1;
		for (int j = 1; j <= i; j++) {
			DP[i][j] = (DP[i - 1][j - 1] + DP[i - 1][j]) % DIV;
		}
	}
}

void solution() {
	init();
	cout << DP[N][K] << endl;
}

int main() {
	solution();
}
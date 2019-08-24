//https://www.acmicpc.net/problem/2225
//2019.08.23 16:01~16:25
#include <iostream>
#define DIV 1000000000
using namespace std;
unsigned long long DP[201][201];
int N, K;

void init() {
	cin >> N >> K;
	for (int n = 0; n <= N; n++)
		DP[1][n] = 1;
	for (int k = 2; k <= K; k++)
		DP[k][0] = 1;
}

unsigned long long dynamic() {
	for (int k = 2; k <= K; k++) {
		for (int n = 1; n <= N; n++)
			DP[k][n] = (DP[k][n - 1] + DP[k - 1][n]) % DIV;
	}
	return DP[K][N];
}

void solution() {
	init();
	cout << dynamic() << endl;
}

int main() {
	solution();
}
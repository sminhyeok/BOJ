//https://www.acmicpc.net/problem/2167
//2019.08.17 22:48~23:18
#include <iostream>
using namespace std;

int NUM[301][301], DP[301][301];
int N, M, K;

void init() {
	cin >> N >> M;
	for(int y = 1; y <= N; y++)
		for (int x = 1; x <= M; x++) {
			cin >> NUM[y][x];
			DP[y][x] = DP[y][x-1]+DP[y-1][x] - DP[y-1][x-1]+ NUM[y][x];
		}
}

int calc(int n1, int m1, int n2, int m2) {
	return DP[n2][m2] - DP[n2][m1 - 1] - DP[n1 - 1][m2] + DP[n1-1][m1-1];
}

void solution() {
	init();
	cin >> K;
	for (int k = 0; k < K; k++) {
		int i, j, x, y;
		cin >> i >> j >> x >> y;
		cout << calc(i, j, x, y) << endl;
	}
}

int main() {
	solution();
}
//https://www.acmicpc.net/problem/11048
//2019.08.19 09:49~09:58
#include <iostream>
using namespace std;

int DP[1001][1001];
int MAP[1001][1001];
int N, M;
int dr[] = { 1,0,1 };
int dc[] = { 0,1,1 };

int max(int a, int b) { return a > b ? a : b; }

void init() {
	cin >> N >> M;
	for (int r = 0; r < N; r++)
		for (int c = 0; c < M; c++)
			cin >> MAP[r][c];
}

void dynamic() {
	for(int r = 0; r < N; r++)
		for (int c = 0; c < M; c++) {
			for (int i = 0; i < 3; i++) {
				DP[r + dr[i]][c + dc[i]] = max(DP[r + dr[i]][c + dc[i]], DP[r][c] + MAP[r][c]);
			}
		}
}

void solution() {
	init();
	dynamic();
	cout << DP[N][M] << endl;
}

int main() {
	solution();
}
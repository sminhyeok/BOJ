//https://www.acmicpc.net/problem/1890
//2019.08.24 13:12~13:28
#include <iostream>
#define MAX 100
using namespace std;
long long DP[MAX][MAX];
int MAP[MAX][MAX];
int N;
int dr[] = { 0,1 };
int dc[] = { 1,0 };	// µ¿³²

void init() {
	cin >> N;
	for(int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			cin >> MAP[i][j];
			DP[i][j] = -1;
		}
}

long long DFS(int r, int c) {
	if (r == N - 1 && c == N - 1) return 1;
	if (r < 0 || r >= N || c < 0 || c >= N) return 0;

	if (DP[r][c] != -1) return DP[r][c];

	DP[r][c] = 0;
	for (int i = 0; i < 2; i++) 
		DP[r][c] += DFS(r + MAP[r][c] * dr[i], c + MAP[r][c] * dc[i]);
	return DP[r][c];
}

void solution() {
	init();
	cout << DFS(0, 0) << endl;
}

int main() {
	solution();
}
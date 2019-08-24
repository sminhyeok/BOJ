//https://www.acmicpc.net/problem/1520
//2019.08.23 12:50~16:00
#include <iostream>
using namespace std;

int DP[500][500], MAP[500][500];
int N, M;

int dr[] = { -1,0,1,0 };
int dc[] = { 0,1,0,-1 };	// ºÏµ¿³²¼­


bool check(int before, int mr, int mc) {
	if (mr < 0 || mc < 0 || mr >= N || mc >= M) return false;
	if (MAP[mr][mc] < before) return true;
	else return false;
}

void init() {
	cin >> N >> M;
	for (int r = 0; r < N; r++)
		for (int c = 0; c < M; c++) {
			cin >> MAP[r][c];
			DP[r][c] = -1;
		}
}

int DFS(int r, int c) {
	if (r == N - 1 && c == M - 1) return 1;
	if (r < 0 || r >= N || c < 0 || c >= M) return 0;
	
	if (DP[r][c] != -1) return DP[r][c];
	DP[r][c] = 0;

	for (int i = 0; i < 4; i++) {
		int mr = r + dr[i], mc = c + dc[i];
		if (check(MAP[r][c],mr,mc)) DP[r][c] += DFS(mr, mc);
	}
	return DP[r][c];
}

void solution() {
	init();
	cout << DFS(0, 0) << endl;
}

int main() {
	solution();
}
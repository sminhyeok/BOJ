//https://www.acmicpc.net/problem/16926
//2019.08.09 09:32~10:10
#include <iostream>
#define MAX 300
using namespace std;
int ARR[MAX][MAX];
int N, M, R, T;	// 행, 열, 총 회전수, 내부 회전수

int min(int a, int b) { return a < b ? a : b; }

void init() {
	cin >> N >> M >> R;
	for (int r = 0; r < N; r++)
		for (int c = 0; c < M; c++)
			cin >> ARR[r][c];
	T = min(N, M) / 2;
}

void rotation() {
	for (int i = 0; i < T; i++) {
		int temp= ARR[i][i];
		for (int c = i + 1; c < M - i; c++) ARR[i][c - 1] = ARR[i][c];
		for (int r = i + 1; r < N - i; r++) ARR[r - 1][M - 1 - i] = ARR[r][M - 1 - i];
		for (int c = M - 1 - i; c > i; c--) ARR[N - 1 - i][c] = ARR[N - 1 - i][c-1];
		for (int r = N - 1 - i; r > i; r--) ARR[r][i] = ARR[r - 1][i];
		ARR[i + 1][i] = temp;
	}
}

void print() {
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < M; c++)
			cout << ARR[r][c] << " ";
		cout << "\n";
	}
}

void solution() {
	init();
	for (int i = 0; i < R; i++) rotation(); 
	print();
}

int main() {
	solution();
}
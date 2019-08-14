//https://www.acmicpc.net/problem/16935
//2019.08.09 12:28~
#include <iostream>
using namespace std;
unsigned long long MAP[100][100], TEMP[100][100]; 
int ORDER[1000];
int N, M, R;

void init() {
	cin >> N >> M >> R;
	for (int r = 0; r < N; r++)
		for (int c = 0; c < M; c++)
			cin >> MAP[r][c];
	for (int i = 0; i < R; i++)
		cin >> ORDER[i];
}

void adjust() {
	for (int r = 0; r < N; r++)
		for (int c = 0; c < M; c++)
			MAP[r][c] = TEMP[r][c];
}
void move(int n) {
	if (n == 1) {
		for (int r = 0; r < N; r++) for (int c = 0; c < M; c++) TEMP[N - 1 - r][c] = MAP[r][c];
	}// 상하반전
	else if (n == 2) {
		for (int r = 0; r < N; r++) for (int c = 0; c < M; c++) TEMP[r][M-1-c] = MAP[r][c];
	}// 좌우반전
	else if (n == 3) {
		for (int r = 0; r < N; r++)
			for (int c = 0; c < M; c++)
				TEMP[c][N - 1 - r] = MAP[r][c];
		int temp = N;
		N = M; M = temp;
	}// 오른쪽 90도 회전
	else if (n == 4) {
		for (int r = 0; r < N; r++)
			for (int c = 0; c < M; c++)
				TEMP[M-1-c][r] = MAP[r][c];
		int temp = N;
		N = M; M = temp;
	}// 왼쪽 90도 회전
	else if (n == 5) {
		int R = N / 2, C = M / 2;
		for (int r = 0; r < R; r++) {
			for (int c = 0; c < C; c++)
				TEMP[r][c + C] = MAP[r][c];
			for (int c = C; c < M; c++)
				TEMP[r + R][c] = MAP[r][c];
		}
		for (int r = R; r < N; r++) {
			for (int c = C; c < M; c++)
				TEMP[r][c - C] = MAP[r][c];
			for (int c = 0; c < C; c++)
				TEMP[r - R][c] = MAP[r][c];
		}	
	}
	else {
		int R = N / 2, C = M / 2;
		for (int r = 0; r < R; r++) {
			for (int c = 0; c < C; c++)
				TEMP[r + R][c] = MAP[r][c];
			for (int c = C; c < M; c++)
				TEMP[r][c - C] = MAP[r][c];
		}
		for (int r = R; r < N; r++) {
			for (int c = 0; c < C; c++)
				TEMP[r][c + C] = MAP[r][c];
			for (int c = C; c < M; c++)
				TEMP[r - R][c] = MAP[r][c];
		}
	}
	adjust();
}

void print() {
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < M; c++)
			cout << MAP[r][c] << " ";
		cout << "\n";
	}
}

void solution() {
	init();
	for (int i = 0; i < R; i++)
		move(ORDER[i]);
	print();
}

int main() {
	solution();
}
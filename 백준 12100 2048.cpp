//https://www.acmicpc.net/problem/12100
//2019.09.10 09:20~11:37
#include <iostream>
#define EMPTY 0
using namespace std;

int BLOCK[401];
int BOARD[21][21], N, INDEX;
int MAX;

void init() {
	MAX = 0;
	cin >> N;
	INDEX = 1;
	for(int y = 1; y <= N; y++)
		for (int x = 1; x <= N; x++) {
			int temp;
			cin >> temp;
			if (temp != 0) {
				BOARD[y][x] = INDEX;
				BLOCK[INDEX++] = temp;
				if (temp > MAX) MAX = temp;
			}
		}
}
// 보드에는 블록들의 인덱스 저장

void MOVE(int dir) {
	if (dir == 1) {
		for (int x = 1; x <= N; x++) {
			int bottom = 1;
			for (int y = 1; y <= N; y++) {
				if (BOARD[y][x] != EMPTY) {
					int temp = BOARD[y][x];
					BOARD[y][x] = EMPTY;
					BOARD[bottom][x] = temp;

					for (int next = y + 1; next <= N; next++) {
						if (BOARD[next][x] != EMPTY) {
							if (BLOCK[temp] == BLOCK[BOARD[next][x]]) {
								BLOCK[temp] += BLOCK[BOARD[next][x]];
								BOARD[next][x] = EMPTY;
								if (BLOCK[temp] > MAX) MAX = BLOCK[temp];

							}
							y = next - 1;
							bottom++; break;
						}
					}
				}
			}
		}
	}// 위로 이동 끝
	else if (dir == 2) {
		for (int x = 1; x <= N; x++) {
			int bottom = N;
			for (int y = N; y >= 1; y--) {
				if (BOARD[y][x] != EMPTY) {
					int temp = BOARD[y][x];
					BOARD[y][x] = EMPTY;
					BOARD[bottom][x] = temp;

					for (int next = y - 1; next >= 1; next--) {
						if (BOARD[next][x] != EMPTY) {
							if (BLOCK[temp] == BLOCK[BOARD[next][x]]) {
								BLOCK[temp] += BLOCK[BOARD[next][x]];
								BOARD[next][x] = EMPTY;
								if (BLOCK[temp] > MAX) MAX = BLOCK[temp];
							}
							y = next + 1;
							bottom--; break;
						}
					}
				}
			}
		}
	}// 아래로 이동 끝
	else if (dir == 3) {
		for (int y = 1; y <= N; y++) {
			int bottom = N;
			for (int x = N; x >= 1; x--) {
				if (BOARD[y][x] != EMPTY) {
					int temp = BOARD[y][x];
					BOARD[y][x] = EMPTY;
					BOARD[y][bottom] = temp;

					for (int next = x - 1; next >= 1; next--) {
						if (BOARD[y][next] != EMPTY) {
							if (BLOCK[temp] == BLOCK[BOARD[y][next]]) {
								BLOCK[temp] += BLOCK[BOARD[y][next]];
								BOARD[y][next] = EMPTY;
								if (BLOCK[temp] > MAX) MAX = BLOCK[temp];
							}
							x = next + 1;
							bottom--; break;
						}
					}
				}
			}
		}
	}// 오른쪽으로 이동 끝
	else {
		for (int y = 1; y <= N; y++) {
			int bottom = 1;
			for (int x = 1; x <= N; x++) {
				if (BOARD[y][x] != EMPTY) {
					int temp = BOARD[y][x];
					BOARD[y][x] = EMPTY;
					BOARD[y][bottom] = temp;

					for (int next = x + 1; next <= N; next++) {
						if (BOARD[y][next] != EMPTY) {
							if (BLOCK[temp] == BLOCK[BOARD[y][next]]) {
								BLOCK[temp] += BLOCK[BOARD[y][next]];
								BOARD[y][next] = EMPTY;
								if (BLOCK[temp] > MAX) MAX = BLOCK[temp];
							}
							x = next - 1;
							bottom++; break;
						}
					}
				}
			}
		}
	}// 왼쪽으로 이동 끝
	
}

void DFS(int T) {
	if (T == 5) return;

	for (int dir = 1; dir <= 4; dir++) {
		int temp[21][21], block[401];
		for (int y = 1; y <= N; y++) for (int x = 1; x <= N; x++) temp[y][x] = BOARD[y][x];
		for (int i = 1; i < INDEX; i++) block[i] = BLOCK[i];

		MOVE(dir);
		DFS(T + 1);

		for (int y = 1; y <= N; y++) for (int x = 1; x <= N; x++) BOARD[y][x] = temp[y][x];
		for (int i = 1; i < INDEX; i++) BLOCK[i] = block[i];
	}
}

void solution() {
	init();
	DFS(0);
	cout << MAX << endl;
}

int main() {
	solution();
}
/*
//https://www.acmicpc.net/problem/17085
//2019.08.06 21:18~21:54
#include <iostream>
#define SIZE 15
#define END 2
using namespace std;

bool VISIT[SIZE][SIZE];
char MAP[SIZE][SIZE];
int N, M, MAX;
int dr[] = { -1,0,1,0 };
int dc[] = { 0,1,0,-1 };

void init() {
	cin >> N >> M;
	for (int r = 0; r < N; r++)
		for (int c = 0; c < M; c++) {
			cin >> MAP[r][c];
			VISIT[r][c] = false;
		}
	MAX = 1;
}

// 십자가를 놓을 수 있는 위치인지 확인 + 제일 큰 십자가 크기 반환
int check(int r, int c) {
	int result = 1;
	for (int i = 1; i < SIZE; i++) {
		for (int d = 0; d < 4; d++) {
			int mr = r + i * dr[d], mc = c + i * dc[d];
			if (mr < 0 || mr >= N || mc < 0 || mc >= M) return result;
			if (MAP[mr][mc] != '#') return result;
		}
		result += 4;
	}
}

// large 만큼의 십자가 두기
void put(int r, int c, int large) {
	MAP[r][c] = '*';
	for (int i = 1; i <= large/4; i++) {
		for (int d = 0; d < 4; d++) {
			int mr = r + i * dr[d], mc = c + i * dc[d];
			MAP[mr][mc] = '*';
		}
	}
}

// large 만큼의 십자가 제거
void clear(int r, int c, int large) {
	MAP[r][c] = '#';
	for (int i = 1; i <= large/4; i++) {
		for (int d = 0; d < 4; d++) {
			int mr = r + i * dr[d], mc = c + i * dc[d];
			MAP[mr][mc] = '#';
		}
	}
}

void DFS(int large, int n) {
	if (n == END) {
		if (MAX < large) MAX = large;
		return;
	}

	for (int r = 0; r < N; r++) {
		for (int c = 0; c < M; c++) {

			if (!VISIT[r][c] && MAP[r][c] == '#') {
				if (n == 0) VISIT[r][c] = true;
				int cross = check(r, c);
				put(r, c, cross);
				DFS(large * cross, n + 1);
				clear(r, c, cross);
			}
		}
	}
}

void solution() {
	init();
	DFS(1, 0);
	cout << MAX << endl;
}

int main() {
	solution();
}
*/
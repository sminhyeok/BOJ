//https://www.acmicpc.net/problem/17136
//2019.08.07 13:46~16:23
#include <iostream>
#include <vector>
#define SIZE 10	// 종이의 크기
#define EA 5	// 각 사이즈 종이의 수
#define EMPTY 0	// 색종이를 못두는 공간
#define COVER 1	// 색종이로 덮어야 하는 공간
#define MAX 100
using namespace std;
struct pos {
	int R, C;
};
vector<pos> V;			// COVER 들의 위치
int PAPER[SIZE][SIZE];	// 종이
int COLOR[EA];			// 색종이의 수가 담김
int N, MIN;				// COVER 해야할 공간의 수, 최소 색종이 수
bool VISIT[SIZE][SIZE];

void init() {
	N = EMPTY; MIN = MAX;
	for(int r = 0; r < SIZE; r++)
		for (int c = 0; c < SIZE; c++) {
			cin >> PAPER[r][c];
			VISIT[r][c] = false;
			if (PAPER[r][c] == COVER) { N++; V.push_back({ r,c }); }
		}
	for (int i = 0; i < EA; i++) COLOR[i] = EA;
}

int check(int r, int c) {
	
	int large = 0;
	for (int i = 1; i <= EA; i++) {
		for (int mc = c; mc <= c + i; mc++)
			if (r+i >= SIZE || mc >= SIZE || PAPER[r + i][mc] != COVER) return large;
		for (int mr = r; mr <= r + i; mr++)
			if (c+i >= SIZE || mr >= SIZE || PAPER[mr][c + i] != COVER) return large;
		large++;
	}
	return large;
}

void put(int r, int c, int large, int type) {
	PAPER[r][c] = type;
	for (int i = 1; i <= large; i++) {
		for (int mc = c; mc <= c + i; mc++)	PAPER[r + i][mc] = type;
		for (int mr = r; mr <= r + i; mr++)	PAPER[mr][c + i] = type;
	}
}

void DFS(int left, int ea, int idx) {	// left는 남은 COVER, ea는 사용한 색종이의 수
	if (left == 0) {
		if (ea < MIN) MIN = ea;
		return;
	}
	if (ea >= MIN) return;

	
	int r = V.at(idx).R, c = V.at(idx).C;
	if (PAPER[r][c] == COVER) {
		if (ea >= MIN) return;
		int large = check(r, c);
				
		for (int i = large; i >= 0; i--) {
			if (COLOR[i] > 0) {	// 해당 large의 색종이가 남아 있을때만 부착가능
				COLOR[i]--;
				put(r, c, i, EMPTY);
				DFS(left - (i + 1) * (i + 1), ea + 1, idx+1);
				put(r, c, i, COVER);
				COLOR[i]++;
			}
		}
	}
	else DFS(left, ea, idx + 1);
}

void solution() {
	init();
	DFS(N, 0, 0);
	if (MIN == MAX) MIN = -1;
	cout << MIN << endl;
}

int main() {
	solution();
}
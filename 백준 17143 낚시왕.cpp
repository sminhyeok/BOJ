//https://www.acmicpc.net/problem/17143
//2019.08.14 13:50~15:12
#include <iostream>
#define EMPTY 0
using namespace std;
struct object {
	int r, c, s, d, z;	// 위치, 속도, 방향, 크기
};
object SHARK[10001];
int MAP[101][101];	// 맵에는 상어의 index가 담김
int TEMP[101][101];
int R, C, M;
int dr[] = { -1,0,1,0 };	// 상우하좌
int dc[] = { 0,1,0,-1 };

void init() {
	cin >> R >> C >> M;
	for (int r = 1; r <= R; r++)
		for (int c = 1; c <= C; c++) 
			MAP[r][c] = EMPTY;
			
	for (int i = 1; i <= M; i++) {
		int r, c, s, d, z;
		cin >> r >> c >> s >> d >> z;	// d 1: 위, 2: 아래, 3: 오, 4: 왼
		MAP[r][c] = i;
		if (d == 1) d = 0;
		else if (d == 2) d = 2;
		else if (d == 3) d = 1;
		else d = 3;

		if (d % 2 == 0) s = s %( 2 * (R - 1));		// 2*(R-1) or 2*(C-1) 만큼 움직이면 원위치
		else s = s % (2 * (C - 1));
		SHARK[i] = { r,c,s,d,z };	// d 0123 상우하좌	(d+2)%4로 반대방향
	}
}

// 상어의 인덱스를 받아서 해당 상어를 이동시키고 TEMP에 인덱스 입력
void move(int S) {
	int r = SHARK[S].r, c = SHARK[S].c, s = SHARK[S].s, d = SHARK[S].d, z = SHARK[S].z;
	for (int i = 0; i < s; i++) {
		if (d == 0 && r == 1) d = (d + 2 ) % 4;
		if (d == 2 && r == R) d = (d + 2) % 4;
		if (d == 1 && c == C) d = (d + 2) % 4;
		if (d == 3 && c == 1)	d = (d + 2) % 4;
		
		r += dr[d]; c += dc[d];
	}
	SHARK[S] = { r,c,s,d,z };

	if (TEMP[r][c] == EMPTY) TEMP[r][c] = S; 
	else {
		if (SHARK[TEMP[r][c]].z > SHARK[S].z) {
			SHARK[S].z = EMPTY;	// 상어가 겹치고, 이미 있는 상어가 더 클때 작은 상어는 먹혀서 사라짐
		}
		else {
			SHARK[TEMP[r][c]].z = EMPTY;	// 기존에 있던 상어는 먹히고, 현재 상어가 그 자리 차지
			TEMP[r][c] = S;	
		}
	}
}

void adjust(int t) {
	for(int r = 1; r <= R; r++)
		for (int c = 1; c <= C; c++) {
			if (t == EMPTY) TEMP[r][c] = EMPTY;	// t가 0 이면 TEMP를 초기화
			else MAP[r][c] = TEMP[r][c];		// t가 0 이 아니면 TEMP를 MAP에 적용(이동이 끝난 상어를 맵에 입력)
		}
}

void moving() {
	adjust(EMPTY);
	for (int i = 1; i <= M; i++) {
		if (SHARK[i].z != EMPTY) move(i);
	}
	adjust(1);

}

void solution() {
	init();
	int ANSWER = 0;
	for (int c = 1; c <= C; c++) {
		for (int r = 1; r <= R; r++) {
			if (MAP[r][c] != EMPTY) {
				ANSWER += SHARK[MAP[r][c]].z;
				SHARK[MAP[r][c]].z = EMPTY; MAP[r][c] = EMPTY;
				break;
			}
		}
		if(c != C) moving();
	}
	cout << ANSWER << endl;
}

int main() {
	solution();
	return 0;
}
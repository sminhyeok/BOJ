//https://www.acmicpc.net/problem/13460
//2019.09.09 10:24~12:21
#include <iostream>
using namespace std;

char BOARD[10][10];	// 보드
int N, M, MIN;	// 세로, 가로 크기
int BALL[2][2], HOLEY, HOLEX;
int dy[] = { -1,0,1,0 };	// 상우하좌
int dx[] = { 0,1,0,-1 };

void init() {
	MIN = 11;
	cin >> N >> M;
	for (int y = 0; y < N; y++)
		for (int x = 0; x < M; x++) {
			cin >> BOARD[y][x];
			if (BOARD[y][x] == 'R') { BALL[0][0] = y; BALL[0][1] = x; }
			if (BOARD[y][x] == 'B') { BALL[1][0] = y; BALL[1][1]= x; }
			if (BOARD[y][x] == 'O') { HOLEY = y; HOLEX = x; }

		}
}

void move(int dir) {
	int y1 = BALL[0][0], y2 = BALL[1][0], x1 = BALL[0][1], x2 = BALL[1][1];

	bool RED = true;	// 빨간공 먼저 일지, 파란공 먼저 일지 확인

	if (dir == 0 && y2 < y1) RED = false;
	else if (dir == 1 && x2 > x1) RED = false;
	else if (dir == 2 && y2 > y1) RED = false;
	else if (dir == 3 && x2 < x1) RED = false;
	
	if (RED) {
		for (int i = 0; i < 2; i++) {
			for (int d = 1; d < 10; d++) {
				int my = BALL[i][0] + d * dy[dir], mx = BALL[i][1] + d * dx[dir];
				if (my >= 1 && my < N - 1 && mx >= 1 && mx < M - 1 && BOARD[my][mx] != '#') {
					// 구멍에 도착했을때
					if (BOARD[my][mx] == 'O') { BALL[i][0] = my; BALL[i][1] = mx; break; }
					// 벽끝에 도달해 RED 구슬과 부딪힐 때, BLUE는 그 전칸으로 돌아감
					if (i == 1 && my == BALL[0][0] && mx == BALL[0][1]) {
						BALL[i][0] += (d - 1) * dy[dir]; BALL[i][1] += (d - 1) * dx[dir]; break;
					}
				}
				else { BALL[i][0] += (d - 1) * dy[dir]; BALL[i][1] += (d - 1) * dx[dir]; break; }
			}
		}
	}
	else {
		for (int i = 1; i >=0 ; i--) {
			for (int d = 1; d < 10; d++) {
				int my = BALL[i][0] + d * dy[dir], mx = BALL[i][1] + d * dx[dir];
				if (my >= 1 && my < N - 1 && mx >= 1 && mx < M - 1 && BOARD[my][mx] != '#') {
					// 구멍에 도착했을때
					if (BOARD[my][mx] == 'O') { BALL[i][0] = my; BALL[i][1] = mx; break; }
					// 벽끝에 도달해 BLUE 구슬과 부딪힐 때, RED는 그 전칸으로 돌아감
					if (i == 0 && my == BALL[1][0] && mx == BALL[1][1]) {
						BALL[i][0] += (d - 1) * dy[dir]; BALL[i][1] += (d - 1) * dx[dir]; break;
					}
				}// 더 갈수 있는 곳이 없을때 그전칸으로 돌아감
				else { BALL[i][0] += (d - 1) * dy[dir]; BALL[i][1] += (d - 1) * dx[dir]; break; }
			}
		}
	}
}

void DFS(int dir, int T) {
	if (T >= MIN) return;
	if (BALL[0][0] == BALL[1][0] && BALL[0][1] == BALL[1][1]) return;
	if (BALL[1][0] == HOLEY && BALL[1][1] == HOLEX) return;
	if (BALL[0][0] == HOLEY && BALL[0][1] == HOLEX) { if (MIN > T) MIN = T; return; }
	//cout << dir << " " << T << " R:" << BALL[0][0] << "," << BALL[0][1] << " B:" << BALL[1][0] << "," << BALL[1][1] << endl;
	for (int d = 0; d < 4; d++) {
		if (dir != d && (dir % 2 != d % 2)) {
			int temp[2][2];
			for (int y = 0; y < 2; y++) for (int x = 0; x < 2; x++) temp[y][x] = BALL[y][x];
			move(d);
			if (BALL[0][0] == temp[0][0] && BALL[0][1] == temp[0][1] && BALL[1][0] == temp[1][0] && BALL[1][1] == temp[1][1]) continue;
			DFS(d, T + 1);
			for (int y = 0; y < 2; y++) for (int x = 0; x < 2; x++) BALL[y][x] = temp[y][x];
		}
	}
}


void solution() {
	init();
	DFS(-1, 0);
	if (MIN != 11) cout << MIN << endl;
	else cout << -1 << endl;
}

int main() {
	solution();
}
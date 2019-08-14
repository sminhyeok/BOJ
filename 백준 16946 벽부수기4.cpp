//https://www.acmicpc.net/problem/16946
//2019.08.09 18:33~19:27
#include <iostream>
#include <queue>
#define MAX 1000
using namespace std;
struct pos {
	int r, c;
};
queue<pos> WALL, EMPTY;
char MAP[MAX][MAX];
int GROUP[MAX][MAX];
int GC[MAX * MAX / 2];
int ANSWER[MAX][MAX];
bool VISIT[MAX][MAX];
int N, M, G;	// R, C, 그룹수
int dr[] = { -1,0,1,0 };
int dc[] = { 0,1,0,-1 };

void init() {
	G = 1;
	cin >> N >> M;
	for(int r = 0; r < N; r++)
		for (int c = 0; c < M; c++) {
			cin >> MAP[r][c];
			if (MAP[r][c] == '1') { WALL.push({ r,c }); GROUP[r][c] = 0; }
			else { EMPTY.push({ r,c }); ANSWER[r][c] = 0; }
		}
}
// 연결되는 0끼리 그룹을 만들어 0의 수 저장. 벽은 주변 그룹의 값만 카운트
void part() {
	// 빈칸들이 저장된 큐를 기준으로 그룹에 들어가지 않은 0을 그룹화
	while (!EMPTY.empty()) {
		int r = EMPTY.front().r, c = EMPTY.front().c; EMPTY.pop();
		int result = 1; 
		if (!VISIT[r][c]) VISIT[r][c] = true;
		else continue;
		// Q를 이용해 그룹에 들어갈 0의 수 구하고, Q2를 이용해 그룹화
		queue<pos> Q, Q2; Q.push({ r,c }); Q2.push({ r,c });
		while (!Q.empty()) {
			int R = Q.front().r, C = Q.front().c; Q.pop();
			for (int i = 0; i < 4; i++) {
				int mr = R + dr[i], mc = C + dc[i];
				if (mr >= 0 && mr < N && mc >= 0 && mc < M && !VISIT[mr][mc] && MAP[mr][mc] == '0') {
					VISIT[mr][mc] = true; result++;
					Q.push({ mr,mc }); Q2.push({ mr,mc });
				}
			}
		}// 0인 그룹 카운팅 완료
		
		while (!Q2.empty()) {
			int R = Q2.front().r, C = Q2.front().c; Q2.pop();
			GROUP[R][C] = G;
		}GC[G++] = result % 10;	// GC에 각 그룹의 수 저장. GROUP에는 해당위치 그룹넘버 저장
	}
}

void check(int r, int c) {
	int result = 1;
	int gc[4] = { -1, }, gindex[4] = { -1, };
	for (int i = 0; i < 4; i++) {
		int mr = r + dr[i], mc = c + dc[i];
		if (mr >= 0 && mr < N && mc >= 0 && mc < M &&  MAP[mr][mc] == '0') {
			int index = GROUP[mr][mc];
			gindex[i] = index;
			if (GC[index] > 0) {
				gc[i] = GC[index]; GC[index] = -1;
			}
			else gindex[i] = -1;
			if (gindex[i] != -1) result += gc[i];

		}
	}
	for (int i = 0; i < 4; i++)
		if (gindex[i] != -1) { GC[gindex[i]] = gc[i]; }

	ANSWER[r][c] = result%10;
}

void print() {
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < M; c++)
			cout << ANSWER[r][c];
		cout << "\n";
	}
}
void solution() {
	init();
	part();
	while (!WALL.empty()) {
		int R = WALL.front().r, C = WALL.front().c; WALL.pop();
		check(R, C);
	}
	print();
}

int main() {
	solution();
}
//https://www.acmicpc.net/problem/16234
//2019.08.07 18:23~
#include <iostream>
#include <queue>
#define MAX 50
using namespace std;
struct pos {
	int r, c;
};
int PEOPLE[MAX][MAX];
int N, L, R; // 나라 수, 인구차 L 이상 R 이하
int TOTAL[MAX * MAX];	// 각 연합의 인구 합
bool VISIT[MAX][MAX];	// 각 지점 방문 확인
queue<pos> V[MAX * MAX];	// 연합의 위치를 담을 큐
int dr[] = { -1,0,1,0 };
int dc[] = { 0,1,0,-1 };

void init() {
	cin >> N >> L >> R;
	for (int r = 0; r < N; r++)
		for (int c = 0; c < N; c++) {
			cin >> PEOPLE[r][c];
			VISIT[r][c] = false;
		}
}

// 방문하거나, 주변에 이동할 곳이 없다면 패스
bool check(int r, int c) {
	if (VISIT[r][c]) return false;
	for (int i = 0; i < 4; i++) {
		int mr = r + dr[i], mc = c + dc[i];
		if (mr >= 0 && mr < N && mc >= 0 && mc < N && !VISIT[mr][mc]) {
			int gap = abs(PEOPLE[r][c] - PEOPLE[mr][mc]);
			if (gap >= L && gap <= R) return true;
		}

	}
	return false;
}

int BFS(int r, int c, int index) {
	int total = PEOPLE[r][c];
	VISIT[r][c] = true;
	queue<pos> Q;
	Q.push({ r,c });	V[index].push({ r,c });
	while (!Q.empty()) {
		int Qr = Q.front().r, Qc = Q.front().c;
		Q.pop();
		for (int i = 0; i < 4; i++) {
			int mr = Qr + dr[i], mc = Qc + dc[i];
			if (mr >= 0 && mr < N && mc >= 0 && mc < N && !VISIT[mr][mc]) {
				int GAP = abs(PEOPLE[Qr][Qc] - PEOPLE[mr][mc]);
				if (GAP >= L && GAP <= R) {
					VISIT[mr][mc] = true;
					total += PEOPLE[mr][mc];
					Q.push({ mr,mc }); V[index].push({ mr,mc });
				}
			}
		}
	}
	return total;
}

void move(int index) {
	int people = TOTAL[index] / V[index].size();
	while (!V[index].empty()) {
		int r = V[index].front().r, c = V[index].front().c; V[index].pop();
		PEOPLE[r][c] = people;
	}
}

// 방문기록 제거
void UNVISIT() {
	for (int r = 0; r < N; r++)
		for (int c = 0; c < N; c++)
			VISIT[r][c] = false;
}

void solution() {
	init();
	int answer = 0;
	while (1) {
		bool flag = true;
		int index = 0;	// V에 담길 연합의 인덱스
		for (int r = 0; r < N; r++)
			for (int c = 0; c < N; c++) {
				if (check(r, c)) {	// 방문하지 않았고, 확장 가능한 곳일때
					TOTAL[index] = BFS(r, c, index);
					index++;
				}
			}
		UNVISIT();	
		for (int i = 0; i < index; i++) { flag = false; move(i); }
		
		if (flag) break;	// 인구이동이 없을때 정지
		answer++;
	}
	cout << answer << endl;
}

int main() {
	solution();
}
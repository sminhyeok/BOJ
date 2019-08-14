//https://www.acmicpc.net/problem/16236
//2019.08.07 21:14~22:09
#include <iostream>
#include <queue>
#define MAX 20
using namespace std;
struct pos {
	int r, c, d;
};
int MAP[MAX][MAX];
int N, BIG, EAT, SR, SC, TIME;	// 맵 크기, 상어 크기, 상어가 먹은 수, 상어 위치, 시간
int dr[] = { -1,0,1,0 };
int dc[] = { 0,1,0,-1 };

void init() {
	BIG = 2; EAT = 0; TIME = 0;
	cin >> N;
	for(int r = 0; r < N; r++)
		for (int c = 0; c < N; c++) {
			cin >> MAP[r][c];
			if (MAP[r][c] == 9) {
				SR = r; SC = c;
			}
		}
	MAP[SR][SC] = 0;
}

bool check() {
	queue<pos> Q;
	queue<pos> FISH;
	Q.push({ SR,SC,0 });
	bool VISIT[MAX][MAX];	
	for (int r = 0; r < N; r++) for (int c = 0; c < N; c++) VISIT[r][c] = false;	// 방문 표시 초기화
	VISIT[SR][SC] = true;
	while (!Q.empty()) {
		int R = Q.front().r, C = Q.front().c, D = Q.front().d; Q.pop();
		for (int i = 0; i < 4; i++) {
			int mr = R + dr[i], mc = C + dc[i];
			// 지도 안, 미방문, 상어 크기와 같거나 작을때만 이동가능
			if (mr >= 0 && mr < N && mc >= 0 && mc < N && !VISIT[mr][mc] && MAP[mr][mc] <= BIG) {
				VISIT[mr][mc] = true;
				// 현재 상어 크기보다 작으면 먹을 수 있음
				if (MAP[mr][mc] < BIG && MAP[mr][mc] > 0) FISH.push({ mr,mc,D + 1 });	// 먹을 수 있는 후보군 리스트
				else Q.push({ mr,mc,D + 1 });						// 다른 곳 더 탐색
			}
		}
	}// 먹이 탐색이 끝나면 FISH에는 먹이 후보들이 있음
	if (FISH.empty()) return false;	// 먹을 수 있는게 없을때
	
	int NR, NC, MIN=MAX*MAX;
	// 먹이 후보 중 가장 가깝고, 가장 위, 가장 왼쪽에 있는 물고기 선택. 
	while (!FISH.empty()) {
		int FR = FISH.front().r, FC = FISH.front().c, DIS = FISH.front().d;	FISH.pop();
		if (DIS <= MIN) {
			if (DIS < MIN) {	NR = FR; NC = FC; MIN = DIS;	}	// 제일 가까운 곳 우선
			else {										// 거리가 같을 때
				if (FR < NR) { NR = FR; NC = FC; }		// 가장 위에 있는 물고기 선택
				else if (FR == NR && FC < NC) NC = FC;	// 높이가 같다면, 가장 왼쪽의 물고기 선택
			}
		}
	}// 먹이 선정 완료
	MAP[NR][NC] = 0;
	SR = NR; SC = NC; TIME += MIN;
	EAT++; if (EAT == BIG) { EAT = 0; BIG++; }
	return true;
}

void solution() {
	init();
	while (1) {
		if (!check()) break;
	}
	cout << TIME << endl;
}

int main() {
	solution();
}
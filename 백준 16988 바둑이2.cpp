/*
//https://www.acmicpc.net/problem/16988
#include <iostream>
#include <queue>
#define EMPTY 0
#define MINE 1
#define ENEMY 2
using namespace std;
struct pos {
	int y, x;
};

int MAP[20][20];
int N, M;	// 세로, 가로
int MAX;
int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };

void init() {
	MAX = 0;
	cin >> N >> M;
	for(int y = 0; y < N; y++)
		for (int x = 0; x < M; x++)
			cin >> MAP[y][x];
}

void check() {
	queue <pos> Q;
	bool VISIT[20][20] = { false };
	
int total = 0;
for (int y = 0; y < N; y++) {
	for (int x = 0; x < M; x++) {
		int dis = 1;
		bool flag;	// 적인 돌 옆에 빈공간이 있으면 계산 X

		if (!VISIT[y][x] && MAP[y][x] == ENEMY) {
			flag = true;
			Q.push({ y,x });
			VISIT[y][x] = true;
			while (!Q.empty()) {
				int qy = Q.front().y, qx = Q.front().x; Q.pop();
				for (int i = 0; i < 4; i++) {
					int my = qy + dy[i], mx = qx + dx[i];
					if (my < 0 || my >= N || mx < 0 || mx >= M) continue;
					if (MAP[my][mx] == EMPTY) flag = false;
					if (!VISIT[my][mx] && MAP[my][mx] == ENEMY) {
						Q.push({ my,mx }); dis++; VISIT[my][mx] = true;
					}
				}
			}
			if (flag) total += dis;
		}

	}
}
if (total > MAX) MAX = total;
}

void DFS(int t) {
	if (t == 2) {
		check();
		return;
	}

	for (int y = 0; y < N; y++)
		for (int x = 0; x < M; x++) {
			if (MAP[y][x] == EMPTY) {
				MAP[y][x] = MINE;
				DFS(t + 1);
				MAP[y][x] = EMPTY;
			}
		}
}

int main() {
	init();
	DFS(0);
	cout << MAX << endl;
}
*/
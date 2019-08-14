//https://www.acmicpc.net/problem/16948
//2019.08.07 16:57~17:10
#include <iostream>
#include <queue>
#define MAX 201
using namespace std;
struct pos {
	int r, c, t;
};
queue<pos> Q;
bool VISIT[MAX][MAX];
int dr[] = { -2,-2,0,0,2,2 };
int dc[] = { -1,1,-2,2,-1,1 };
int N, GoalR, GoalC;

void init() {
	int r, c;
	cin >> N >> r >> c >> GoalR >> GoalC;
	Q.push({ r,c,0 });
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			VISIT[i][j] = false;
}

int BFS() {
	while (!Q.empty()) {
		int R = Q.front().r, C = Q.front().c, T = Q.front().t; 
		Q.pop();
		if (R == GoalR && C == GoalC) return T;
		for (int i = 0; i < 6; i++) {
			int mr = R + dr[i], mc = C + dc[i];
			if (mr >= 0 && mr < N && mc >= 0 && mc < N && !VISIT[mr][mc]) {
				VISIT[mr][mc] = true;
				if (GoalR == mr && GoalC == mc) return T + 1;
				Q.push({ mr,mc,T + 1 });
			}
		}
	}
	return -1;
}

void solution() {
	init();
	cout << BFS() << endl;
}

int main() {
	solution();
}
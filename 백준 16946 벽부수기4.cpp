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
int N, M, G;	// R, C, �׷��
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
// ����Ǵ� 0���� �׷��� ����� 0�� �� ����. ���� �ֺ� �׷��� ���� ī��Ʈ
void part() {
	// ��ĭ���� ����� ť�� �������� �׷쿡 ���� ���� 0�� �׷�ȭ
	while (!EMPTY.empty()) {
		int r = EMPTY.front().r, c = EMPTY.front().c; EMPTY.pop();
		int result = 1; 
		if (!VISIT[r][c]) VISIT[r][c] = true;
		else continue;
		// Q�� �̿��� �׷쿡 �� 0�� �� ���ϰ�, Q2�� �̿��� �׷�ȭ
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
		}// 0�� �׷� ī���� �Ϸ�
		
		while (!Q2.empty()) {
			int R = Q2.front().r, C = Q2.front().c; Q2.pop();
			GROUP[R][C] = G;
		}GC[G++] = result % 10;	// GC�� �� �׷��� �� ����. GROUP���� �ش���ġ �׷�ѹ� ����
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
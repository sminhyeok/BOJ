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
int N, L, R; // ���� ��, �α��� L �̻� R ����
int TOTAL[MAX * MAX];	// �� ������ �α� ��
bool VISIT[MAX][MAX];	// �� ���� �湮 Ȯ��
queue<pos> V[MAX * MAX];	// ������ ��ġ�� ���� ť
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

// �湮�ϰų�, �ֺ��� �̵��� ���� ���ٸ� �н�
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

// �湮��� ����
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
		int index = 0;	// V�� ��� ������ �ε���
		for (int r = 0; r < N; r++)
			for (int c = 0; c < N; c++) {
				if (check(r, c)) {	// �湮���� �ʾҰ�, Ȯ�� ������ ���϶�
					TOTAL[index] = BFS(r, c, index);
					index++;
				}
			}
		UNVISIT();	
		for (int i = 0; i < index; i++) { flag = false; move(i); }
		
		if (flag) break;	// �α��̵��� ������ ����
		answer++;
	}
	cout << answer << endl;
}

int main() {
	solution();
}
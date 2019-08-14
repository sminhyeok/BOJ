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
int N, BIG, EAT, SR, SC, TIME;	// �� ũ��, ��� ũ��, �� ���� ��, ��� ��ġ, �ð�
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
	for (int r = 0; r < N; r++) for (int c = 0; c < N; c++) VISIT[r][c] = false;	// �湮 ǥ�� �ʱ�ȭ
	VISIT[SR][SC] = true;
	while (!Q.empty()) {
		int R = Q.front().r, C = Q.front().c, D = Q.front().d; Q.pop();
		for (int i = 0; i < 4; i++) {
			int mr = R + dr[i], mc = C + dc[i];
			// ���� ��, �̹湮, ��� ũ��� ���ų� �������� �̵�����
			if (mr >= 0 && mr < N && mc >= 0 && mc < N && !VISIT[mr][mc] && MAP[mr][mc] <= BIG) {
				VISIT[mr][mc] = true;
				// ���� ��� ũ�⺸�� ������ ���� �� ����
				if (MAP[mr][mc] < BIG && MAP[mr][mc] > 0) FISH.push({ mr,mc,D + 1 });	// ���� �� �ִ� �ĺ��� ����Ʈ
				else Q.push({ mr,mc,D + 1 });						// �ٸ� �� �� Ž��
			}
		}
	}// ���� Ž���� ������ FISH���� ���� �ĺ����� ����
	if (FISH.empty()) return false;	// ���� �� �ִ°� ������
	
	int NR, NC, MIN=MAX*MAX;
	// ���� �ĺ� �� ���� ������, ���� ��, ���� ���ʿ� �ִ� ����� ����. 
	while (!FISH.empty()) {
		int FR = FISH.front().r, FC = FISH.front().c, DIS = FISH.front().d;	FISH.pop();
		if (DIS <= MIN) {
			if (DIS < MIN) {	NR = FR; NC = FC; MIN = DIS;	}	// ���� ����� �� �켱
			else {										// �Ÿ��� ���� ��
				if (FR < NR) { NR = FR; NC = FC; }		// ���� ���� �ִ� ����� ����
				else if (FR == NR && FC < NC) NC = FC;	// ���̰� ���ٸ�, ���� ������ ����� ����
			}
		}
	}// ���� ���� �Ϸ�
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
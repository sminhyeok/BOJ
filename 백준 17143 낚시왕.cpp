//https://www.acmicpc.net/problem/17143
//2019.08.14 13:50~15:12
#include <iostream>
#define EMPTY 0
using namespace std;
struct object {
	int r, c, s, d, z;	// ��ġ, �ӵ�, ����, ũ��
};
object SHARK[10001];
int MAP[101][101];	// �ʿ��� ����� index�� ���
int TEMP[101][101];
int R, C, M;
int dr[] = { -1,0,1,0 };	// �������
int dc[] = { 0,1,0,-1 };

void init() {
	cin >> R >> C >> M;
	for (int r = 1; r <= R; r++)
		for (int c = 1; c <= C; c++) 
			MAP[r][c] = EMPTY;
			
	for (int i = 1; i <= M; i++) {
		int r, c, s, d, z;
		cin >> r >> c >> s >> d >> z;	// d 1: ��, 2: �Ʒ�, 3: ��, 4: ��
		MAP[r][c] = i;
		if (d == 1) d = 0;
		else if (d == 2) d = 2;
		else if (d == 3) d = 1;
		else d = 3;

		if (d % 2 == 0) s = s %( 2 * (R - 1));		// 2*(R-1) or 2*(C-1) ��ŭ �����̸� ����ġ
		else s = s % (2 * (C - 1));
		SHARK[i] = { r,c,s,d,z };	// d 0123 �������	(d+2)%4�� �ݴ����
	}
}

// ����� �ε����� �޾Ƽ� �ش� �� �̵���Ű�� TEMP�� �ε��� �Է�
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
			SHARK[S].z = EMPTY;	// �� ��ġ��, �̹� �ִ� �� �� Ŭ�� ���� ���� ������ �����
		}
		else {
			SHARK[TEMP[r][c]].z = EMPTY;	// ������ �ִ� ���� ������, ���� �� �� �ڸ� ����
			TEMP[r][c] = S;	
		}
	}
}

void adjust(int t) {
	for(int r = 1; r <= R; r++)
		for (int c = 1; c <= C; c++) {
			if (t == EMPTY) TEMP[r][c] = EMPTY;	// t�� 0 �̸� TEMP�� �ʱ�ȭ
			else MAP[r][c] = TEMP[r][c];		// t�� 0 �� �ƴϸ� TEMP�� MAP�� ����(�̵��� ���� �� �ʿ� �Է�)
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
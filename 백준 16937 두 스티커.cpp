/*
//https://www.acmicpc.net/problem/16937
// 2019.08.02 14:58~
#include <iostream>
#include <algorithm>
using namespace std;

struct STICKER {
	int R, C;
};
STICKER S1[100], S2[100];	// ���� �������� ��������, �������� �� ��ƼĿ���� 90ȸ��(R�� C�� �ٲ�)
int H, W, N;	// ����, ����, ��ƼĿ ��
int MAX;
int H1, W1, H2, W2;	// ��ƼĿ�� ���� ���� - R = 1, C = 1 �� ��ƼĿ�� H1, H2 =0, W1,W2 = 0�� ��
bool FIND;

bool comp(const STICKER& a, STICKER& b) {
	if (a.R * a.C > b.R * b.C) return true;
	else return false;
}


void init() {
	FIND = false;
	H1 = 0; W1 = 0;
	cin >> H >> W >> N;

	for (int i = 0; i < N; i++) {
		int r, c;
		cin >> r >> c;
		S1[i].R = r; S1[i].C = c;
	}
	sort(S1, S1 + N, comp);
	for (int i = 0; i < N; i++) {
		S2[i].R = S1[i].C;
		S2[i].C = S1[i].R;
	}

}

// �ش� ��ƼĿ�� ���� ������ �ִ��� Ȯ��
bool check(STICKER s, int r, int c, int t) {
	// ��ƼĿ�� ���������� �����̸� ��� ���
	if (r < 0 || c < 0) return false;
	if (r + s.R > H || c + s.C > W) return false;

	// ��ƼĿ�� ���� �� �𼭸��� H1,W1,H2,W2 �� �� ���� �����ϴ� ��ġ�� ��ġ���� Ȯ��
	if (t==1 && (H1 <= r && H2 >= r) && (W1 <= c && W2 >= c)) return false;

	return true;
}

void DFS(int t, int sum, int next) {
	if (t == 2) {
		if (MAX < sum) MAX = sum;
		return;
	}

	for (int i = next; i < N; i++) {
		if (t == 0) {
			if (MAX >= S1[i].R * S1[i].C * 2) return;	// �̹� ���� MAX ���� �� ū MAX�� ���� �� �� �����Ƿ� ����
			if (check(S1[i], 0, 0, 0)) {	// ���� �Ʒ��� ��ƼĿ ����
				H2 = S1[i].R - 1; W2 = S1[i].C - 1;
				DFS(t + 1, S1[i].R * S1[i].C, i + 1);
			}
			if (check(S2[i], 0, 0, 0)) {
				H2 = S2[i].R - 1; W2 = S2[i].C - 1;
				DFS(t + 1, S2[i].R * S2[i].C, i + 1);
			}
		}
		else {
			if (MAX >= sum + S1[i].R * S1[i].C) return;	// �̹� ���� MAX ���� �� ū MAX ���� �� ����
			if (check(S1[i], H - S1[i].R, W - S1[i].C, 1)) {	// ������ �Ʒ��� ��ƼĿ ����
				DFS(t + 1, sum + S1[i].R * S1[i].C, i);
			}
			if (check(S2[i], H - S2[i].R, W - S2[i].C, 1)) {	// ������ �Ʒ��� ��ƼĿ ����
				DFS(t + 1, sum + S2[i].R * S2[i].C, i);
			}
		}
	}
}

int main() {
	init();
	DFS(0, 0, 0);
	cout << MAX << endl;
}

*/
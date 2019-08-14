//https://www.acmicpc.net/problem/16917
//2019.08.09 13:53~14:11
#include <iostream>
using namespace std;
int PRICE[3];	// ���, �Ķ��̵�, �ݹ� ����
int X, Y;		// ���, �Ķ��̵� ġŲ

int min(int a, int b) { return a < b ? a : b; }

void init() {
	for (int i = 0; i < 3; i++) cin >> PRICE[i];
	cin >> X >> Y;
}

void solution() {
	init();
	int MIN = min(PRICE[0] + PRICE[1], PRICE[2] * 2);	// ���, �Ķ��̵� �Ѹ����� �� �� ���� ���Ե�� ���
	int MIN_EA = min(X, Y);	// �� ���� ġŲ ����
	int TOTAL = MIN_EA * MIN;
	int GAP = X - Y;

	int REST;	// ���� ġŲ �� ��
	if (GAP < 0) REST = abs(GAP) * PRICE[1];	// �Ķ��̵带 �� ����Ҷ�
	else REST = GAP * PRICE[0];				// ����� �� ����Ҷ�
	REST = min(REST, abs(GAP) * PRICE[2] * 2); // ������ ���Ϸ� �춧�� �ݹ����� �춧 ��
	TOTAL += REST;
	cout << TOTAL << endl;
}

int main() {
	solution();
}
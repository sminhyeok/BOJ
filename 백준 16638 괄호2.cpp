/*
//https://www.acmicpc.net/problem/16638
#include <iostream>
#include <stack>
using namespace std;

long long MAX;
int N, SC, NC;	// ���ڿ� ����, �ɺ� ��, ���� ��
char INPUT[20]; // �Է� ���ڿ�
char SYM[10];	// �ɺ�
bool FLAG[11] = { false };

void init() {
	MAX = -2147483647;
	cin >> N;
	SC = 1; NC = 1;
	for (int i = 0; i < N; i++) {
		char temp;
		cin >> temp;
		INPUT[i] = temp;
		if (temp >= '0' && temp <= '9') NC++;
		else SYM[SC++] = temp;
	}
}

long long SUM(char symbol, long long num1, long long num2) {
	long long result;
	if (symbol == '-') result = num1 - num2;
	else if (symbol == '+') result = num1 + num2;
	else result = num1 * num2;
	return result;
}

void calc() {
	long long result;
	long long NUM[11];
	char sym[10];

	for (int i = 1; i < NC; i++) NUM[i] = INPUT[2 * (i - 1)] - '0';
	for (int i = 1; i < SC; i++) {
		sym[i] = SYM[i];
		if (FLAG[i]) {
			NUM[i] = SUM(sym[i], NUM[i], NUM[i + 1]);
			NUM[i + 1] = NUM[i];
			sym[i] = ' ';
		}
	}// ��ȣ����
	int sc = 0;
	for (int i = 1; i < SC; i++) {
		if (sym[i] != ' ') {
			sym[sc] = sym[i];
			NUM[sc++] = NUM[i];
		}
	}NUM[sc] = NUM[NC - 1];

	// sym���� �ɺ���, NUM���� ���ڵ��� �����Ǿ�����
	for (int i = 0; i < sc; i++) {
		if (sym[i] == '*') {
			NUM[i] = NUM[i] * NUM[i + 1];
			NUM[i + 1] = NUM[i];
			sym[i] = ' ';
		}
	}// ���� ����

	int sc2 = 0;
	for (int i = 0; i < sc; i++) {
		if (sym[i] != ' ') {
			sym[sc2] = sym[i];
			NUM[sc2++] = NUM[i];
		}
	}NUM[sc2] = NUM[sc]; // ������ ����

	result = NUM[0];
	for (int i = 0; i < sc2; i++) result = SUM(sym[i], result, NUM[i + 1]);
	if (MAX < result) MAX = result;
}

void DFS(int sc) {
	if (sc >= SC) {
		calc();
		return;
	}
	for (int i = sc; i <= SC; i++) {
		if (!FLAG[i]) {
			FLAG[i] = true;
			DFS(i + 2);
			FLAG[i] = false;
		}
	}
}

int main() {
	init();
	calc();
	DFS(1);
	cout << MAX << endl;
}
*/
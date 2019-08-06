/*
//https://www.acmicpc.net/problem/16637
// 2019.07.31 20:41~
#include <iostream>
using namespace std;

long long MAX;
int N, SC, NC;	// 문자열 길이, 심볼 수, 숫자 수
char INPUT[20]; // 입력 문자열
char SYM[10];	// 심볼 위치
bool FLAG[11] = { false };

void init() {
	MAX = -2147483647;
	cin >> N;
	SC = 1; NC = 0;
	for (int i = 0; i < N; i++) {
		char temp;
		cin >> temp;
		INPUT[i] = temp;
		if (temp >= '0' && temp <= '9') NC++;
		else SYM[SC++] = temp;
	}
}

long long SUM(char symbol, long long num1, long long num2 ) {
	long long result;
	if (symbol == '-') result = num1 - num2;
	else if (symbol == '+') result = num1 + num2;
	else result = num1 * num2;
	return result;
}

void calc() {
	long long answer = (long long) (INPUT[0]-'0');

	for (int i = 1; i < SC; i++) {
		long long next;
		int jump = 0;
		if (FLAG[i]) { next = (long long)(INPUT[2 * i] - '0'); }
		else {
			if (i < SC-1  && FLAG[i+1]) {
				next = SUM(SYM[i + 1], (long long)(INPUT[2 * i] - '0'), (long long)(INPUT[2 * i +2] - '0'));	jump = 1;
			}
			else next = (long long)(INPUT[2 * i] - '0');
		}
		answer = SUM(SYM[i], answer, next); i += jump;

	}

	if (answer > MAX) MAX = answer;
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
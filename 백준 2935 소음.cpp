//https://www.acmicpc.net/problem/2935
//2019.08.28 09:49~10:29
#include <iostream>
#include <string>
#define MAX 200
using namespace std;
string NUM1, NUM2;
char SYM;

void init() {
	cin >> NUM1 >> SYM >> NUM2;
}

int max(int a, int b) { return a > b ? a : b; }

string calc() {
	string ANSWER = "1";
	int L1 = NUM1.size()-1, L2 = NUM2.size()-1;
	
	if (SYM == '*') {
		for (int i = 0; i < L1 + L2; i++)
			ANSWER += "0";
	}
	else {
		int big = max(L1, L2);
		for (int i = 0; i < big; i++)
			ANSWER += "0";
		ANSWER[big - L1] = '1';
		ANSWER[big - L2] = '1';
		if (L1 == L2) ANSWER[0] = '2';
	}
	return ANSWER;
}

void solution() {
	init();
	cout << calc() << endl;
}

int main() {
	solution();
}
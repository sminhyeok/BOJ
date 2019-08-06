/*
//https://www.acmicpc.net/problem/16968
//2019.08.04 19:12~20:23
#include <iostream>
#define NUM 10
#define LETTER 26
#define N 4
using namespace std;


char input[N];

void init() {
	for (int i = 0; i < N; i++) input[i] = ' ';
	cin >> input;
}

void solution() {
	int result = 0;
	if (input[0] == 'c') result = LETTER;
	else result = NUM;

	for (int i = 1; i < N; i++) {
		if (input[i] == ' ') break;
		if (input[i] == 'c') {
			if (input[i - 1] == 'c') result = result * (LETTER-1);
			else result = result * LETTER;
		}
		else if(input[i] == 'd'){
			if (input[i - 1] == 'd') result = result * (NUM - 1);
			else result = result * NUM;
		}
	}
	cout << result << endl;
}

int main() {
	init();
	solution();
}
*/
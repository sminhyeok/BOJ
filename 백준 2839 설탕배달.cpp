//https://www.acmicpc.net/problem/2839
//2019.09.18 10:21~10:49
#include <iostream>
using namespace std;

int N;
int SUGAR[2] = { 5,3 };
int EA[2][5001];
int INDEX[2];
void init() {
	cin >> N;
	for (int i = 0; i < 2; i++) {
		int temp = SUGAR[i];
		int j;
		for ( j = 1; temp <= N; j++) {
			EA[i][temp] = j;
			temp += SUGAR[i];
		}
		INDEX[i] = j - 1;
	}
}

int CALC() {
	int MIN = 2000;
	for (int j = INDEX[0]; j >= 0; j--) {
		int ea = EA[0][SUGAR[0] * j];
		int left = N - SUGAR[0] * j;
		if (left == 0) return ea;
		if (EA[1][left] != 0) return ea + EA[1][left];
	}
	return -1;
	
}

void solution() {
	init();
	cout << CALC() << endl;
}

int main() {
	solution();
}
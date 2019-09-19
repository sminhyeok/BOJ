//https://www.acmicpc.net/problem/11399
//2019.09.19 11:02~11:17
#include <iostream>
#include <algorithm>
using namespace std;

int N, P[1000];

void init() {
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> P[i];
}

int CALC() {
	sort(P, P + N);
	int MIN = 0;
	for (int i = 0; i < N; i++)
		MIN += P[i]*(N-i);
	return MIN;
}

void solution() {
	init();
	cout << CALC() << endl;
}


int main() {
	solution();
}
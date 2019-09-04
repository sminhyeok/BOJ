//https://www.acmicpc.net/problem/2231
//2019.09.04 10:49~11:00
#include <iostream>
using namespace std;

int N;

void init() {
	cin >> N;
}

bool check(int n) {
	int sum = 0, temp = n;
	while (temp) {
		sum += temp % 10;
		temp /= 10;
	}
	if (sum + n == N) return true;
	else return false;
}

int find() {
	int answer = 0;
	for (int i = 1; i < N; i++) {
		if (check(i)) return i; 
	}
	return answer;
}

void solution() {
	init();
	cout << find() << endl;
}

int main() {
	solution();
}
//https://www.acmicpc.net/problem/1065
//2019.09.02 15:14~15:31
#include <iostream>
using namespace std;

int N;

void init() {
	cin >> N;
}

bool check(int n) {
	if (n < 100) return true;
	if (n == 1000) return false;
	int gap = (n % 10) - ((n / 10) % 10);
	int gap2 = ((n / 10) % 10) - ((n / 100) % 10);
	
	if (gap == gap2) return true;
	else return false;
}

int find() {
	int result = 0;
	for (int i = 1; i <= N; i++)
		if (check(i)) result++;
	return result;
}

void solution() {
	init();
	cout << find() << endl;
}

int main() {
	solution();
}
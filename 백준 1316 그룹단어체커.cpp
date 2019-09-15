//https://www.acmicpc.net/problem/1316
//2019.09.14 20:35~12:35
#include <iostream>
using namespace std;

int N;
void init() {
	cin >> N;
}

bool check(char str[]) {
	bool USE[26];
	for (int i = 0; i < 26; i++) USE[i] = false;
	char before = str[0];
	USE[before - 'a'] = true;

	for (int i = 1; i < 100; i++) {
		if (str[i] < 'a' || str[i] >'z') break;
		if (before == str[i]) continue;
		if (USE[str[i] - 'a']) return false;
		USE[str[i] - 'a'] = true;
		before = str[i];
	}
	return true;
}

int find() {
	int result = 0;
	for (int i = 0; i < N; i++) {
		char str[100];
		cin >> str;
		if (check(str)) result++;
	}
	return result;
}

void solution() {
	init();
	cout << find();
}

int main() {
	solution();
}
//https://www.acmicpc.net/problem/1789
//2019.08.28 09:29~09:47
#include <iostream>
using namespace std;
unsigned long long S;

int DFS(unsigned long long s, unsigned long long n) {
	if (S <= s) return 1;
	else return 1 + DFS(s + n, n + 1);
}

void solution() {
	cin >> S;
	cout << DFS(2, 3) << endl;
}

int main() {
	solution();
}
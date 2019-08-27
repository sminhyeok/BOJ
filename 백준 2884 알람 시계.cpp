//https://www.acmicpc.net/problem/2884
//2019.08.27 10:03~10:18
#include <iostream>
using namespace std;

int H, M;

void init() {
	cin >> H >> M;
}

void fast() {
	if (M < 45) H--;
	M -= 45;
	if (M < 0) M = 60 + M;
	if (H < 0) H = 23;
}

void solution() {
	init();
	fast();
	cout << H << " " << M;
}

int main() {
	solution();
}
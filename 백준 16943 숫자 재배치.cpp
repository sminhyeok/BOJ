/*
//https://www.acmicpc.net/problem/16943
// 2019.08.02 20:26~20:43
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> V;
long long A, B, MAX;
bool USE[10];
bool comp(const int& a, const int& b) { return a > b; }	// 내림차순정렬

void init() {
	MAX = -1;
	cin >> A >> B;
	while (A) {
		V.push_back(A % 10);
		A /= 10;
	} // V에 A의 각 숫자들이 저장됨
	sort(V.begin(), V.end(), comp);
}

void DFS(long long num, int t) {
	if (num > B) return;
	if (t == V.size() && MAX < num) { MAX = num; return; }

	for (int i = 0; i < V.size(); i++) {
		if (t == 0 && V.at(i) == 0) return;
		if (!USE[i]) {
			USE[i] = true;
			long long sum = num * 10;
			sum += (long long)V.at(i);
			DFS(sum, t+1);
			USE[i] = false;
		}

	}

}

int main() {
	init();
	DFS(0, 0);
	cout << MAX << endl;
}
*/
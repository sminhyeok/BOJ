//https://www.acmicpc.net/problem/2851
//2019.08.29 09:10~09:23
#include <iostream>
#define MID 100
using namespace std;

int MUSHROOM[10];

void init() {
	for (int i = 0; i < 10; i++)
		cin >> MUSHROOM[i];
}

int CALC() {
	int result = 0, gap = MID;
	for (int i = 0; i < 10; i++) {
		if (result < 100) {
			int next = result + MUSHROOM[i];
			if (abs(next - MID) <= abs(result - MID)) {
				result = next;
			}
			else return result;
		}
	}
	return result;
}

void solution() {
	init();
	cout << CALC() << endl;
}

int main() {
	solution();
}
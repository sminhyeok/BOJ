//https://www.acmicpc.net/problem/2309
//2019.08.31 10:37~11:00
#include <iostream>
#define SUM 100
using namespace std;

int PEOPLE[9], ANSWER[7];
bool FLAG;
void init() {
	FLAG = false;
	for (int i = 0; i < 9; i++)
		cin >> PEOPLE[i];
}

void DFS(int start, int index, int total) {
	if (FLAG) return;
	if (total > SUM) return;
	if (index == 7 && total == SUM) {
		FLAG = true; return;
	}
	if (index == 7) return;

	for(int i = start; i <= 2+index; i++){
		if (FLAG) return;
		ANSWER[index] = PEOPLE[i];
		DFS(i + 1, index + 1, total + PEOPLE[i]);
	}
}

void sort() {
	for(int i = 0; i < 6; i++)
		for (int j = i + 1; j < 7; j++) {
			if (ANSWER[i] > ANSWER[j]) {
				int temp = ANSWER[i];
				ANSWER[i] = ANSWER[j];
				ANSWER[j] = temp;
			}
		}
}

void print() {
	for (int i = 0; i < 7; i++)
		cout << ANSWER[i] << endl;
}

void solution() {
	init();
	DFS(0, 0, 0);
	sort();
	print();
}

int main() {
	solution();
}

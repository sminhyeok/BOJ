//https://www.acmicpc.net/problem/1182
//2019.09.01 13:45~14:25
#include <iostream>
using namespace std;
int NUM[20];
int N, S, ANSWER;

void init() {
	cin >> N >> S;
	ANSWER = 0;
	for (int i = 0; i < N; i++) {
		cin >> NUM[i];
	}
}

void swap(int a, int b) {
	int temp = NUM[a];
	NUM[a] = NUM[b]; NUM[b] = temp;
}

void quicksort(int left, int right) {
	if (left >= right) return;
	int pivot = NUM[(left + right) / 2];
	int i = left;
	int j = right;
	
	while (i <= j) {
		while (NUM[i] < pivot) i++;
		while (NUM[j] > pivot) j--;
		if (i <= j) {
			swap(i, j); i++; j--;
		}
	}
	quicksort(left, j);
	quicksort(i, right);
}

void DFS(int total, int index) {
	if (total + NUM[index] == S) ANSWER++;
	if (index == N - 1) return;

	DFS(total, index + 1);
	DFS(total + NUM[index], index + 1);
}

void solution() {
	init();
	quicksort(0, N - 1);
	DFS(0, 0);
	cout << ANSWER << endl;
}

int main() {
	solution();
}

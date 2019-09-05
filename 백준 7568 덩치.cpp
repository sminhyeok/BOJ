//https://www.acmicpc.net/problem/7568
//2019.09.05 11:23~12:23
#include <iostream>
#define MAX 50
using namespace std;

struct STAT {
	int w, h;
};
STAT PEOPLE[MAX];
int RANK[MAX];
int N;

void init() {
	cin >> N;
	for (int i = 0; i < N; i++) 
		cin >> PEOPLE[i].w >> PEOPLE[i].h;
	
}

void find() {
	for (int i = 0; i < N; i++) {
		int r = 0, W = PEOPLE[i].w, H = PEOPLE[i].h;
		for (int j = 0; j < N; j++) {
			if (PEOPLE[j].w > W && PEOPLE[j].h > H) r++;
		}
		RANK[i] = r + 1;
	}
}

void print() {
	for (int i = 0; i < N; i++)
		cout << RANK[i] << " ";
}

void solution() {
	init();
	find();
	print();
}

int main() {
	solution();
}
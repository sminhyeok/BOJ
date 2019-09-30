//2019.09.30 10:58~11:14
#include <iostream>
using namespace std;

int N, M;
int PARENT[200], LEVEL[200];

void init() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) { PARENT[i] = i; LEVEL[i] = 1; }
}


int FIND(int u) {
	if (u == PARENT[u]) return u;
	return PARENT[u] = FIND(PARENT[u]);
}

void UNION(int u, int v) {
	u = FIND(u); v = FIND(v);
	if (u == v) return;

	if (LEVEL[u] > LEVEL[v]) swap(u, v);
	PARENT[u] = v;
	if (LEVEL[u] == LEVEL[v]) LEVEL[v]++;
}

bool CHECK() {
	int LINK[1000];
	for (int i = 0; i < M; i++) {
		int CITY; cin >> CITY;
		LINK[i] = FIND(CITY - 1);
	}

	for (int i = 1; i < M; i++)
		if (LINK[1] != LINK[i]) return false;
	return true;
}

void solution() {
	init();
	// UNION 트리 형성
	for(int y = 0; y < N; y++)
		for (int x = 0; x < N; x++) {
			bool connect;
			cin >> connect;
			if (connect) UNION(y, x);
		}
	if (CHECK()) cout << "YES";
	else cout << "NO";
}

int main() {
	solution();
}
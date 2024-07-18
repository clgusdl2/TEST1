#include<iostream>
#include<cstring>
#include<queue>

using namespace std;

int N, cnt;
int K[301][301] = { 0, };
int visited[301][301] = { 0, };
char M[301][301] = { 0, };
int dx[8] = { -1,-1,0,1,1,1,0,-1 };
int dy[8] = { 0,1,1,1,0, -1, -1, -1 };
queue <pair<int, int >> q;

void mak() {
	int ax, ay, c;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (M[i][j] == '*') {
				K[i][j] = -1;
				visited[i][j]++;
				continue;
			}
			c = 0;
			for (int x = 0; x < 8; x++) {
				ax = i + dx[x];
				ay = j + dy[x];

				if (ax > N - 1 || ay > N - 1 || ax < 0 || ay < 0) {
					continue;
				}
				if (M[ax][ay] == '*') {
					c++;
				}
			}
			K[i][j] = c;
		}
	}
}

void bfs() {
	int x, y, ax, ay;

	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		if (visited[x][y] == 0) {
			visited[x][y]++;
			cnt++;
		}
		q.pop();

		for (int i = 0; i < 8; i++) {
			ax = x + dx[i];
			ay = y + dy[i];

			if (ax > N - 1 || ay > N - 1 || ax < 0 || ay < 0) {
				continue;
			}
			if (visited[ax][ay] == 0) {
				visited[ax][ay]++;
				if (K[ax][ay] == 0) {
					q.push(make_pair(ax, ay));
				}
			}
		}
	}
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		memset(K, 0, sizeof(K));
		memset(visited, 0, sizeof(visited));
		memset(M, 0, sizeof(M));
		cnt = 0;

		cin >> N;
		for (int i = 0; i < N; i++) {
			string s;
			cin >> s;
			for (int j = 0; j < N; j++) {
				M[i][j] = s[j];
			}
		}

		mak();

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (K[i][j] == 0) {
					q.push(make_pair(i, j));
					bfs();
				}
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (visited[i][j] == 0) {
					cnt++;
				}
			}
		}


		cout << '#' << test_case << ' ' << cnt << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
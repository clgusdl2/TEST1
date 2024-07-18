#include<iostream>
#include<string.h>
#include<queue>
#include<tuple>

using namespace std;


int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N, s[2], e[2], t;
		int map[15][15];
		int xx[4] = { 0,0,1,-1 };
		int yy[4] = { 1,-1,0,0 };
		queue<tuple<int, int, int>> q;
		int vit[15][15];
		memset(vit, 0, sizeof(vit));
		cin >> N;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
			}
		}
		cin >> s[0] >> s[1];
		cin >> e[0] >> e[1];
		q.push(make_tuple(s[0], s[1], 0));
		t = 0;

		while (!q.empty()) {
			int x = get<0>(q.front());
			int y = get<1>(q.front());
			int c = get<2>(q.front());
			q.pop();

			if (x == e[0] && y == e[1]) {
				cout << "#" << test_case << " " << c << endl;
				t = 1;
				break;
			}
			vit[x][y] = 1;

			for (int i = 0; i < 4; i++) {
				int dx = x + xx[i];
				int dy = y + yy[i];

				if (vit[dx][dy] == 1 || map[dx][dy] == 1 || dx < 0 || dy < 0 || dx >= N || dy >= N) continue;
				if (map[dx][dy] == 2) {
					if (c % 3 == 2) {
						q.push(make_tuple(dx, dy, c + 1));
					}
					else {
						q.push(make_tuple(x, y, c + 1));
					}
				}
				if(map[dx][dy] == 0) {
					q.push(make_tuple(dx, dy, c + 1));
				}
			}
		}
		if (t == 0) {
			cout << "#" << test_case << " " << -1 << endl;
		}
	}

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
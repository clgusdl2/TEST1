#include<iostream>

using namespace std;
int N, M;
int c;
int map[15][15];
int x[8] = { 0,0,1,-1 , 1,1,-1,-1 };
int y[8] = { 1,-1,0,0,1,-1,1,-1 };

void so() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int c2 = map[i][j];
			int c3 = map[i][j];
			for (int k = 1; k < M; k++) {
				for (int z = 0; z < 4; z++) {
					int dx = i + x[z] * k;
					int dy = j + y[z] * k;
					if (dx < 0 || dy < 0 || dx >= N || dy >= N) continue;
					c2 += map[dx][dy];
				}
				for (int z = 4; z < 8; z++) {
					int dx = i + x[z] * k;
					int dy = j + y[z] * k;
					if (dx < 0 || dy < 0 || dx >= N || dy >= N) continue;
					c3 += map[dx][dy];
				}
			}
			if (c < c2) {
				c = c2;
			}
			if (c < c3) {
				c = c3;
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
		cin >> N >> M;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
			}
		}
		c = 0;
		so();


		cout << "#" << test_case << " " << c << endl;

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
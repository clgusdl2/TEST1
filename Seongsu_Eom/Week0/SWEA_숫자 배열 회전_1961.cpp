#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N;
		cin >> N;
		int M[4][7][7];
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> M[0][i][j];
			}
		}

		for (int i = 1; i < 4; i++) {
			for (int j = 0; j < N; j++) {
				for (int k = 0; k < N; k++) {
					M[i][k][N - j - 1] = M[i - 1][j][k];
				}
			}
		}


		cout << "#" << test_case << endl;
		for (int i = 0; i < N; i++) {
			for (int j = 1; j < 4; j++) {
				for (int k = 0; k < N; k++) {
					cout << M[j][i][k];
				}
				cout << " ";
			}
			cout << endl;
		}

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
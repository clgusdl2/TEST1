#include<iostream>
#include<vector>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N, M;
		cin >> N >> M;
		int A[20], B[20];
		for (int i = 0; i < N; i++) {
			cin >> A[i];
		}
		for (int i = 0; i < M; i++) {
			cin >> B[i];
		}
		int max = 0;
		if (N == M) {
			for (int i = 0; i < M; i++) {
				max += A[i] * B[i];
			}
		}
		else if (N < M) {
			for (int i = 0; i < M - N + 1; i++) {
				int max2 = 0;
				for (int j = 0; j < N; j++) {
					max2 += A[j] * B[i + j];
				}
				if (max2 > max) {
					max = max2;
				}
			}
		}
		else {
			for (int i = 0; i < N - M + 1; i++) {
				int max2 = 0;
				for (int j = 0; j < M; j++) {
					max2 += A[i + j] * B[j];
				}
				if (max2 > max) {
					max = max2;
				}
			}
		}
		cout << "#" << test_case << " " << max << endl;

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
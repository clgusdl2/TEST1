#include<iostream>

using namespace std;

int so(int N, int B, int H[20], int cnt, int S) {
	if (cnt == N) {
		if (S >= B) {
			return S - B;
		}
		return -1;
	}
	if (S >= B) {
		return S - B;
	}

	int s1 = so(N, B, H, cnt + 1, S);
	int s2 = so(N, B, H, cnt + 1, S + H[cnt]);

	if (s1 == -1) {
		return s2;
	}
	else if (s2 == -1) {
		return s1;
	}
	else {
		if (s1 > s2) {
			return s2;
		}
		else {
			return s1;
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
		int N, B, S;
		int H[20];
		cin >> N >> B;
		for (int i = 0; i < N; i++) {
			cin >> H[i];
		}

		S = so(N, B, H, 0, 0);


		cout << "#" << test_case << " " << S << endl;

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
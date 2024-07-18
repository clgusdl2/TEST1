#include<iostream>

using namespace std;



int solve()
{
	int n, m;
	cin >> n >> m;

	int ai[21] = { 0, };
	int bj[21] = { 0, };
	
	for (int i = 0; i < n; i++)
	{
		cin >> ai[i];
	}
	for (int j = 0; j < m; j++)
	{
		cin >> bj[j];
	}	

	if (n > m)
	{
		int ansSum = 0;
		for (int i = 0; i <= n-m; i++)
		{
			int sum = 0;
			for (int j = 0; j < m; j++)
			{
				sum += ai[i + j] * bj[j];
			}

			ansSum = max(sum, ansSum);
		}
		return ansSum;
	}
	else
	{
		int ansSum = 0;
		for (int i = 0; i <= m - n; i++)
		{
			int sum = 0;
			for (int j = 0; j < n; j++)
			{
				sum += bj[i + j] * ai[j];
			}
			ansSum = max(sum, ansSum);
		}
		return ansSum;
	}

}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int ans = solve();
		cout << "#" << test_case << " " << ans << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
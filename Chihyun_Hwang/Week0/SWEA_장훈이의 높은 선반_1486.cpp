#include<iostream>
#include<vector>
#include <cstring>
using namespace std;

int n, b;// 사람 수 , 원하는 물건위치
int visited[21];
vector<int>p; //

int minv = 10001;
int test_case;
int T;
void input()
{
	cin >> n >> b;
	p.clear();
	p.resize(n);
	minv = 10001;

	memset(visited, 0, sizeof(visited));

	for (int i = 0; i < n; i++)
	{
		cin >> p[i];
	}
}

void dt(int level, int sum)
{

	if (sum >= b)
	{
		if (minv > sum)
		{
			minv = sum;
		}
		return;
	}
	if (level == n)
	{
		if (sum >= b)
		{
			if (minv > sum)
			{
				minv = sum;
			}
			return;
		}
		return;
	}

	for (int i = level; i < p.size(); i++)
	{
		if (!visited[i])
		{
			visited[i] = 1;
			sum += p[i];
			dt(i+1, sum);
			sum -= p[i];
			visited[i] = 0;

		}
	}

}

void solve()
{


	dt(0, 0);
	cout << "#" << test_case << " " << b-minv << endl;
	

}

int main(int argc, char** argv)
{


	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		input();
		solve();
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
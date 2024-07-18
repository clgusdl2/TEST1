#include<iostream>

using namespace std;


int sz, power;
int map[16][16];
void init()
{
	cin >> sz >> power;
	for (int i = 0; i < sz; i++)
	{
		for (int j = 0; j < sz; j++)
		{
			cin>>map[i][j];
		}
	}
}
// 북동남서
int dx1[4] = {-1,0,1,0};
int dy1[4] = {0,1,0,-1};

// 왼대각 시계방향
int dx2[4] = {-1,-1,1,1};
int dy2[4] = {-1,1,1,-1};

void solve(int test_case)
{

	int maxplusSum = 0;
	for (int i = 0; i < sz; i++)
	{
		for (int j = 0; j < sz; j++)
		{
			int plusSum = map[i][j];
			for (int t = 1; t <= power-1; t++)
			{
				for (int k= 0; k < 4; k++)
				{
					int nx = i + (dx1[k] * t);
					int ny = j + (dy1[k] * t);
					if (nx < 0 || nx >= sz || ny < 0 || ny >= sz) {
						continue;
					} // 범위에 벗어나면 무시
					plusSum += map[nx][ny];
				}
			}
			if (maxplusSum < plusSum)
			{
				maxplusSum = plusSum;
			}
		}
	}
	// +

	

	// x
	int maxXsum = 0;
	for (int i = 0; i < sz; i++)
	{
		for (int j = 0; j < sz; j++)
		{
			int xSum = map[i][j];
			for (int t = 1; t <= power-1; t++)
			{
				for (int k = 0; k < 4; k++)
				{
					int nx = i + (dx2[k] * t);
					int ny = j + (dy2[k] * t);
					if (nx < 0 || nx >= sz || ny < 0 || ny >= sz) {
						continue;
					} // 범위에 벗어나면 무시
					xSum += map[nx][ny];
					//cout << nx <<" " << ny << endl;
				}
			}
			if (maxXsum < xSum)
			{
				maxXsum = xSum;
			}
		}
	}
	cout << "#" << test_case << " " << max(maxXsum, maxplusSum)<<endl;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{
		// + 방법과 x 방법중 가장많이 퇴치 되는것을 골라서 
		// 프린트
		init();
		solve(test_case);

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
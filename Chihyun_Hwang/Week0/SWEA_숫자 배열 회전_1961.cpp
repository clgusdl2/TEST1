#include<iostream>

#define maxSZ 7
int originmap[maxSZ][maxSZ];
int map[maxSZ][maxSZ];
int map90[maxSZ][maxSZ];
int map180[maxSZ][maxSZ];
int map270[maxSZ][maxSZ];

using namespace std;

void rot90(int squarex,int squarey, int sz,int (*map)[7])
{

	int tempmap[maxSZ][maxSZ] = { 0, };
	for (int x = squarex; x < sz+squarex; x++)
	{
		for (int y = squarey; y < sz+squarey; y++)
		{
			int sx = x - squarex;
			int sy = y - squarey;

			tempmap[sy + squarex][sz - sx - 1 + squarey] = map[x][y];
		}
	}
	for (int x = 0; x < sz; x++)
	{
		for (int y = 0; y < sz; y++)
		{
			map[x][y] = tempmap[x][y];
		}
	}
}

void copymap(int(*map)[7], int(*map2)[7])
{
	for (int x = 0; x < 7; x++)
	{
		for (int y = 0; y < 7; y++)
		{
			map[x][y] = map2[x][y];
		}
	}
}

void solve()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
		}
	}

	rot90(0,0,n,map);
	copymap(map90, map);
	rot90(0, 0, n, map);
	copymap(map180, map);
	rot90(0, 0, n, map);
	copymap(map270, map);

	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << map90[i][j];
		}
		cout << " ";
		for (int j = 0; j < n; j++)
		{
			cout << map180[i][j];
		}
		cout << " ";
		for (int j = 0; j < n; j++)
		{
			cout << map270[i][j];
		}

		cout << endl;
	}

}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		cout << "#" << test_case << endl;
		solve();
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
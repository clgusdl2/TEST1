#include<iostream>
#include<queue>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAXN 301

int visited[MAXN][MAXN];
char map[MAXN][MAXN];
int n;
int cnt = 0;


int dx[8] = { 0, 0, -1, 1, -1, 1, -1, 1 };
int dy[8] = { -1, 1, 0, 0, -1, 1, 1, -1 };


int test_case;
int T;
//���� 8�� ���� ���� 0���� ��ġ ã��

bool check(int x, int y)
{
	for (int i = 0; i < 8; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
		
		if (map[nx][ny] == '*')
		{
			return false;
		}
	}
	return true;
}

void init()
{
	cin >> n;
	
	memset(visited, 0, sizeof(visited));
	memset(map, 0, sizeof(map));

	cnt = 0;

	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < s.size(); j++)
		{
			map[i][j] = s[j];
		}

	}


}


void bfs(int x ,int y)
{
	queue<pair<int, int>>q;
	q.push({ x,y });
	visited[x][y] = 1;

	while (!q.empty())
	{
		pair<int, int> temp = q.front();
		int cx = temp.first, cy = temp.second;
		q.pop();
		for (int i = 0; i < 8; i++)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;

			if (visited[nx][ny]) continue;

			if (map[nx][ny] == '.')
			{	
				visited[nx][ny] = 1;
				if (check(nx, ny))
				{
					q.push({ nx,ny });
				}
			}


		}
	}


}

void solve()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!visited[i][j] && map[i][j] == '.' && check(i, j))
			{
				cnt++;
				bfs(i, j);
			}
		}
	} //bfs�� ���� 8���� 0�ΰ� üũ

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!visited[i][j] && map[i][j] == '.')
			{
				cnt++;
			}
		}
	}//�湮 �������� ���� ��� ��������
	cout <<"#"<<test_case<<" " << cnt << endl;


}

int main(int argc, char** argv)
{


	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		init();
		solve();

	}
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}
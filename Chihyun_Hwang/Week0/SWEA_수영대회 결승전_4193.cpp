#include<iostream>
#include <string.h>
#include <algorithm>
#include <queue>
using namespace std;

#define MAXN 15
int n; // ��ũ��
int map[MAXN][MAXN]; //��
int visited[MAXN][MAXN];

int sx, sy; //������ġ
int ex, ey; //������ġ

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int result = 0;

void init()
{
	result = 0;
	memset(map, 0, sizeof(map));
	memset(visited, 0, sizeof(visited));

	/*
		fill(&map[0][0], &map[MAXN-1][MAXN], 0);
	*/
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
		}
	}
	cin >> sx >> sy;
	cin >> ex >> ey;


}

void bfs(int sx, int sy)
{
	queue<pair<int, pair<int, int>>>q;
	q.push({ -1,{ sx,sy } });
	visited[sx][sy] = 1;


	while (!q.empty())
	{

		int size = q.size();
		pair<int, pair<int, int>> temp = q.front();
		int timep = temp.first;
		int cx = temp.second.first;
		int cy = temp.second.second;
		timep++;
		q.pop();

		//cout << "cxcy: " << " �ð� " << timep << " " << cx << " " << cy << endl;

		if (cx == ex && cy == ey)
		{
			result = timep;
			return;
		}

		for (int i = 0; i < 4; i++)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			//��ǥ ���� Ȯ��
			if (nx >= n || ny >= n || nx < 0 || ny < 0) continue;

			if (map[nx][ny] == 1) continue; //������

			if (visited[nx][ny]) continue;

			if (map[nx][ny] == 2)
			{
				if (timep % 3 == 2) // ����̵� ������ �� �ִ� �ð�
				{
					q.push({ timep,{ nx,ny } });
					visited[nx][ny] = 1;
				}
				else
				{
					q.push({ timep,{ cx,cy } });
				}
			}

			if (!visited[nx][ny] && map[nx][ny] == 0)
			{
				visited[nx][ny] = 1;
				q.push({ timep,{ nx,ny } });
			}

		}

	}
	result = -1; // ������ �� ���ٸ�
	return;

}

int solve()
{
	// 0�� ������ �� �ִ� �Ÿ�
	// ������ �� ���� ��ֹ�, ������� ��ֹ�
	//�ҿ뵹�̴� 0�� 1�� / 2�� ������ / 3,4�� ���� / 5�� ������

	// �� 0�϶��� ���������� 1�ʴ� ������
	// ���� bfs������ --�ϸ� �ɵ�

	bfs(sx, sy);
	return result;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;
	/*
	   ���� ���� �׽�Ʈ ���̽��� �־����Ƿ�, ������ ó���մϴ�.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{
		init();
		solve();
		cout << "#" << test_case << " " << result << endl;
	}
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}